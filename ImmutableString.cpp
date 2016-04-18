#include "ImmutableString.h"


    ImmutableString::ImmutableString(const std::string& s) : str(s)
    {}

//accessors
//----------------------------------------------------------------------------------------
    const ImmutableString::value_type& ImmutableString::at(ImmutableString::size_type idx)
    {
        return str.at(idx);
    }

    const ImmutableString::value_type& ImmutableString::operator[](ImmutableString::size_type idx)
    {
        return str[idx];
    }

    const ImmutableString::value_type& ImmutableString::front()
    {
        return str.front();
    }

    const ImmutableString::value_type& ImmutableString::back()
    {
        return str.back();
    }

    const ImmutableString::value_type* ImmutableString::c_str()
    {
        return str.c_str();
    }

//accessors - iterators

    ImmutableString::const_iterator ImmutableString::cbegin()
    {
        return str.cbegin();
    }

    ImmutableString::const_iterator ImmutableString::cend()
    {
        return str.cend();
    }

    ImmutableString::const_reverse_iterator ImmutableString::crbegin()
    {
        return str.crbegin();
    }

    ImmutableString::const_reverse_iterator ImmutableString::crend()
    {
        return str.crend();
    }


    //info
//----------------------------------------------------------
    bool ImmutableString::empty() const
    {
        return str.empty();
    }

    ImmutableString::size_type ImmutableString::size() const
    {
        return str.size();
    }

    ImmutableString::size_type ImmutableString::max_size() const
    {
        return str.max_size();
    }

    ImmutableString::size_type ImmutableString::capacity() const
    {
        return str.capacity();
    }
//----------------------------------------------------------------------
    void ImmutableString::shrink_to_fit()
    {
        str.shrink_to_fit();
    }

//TODO: compare, substr, copy

//-------------------------------------------------------------------

    std::ostream& operator<<(std::ostream& os, ImmutableString im)
    {
        os << im.str;
    }


