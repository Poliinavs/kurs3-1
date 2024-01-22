#pragma once
#include"COM.h"

#define FNAME L"Smw.CA.COM"
#define VINDX L"Smw.CA.1"
#define PRGID L"Smw.CA"


static const GUID CLSID_SP =
		{ 0x0faa8848, 0x0e97, 0x4cef, { 0xb9, 0x50, 0xce, 0xa0, 0x37, 0x16, 0x11, 0x55} };

static const GUID IID_Adder =
{ 0xdaa42d5f, 0x58d2, 0x4cc1, { 0x87, 0x90, 0xf, 0x79, 0x62, 0xc, 0xf1, 0x68 } };

struct IAdder : IUnknown
{
    virtual HRESULT STDMETHODCALLTYPE Add(const double x, const double y, double& z) = 0;
    virtual HRESULT STDMETHODCALLTYPE Sub(const double x, const double y, double& z) = 0;
};

static const GUID IID_Multiplier =
{ 0xd5a9b0a3, 0xfaf2, 0x4de6, { 0xb7, 0x3c, 0xda, 0x77, 0x73, 0xc8, 0xba, 0x86 } };

struct IMultiplier : IUnknown
{
    virtual HRESULT STDMETHODCALLTYPE Mul(const double x, const double y, double& z) = 0;
    virtual HRESULT STDMETHODCALLTYPE Div(const double x, const double y, double& z) = 0;
};
