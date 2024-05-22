#ifndef IC_H
#define IC_H

#include <typeinfo>
#include <format>
#include <exception>

template <typename T, int lim>
struct Counter {
    static int objects_created;
    static int objects_alive;

    Counter() {
        if (objects_alive < lim) {
            ++objects_created;
            ++objects_alive;
        } else {
            throw std::runtime_error(std::format("You reach the limit of {}!", typeid(T).name()));
        }
    }

    Counter(const Counter&) {
        if (objects_alive < lim) {
            ++objects_created;
            ++objects_alive;
        } else {
            throw std::runtime_error(std::format("You reach the limit of {}!", typeid(T).name()));
        }
    }

protected:
    ~Counter() {
        --objects_alive;
    }
};


template <typename T> struct Counter<T, 0>;

template<typename T, int lim> int Counter<T, lim>::objects_alive(0);
template<typename T, int lim> int Counter<T, lim>::objects_created(0);


#endif // IC_H
