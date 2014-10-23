//File Name:driver.cpp

//Programmer:Jon Holmberg
//Date:4/1/2013
//Purpose: 1. Instantiate class objects.
// 2. Enter values for class objects.
// 3. Feed array with iFile.
// 4. Display Array.
// 5. Enter value for decision to receive outcome.

#include <iostream>
#include "legendHeader.h"
using namespace std;
int main()
{
	Player P1;
	P1.displaySta();
	P1.readFromFile();
	//P1.display();(beta)
	P1.act1();
	P1.ending();



	system("pause");

	return 0;

}