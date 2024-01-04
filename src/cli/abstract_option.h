#ifndef FIREFOX_UPDATER_ABSTRACT_OPTION_H
#define FIREFOX_UPDATER_ABSTRACT_OPTION_H

#include "iostream"
#include "utils/array.h"

namespace cli {
    template<class T>
    class abstract_option {
    public:
        explicit abstract_option(const T &option_value) : option_value(option_value) {}

        [[nodiscard]] T get_option_value() const;

        [[nodiscard]] virtual bool is_valid_option_value() const = 0;

        [[nodiscard]] virtual std::string get_validation_error_message() const = 0;

        ~abstract_option() = default;

    private:
        T option_value;

    protected:
        virtual void validate_option_value() final;
    };

    template<class T>
    T abstract_option<T>::get_option_value() const {
        return option_value;
    }

    template<class T>
    void abstract_option<T>::validate_option_value() {
        if (!is_valid_option_value()) {
            std::cerr << "ERROR: " << get_validation_error_message() << std::endl;
            std::exit(EXIT_FAILURE);
        }
    }
}

#endif //FIREFOX_UPDATER_ABSTRACT_OPTION_H
