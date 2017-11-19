#ifndef IMMUTABLEINT_H_INCLUDED
#define IMMUTABLEINT_H_INCLUDED

#include <ostream>
#include <type_traits>
#include "nonassignable.h"

template<typename T>
class ImmutableNumeric : public nonassignable
{

    static_assert(std::is_integral<T>::value, "Class must be of numeric type");

private:
    T val;

    public:
    ImmutableNumeric<T>() = default;
    ImmutableNumeric<T>(T num) : val(num)
    {}

    //getter
    T value()
    {
        return val;
    }

    //overload operators to do arithmetic on ImmutableNumerics directly
    //otherwise just use ImmutableNumeric.value in any context that supports the ImmutableNumeric's template type
  //  friend T operator+ <>(T, ImmutableNumeric);

    friend std::ostream& operator<<(std::ostream&, ImmutableNumeric<T>); //not templatized
};

    template <typename T>
    std::ostream& operator<<(std::ostream& os, ImmutableNumeric<T> im)
    {
        os << im.val;
    };

#endif // IMMUTABLEINT_H_INCLUDED
