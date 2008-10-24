#ifndef DEFINES_H
#define DEFINES_H
//--------------------------------------------------------------------------------
// deshabilito el warning del export de STL dll 
#pragma warning(disable : 4251)
//--------------------------------------------------------------------------------
//opcion import/export
#ifdef ENGINE_EXPORTS
	#define ENGINE_API __declspec(dllexport)
#else
	#define ENGINE_API __declspec(dllimport)
#endif //ENGINE_EXPORT
//--------------------------------------------------------------------------------
// includes estandar
#include <windows.h>
#include <string>
#include <vector>
#include <map>
#include <cassert>
#include <sstream>
#include <stdarg.h>
#include <stdio.h>
//--------------------------------------------------------------------------------
// boost smart pointer
#include <boost/shared_ptr.hpp>

#define DECLARE_SMART_POINTER(classname) \
	public:	\
		typedef boost::shared_ptr<classname> Ptr;
//--------------------------------------------------------------------------------
// uso el namespace std
using namespace std;
//--------------------------------------------------------------------------------
// uso shifting para devolver los componentes de un D3DCOLOR (un DWORD)
#define getA(c) (((c)&0xff000000)>>24)
#define getR(c) (((c)&0x00ff0000)>>16)
#define getG(c) (((c)&0x0000ff00)>>8)
#define getB(c) ((c)&0x000000ff)
//--------------------------------------------------------------------------------
#endif //DEFINES_H