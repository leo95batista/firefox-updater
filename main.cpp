#include "iostream"
#include "cli/options_manager.h"

int main(int argc, char *argv[]) {

    cli::options_manager options_manager(argc, argv);

    std::cout << options_manager.get_arch();

    return EXIT_SUCCESS;
}