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
// include DirectX to have the matrix constants
#include <d3dx9.h>
//----------------------------------------------------------------
// matrix modes
enum MatrixMode
{
	WORLD = D3DTS_WORLDMATRIX(0),
	VIEW = D3DTS_VIEW,
	PROJECTION = D3DTS_PROJECTION
};
//----------------------------------------------------------------
// texture vertex D3D define
#define TEXTURE_VERTEX (D3DFVF_XYZ|D3DFVF_TEX1|D3DFVF_TEXCOORDSIZE2(0))

// texture vertex struct
struct TextureVertex
{
	float X,Y,Z;
	float U, V;
};
//----------------------------------------------------------------
// Estructura para almacenar un color RGB
struct RGBColor {
	int red;
	int green;
	int blue;
};
//----------------------------------------------------------------
#endif // GRAPHICS_STRUCTS_H
//----------------------------------------------------------------