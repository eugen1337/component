#pragma once

#include "windows.h"
#include <objbase.h>

const IID IID_IUnknown1 = {0x00000000,0x0000,0x0000,{0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}};
const IID IID_IClassFactory1 = {0x00000001,0x0000,0x0000,{0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}};

const IID IID_IDispatch = {0x00020400,0x0000,0x0000,{0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}};

const IID IID_IFileManager = {0x00000001,0x0000,0x0000,{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00}};
const IID IID_IFolderManager = {0x00000002,0x0000,0x0000,{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00}};
const IID IID_IFSMFactory = {0x00000011,0x0000,0x0000,{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00}};

const IID IID_IFSMInfo = {0x00000003,0x0000,0x0000,{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00}};

const CLSID CLSID_IFSManager = {0xB600D26B,0xF464,0x4308,{0x8A,0xC7,0x04,0x39,0x69,0xB7,0x61,0x4A}};

const CLSID CLSID_FSMInfo = {0x29106A92,0x9342,0x4F4E,{0xA7,0x89,0xE4,0x20,0x21,0x91,0x78,0x1C}};
//{29106A92-9342-4F4E-A789-E4202191781C}

class IFSMInfo : public IUnknown
{
    public:
        virtual HRESULT __stdcall fileInfo(char *path) = 0;
};

class IFSMFactory : public IUnknown
{
    public:
        virtual HRESULT __stdcall CreateInstance(const IID& iid, void** ppv, int a) = 0;
};

class IFolderManager : public IUnknown
{
    public:
        virtual HRESULT __stdcall CreateFolder(char *path)=0;
        virtual HRESULT __stdcall DeleteFolder(char *path)=0;
};

class IFileManager : public IUnknown
{
    public:
		virtual HRESULT __stdcall CreateThisFile(char *path)=0;
		virtual HRESULT __stdcall DeleteThisFile(char *path)=0;
};

extern "C" HRESULT __stdcall __declspec(dllexport) DllGetClassObject(const CLSID& clsid, const IID& iid, void** ppv);