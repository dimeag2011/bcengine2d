#ifndef RENDERER_H
#define RENDERER_H
//--------------------------------------------------------------------------------
#include <D3D9.h>
#include <D3DX9.h>
#include "Structs.h"
#include "VertexBuffer.h"
#include "Defines.h"
#include "Texture.h"
//--------------------------------------------------------------------------------
#pragma comment (lib, "d3d9.lib")
#pragma comment (lib, "d3dx9.lib")
//--------------------------------------------------------------------------------
class Texture;
//--------------------------------------------------------------------------------
class Renderer
{
public:
	enum PrimitiveType
	{
		TRIANGLE_LIST = D3DPT_TRIANGLELIST,
		TRIANGLE_STRIP = D3DPT_TRIANGLESTRIP,
		TRIANGLE_FAN = D3DPT_TRIANGLEFAN,
		LINE_STRIP = D3DPT_LINESTRIP
	};

	Renderer(HWND hWnd);
	~Renderer();

	void Draw(ColorVertex * vertexColletion, PrimitiveType ePrim, unsigned int uiVertexCount);
	void Draw(TextureVertex * vertexColletion, PrimitiveType ePrim, unsigned int uiVertexCount);

// matrix handling
	void setMatrixMode (MatrixMode eMode);
	void loadIdentity ();
	void translate (float fX, float fY, float fZ = 0.0f);
	void rotateZ (float fAngle);
	void setViewPosition (float fPosX, float fPosY);
	void scale (float fW, float fH);

//	Metodos de Textura
	void unbindTexture ();
	bool bindTexture (Texture::Ptr rkTexture);
	bool loadTexture (const char* pszFilename, Texture::Ptr rkTexture);

private:
	void StartFrame();
	void EndFrame();

	bool InitDX(HWND hWnd);

	HWND m_hWnd;
	IDirect3DDevice9*  m_pkDevice;
	VertexBuffer<ColorVertex,COLOR_VERTEX> m_pkVertexBuffer;
	VertexBuffer<TextureVertex, TEXTURE_VERTEX> m_kTextureBuffer;
	/*
	D3DXMATRIX d3dmat;
	*/D3DXMATRIX m_mProjectionMatrix;
	
	// current matrix mode
	MatrixMode m_eCurrentMatMode;

protected:
	map <string, IDirect3DTexture9*> m_kTextureMap;
	typedef map<string, IDirect3DTexture9*>::iterator TextureIterator;

	friend class Game;
};
//--------------------------------------------------------------------------------
#endif //RENDERER_H