#pragma once

#include "windows.h"
#include <objbase.h>

const IID IID_IUnknown1 = {0x00000000,0x0000,0x0000,{0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}};
const IID IID_IClassFactory1 = {0x00000001,0x0000,0x0000,{0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}};

const IID IID_IFSMInfo = {0x00000003,0x0000,0x0000,{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00}};
const IID IID_IInfoFactory= {0x00000012,0x0000,0x0000,{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00}};

const CLSID CLSID_FSMInfo = {0x29106A92,0x9342,0x4F4E,{0xA7,0x89,0xE4,0x20,0x21,0x91,0x78,0x1C}};
//{29106A92-9342-4F4E-A789-E4202191781C}

class IFSMInfo : public IUnknown
{
    public:
        virtual HRESULT __stdcall fileInfo(char *path) = 0;
};

class IInfoFactory : public IUnknown
{
    public:
        virtual HRESULT __stdcall CreateInstance(const IID& iid, void** ppv, int a) = 0;
};


extern "C" HRESULT __stdcall __declspec(dllexport) DllGetClassObject(const CLSID& clsid, const IID& iid, void** ppv);