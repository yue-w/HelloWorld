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