#ifndef FIREFOX_UPDATER_ARCH_OPTION_H
#define FIREFOX_UPDATER_ARCH_OPTION_H

#include "array"
#include "abstract_option.h"

namespace cli::options {
    class arch_option : public abstract_option<std::string> {
    public:
        explicit arch_option(const std::string &arch = "linux") : abstract_option(arch) {
            validate_option_value();
        };

        [[nodiscard]] bool is_valid_option_value() const override;

        [[nodiscard]] std::string get_validation_error_message() const override;

    private:
        static const std::array<std::string_view, 2> available_architectures;
    };
}

#endif //FIREFOX_UPDATER_ARCH_OPTION_H
