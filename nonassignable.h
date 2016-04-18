#ifndef IMMUTABLE_H_INCLUDED
#define IMMUTABLE_H_INCLUDED

//inherit publicly from this and omit operator= in derived class it non-assignable
class nonassignable
{
    protected:
    nonassignable& operator=(const nonassignable&) = delete;
};

#endif // IMMUTABLE_H_INCLUDED
