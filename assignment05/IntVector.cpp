//  =============== BEGIN ASSESSMENT HEADER ================
/// @file assn<#>/main.cpp 
/// @brief Assignment/Lab <#, e.g. 1,2,3..10> for CS 12 <quarter & year>
///
/// @author <CHaoyun Ma> [chaoyunma10@gmail.com]
/// @date <2.18.2015>
///
/// @par Enrollment Notes 
///     Lecture Section: <e.g. 001>
/// @par
///     Lab Section: <e.g. 022>
/// @par
///     TA: <TA name>
///
/// @par Plagiarism Section
/// I hereby certify that the code in this file
/// is ENTIRELY my own original work.
//  ================== END ASSESSMENT HEADER ===============

#include "IntVector.h"
#include <stdlib.h>
IntVector::IntVector()
{
    sz = 0;
    cap = 0;
    data = 0;
}

IntVector::IntVector(unsigned size)
{
    sz = size;
    cap = size;
    data = new int[size];
    for(unsigned i = 0; i < size; ++i)
    {
        *(data + i) = 0;
    }
}


IntVector::IntVector(unsigned size, int value)
{
    sz = size;
    cap = size;
    data = new int[size];
    for(unsigned i = 0; i < size; ++i)
    {
        *(data + i) = value;
    }
}

unsigned IntVector::size() const
{
    return sz;
}

unsigned IntVector::capacity() const
{
    return cap;
}

bool IntVector::empty() const
{
    if(sz == 0)
        return true;
    else
        return false;
}

const int & IntVector:: at(unsigned index) const
{   
    if(index >= sz)
        exit(1);
    
    return *(data + index);
}

const int & IntVector::front( ) const
{
    return *data;
}

const int & IntVector::back( ) const
{
    return *(data + sz - 1);
}

IntVector::~IntVector( )
{
    delete[] data;
}

void IntVector::expand()
{
    
    
    cap = cap * 2;
    int* tem = new int[cap];
    
    
    for(unsigned i = 0; i < sz; ++i)
    {
        *(tem + i) = *(data + i);
    }
    
    delete[] data;
    data = tem;
}

void IntVector::expand( unsigned amount )
{
    cap += amount;
    int* tem = new int[cap];
    
    
    for(unsigned i = 0; i < sz; ++i)
    {
        *(tem + i) = *(data + i);
    }
    
    delete[] data;
    data = tem;
}

void IntVector::insert( unsigned index, int value )
{
    if(index > sz)
    {
        exit(1);
    }
    if(cap == 0)//no array
    {
        expand(1);
        *data = value;
        
    }
    
    if(cap >= (sz + 1))//enough cap
    {
        
        for(unsigned i = sz - 1; i >= index; --i)
        {
            *(data + i + 1) = *(data + i);
        }
        *(data + index) = value;
    }
    
    if(cap == sz)//not enough cap
    {
        expand();
        for(unsigned i = sz - 1; i >= index; --i)
        {
            *(data + i + 1) = *(data + i);
        }
        *(data + index) = value;
    }
    
    sz += 1;
}

void  IntVector::erase(unsigned index)
{
    if(index >= sz)//out of range
        exit(1);
    
    for(unsigned i = index;i < sz; ++i)
        {
            *(data + i ) = *(data + i + 1);
        }
    
    sz -= 1;
}

void IntVector::push_back (int value)
{
    if(cap == 0)//no array
    {
        expand(1);
        *data = value;
    }
    
    if(sz < cap)
    {
        *(data + sz) = value;
    }
    
    if(sz == cap)
    {
        expand();
        *(data + sz) = value;
    }
    
    sz += 1;
}


void IntVector::pop_back()
{
    if(empty())
        exit(1);
    
    sz -= 1;
}

void IntVector::clear()
{
    sz = 0;
}

void IntVector::resize( unsigned size )
{
    if(size <= sz)
        sz = size;
    else if( size <= cap)
    {
        for(unsigned i = sz - 1; i < cap; ++i)
        {
            *(data + i) = 0;
        }
        
        sz = size;
    }
    else if((size - cap) <= (2 * cap))
    {
        expand();
        for(unsigned i = sz - 1; i < cap; ++i)
        {
            *(data + i) = 0;
        }
        
        sz = size;
    }
    else
    {
        expand((size - cap));
        for(unsigned i = sz - 1; i < cap; ++i)
        {
            *(data + i) = 0;
        }
        
        sz = size;
    }
        
}

void IntVector::resize(unsigned size, int value)
{
    if(size <= sz)
        sz = size;
        
    else if( size <= cap)
    {
        for(unsigned i = sz; i < cap; ++i)
        {
            *(data + i) = value;
        }
        
        sz = size;
    }
    else if((size - cap) <= (2 * cap))
    {
        expand();
        for(unsigned i = sz; i < cap; ++i)
        {
            *(data + i) = value;
        }
        
        sz = size;
    }
    else
    {
        expand((size - cap));
        for(unsigned i = sz; i < cap; ++i)
        {
            *(data + i) = value;
        }
        
        sz = size;
    }
}

void IntVector::reserve(unsigned n)
{
    if(cap == 0)
    {
        expand(n);
    }
    else if(n < (2 * cap))
        expand();
    else 
        expand((n-cap));
    
}

void IntVector::assign(unsigned n, int value)
{
    if(n <= cap)
    {
        sz = n;
        for(unsigned i = 0; i < sz; ++i)
            *(data + i) = value;
    }
    else if(n <= (2 * cap))
    {
        expand();
        sz = n;
        for(unsigned i = 0; i < sz; ++i)
            *(data + i) = value;
    }
    else
    {
        expand((n - cap));
        sz = n;
        for(unsigned i = 0; i < sz; ++i)
            *(data + i) = value;
    }
    
}

int & IntVector::at(unsigned index)
{
    if(index >= sz)
        exit(1);
    
    return *(data + index);
}

int & IntVector::front( )
{
    return *data;
}

int & IntVector::back( )
{
    return *(data + sz - 1);
}