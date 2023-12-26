#ifndef FIREFOX_UPDATER_ARCH_OPTION_H
#define FIREFOX_UPDATER_ARCH_OPTION_H

#include "array"
#include "algorithm"
#include "abstract_option.h"

namespace cli::options {
    class arch_option : public abstract_option<std::string> {
    public:
        explicit arch_option(const std::string &arch = "linux") : abstract_option(arch) {};

        bool is_valid() override;

    private:
        static const std::array<std::string_view, 2> available_architectures;
    };
}

#endif //FIREFOX_UPDATER_ARCH_OPTION_H
