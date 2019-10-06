#include "initialize.h"
#include <filesystem>
#include <string>
#include <iostream>
#include <SQLiteCpp/SQLiteCpp.h>
#include <array>

using std::filesystem::is_directory;
using std::filesystem::exists;
using std::filesystem::is_regular_file;
using std::filesystem::create_directories;
using std::filesystem::path;
using std::string;
using SQLite::Database;
using SQLite::Statement;
using std::array;

namespace {
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
}
string dbPath;

bool initializeIrem()
{
    try {
        path iremdir { getenv("HOME") };
        path iremfile;

        iremdir /= ".config";
        iremdir /= "irem";
        iremfile = iremdir / "irem.sqlite";

        if (! is_directory(iremdir))
            create_directories(iremdir);

        if (exists(iremfile) && is_regular_file(iremfile))
            return true;
        
        dbPath = iremfile.c_str();
        auto flags = SQLite::OPEN_READWRITE|SQLite::OPEN_CREATE;
        Database db(dbPath, flags);
        for (auto stmt: initializers)
            db.exec(stmt);

    } catch (...) {
        return false;
    }
    return true;
}