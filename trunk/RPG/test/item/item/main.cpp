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

	Item * myItem = new Item();
	myItem->setName("mami");

	myAuxFactory->CreateItem(5);

	Slot * myBlackSlot = new Slot();
	myBlackSlot->setName("Slotito");
	myBlackSlot->addNewChild(myItem);

	//cout << myBlackSlot->m_kName << "  " <<  << endl;

	if (myItem->getParent())
	{
		cout << "Parent is: " << myItem->getParent()->getName();
		
	}
	else
	{
		cout << "-";
	}
	cout << endl << "----------------------------------------------------" << endl;
	
	//cout >>  >> endl;



	myAuxFactory->GetCreations();
	
	system("PAUSE");

	myAuxFactory->RelaseInstance();
}
