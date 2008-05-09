#ifndef RENDERER_H
#define RENDERER_H
//--------------------------------------------------------------------------------
#include <D3D9.h>
#include <D3DX9.h>
#include "Structs.h"
#include "VertexBuffer.h"
//--------------------------------------------------------------------------------
#pragma comment (lib, "d3d9.lib")
#pragma comment (lib, "d3dx9.lib")
//--------------------------------------------------------------------------------
class Renderer
{
public:
	enum PrimitiveType
	{
		TRIANGLE_LIST = D3DPT_TRIANGLELIST,
		TRIANGLE_STRIP = D3DPT_TRIANGLESTRIP,
		TRIANGLE_FAN = D3DPT_TRIANGLEFAN
	};

	Renderer(HWND hWnd);
	~Renderer();
	void Draw(ColorVertex * vertexColletion, PrimitiveType ePrim, unsigned int uiVertexCount);
// matrix handling
	void setMatrixMode (MatrixMode eMode);
	void loadIdentity ();
	void translate (float fX, float fY, float fZ = 0.0f);
	void rotateZ (float fAngle);
	void setViewPosition (float fPosX, float fPosY);
	void scale (float fW, float fH);

private:
	void StartFrame();
	void EndFrame();

	bool InitDX(HWND hWnd);

	HWND m_hWnd;
	IDirect3DDevice9*  m_pkDevice;
	VertexBuffer<ColorVertex,COLOR_VERTEX> * m_pkVertexBuffer;
	/*
	D3DXMATRIX d3dmat;
	*/D3DXMATRIX m_mProjectionMatrix;
	
	// current matrix mode
	MatrixMode m_eCurrentMatMode;

	friend class Game;
};
//--------------------------------------------------------------------------------
#endif //RENDERER_H