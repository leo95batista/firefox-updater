#include "arch_option.h"

const std::array<std::string_view, 2> cli::options::arch_option::available_architectures = {
        "linux", "linux64"
};

bool cli::options::arch_option::is_valid_option_value() const {
    return utils::array::in_array(available_architectures, get_option_value());
}