#include <string>
using namespace std;
class Date
{
    private:
        unsigned int day;
        unsigned int month;
        string monthName; 
        //this class is NOT designed to handle negative years, aka "BC"
        unsigned int year;
    
        //helpers
        bool isLeap( unsigned ) const;
        unsigned daysPerMonth( unsigned m, unsigned y ) const;
        string name( unsigned m ) const;
        unsigned number( const string &mn ) const;
        
    public:
        //default constructor: creates the date January 1st, 2000.
        Date();
        //default constructor: creates the date January 1st, 2000.
        Date( unsigned m, unsigned d, unsigned y );
        //parameterized constructor: month name, day, year .
        //e.g. (December, 15, 2012) would construct the date December 15th, 2012
        Date( const string &mn, unsigned d, unsigned y ); 
        //const accessor function to output a Date exactly in the format "3/1/2012". 
        //Do not output a newline (endl) at the end!
        void printNumeric( )  const;
        void printAlpha( )  const;
        
        Date addDays( int ) const;
};



