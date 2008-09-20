#include <stdio.h>
#include <iostream>
#include <string>

//#include "item.h"
//#include "functions.h"
#include "include.h"

using namespace std;

void main()
{
	//Creo el el factory
	ItemFactory * myFactory    = ItemFactory::GetInstance();
	ItemFactory * myAuxFactory = myFactory -> GetInstance();
    ItemFactory & ref = * ItemFactory::GetInstance();


	myAuxFactory->CreateItem(5);



	system("PAUSE");
}
