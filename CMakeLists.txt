cmake_minimum_required(VERSION 3.13)
project(irem VERSION 0.3)

if (MSVC)
  message(FATAL_ERROR "UNIX only, guys.")
endif()

add_subdirectory(${CMAKE_CURRENT_LIST_DIR}/thirdparty/SQLiteCpp)


include(GNUInstallDirs)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED true)
set(CMAKE_BUILD_TYPE Release)

find_package(PkgConfig REQUIRED)
pkg_check_modules(GTKMM gtkmm-3.0 REQUIRED IMPORTED_TARGET)

find_package(Threads REQUIRED)

find_package(Boost 1.65.0 REQUIRED COMPONENTS system)

set(Boost_USE_STATIC_LIBS OFF)
set(Boost_USE_DEBUG_LIBS OFF)
set(Boost_USE_RELEASE_LIBS ON)

add_definitions(-DPACKAGE_VERSION="${PACKAGE_VERSION}"
                -DPACKAGE_URL="https://rjhansen.github.io/irem"
                -DPACKAGE_BUGREPORT="rob@hansen.engineering")

add_executable(irem src/main.cc src/initialize.cc src/ui.cc)
link_directories(${GTKMM_LIBRARY_DIRS})
include_directories(${GTKMM_INCLUDE_DIRS} ${Boost_INCLUDE_DIRS}
    src ${CMAKE_CURRENT_LIST_DIR}/thirdparty/SQLiteCpp/include)
target_link_libraries(irem Boost::system Threads::Threads 
    ${GTKMM_LIBRARIES} SQLiteCpp sqlite3 dl)

if ("${CMAKE_CXX_COMPILER_ID}" MATCHES "Clang")
    target_link_libraries(irem c++fs)
elseif ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU")
    target_link_libraries(irem stdc++fs)
endif()

install(TARGETS irem RUNTIME DESTINATION bin)
