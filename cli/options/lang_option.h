#ifndef FIREFOX_UPDATER_LANG_OPTION_H
#define FIREFOX_UPDATER_LANG_OPTION_H

#include "array"
#include "algorithm"
#include "abstract_option.h"

namespace cli::options {
    class lang_option : public abstract_option<std::string> {
    public:
        explicit lang_option(const std::string &lang = "en-US") : abstract_option(lang) {};

        bool is_valid() override;

    private:
        static const std::array<std::string_view, 1> available_languages;
    };
}

#endif //FIREFOX_UPDATER_LANG_OPTION_H
