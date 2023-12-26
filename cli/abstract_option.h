#ifndef FIREFOX_UPDATER_ABSTRACT_OPTION_H
#define FIREFOX_UPDATER_ABSTRACT_OPTION_H

#include "iostream"

namespace cli {
    template<typename T>
    class abstract_option {
    public:
        explicit abstract_option(const T &value) : option_value(value) {}

        virtual bool is_valid() = 0;

        T get_option_value() const;

        ~abstract_option() = default;

    private:
        T option_value;

    };

    template<typename T>
    T abstract_option<T>::get_option_value() const {
        return option_value;
    }
}

#endif //FIREFOX_UPDATER_ABSTRACT_OPTION_H
