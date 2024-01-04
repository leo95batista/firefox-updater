#ifndef FIREFOX_UPDATER_ARRAY_H
#define FIREFOX_UPDATER_ARRAY_H

#include "algorithm"

namespace utils::array {
    template<typename U, typename T>
    bool in_array(const U &container, const T &value) {
        return std::find(std::begin(container), std::end(container), value) != std::end(container);
    }
}

#endif //FIREFOX_UPDATER_ARRAY_H
