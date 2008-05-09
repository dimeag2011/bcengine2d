//----------------------------------------------------------------
#ifndef TEXTURE_H
#define TEXTURE_H
//----------------------------------------------------------------
#include "Defines.h"
//----------------------------------------------------------------
class ENGINE_API Texture
{

// constructor / destructor
public:
	Texture (std::string kFilename);
	~Texture ();

// accessors
public:
	unsigned int getWidth ();
	unsigned int getHeight ();
	std::string getFilename ();
	void setWidth (unsigned int uiWidth);
	void setHeight (unsigned int uiHeight);

// properties
private:
	unsigned int m_uiWidth;
	unsigned int m_uiHeight;
	std::string m_kFilename;
};
//----------------------------------------------------------------
#include "Texture.inl"
//----------------------------------------------------------------
#endif //TEXTURE_H
//----------------------------------------------------------------