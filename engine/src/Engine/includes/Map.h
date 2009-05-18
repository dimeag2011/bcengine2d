//----------------------------------------------------------------
#ifndef MAP_H
#define MAP_H
//----------------------------------------------------------------
#include "Defines.h"
#include "Structs.h"
#include "Tile.h"
#include "XMLParser.h"
#include "Renderer.h"
//----------------------------------------------------------------
class ENGINE_API Map
{
public:
	Map(Renderer* pkRenderer);
	~Map();

	bool loadMap(string kTileSetFile, string kTileMapFile);
	void draw();
	void update(float fTimeBetweenFrames);
	void setPos(float fX, float fY, float fZ=15);
	float getPosX();
	float getPosY();
	float getPosZ();
	void setLayerVisible(int iLayerId, bool bVisible);
	bool getLayerVisible(int iLayerId);
	void setLayerUpdatable(int iLayerId, bool bUpdatable);
	bool getLayerUpdateble(int iLayerId);
	int getTileWidth();
	int getTileHeight();
	int getNumCols();
	int getNumRows();
	int getNumLayers();
	bool setTile(int iCol, int iRow, int iLayer, int iTileIndex); 
	int getTile(int iCol, int iRow, int iLayer); 

private:
	string m_kName;
	int m_iLayers;
	int m_iRows;
	int m_iCols;
	int m_iTileWidth;
	int m_iTileHeight;
	float m_fPosX;
	float m_fPosY;
	float m_fPosZ;
	RGBColor m_kBackgroundColor;

	map<int, Tile*> m_kpTileMap;
	typedef map<int, Tile*>::iterator TileMapIterator;

	map<string, Texture::Ptr> m_kpTileSetMap;
	typedef map<string, Texture::Ptr>::iterator TileSetMapIterator;
	map<string, string> m_kkTileSetNamesMap;
	typedef map<string, string>::iterator TileSetNamesMapIterator;
	
	typedef vector<Tile*> TileVector;
	map<string, TileVector*> m_kkLayerMap;
	typedef map<string, TileVector*>::iterator LayerMapIterator;
	
	struct LayerData {
		string kName;
		bool bVisible;
		bool bUpdatable;
	};
	map<int, LayerData> m_ikLayerIdMap;
	typedef map<int, LayerData>::iterator LayerIdMapIterator;



	Renderer* m_pkRenderer;

	void parseBackgroundColor(string kStringToParse);
	void getMapAttributes(XMLNode kMapNode);
	void loadTileSet(XMLNode kTileSet, string kParentPath);
	void loadTile(XMLNode kTile);
	void createTile(int iId, Tile* pkTile);
	void loadLayer(XMLNode kLayer);
	void procesarData(string kData, vector<int> &kDataVector);
	void moveMap();

	Tile* m_pkCurrentTile;


};
//----------------------------------------------------------------
#include "Map.inl"
//----------------------------------------------------------------
#endif //MAP_H
//----------------------------------------------------------------