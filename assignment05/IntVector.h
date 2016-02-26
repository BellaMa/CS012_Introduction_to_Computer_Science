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

#ifndef __INTVECTOR_H__
#define __INTVECTOR_H__


class IntVector
{
    private:
        unsigned sz;
        unsigned cap;
        int *data;
    public:
        IntVector();//done
        IntVector( unsigned size );//done
        IntVector( unsigned size, int value );//done
        unsigned size( ) const;//done
        unsigned capacity( ) const;//done
        bool empty( ) const;//done
        const int & at( unsigned index ) const;//done
        
        ~IntVector();//done
        int & at( unsigned index );//done
        void insert( unsigned index, int value );//done
        void erase( unsigned index );//done
        const int & front( ) const;//done
        int & front( );//done
        const int & back( ) const;//done
        int & back( );//done
        void assign( unsigned n, int value );//done
        void push_back( int value );//done
        void pop_back( );//done
        void clear( );//done
        void resize( unsigned size );//done
        void resize( unsigned size, int value );//done
        void reserve( unsigned n );//done

    private:
        void expand();//done
        void expand( unsigned amount );//done

};

#endif