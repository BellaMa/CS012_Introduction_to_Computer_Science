#include "User.h"
#include "Message.h"
#include "BBoard.h"
#include <string>
#include <iostream>
#include <vector>
#include <fstream>
#include <stdio.h>
using namespace std;

int main(int argc,char* argv[])
{
	if(argc != 2)
	{
		cout << "Improper usage!" << endl;
		cout << "usage : ./a.out users1.txt" << endl;
	}
	
	string userlist = argv[1];
	
	BBoard bboard;
	bboard.setup(userlist);
	bboard.login();
	bboard.run();
	return 0;
}