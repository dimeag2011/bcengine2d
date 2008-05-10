//----------------------------------------------------------------
#ifndef IMPORTER_H
#define IMPORTER_H
//----------------------------------------------------------------
#include "Defines.h"
#include "Sprite.h"
#include "XMLParser.h"
//----------------------------------------------------------------
class ENGINE_API Importer
{
public:
	friend class Game;

// destructor
public:
	~Importer ();

// constructor
private:
	Importer (Renderer* pkRenderer);

// entry point
public:
	bool importResources (const char* pszFilename);

// resources accessors
public:
	bool createSprite (const char* pszName, Sprite& rkSprite);
	Texture::Ptr getTexture (const char* pszFilename);

// loaders
private:
	bool importSprite (XMLNode& rkNode);
	bool importTexture (const char* pszFilename);
	bool importSpriteAnimation (XMLNode& rkNode);

// resources
private:
	Renderer* m_pkRenderer;

	map<string, Sprite*> m_kpSpritesMap;
	map<string, Texture::Ptr> m_kpTexturesMap;
	map<string, AnimationInfo::Ptr> m_kpSpriteAnimsMap;

	Sprite* m_pkCurrentSprite;
};
//----------------------------------------------------------------
#endif //IMPORTER_H
//----------------------------------------------------------------
