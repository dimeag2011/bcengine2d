//----------------------------------------------------------------
#ifndef CHARACTER_H
#define CHARACTER_H
//----------------------------------------------------------------
#include "Sprite.h"
#include "Structs.h"
//----------------------------------------------------------------
class ENGINE_API Character : public Sprite
{
public:
	Character();
	~Character();

	void setCharData(CharData kData);
	CharData getCharData();

private:
	CharData m_kData;

};
//----------------------------------------------------------------
#include "Character.inl"
//----------------------------------------------------------------
#endif //CHARACTER_H
//----------------------------------------------------------------
