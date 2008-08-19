#include "functions.h"

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