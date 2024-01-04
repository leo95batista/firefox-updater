cmake_minimum_required(VERSION 3.27)

project(firefox_updater)

set(CMAKE_CXX_STANDARD 17)

add_executable(firefox_updater
        src/main.cpp
        src/cli/abstract_option.h
        src/cli/abstract_option.cpp
        src/cli/options_manager.h
        src/cli/options_manager.cpp
        src/cli/options/arch_option.h
        src/cli/options/arch_option.cpp
        src/cli/options/edition_option.h
        src/cli/options/edition_option.cpp
        src/cli/options/lang_option.h
        src/cli/options/lang_option.cpp
        src/cli/options/path_option.h
        src/cli/options/path_option.cpp
        src/include/utils/array.h
)

target_include_directories(firefox_updater
        PRIVATE src/cli
        PRIVATE src/include
)
