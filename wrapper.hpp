#pragma once
#include <cstddef>
#if defined(_WIN32) && defined(EXPORTING_DLL)
#define DLL_PUBLIC __declspec(dllexport)
#else
#define DLL_PUBLIC
#endif

DLL_PUBLIC void resetData(size_t sz);

DLL_PUBLIC void printData();
