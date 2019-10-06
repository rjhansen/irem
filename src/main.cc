#include "main.h"
#include "initialize.h"
#include <iostream>
#include <filesystem>

using std::filesystem::path;
using Glib::RefPtr;
using Gtk::Main;
using Gtk::Builder;
using Gtk::Application;
using Gtk::Window;
using Gtk::MenuItem;
using std::string;
using std::cout;
using sigc::ptr_fun;
using sigc::mem_fun;

extern const std::string mainWindowXML;
extern const string dbPath;

Irem::Irem(RefPtr<Application> application) : app(application),
    window(nullptr),
    avatars(nullptr),
    db(dbPath.c_str(), SQLite::OPEN_READWRITE)
{
    auto builder = Builder::create_from_string(mainWindowXML);
    MenuItem *mi { nullptr };
    builder->get_widget("MainWindow", window);

    builder->get_widget("connect-to", mi);
    mi->signal_activate().connect(mem_fun(*this, &Irem::connectTo));

    builder->get_widget("quit", mi);
    mi->signal_activate().connect(mem_fun(*window, &Window::close));
    
    builder->get_widget("worlds", mi);
    mi->signal_activate().connect(mem_fun(*this, &Irem::showWorldEditor));

    builder->get_widget("avatars", avatars);
    avatars->signal_activate().connect(mem_fun(*this, &Irem::showAvatarEditor));
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

int main(int argc, char *argv[]) 
{
    initializeIrem();
    auto app = Application::create(argc, argv, "engineering.hansen.irem");
    Irem irem(app);
    app->run(irem.getWindow());
    return 0;
}
