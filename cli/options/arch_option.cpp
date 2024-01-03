#include "arch_option.h"

const std::array<std::string_view, 2> cli::options::arch_option::available_architectures = {
        "linux", "linux64"
};

bool cli::options::arch_option::is_valid() {
    return utils::array::in_array(get_option_value(), available_architectures);
}
