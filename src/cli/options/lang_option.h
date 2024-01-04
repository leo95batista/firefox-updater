#ifndef FIREFOX_UPDATER_LANG_OPTION_H
#define FIREFOX_UPDATER_LANG_OPTION_H

#include "array"
#include "abstract_option.h"

namespace cli::options {
    class lang_option : public abstract_option<std::string> {
    public:
        explicit lang_option(const std::string &lang = "en-US") : abstract_option(lang) {
            validate_option_value();
        };

        [[nodiscard]] bool is_valid_option_value() const override;

        [[nodiscard]] std::string get_validation_error_message() const override;

    private:
        static const std::array<std::string_view, 2> available_languages;
    };
}

#endif //FIREFOX_UPDATER_LANG_OPTION_H
