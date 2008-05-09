//----------------------------------------------------------------
#ifndef SPRITE_H
#define SPRITE_H
//----------------------------------------------------------------
#include "Defines.h"
#include "Entity2D.h"
#include "Structs.h"
//----------------------------------------------------------------
class Texture;
//----------------------------------------------------------------
class ENGINE_API Sprite : public Entity2D
{
// constructor / destructor
public:
	Sprite ();
	~Sprite () { /***/ }

// drawing (inherited from Entity2D)
public:
	void draw (Renderer* rkRenderer);

// texture handling
public:
	void setTexture (Texture* pkTexture);
	const Texture* getTexture ();

	void setTextureArea (unsigned int uiOffsetX, 
						unsigned int uiOffsetY, 
						unsigned int uiWidth, 
						unsigned int uiHeight); 

// topology
private:
	TextureVertex m_akVertices[4];

	Texture* m_pkTexture;
};
//----------------------------------------------------------------
#include "Sprite.inl"
//----------------------------------------------------------------
#endif //SPRITE_H
//----------------------------------------------------------------