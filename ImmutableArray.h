#ifndef IMMUTABLEARRAY_H_INCLUDED
#define IMMUTABLEARRAY_H_INCLUDED

#include <array>
#include "nonassignable.h"

//immutable Array. Wraps std::array

template<typename T, std::size_t sz>
class ImmutableArray : public nonassignable
{
    private:
        std::array<T, sz> arr;

    public:

            //same interface as Array but fill(), swap(), data() are forbidden
            //and accessors only return const reference to forbid modifying

            ImmutableArray<T, sz>() = default;
            ImmutableArray<T, sz>(std::initializer_list<T> l)
            {
               for(unsigned int i=0; i<sz; ++i)
                arr[i]= *(l.begin()+i);
            }

            //copy cstr to convert a std::array into ImmutableArray
            ImmutableArray<T, sz>(const std::array<T, sz>& stdarr)
            {
                for(int i=0; i<sz; ++i)
                    arr[i]=stdarr[i];
            }


            //accessors return a const reference to forbid modifying
            //-------------------------------------------------------------
            const T& at(int idx)
            {
                return arr.at(idx);
            }

            const T& operator[](int idx)
            {
                return arr[idx];
            }

            const T& front()
            {
                return arr.front();
            }

            const T& back()
            {
                return arr.back();
            }
            //-------------------------------------------------------------

            //only const_iterators provided
            //-------------------------------------------------------------
            typename std::array<T, sz>::const_iterator cbegin()
            {
                return arr.cbegin();
            }

            typename std::array<T, sz>::const_iterator cend()
            {
                return arr.cend();
            }

            typename std::array<T, sz>::const_reverse_iterator crbegin()
            {
                return arr.crbegin();
            }

            typename std::array<T, sz>::const_reverse_iterator crend()
            {
                return arr.crend();
            }
            //-------------------------------------------------------------

            bool empty() const
            {
                return arr.empty();
            }

            typename std::array<T, sz>::size_type size() const
            {
                return arr.size();
            }

            constexpr typename std::array<T, sz>::size_type max_size() const
            {
                return arr.max_size();
            }

};

#endif // IMMUTABLEARRAY_H_INCLUDED
