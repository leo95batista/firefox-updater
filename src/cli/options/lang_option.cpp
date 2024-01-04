#include "lang_option.h"

const std::array<std::string_view, 2> cli::options::lang_option::available_languages = {
        "en-US", "es-ES"
};

bool cli::options::lang_option::is_valid_option_value() const {
    return utils::array::in_array(available_languages, get_option_value());
}

std::string cli::options::lang_option::get_validation_error_message() const {
    return "the given language is invalid";
}
