#ifndef DEFINES_H
#define DEFINES_H
//--------------------------------------------------------------------------------
#include <windows.h>
//--------------------------------------------------------------------------------
#ifdef ENGINE_EXPORTS
	#define ENGINE_API __declspec(dllexport)
#else
	#define ENGINE_API __declspec(dllimport)
#endif //ENGINE_EXPORT
//--------------------------------------------------------------------------------
#endif //DEFINES_H