#include "arch_option.h"

const std::array<std::string_view, 2> cli::options::arch_option::available_architectures = {
        "linux", "linux64"
};

bool cli::options::arch_option::is_valid() {
    return std::find(std::begin(available_architectures), std::end(available_architectures), get_option_value());
}
