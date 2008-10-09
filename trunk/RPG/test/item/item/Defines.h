//------------------------------------------------------------------------------
#pragma once
#include "string.h"
#include <iostream>
using namespace std;

// Master Types
#define TYPE_EQUIPABLE			0
#define TYPE_CONSUMEABLE		1
#define TYPE_QUEST				3
#define TYPE_TRASH				4
#define TYPE_ITEM				5
//------------------------------------------------------------------------------
// Subtypes
#define TYPE_ARMOR		5
#define TYPE_WEAPON		6
#define TYPE_POTION		7
//------------------------------------------------------------------------------
#define INVENTORY_SLOTS			30
//------------------------------------------------------------------------------
// Actor Types
#define TYPE_PLAYER		8
#define TYPE_NPC		9
#define TYPE_MINON		10
#define TYPE_BOSS		11
//------------------------------------------------------------------------------
// Actor Class
#define TYPE_WARRIOR    12
#define TYPE_MAGE		13
#define TYPE_ROUGE		14
#define TYPE_CLERIC		15
//------------------------------------------------------------------------------
//clases de personajes

struct Clase{
int iClase;
string sNomClass;
int iVida; 	
int iMana;
int iCa;
int iAtk; //Attack
};