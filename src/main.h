#include <gtkmm.h>
#include <SQLiteCpp/SQLiteCpp.h>
#include <string>

class Irem {
    public:
    Irem(Glib::RefPtr<Gtk::Application> application);
    ~Irem() { delete window; }
    Gtk::Window& getWindow() { return *window; }

    private:
    void updateUI();
    void connectTo();
    void disconnectFrom();
    void showWorldEditor();
    void showAvatarEditor();
    Glib::RefPtr<Gtk::Application> app;
    Gtk::Window* window;
    Gtk::MenuItem* avatars;
    SQLite::Database db;
};

bool initializeIrem();