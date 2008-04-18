#ifndef DEFINES_H
#define DEFINES_H
//--------------------------------------------------------------------------------
#include <windows.h>
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
//--------------------------------------------------------------------------------
// uso el namespace std
using namespace std;
//--------------------------------------------------------------------------------
#endif //DEFINES_H