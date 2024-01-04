#include "iostream"
#include "cli/options_manager.h"

int main(int argc, char *argv[]) {

    cli::options_manager options_manager(argc, argv);
    
    return EXIT_SUCCESS;
}