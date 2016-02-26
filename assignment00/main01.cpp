   // This program plays a guessing game where you try to guess the number 
   // the computer has picked.
    using namespace::std;
   #include <iostream>
   #include <cstdlib>
   #include <ctime>
   #include <stdio.h>
   #include <time.h>
   int main()
   {
     srand (time(NULL));
     int number_to_guess = rand()%100;
        //cout << number_to_guess << endl;

     cout << "Guess a number between 1 and 100.  type in your guess \n" ;

     
     int guess;
     cin >> guess;
    
     while ( number_to_guess != guess )
     {
        cout<<"type in 1000 to quit \n";
       if ( guess > number_to_guess )
       {
         cout << "\nTry lower." << endl ;
       }
       else if ( guess < number_to_guess )
       {
         cout << "\nTry Higher." << endl ;
       }
       
       cin >> guess;
       
       if (guess == 1000)
        {
            cout<< "you quit the program \n";
            return -1;
        }
     }
   
     cout << "You guessed right!!!" << endl;
     return 0;
   }


