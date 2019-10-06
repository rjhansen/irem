#include <gtkmm.h>
#include <SQLiteCpp/SQLiteCpp.h>
#include <string>
#include <memory>

class Irem {
    public:
    Irem(Glib::RefPtr<Gtk::Application> application);
    ~Irem() { }
    Gtk::Window& getWindow() { return *window; }

    private:
    void updateUI();
    void connectTo();
    void disconnectFrom();
    void showWorldEditor();
    void showAvatarEditor();
    void initializeDb();
    void initializeUi();
    Glib::RefPtr<Gtk::Application> app;
    Glib::RefPtr<Gtk::Builder> bldr;
    std::unique_ptr<SQLite::Database> db;
    std::unique_ptr<Gtk::Window> window;
};

bool initializeIrem();