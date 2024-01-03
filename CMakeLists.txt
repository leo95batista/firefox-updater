cmake_minimum_required(VERSION 3.27)

project(firefox_updater)

set(CMAKE_CXX_STANDARD 17)

find_package(Boost REQUIRED COMPONENTS program_options)
find_package(CURL REQUIRED)

add_executable(firefox_updater
        main.cpp
        cli/abstract_option.h
        cli/abstract_option.cpp
        cli/options_manager.h
        cli/options_manager.cpp
        cli/options/arch_option.h
        cli/options/arch_option.cpp
        cli/options/edition_option.h
        cli/options/edition_option.cpp
        cli/options/lang_option.h
        cli/options/lang_option.cpp
        cli/options/path_option.h
        cli/options/path_option.cpp
        include/utils/array.h
)

target_link_libraries(firefox_updater
        CURL::libcurl
)

target_include_directories(firefox_updater
        PRIVATE ${PROJECT_SOURCE_DIR}/cli
        PRIVATE ${PROJECT_SOURCE_DIR}/include
)
