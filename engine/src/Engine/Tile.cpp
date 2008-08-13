//----------------------------------------------------------------
#include "includes\Tile.h"
//----------------------------------------------------------------
Tile::Tile():
m_iId(0),
m_kCode1(""),
m_kCode2("")
{

}
//----------------------------------------------------------------
Tile::~Tile()
{

}
//----------------------------------------------------------------
void Tile::clone(Tile* pkTile)
{
	if(pkTile == this)
		return;

	Sprite::clone(pkTile);

	pkTile->setId(getId());
	pkTile->setDim(getDimW(), getDimH());
	pkTile->setHFlip(getHFlip());
	pkTile->setVFlip(getVFlip());
	
	//TO DO: clonar codes y colisiones
}
//----------------------------------------------------------------
