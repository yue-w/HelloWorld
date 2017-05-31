#pragma once
#include <string.h>
#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

#ifdef _EXPORT_CORE
#define _EXPORT_CORE_DLL _declspec(dllexport)
#else
#define _EXPORT_CORE_DLL _declspec(dllimport)
#endif // _EXPORT_CORE

#ifdef _EXPORT_FOR_UNIT_TEST
#define _EXPORT_DLL_UNIT_TEST _declspec(dllexport)
#else
#ifdef UNIT_TEST
#define _EXPORT_DLL_UNIT_TEST _declspec(dllimport)
#else
#define _EXPORT_DLL_UNIT_TEST
#endif // UNIT_TEST
#endif // _EXPORT_CORE