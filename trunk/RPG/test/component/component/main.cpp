#include <stdio.h>
#include <iostream>
#include <string>

#include "component.h"

using namespace std;

void main()
{
	Component* pkMochila = new Component();
	pkMochila->setName("Mochila");
	pkMochila->setType("container");
	cout << "Nombre: " << pkMochila->getName() << " - Type: " << pkMochila->getType() << endl;
	Component* pkPot = new Component();
	pkPot->setName("Pot");
	pkPot->setType("consumible");
	Component* pkPot2 = new Component("Pot2", "consumible2");
	pkMochila->addNewChild(pkPot);
	pkMochila->addNewChild(pkPot2);
	Component* pkAux = pkMochila->getCurrentChild();
	pkMochila->goFirstChild();
	pkAux = pkMochila->getCurrentChild();
	cout << "Nombre: " << pkAux->getName() << " - Type: " << pkAux->getType() << " - Parent Name: "  << pkAux->getParent()->getName() << endl;
	pkMochila->goNextChild();
	pkAux = pkMochila->getCurrentChild();
	pkPot->setNewParent(pkPot2);
	pkMochila->removeChild(pkPot);
	pkPot2->removeParent();
	cout << "Nombre: " << pkAux->getName() << " - Type: " << pkAux->getType() << " - Parent Name: "  << pkAux->getParent()->getName() << endl;
	system("PAUSE");
}

void printChilds(Component* pkRoot)
{

}