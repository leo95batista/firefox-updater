#ifndef FIREFOX_UPDATER_PATH_OPTION_H
#define FIREFOX_UPDATER_PATH_OPTION_H

#include "filesystem"
#include "abstract_option.h"

namespace cli::options {
    class path_option : public cli::abstract_option<std::filesystem::path> {
    public:
        explicit path_option(const std::filesystem::path &path) : abstract_option(path) {
            validate_option_value();
        };

        [[nodiscard]] bool is_valid_option_value() const override;

        [[nodiscard]] std::string get_validation_error_message() const override;
    };
}

#endif //FIREFOX_UPDATER_PATH_OPTION_H
