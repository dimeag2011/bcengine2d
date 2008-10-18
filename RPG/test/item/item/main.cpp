#include <stdio.h>
#include <iostream>
#include <string>
#include <conio.h>

//#include "item.h"
//#include "functions.h"
#include "include.h"

using namespace std;
void CharacterCreations();
void main()
{
	//Creo el factory
	//ItemFactory * myFactory    = ItemFactory::GetInstance();
	//ItemFactory * myAuxFactory = myFactory -> GetInstance();
    //ItemFactory & ref = * ItemFactory::GetInstance();

//	Item * myItem = new Item();
//	myItem->setName("mami");

	//myAuxFactory->CreateItem(TYPE_ARMOR);

	/*Slot * myBlackSlot = new Slot();
	myBlackSlot->setName("Slotito");
	myBlackSlot->addNewChild(myItem);*/

	//cout << myBlackSlot->m_kName << "  " <<  << endl;
/*
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

*/

/*	myAuxFactory->GetCreations();
	cout << myItem->getName() <<endl;
	system("PAUSE");
*/
	CharacterCreations();
	//myAuxFactory->RelaseInstance();
}
void CharacterCreations(){

	//Base del actor
	string Nombre = "";
	int Tipo = 8;
	int Arqueotipo = 13;
	//Atributos Base
	int ResAcid = 0;
	int ResFire = 0;
	int ResFrozen = 0;
	int ResSonic  = 0;
	int ResElectric = 0;
	int Strenght = 0;
	int Dextery = 0;
	int Constitution = 0;
	int Intelligence = 0;
	int Wisdom = 0 ;
	int Charm = 0;
	
	ActorFactory * myActor    = ActorFactory::GetInstance();
	ActorFactory * myAuxActorFactory = myActor-> GetInstance();
	//ActorFactory & refA = * ActorFactory::GetInstance();
	
	Item * myItem = new Item();
	myItem->setName("Item loco 1");
	myItem->setAttributes(2,2,2,2,2,10,10,10,10,10,10, true);

	Item * myItem2 = new Item();
	myItem2->setName("Posion loca");
	myItem2->setAttributes(1,1,1,1,1,0,0,0,0,0,0, true);

	Item * myItem3 = new Item();
	myItem3->setName("Cosa rara");
	myItem3->setAttributes(3,3,3,3,3,30,30,30,30,30,30, false);
	
	Actor* pj = new Actor();

	int opt = 0;
	while(opt != 5){
//	clrscr();
	system("CLS");
	cout << "Ingrese opcion:" <<endl;
	cout << "1.Crear personaje." <<endl;
	cout << "2.Setear Stats del personaje." <<endl;
	cout << "3.Ver Stats" <<endl;
	cout << "4.Sacar efecto del item." <<endl;
	cout << "5.Salir." <<endl;


	cin >> opt;

	

		switch (opt)
		{
		case 1:

				//clrscr();
				system("CLS");
				cout << "Creacion de personajes" << endl;
				cout << "----------------------" << endl;

				cout <<" Ingrese nombre: ";
				cin >> Nombre;
				cout << endl << "Ingrese Tipo de pj: 8.Player, 9.NPC, 10.Miñon, 11.Boss"<<endl;
				cin >> Tipo;
				cout << "Ingrese Clase de pj: 12.Guerrero, 13.Mago, 14 Ladron , Clerigo"<<endl;
				cin >> Arqueotipo;
				pj = myAuxActorFactory->CreateActor(Nombre, Tipo, Arqueotipo);
//Ver aca			
				pj->putItemInventory(myItem);
				pj->putItemInventory(myItem2);
				pj->putItemInventory(myItem3);


				break;
		case 2:
		
				//clrscr();
				system("CLS");
				cout << "Seteo de atributos base :"<<endl;
				cout << "Seteo de Resistencia al acido :"<<endl;
				cin >> ResAcid;
				cout << "Seteo de Resistencia al fuego :"<<endl;
				cin >> ResFire;
				cout << "Seteo de Resistencia al Los Cubitos :"<<endl;
				cin >> ResFrozen;
				cout << "Seteo de Resistencia al Sonic Beam :"<<endl;
				cin >> ResSonic;
				cout << "Seteo de Resistencia a la electricidad :"<<endl;
				cin >> ResElectric;
				cout << "Seteo de fuerza :"<<endl;
				cin >> Strenght;
				cout << "Seteo de destreza :"<<endl;
				cin >> Dextery;
				cout << "Seteo de Costitucion :"<<endl;
				cin >> Constitution;
				cout << "Seteo de Inteligencia :"<<endl;
				cin >> Intelligence;
				cout << "Seteo de Sabiduria :"<<endl;
				cin >> Wisdom;
				cout << "Seteo de Carisma :"<<endl;
				cin >> Charm;

				//pj->setAttributes( TO-DO: factory por pj)
				
				pj->setAttributes(ResAcid,ResFire,ResFrozen,ResSonic,ResElectric,Strenght,Dextery,Constitution,Intelligence,Wisdom,Charm);
				pj->useItem(myItem->GetItemType());
			break;
		
		case 3:
			//clrscr();	
			system("CLS");
			cout << " Atributos de tu PJ: " << endl;
			cout << " ------------------- " << endl;

			cout << " Fuerza: " << pj->m_kAuxActAtt.getStr() << endl;
			cout << " Destreza: " << pj->m_kAuxActAtt.getDex() << endl;
			cout << " Constitucion: " << pj->m_kAuxActAtt.getCon() << endl;
			cout << " Inteligencia: " << pj->m_kAuxActAtt.getInt() << endl;
			cout << " Sabiduria: " << pj->m_kAuxActAtt.getWis() << endl;
			cout << " Carisma: " << pj->m_kAuxActAtt.getCha() << endl;
			cout << " Resis.al acido: " << pj->m_kAuxActAtt.getResAcd() << endl;
			cout << " Resis.al fuego: " << pj->m_kAuxActAtt.getResFir() << endl;
			cout << " Resis.al frio: " << pj->m_kAuxActAtt.getResFro() << endl;
			cout << " Resis.al sonico: " << pj->m_kAuxActAtt.getResSon() << endl;
			cout << " Resis.al electricidad: " << pj->m_kAuxActAtt.getResElec() << endl;
			cout << " Salvacion de Fortaleza: " << pj->m_kAuxActAtt.getSref() << endl;
			cout << " Salvacion de Reflejos: " << pj->m_kAuxActAtt.getSstr() << endl;
			cout << " Salvacion de Voluntad: " << pj->m_kAuxActAtt.getSwill() << endl;
			system("PAUSE");

			break;
		case 4:

			string	rmItem;
			int OPC;
			cout << " Seleccione el item que desea remover"<<endl;
			cout << "1.Item loco 1 "<<endl;
			cout << "2.Posion loca "<<endl;
			cout << "3.Cosa rara "<<endl;

			cin >> OPC;

			if(OPC == 1)
			{
				rmItem = myItem->getName() ;
			}else if(OPC == 2){
				
				rmItem = myItem2->getName() ;

			}else {

				rmItem = myItem3->getName() ;

			}
			pj->removeEffect(rmItem);		

};


	}
	delete pj;
	pj = NULL;
}