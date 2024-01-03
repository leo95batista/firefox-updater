#ifndef FIREFOX_UPDATER_EDITION_OPTION_H
#define FIREFOX_UPDATER_EDITION_OPTION_H

#include "array"
#include "abstract_option.h"

namespace cli::options {
    class edition_option : public cli::abstract_option<std::string> {
    public:
        explicit edition_option(const std::string &edition = "standard") : abstract_option(edition) {}

    private:
        static const std::array<std::string_view, 5> available_editions;
    };
}

#endif //FIREFOX_UPDATER_EDITION_OPTION_H
