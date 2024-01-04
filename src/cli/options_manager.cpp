#include "options_manager.h"

void cli::options_manager::print_help(int status) {
    /**
     * Determine the stream to use from the given status code.
     */
    FILE *stream = (status == EXIT_SUCCESS) ? stdout : stderr;

    fprintf(stream,
            "USAGE: firefox-updater --path <PATH> [OPTIONS]...\n\n"

            "OPTIONS\n"
            "  -a, --arch <ARCH>        Define target architecture [default: linux]\n"
            "  -e, --edition <EDITION>  Define target architecture [default: standard]\n"
            "  -l, --lang <LANG>        Define target language [default: en-US]\n"
            "  -p, --path <PATH>        Define target path\n"
            "  -h, --help               Print help\n"
    );

    std::exit(status);
}

int cli::options_manager::parse_options() {

    int option_index;
    static constexpr const char *short_options = "a:e:l:p:h";

    static struct option long_options[] = {
            {"arch",    required_argument, nullptr, 'a'},
            {"edition", required_argument, nullptr, 'e'},
            {"lang",    required_argument, nullptr, 'l'},
            {"path",    required_argument, nullptr, 'p'},
            {"help",    no_argument,       nullptr, 'h'},
            {nullptr, 0,                   nullptr, 0},
    };

    while ((option_index = getopt_long(argc, argv, short_options, long_options, &option_index)) != -1) {
        switch (option_index) {
            case 'a': {
                options_map.insert_or_assign("arch", std::make_unique<cli::options::arch_option>(optarg));
                break;
            }
            case 'e': {
                options_map.insert_or_assign("edition", std::make_unique<cli::options::edition_option>(optarg));
                break;
            }
            case 'l': {
                options_map.insert_or_assign("lang", std::make_unique<cli::options::lang_option>(optarg));
                break;
            }
            case 'p': {
                options_map.insert_or_assign("path", std::make_unique<cli::options::path_option>(optarg));
                break;
            }
            case 'h': {
                print_help(EXIT_SUCCESS);
                break;
            }
            default: {
                print_help(EXIT_FAILURE);
            }
        }
    }

    return optind;
}
