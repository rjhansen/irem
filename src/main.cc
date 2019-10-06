#include "main.h"
#include <array>
#include <filesystem>
#include <iostream>

using Glib::RefPtr;
using Gtk::Main, Gtk::Builder, Gtk::Application, Gtk::Window, Gtk::MenuItem;
using sigc::ptr_fun, sigc::mem_fun;
using SQLite::Database;
using std::string, std::cout, std::array, std::make_unique, std::unique_ptr,
    std::filesystem::path;

extern const std::string mainWindowXML;

Irem::Irem(RefPtr<Application> application)
    : app(application)
{
    initializeDb();
    initializeUi();
}

void Irem::initializeUi()
{
    bldr = Builder::create_from_string(mainWindowXML);
    MenuItem* mi { nullptr };
    Window* window { nullptr };

    bldr->get_widget("MainWindow", window);
    this->window = unique_ptr<Window>(window);

    bldr->get_widget("connect-to", mi);
    mi->signal_activate().connect(mem_fun(*this, &Irem::connectTo));

    bldr->get_widget("quit", mi);
    mi->signal_activate().connect(mem_fun(*window, &Window::close));

    bldr->get_widget("worlds", mi);
    mi->signal_activate().connect(mem_fun(*this, &Irem::showWorldEditor));

    bldr->get_widget("avatars", mi);
    mi->signal_activate().connect(mem_fun(*this, &Irem::showAvatarEditor));
}

void Irem::initializeDb()
{
    array<const char*, 4> initializers = {
        "CREATE TABLE IF NOT EXISTS kinds "
        "(id INTEGER PRIMARY KEY, name TEXT, UNIQUE(name))",
        "CREATE TABLE IF NOT EXISTS worlds "
        "(id INTEGER PRIMARY KEY, kind INTEGER, name TEXT, "
        "host TEXT, port INTEGER, FOREIGN KEY(kind) "
        "REFERENCES kinds(id), UNIQUE(name), UNIQUE(host, port) "
        "ON CONFLICT REPLACE)",
        "CREATE TABLE IF NOT EXISTS avatars (id INTEGER "
        "PRIMARY KEY, world INTEGER, name TEXT, password TEXT, "
        "FOREIGN KEY(world) REFERENCES worlds(id), UNIQUE(world, "
        "name) ON CONFLICT REPLACE)"
    };

    auto iremdir = path(getenv("HOME")) / ".config" / "irem";
    path iremfile = iremdir / "irem.sqlite";

    if (!is_directory(iremdir))
        create_directories(iremdir);

    if (!(exists(iremfile) && is_regular_file(iremfile))) {
        auto dbPath = iremfile.c_str();
        auto flags = SQLite::OPEN_READWRITE | SQLite::OPEN_CREATE;
        Database tmpDbObj(dbPath, flags);
        for (auto stmt : initializers)
            tmpDbObj.exec(stmt);
    }
    db = make_unique<Database>(iremfile.c_str(),
        SQLite::OPEN_READWRITE);
}

void Irem::connectTo()
{
}

void Irem::disconnectFrom()
{
}

void Irem::showWorldEditor()
{
}

void Irem::showAvatarEditor()
{
}

void Irem::updateUI()
{
}

int main(int argc, char* argv[])
{
    auto app = Application::create(argc, argv, "engineering.hansen.irem");
    Irem irem(app);
    app->run(irem.getWindow());
    return 0;
}
