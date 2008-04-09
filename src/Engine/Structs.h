#ifndef GRAPHICS_STRUCTS_H
#define GRAPHICS_STRUCTS_H
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
#endif // GRAPHICS_STRUCTS_H
//----------------------------------------------------------------