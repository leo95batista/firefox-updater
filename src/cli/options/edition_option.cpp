#include "edition_option.h"

const std::array<std::string_view, 5> cli::options::edition_option::available_editions = {
        "beta", "devedition", "esr", "nightly", "standard"
};

bool cli::options::edition_option::is_valid_option_value() const {
    return utils::array::in_array(available_editions, get_option_value());
}

std::string cli::options::edition_option::get_validation_error_message() const {
    return "the given edition is invalid";
}
