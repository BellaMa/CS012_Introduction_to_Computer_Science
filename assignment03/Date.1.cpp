#include "Date.h"

#include <string>
#include <iostream>
using namespace std;

//Tests for leap year. 
bool Date::isLeap( unsigned int y) const 
{
    if((y % 4) == 0)
    {
        if((y % 100) == 0)
        {
            if((y % 400) == 0)
            {
                //2000 is a leap year
                return true;
            }
            else
            //2100 is not a leap year
            return false;
        }
        return true;
    }
    else 
    return false;
}
//Returns number of days allowed in a given month e.g. daysPerMonth(9, 2000) returns 30
unsigned Date::daysPerMonth( unsigned int m, unsigned int y ) const 
{
    if(isLeap(y))
    {   
        //for a leap year
        //bad month
        if(m == 0 || m > 12)
            m = 12;
            
        switch(m)
        {
            case 1:
            return 31;
            
            case 2:
            return 29;
            
            case 3:
            return 31;
            
            case 4:
            return 30;
            
            case 5:
            return 31;
            
            case 6:
            return 30;
            
            case 7:
            return 31;
            
            case 8:
            return 31;
            
            case 9:
            return 30;
            
            case 10:
            return 31;
            
            case 11:
            return 30;
            
            case 12:
            return 31;
        }
    }
    else
    {
        //bad month
        if(m == 0 || m > 12)
            m = 12;
            
        switch(m)
        {
            case 1:
            return 31;
            
            case 2:
            return 28;
            
            case 3:
            return 31;
            
            case 4:
            return 30;
            
            case 5:
            return 31;
            
            case 6:
            return 30;
            
            case 7:
            return 31;
            
            case 8:
            return 31;
            
            case 9:
            return 30;
            
            case 10:
            return 31;
            
            case 11:
            return 30;
            
            case 12:
            return 31;
        }
    
        return 0;
    }

    return 0;
}

//Returns the name of a given month
string Date::name( unsigned int m ) const
{
    switch(m)
    {
        case 1 :
            return  "January";
        case 2 :
            return  "February";
        case 3 : 
            return  "March";
        case 4 :
            return  "April";
        case 5 :
            return  "May";
        case 6 :
            return  "June";
        case 7 :
            return  "July";
        case 8 :
            return  "August";
        case 9 :
            return  "September";
        case 10 :
            return  "October";
        case 11 :
            return  "November";
        case 12 :
            return  "December";
        default:
            return "wrong month";
    }
}

//Returns the number of a given named month
unsigned Date::number( const string &mn ) const
{
    if((mn == "January") ||(mn == "january"))
        return 1;
    else
    {
        if((mn == "February") || (mn == "february"))
            return 2;
        else
        {
            if((mn == "March") || (mn == "march"))
                return 3;
            else
            {
                if((mn == "April") || (mn == "april"))
                    return 4;
                else
                {
                    if((mn == "May") || (mn == "may"))
                        return 5;
                    else
                    {
                        if((mn == "June") || (mn == "june"))
                            return 6;
                        else
                        {
                            if((mn == "July") || (mn == "july"))
                                return 7;
                            else
                            {
                                if((mn == "August") || (mn == "august"))
                                    return 8;
                                else
                                {
                                    if((mn == "September") || (mn == "september"))
                                        return 9;
                                    else
                                    {
                                        if((mn == "October") || (mn == "october"))
                                            return 10;
                                        else
                                        {
                                            if((mn == "November") || (mn == "november"))
                                                return 11;
                                            else 
                                            {
                                                if((mn == "December") || (mn == "december"))
                                                    return 12;
                                                else
                                                    return 0;
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}


//default constructor: creates the date January 1st, 2000.
Date::Date()
{
    day = 1;
    month = 1;
    monthName = "January";
    year = 2000;
}

//parameterized constructor: month number, day, year
// - e.g. (3, 1, 2010) would construct the date March 1st, 2010
Date::Date(unsigned int m, unsigned int d, unsigned int y)
{
    if(m == 0 || m >12)
        m = 12;
    
    if(daysPerMonth(m,y) >= d)
    {
        day = d;
        month = m;
        year = y;
        monthName = name(month);
    }
    else
    {
        day = d - daysPerMonth(m,y);
        
        month = m + 1;
        while(daysPerMonth(m,y) < day)
        {
            day = day - daysPerMonth(m,y);
            month += 1;
        }
        
        year = y;
        monthName = name(month);
    }
}

//parameterized constructor: month name, day, year 
// e.g. (December, 15, 2012) would construct the date December 15th, 2012
Date::Date( const string &mn, unsigned d, unsigned y ) 
{
    month = number(mn);
    if(month == 0)
    {
        cout << "Invalid month name: the Date was set to 1/1/2000" << endl;
        month = 1;
        day = 1;
        year = 2000;
        monthName = name(month);
    }
    else
    {
        if(daysPerMonth(month,y) >= d)
        {
            day = d;
            year = y;
            monthName = name(month);
        }
        else
        {
            day = d - daysPerMonth(month,y);
            
            month = month + 1;
            while(daysPerMonth(month,y) < day)
            {
                day = day - daysPerMonth(month,y);
                month += 1;
            }
            
            year = y;
            monthName = name(month);
        }
        
    }
    
}

//const accessor function to output a Date exactly in the format "3/1/2012"
void Date::printNumeric( )  const
{
    cout  << month << "/" << day << "/" << year  ;
}

//const accessor function to output a Date exactly in the format "March 1, 2012"
void Date::printAlpha( )  const
{
    cout  << monthName << " " << day << ", " << year ;
}


// Add a number of days to one date to get another: 
// this number may be positive or negative.
// Obviously, the new date will have to be a valid date, 
// accounting for the correct number of days in each month, 
// and for leap years.
Date Date::addDays( int more) const
{   
    Date newDate;
    int dayNew = day + more;
    newDate.day = dayNew;
    newDate.month = month;
    newDate.year = year;
    newDate.monthName = monthName;
    if(daysPerMonth(month,year) >= dayNew)
    {
        //after adding more days, the day is still not goes beyong that month max
        newDate.day = dayNew;
        newDate.month = month;
        newDate.year = year;
        newDate.monthName = monthName;
        return newDate;
    }
    else
    {
        //the added days goes beyond a month
        newDate.day = dayNew - daysPerMonth(month,year);
        newDate.month += 1;
        while(daysPerMonth(month,year) < newDate.day)
        {
            newDate.month += 1;
            if(newDate.month == 13)
            {
                newDate.year += 1;
            }
        }
        
        newDate.monthName = name(newDate.month);
        
        return newDate;
    }
    
    
}