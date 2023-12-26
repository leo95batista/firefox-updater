#include "options_manager.h"
#include "options/arch_option.h"
#include "options/lang_option.h"

std::string cli::options_manager::get_arch() const {
    // TODO
}

std::string cli::options_manager::get_lang() const {
    // TODO
}

std::filesystem::path cli::options_manager::get_path() const {
    // TODO
}

void cli::options_manager::initialize_default_options() {
    options_map.emplace("arch", std::make_unique<cli::options::arch_option>());
    options_map.emplace("lang", std::make_unique<cli::options::lang_option>());
}

int cli::options_manager::parse_options() {

    int option_index;
    static constexpr const char *short_options = "a:l:p:hv";

    static struct option long_options[] = {
            {"arch",    required_argument, nullptr, 'a'},
            {"lang",    required_argument, nullptr, 'l'},
            {"path",    required_argument, nullptr, 'p'},
            {"help",    no_argument,       nullptr, 'h'},
            {"version", no_argument,       nullptr, 'v'},
            {nullptr, 0,                   nullptr, 0},
    };

    initialize_default_options();

    while ((option_index = getopt_long(argc, argv, short_options, long_options, &option_index)) != -1) {
        switch (option_index) {
            case 'a': {
                options_map.emplace("arch", std::make_unique<cli::options::arch_option>(optarg));
                break;
            }
            case 'l': {
                options_map.emplace("lang", std::make_unique<cli::options::lang_option>(optarg));
                break;
            }
            case 'p': {
                printf("p: %s\n", optarg);
                break;
            }
            case 'h': {
                print_help(EXIT_SUCCESS);
                break;
            }
            case 'v': {
                print_version();
                break;
            }
            default: {
                fprintf(stderr, "\n");
                print_help(EXIT_FAILURE);
            }
        }
    }

    return optind;
}

void cli::options_manager::print_help(int status) {
    /**
     * Determine the stream from the given status code.
     */
    FILE *stream = (status == EXIT_SUCCESS) ? stdout : stderr;

    fprintf(stream,
            "USAGE: firefox-updater --path <PATH> [OPTIONS]...\n\n"

            "OPTIONS\n"
            "  -a, --arch <ARCH>    Define target architecture [default: linux]\n"
            "  -l, --lang <LANG>    Define target language [default: en-US]\n"
            "  -p, --path <PATH>    Define target path\n"
            "  -h, --help           Print help\n"
            "  -v, --version        Print version\n"
    );

    std::exit(status);
}

void cli::options_manager::print_version() {
    printf("%s\n", "1.0.0");
    std::exit(EXIT_SUCCESS);
}