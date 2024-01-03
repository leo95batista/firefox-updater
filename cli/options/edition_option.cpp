#include "edition_option.h"

const std::array<std::string_view, 5> cli::options::edition_option::available_editions = {
        "beta", "devedition", "esr", "nightly", "standard"
};

bool cli::options::edition_option::is_valid() {
    return utils::array::in_array(get_option_value(), available_editions);
}

std::string cli::options::edition_option::as_product() const {

    if (get_option_value() == "standard") {
        return "firefox-latest-ssl";
    }

    return "firefox-" + get_option_value() + "-latest-ssl";
}
