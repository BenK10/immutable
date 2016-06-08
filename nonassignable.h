#ifndef IMMUTABLE_H_INCLUDED
#define IMMUTABLE_H_INCLUDED

//based on Boost::immutable
//requires C++11

//inherit publicly from this and omit operator= in derived class to make it non-assignable
class nonassignable
{
    protected:
    nonassignable& operator=(const nonassignable&) = delete;
};

#endif // IMMUTABLE_H_INCLUDED
