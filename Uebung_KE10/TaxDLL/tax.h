#pragma once
#ifndef TAX_H
#define TAX_H

#ifdef __cplusplus
extern "C" {
#endif

#ifdef TAX_DLL
#define TAX_API __declspec(dllexport)
#else
#define TAX_API __declspec(dllimport)
#endif

TAX_API double GetValueAddedTax(void);

#ifdef __cplusplus
}
#endif

#endif
