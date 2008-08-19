#include <stdio.h>
#include <iostream>
#include <string>

#include "component.h"

using namespace std;

void printComponent(Component* pkComponent);

void main()
{
	Component* pkMochila = new Component();
	pkMochila->setName("Mochila");
	pkMochila->setType("container");

	Component* pkPot = new Component();
	pkPot->setName("Pot");
	pkPot->setType("consumible");

	Component* pkPot2 = new Component("Pot2", "consumible2");

	pkMochila->addNewChild(pkPot);
	pkMochila->addNewChild(pkPot2);


	//pkPot->setNewParent(pkPot2);
	//pkMochila->addNewChild(pkPot);
	//pkPot->addNewChild(pkPot2);
	//pkMochila->removeChild(pkPot);
	//pkPot2->removeParent();

	printComponent(pkMochila);

	system("PAUSE");
}

void printComponent(Component* pkComponent)
{
	cout << "Nombre: " << pkComponent->getName() << endl;
	cout << "Type: " << pkComponent->getType() << endl;
	cout << "Padre: ";
	if (pkComponent->getParent())
	{
		cout << pkComponent->getParent()->getName();
	}
	else
	{
		cout << "-";
	}
	cout << endl << "----------------------------------------------------" << endl;
	int iSize = pkComponent->getNumChilds();
	pkComponent->goFirstChild();
	for(int i = 0; i < iSize; i++)
	{
		printComponent(pkComponent->getCurrentChild());
		pkComponent->goNextChild();
	}
}