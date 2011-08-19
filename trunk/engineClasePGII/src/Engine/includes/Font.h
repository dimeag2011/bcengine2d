//----------------------------------------------------------------
#ifndef FONT_H
#define FONT_H
//----------------------------------------------------------------
#include "Character.h"
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
	void setText(char * psz_Texto, ...);
	void setPos(float fPosX, float fPosY, float fPosZ = 1.0f);
	string getText();
	float getPosX();
	float getPosY();
	float getPosZ();

private:
	//Character* m_pkChars;
	vector<Character> m_pkChars;

	float m_fPosX;
	float m_fPosY;
	float m_fPosZ;

	string m_kText;
	int m_iLength;

	map<char,CharData> m_pcCharsData;
	typedef map<char,CharData>::iterator CharsDataIt;

	Texture::Ptr m_pkTexture;

	Renderer* m_pkRenderer;
	Scene* m_pkScene;
};
//----------------------------------------------------------------
#include "Font.inl"
//----------------------------------------------------------------
#endif //FONT_H
//----------------------------------------------------------------
