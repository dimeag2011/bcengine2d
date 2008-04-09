#ifndef RENDERER_H
#define RENDERER_H
//--------------------------------------------------------------------------------
#include <D3D9.h>
#include "Structs.h"
#include "VertexBuffer.h"
//--------------------------------------------------------------------------------
#pragma comment (lib, "d3d9.lib")
//--------------------------------------------------------------------------------
class Renderer
{
public:
	Renderer(HWND hWnd);
	~Renderer();
	bool InitDX(HWND hWnd);
	void StartFrame();
	void EndFrame();
	void Draw(ColorVertex * vertexColletion, D3DPRIMITIVETYPE prim, unsigned int uiVertexCount);

private:
	HWND m_hWnd;
	IDirect3DDevice9*  m_pkDevice;
	VertexBuffer<ColorVertex,COLOR_VERTEX> * m_pkVertexBuffer;
};
//--------------------------------------------------------------------------------
#endif //RENDERER_H