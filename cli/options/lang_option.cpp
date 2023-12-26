#include "lang_option.h"

const std::array<std::string_view, 1> cli::options::lang_option::available_languages = {
        "en-US"
};

bool cli::options::lang_option::is_valid() {
    return std::find(std::begin(available_languages), std::end(available_languages), get_option_value());
}
