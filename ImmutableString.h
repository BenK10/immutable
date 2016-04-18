#ifndef IMMUTABLESTRING_H_INCLUDED
#define IMMUTABLESTRING_H_INCLUDED

#include <ostream>
#include <string>
#include "nonassignable.h"

class ImmutableString : public nonassignable
{

private:
    std::string str;

public:

    typedef std::string::value_type value_type;
    typedef std::string::size_type size_type;
    typedef std::string::const_iterator const_iterator;
    typedef std::string::const_reverse_iterator const_reverse_iterator;


    ImmutableString() = default;
    ImmutableString(const std::string&);

    const value_type& at(size_type);
    const value_type& operator[](size_type);
    const value_type& front();
    const value_type& back();
    const value_type* c_str();

    const_iterator cbegin();
    const_iterator cend();
    const_reverse_iterator crbegin();
    const_reverse_iterator crend();

    bool empty() const;
    size_type size() const;
   // size_type length(); redundant
   size_type max_size() const; //std::string's version is constexpr but this is not because class has nontrivial dstr
   size_type capacity() const;
   void shrink_to_fit();
   int compare(const std::string&) const; //TODO rest of overloads
   std::string substr(size_type, size_type) const;
   size_type copy(value_type*, size_type, size_type) const;

   //TODO find operations

    friend std::ostream& operator<<(std::ostream&, ImmutableString);
};

#endif // IMMUTABLESTRING_H_INCLUDED
