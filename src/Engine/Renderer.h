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
	Renderer(HWND hWnd);
	~Renderer();
	bool InitDX(HWND hWnd);
	void Draw(ColorVertex * vertexColletion, D3DPRIMITIVETYPE prim, unsigned int uiVertexCount);
// matrix handling
	void setMatrixMode (MatrixMode eMode);
	void loadIdentity ();
	void translate (float fX, float fY, float fZ = 0.0f);
	void rotateZ (float fAngle);
	void setViewPosition (float fPosX, float fPosY);


private:
	void StartFrame();
	void EndFrame();

	HWND m_hWnd;
	IDirect3DDevice9*  m_pkDevice;
	VertexBuffer<ColorVertex,COLOR_VERTEX> * m_pkVertexBuffer;
	/*
	D3DXMATRIX d3dmat;
	D3DXMATRIX m_mProjectionMatrix;
	*/
	// current matrix mode
	MatrixMode m_eCurrentMatMode;

};
//--------------------------------------------------------------------------------
#endif //RENDERER_H