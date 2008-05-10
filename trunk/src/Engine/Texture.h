//----------------------------------------------------------------
#ifndef TEXTURE_H
#define TEXTURE_H
//----------------------------------------------------------------
#include "Defines.h"
//----------------------------------------------------------------
class ENGINE_API Texture
{

	DECLARE_SMART_POINTER(Texture);

// constructor / destructor
public:
	Texture (string kFilename);
	~Texture ();

// accessors
public:
	unsigned int getWidth ();
	unsigned int getHeight ();
	string getFilename ();
	void setWidth (unsigned int uiWidth);
	void setHeight (unsigned int uiHeight);

// properties
private:
	unsigned int m_uiWidth;
	unsigned int m_uiHeight;
	string m_kFilename;
};
//----------------------------------------------------------------
#include "Texture.inl"
//----------------------------------------------------------------
#endif //TEXTURE_H
//----------------------------------------------------------------