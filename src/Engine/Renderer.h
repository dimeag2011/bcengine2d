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
class ENGINE_API Renderer
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
	void scale (float fW, float fH);

//	Metodos de Textura
	void unbindTexture ();
	bool bindTexture (Texture::Ptr rkTexture);
	bool loadTexture (const char* pszFilename, Texture::Ptr rkTexture);

//	Metodos de la posicion del viewer
	void setViewerPosition(float fPosX, float fPosY);
	void getViewerPosition(float &fPosX, float &fPosY);
	void setViewerAngle(float fAngle);
	float getViewerAngle();

private:
	void StartFrame();
	void EndFrame();

	bool InitDX(HWND hWnd);

	//Metodo para la posicion del viewport
	//DEPRECATED
	//void setViewPosition (float fPosX, float fPosY);
	//NEW VERSION
	void setViewportPosition();

	HWND m_hWnd;
	IDirect3DDevice9*  m_pkDevice;
	VertexBuffer<ColorVertex,COLOR_VERTEX> m_pkVertexBuffer;
	VertexBuffer<TextureVertex, TEXTURE_VERTEX> m_kTextureBuffer;
	/*
	D3DXMATRIX d3dmat;
	*/D3DXMATRIX m_mProjectionMatrix;
	
	// current matrix mode
	MatrixMode m_eCurrentMatMode;

	D3DXVECTOR3 m_kViewerPos;
	D3DXVECTOR3 m_kViewerUp;
	float m_fViewerAngle;

protected:
	map <string, IDirect3DTexture9*> m_kTextureMap;
	typedef map<string, IDirect3DTexture9*>::iterator TextureIterator;

	friend class Game;
};
//--------------------------------------------------------------------------------
#include "Renderer.inl"
//--------------------------------------------------------------------------------
#endif //RENDERER_H