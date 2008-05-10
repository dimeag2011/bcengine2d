//----------------------------------------------------------------
#ifndef SPRITE_H
#define SPRITE_H
//----------------------------------------------------------------
#include "Defines.h"
#include "Entity2D.h"
#include "Structs.h"
#include "Texture.h"
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
	void setTexture (Texture::Ptr pkTexture);
	const Texture::Ptr getTexture ();

	void setTextureArea (unsigned int uiOffsetX, 
						unsigned int uiOffsetY, 
						unsigned int uiWidth, 
						unsigned int uiHeight); 

// topology
private:
	TextureVertex m_akVertices[4];

	Texture::Ptr m_pkTexture;
};
//----------------------------------------------------------------
#include "Sprite.inl"
//----------------------------------------------------------------
#endif //SPRITE_H
//----------------------------------------------------------------