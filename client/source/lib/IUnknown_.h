#pragma once

using IID_ = int;
using CLSID_ = int;
using HRESULT_ = int;
using ULONG_ = int;


const int IID_IUnknown_ = 0;
const int IID_IFileManager = 1;
const int IID_IFolderManager = 2;

const int IID_IClassFactory_ = 100;
const int IID_IFSMFactory = 101;


const int S_OK_ = 0;
const int E_NOINTERFACE_ = 1;
const int E_NOCOMPONENT_ = 2;

const int CLSID_IFSManager = 1;

const int CLSID_FSMFactory = 1;

class IUnknown_
{
    public:
        virtual HRESULT_ __stdcall QueryInterface(const IID_& iid, void** ppv) = 0;
        virtual ULONG_ __stdcall AddRef() = 0;
        virtual ULONG_ __stdcall Release() = 0;
};

extern "C" HRESULT_ __stdcall __declspec(dllexport) GetClassObject(const CLSID_& clsid, const IID_& iid, void** ppv);
HRESULT_ __stdcall CreateInstance(const CLSID_& clsid, const IID_& iid, void** ppv);