#include "initialize.h"
#include <filesystem>
#include <string>
#include <iostream>

using std::filesystem::is_directory;
using std::filesystem::create_directories;
using std::filesystem::path;
using std::string;
using std::cout;

void initializeIrem()
{
    path configdir { getenv("HOME") };
    configdir /= ".config";
    configdir /= "irem";
    cout << configdir.c_str() << "\n";
    if (! is_directory(configdir))
        create_directories(configdir);
    exit(1);
}