//----------------------------------------------------------------
#ifndef TEXTURE_H
#define TEXTURE_H
//----------------------------------------------------------------
#include "Defines.h"
#include "Structs.h"
//----------------------------------------------------------------
class ENGINE_API Texture
{

	DECLARE_SMART_POINTER(Texture);

// constructor / destructor
public:
	Texture (string kFilename, int iRed, int iGreen, int iBlue);
	~Texture ();

// accessors
public:
	unsigned int getWidth ();
	unsigned int getHeight ();
	string getFilename ();
	void setWidth (unsigned int uiWidth);
	void setHeight (unsigned int uiHeight);
	void getColorKey (int &iRed, int &iGreen, int &iBlue);

// properties
private:
	unsigned int m_uiWidth;
	unsigned int m_uiHeight;
	string m_kFilename;
	RGBColor m_kColorKey;
};
//----------------------------------------------------------------
#include "Texture.inl"
//----------------------------------------------------------------
#endif //TEXTURE_H
//----------------------------------------------------------------