#include "edition_option.h"

bool cli::options::edition_option::is_valid() {
    return std::find(std::begin(available_editions), std::end(available_editions), get_option_value());
}

const std::array<std::string_view, 5> cli::options::edition_option::available_editions = {
        "beta", "devedition", "esr", "nightly", "standard"
};
