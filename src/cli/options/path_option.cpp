#include "path_option.h"

bool cli::options::path_option::is_valid_option_value() const {
    return std::filesystem::is_directory(get_option_value());
}

std::string cli::options::path_option::get_validation_error_message() const {
    return "the given path doesn't exists or it's an invalid directory";
}
