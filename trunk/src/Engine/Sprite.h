//----------------------------------------------------------------
#ifndef SPRITE_H
#define SPRITE_H
//----------------------------------------------------------------
#include "Defines.h"
#include "Entity2D.h"
#include "Structs.h"
#include "Texture.h"
#include "Animation.h"
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

// clones a sprite
public:
	void clone (Sprite& rkSprite);

// texture handling
public:
	void setTexture (Texture::Ptr pkTexture);
	const Texture::Ptr getTexture ();

	void setTextureArea (unsigned int uiOffsetX, 
						unsigned int uiOffsetY, 
						unsigned int uiWidth, 
						unsigned int uiHeight); 

// animation
private:	
	std::map<std::string, AnimationInfo::Ptr> m_kAnimationMap;
	
// topology
private:
	TextureVertex m_akVertices[4];
	Texture::Ptr m_pkTexture;
	Animation* m_pkCurrentAnim;

// animation
public:
	bool addAnimationInfo (std::string kName, AnimationInfo::Ptr pkInfo);
	bool removeAnimationInfo (std::string kName);

	bool setAnimation (std::string kName);
	AnimationInfo::Ptr getAnimationInfo (std::string kName);
	Animation* getAnimation () const;

};
//----------------------------------------------------------------
#include "Sprite.inl"
//----------------------------------------------------------------
#endif //SPRITE_H
//----------------------------------------------------------------