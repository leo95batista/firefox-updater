#ifndef FIREFOX_UPDATER_ARRAY_H
#define FIREFOX_UPDATER_ARRAY_H

#include "algorithm"

namespace utils::array {
    template<typename T, typename U>
    bool in_array(const T &value, const U &container) {
        return std::find(std::begin(container), std::end(container), value) != std::end(container);
    }
}

#endif //FIREFOX_UPDATER_ARRAY_H
