#include "path_option.h"

bool cli::options::path_option::is_valid() {
    return std::filesystem::is_directory(get_option_value());
}
