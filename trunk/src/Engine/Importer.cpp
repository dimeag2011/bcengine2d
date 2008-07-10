#include "Importer.h"
#include "Renderer.h"
#include "Sprite.h"
//----------------------------------------------------------------
Importer::Importer (Renderer* pkRenderer)
:
m_pkRenderer(pkRenderer)
{
	/***/
}
//----------------------------------------------------------------
Importer::~Importer ()
{
/*
	for(vector<Sprite*>::iterator it = m_kpSpritesVector.begin(); it != m_kpSpritesVector.end(); it++)
	{
		Sprite *p = *it;
		delete p;
		p = NULL;
	}
	m_kpSpritesVector.clear();
*/
	// delete all the prototype sprites
	for( map<string, Sprite*>::iterator it = m_kpSpritesMap.begin(), e = m_kpSpritesMap.end(); it != e; )
	{
		Sprite* pkSprite = it->second;
		
		m_kpSpritesMap.erase(it++);
		
		delete pkSprite;
		pkSprite = NULL;
	}
}
//----------------------------------------------------------------
bool Importer::importResources (const char* pszFilename)
{
	XMLNode kMainNode = XMLNode::openFileHelper(pszFilename,"PMML");

	// load sprites
	int iSpriteCount = kMainNode.nChildNode("SPRITE");	

	int iIterator = 0;
	for(int i=0; i<iSpriteCount; i++)
	{
		XMLNode& rkSprite = kMainNode.getChildNode("SPRITE",&iIterator);
		importSprite(rkSprite);
	}

	return true;
}
//----------------------------------------------------------------------
bool Importer::importSprite (XMLNode& rkNode)
{
	// load attributes
	const char* pszName = rkNode.getAttribute("Name");

	// find the sprite

	Sprite* pkSprite = m_kpSpritesMap[pszName];
	
	// if it was found, return
	if(pkSprite)
		return true;

	// create the new sprite
	pkSprite = new Sprite();
	m_pkCurrentSprite = pkSprite;

	// add to map
	m_kpSpritesMap[pszName] = pkSprite;

	// load sprite attributes
	const char* pszTexXMLFile = rkNode.getAttribute("TextureFile");
	const char* pszTexPosX = rkNode.getAttribute("TexPosX");
	const char* pszTexPosY = rkNode.getAttribute("TexPosY");
	const char* pszWidth = rkNode.getAttribute("Width");
	const char* pszHeight = rkNode.getAttribute("Height");

	// convert sprite attibutes
	unsigned int uiTexPosX = atoi(pszTexPosX);
	unsigned int uiTexPosY = atoi(pszTexPosY);
	unsigned int uiWidth = atoi(pszWidth);
	unsigned int uiHeight = atoi(pszHeight);

	// set attributes to sprite
	XMLNode kMainNode = XMLNode::openFileHelper(pszTexXMLFile,"PMML");
	XMLNode& rkTextureNode = kMainNode.getChildNode("TEXTURA");
	importTexture(rkTextureNode);

	const char* pszTexFile = rkTextureNode.getAttribute("TextureFile");
	pkSprite->setTexture( m_kpTexturesMap[pszTexFile] );

	pkSprite->setName(pszName);
	pkSprite->setTextureArea(uiTexPosX, uiTexPosY, uiWidth, uiHeight);

	// load animations
	int iTotalAnims = rkNode.nChildNode("SPRITE_ANIMATION");	

	int iIterator = 0;
	for(int i=0; i<iTotalAnims; i++)
	{
		XMLNode& rkAnim = rkNode.getChildNode("SPRITE_ANIMATION",&iIterator);
		importSpriteAnimation(rkAnim);
	}

	return true;
}
//----------------------------------------------------------------------
bool Importer::importSpriteAnimation (XMLNode& rkNode)
{
	// load attributes
	const char* pszName = rkNode.getAttribute("Name");

	// find the animation
	AnimationInfo::Ptr pkAnimInfo = m_kpSpriteAnimsMap[pszName];
	
	// if it was found, return
	if(pkAnimInfo.get())
		return true;

	// create the new animation
	pkAnimInfo = AnimationInfo::Ptr( new AnimationInfo() );

	// add to map and to sprite
	m_kpSpriteAnimsMap[pszName] = pkAnimInfo;
	m_pkCurrentSprite->addAnimationInfo(pszName, pkAnimInfo);

	// get animation attibutes
	const char* pszTime = rkNode.getAttribute("Time");

	// convert animation attibutes
	float fTime = (float)(strtod(pszTime,NULL));
	pkAnimInfo->setLength(fTime);
	
	// load frames
	int iTotalFrames = rkNode.nChildNode("FRAME");	

	int iIterator = 0;
	for(int i=0; i<iTotalFrames; i++)
	{
		XMLNode& rkFrame = rkNode.getChildNode("FRAME",&iIterator);
		
		// get frame data
		const char* pszTexPosX = rkFrame.getAttribute("TexPosX");
		const char* pszTexPosY = rkFrame.getAttribute("TexPosY");
		const char* pszWidth = rkFrame.getAttribute("Width");
		const char* pszHeight = rkFrame.getAttribute("Height");

		// convert frame data
		unsigned int uiTexPosX = atoi(pszTexPosX);
		unsigned int uiTexPosY = atoi(pszTexPosY);
		unsigned int uiWidth = atoi(pszWidth);
		unsigned int uiHeight = atoi(pszHeight);

		pkAnimInfo->addFrame(uiTexPosX, uiTexPosY, uiWidth, uiHeight);
	}

	return true;
}
//----------------------------------------------------------------------
bool Importer::importTexture (XMLNode& rkTextureNode)
{
	assert(m_pkRenderer);

	const char* pszTextureFile = rkTextureNode.getAttribute("TextureFile");

	// find the texture
	Texture::Ptr pkTexture = m_kpTexturesMap[pszTextureFile];
	
	// if it was found, return
	if(pkTexture.get())
		return true;

	XMLNode kColoreyNode = rkTextureNode.getChildNode("ColorKey");

	const char* pszRed = kColoreyNode.getAttribute("R");
	const char* pszGreen = kColoreyNode.getAttribute("G");
	const char* pszBlue = kColoreyNode.getAttribute("B");

	int iRed = atoi(pszRed);
	int iGreen = atoi(pszGreen);
	int iBlue = atoi(pszBlue);

	// create the new texture
	pkTexture = Texture::Ptr( new Texture(pszTextureFile, iRed, iGreen, iBlue) );

	// add to map
	m_kpTexturesMap[pszTextureFile] = pkTexture;

	m_pkRenderer->loadTexture(pszTextureFile, pkTexture);

	return true;
}
//----------------------------------------------------------------------
bool Importer::createSprite (const char* pszName, Sprite* rkSprite)
{
	Sprite* pkSprite = m_kpSpritesMap[pszName];

	if(!pkSprite)
		return false;

	pkSprite->clone(rkSprite);

	return true;
}
//----------------------------------------------------------------
Texture::Ptr Importer::getTexture (const char* pszFilename)
{
	Texture::Ptr pkTexture = m_kpTexturesMap[pszFilename];
	int iRed;
	int iGreen;
	int iBlue;
	pkTexture->getColorKey(iRed,iGreen,iBlue);
	Texture::Ptr pkNewTexture(new Texture(pkTexture->getFilename(), iRed, iGreen ,iBlue));
	return pkNewTexture;
}
//----------------------------------------------------------------
