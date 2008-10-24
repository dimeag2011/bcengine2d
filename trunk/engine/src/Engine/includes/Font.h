//----------------------------------------------------------------
#ifndef FONT_H
#define FONT_H
//----------------------------------------------------------------
#include "Sprite.h"
#include "Defines.h"
#include "Structs.h"
#include "XMLParser.h"
#include "Renderer.h"
#include "Scene.h"
//----------------------------------------------------------------
class ENGINE_API Font
{
public:
	Font(Renderer* pkRenderer, Scene* pkScene);
	~Font();
	bool loadFont(string kFontFile);
	void setText(string kText);
	void setPos(float fPosX, float fPosY, float fPosZ = 1.0f);
	string getText();
	float getPosX();
	float getPosY();
	float getPosZ();

private:
	struct CharData
	{
		float fX;
		float fY;
		float fHeight;
		float fWidth;
		float fXAdvance;
	};
	Sprite* m_pkChars;
	float m_fPosX;
	float m_fPosY;
	float m_fPosZ;
	string m_kText;
	Renderer* m_pkRenderer;
	Scene* m_pkScene;
	Texture::Ptr m_pkTexture;
	map<char,CharData> m_pcCharsData;
	typedef map<char,CharData>::iterator CharsDataIt;
	int m_iLength;
};
//----------------------------------------------------------------
#include "Font.inl"
//----------------------------------------------------------------
#endif //FONT_H
//----------------------------------------------------------------
