#ifndef FIREFOX_UPDATER_OPTIONS_MANAGER_H
#define FIREFOX_UPDATER_OPTIONS_MANAGER_H

#include "iostream"
#include "filesystem"
#include "getopt.h"
#include "map"
#include "memory"
#include "variant"
#include "abstract_option.h"
#include "options/arch_option.h"

namespace cli {
    class options_manager {
    public:
        options_manager(int argc, char *argv[]) : argc(argc), argv(argv) {

            int option_index = parse_options();

            if (option_index == 1 || option_index < argc) {
                /**
                 * If no argument is given when application is launched, or if none of the
                 * given options is a valid option, then we print the help and exit.
                 */
                print_help(EXIT_FAILURE);
            }
        }

        static void print_help(int status);

        static void print_version();

        ~options_manager() = default;

    private:
        int argc;
        char **argv;
        std::map<std::string, std::variant<
                std::unique_ptr<cli::options::arch_option>
        >> options_map;

        int parse_options();
    };
}

#endif //FIREFOX_UPDATER_OPTIONS_MANAGER_H
