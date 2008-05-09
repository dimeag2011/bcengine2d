#ifndef GRAPHICS_STRUCTS_H
#define GRAPHICS_STRUCTS_H
//----------------------------------------------------------------
#include <windows.h>
//----------------------------------------------------------------
// color vertex D3D define
#define COLOR_VERTEX (D3DFVF_XYZ|D3DFVF_DIFFUSE)

// color vertex struct
struct ColorVertex
{
	float x,y,z;
	DWORD color;
};
//----------------------------------------------------------------
// matrix modes

// include DirectX to have the matrix constants
#include <d3dx9.h>

enum MatrixMode
{
	WORLD = D3DTS_WORLDMATRIX(0),
	VIEW = D3DTS_VIEW,
	PROJECTION = D3DTS_PROJECTION
};
//----------------------------------------------------------------
#endif // GRAPHICS_STRUCTS_H
//----------------------------------------------------------------