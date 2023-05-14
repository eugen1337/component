#pragma once

#include "Interfaces.h"

class FSMFactory : public IClassFactory, public IFSMFactory
{
    private:
        int fRefCount;


    public:
        FSMFactory();
        ~FSMFactory();

        virtual HRESULT __stdcall QueryInterface(const IID& iid, void** ppv);
        virtual ULONG __stdcall AddRef();
        virtual ULONG __stdcall Release();

        virtual HRESULT __stdcall CreateInstance(const IID& iid, void** ppv);
        virtual HRESULT __stdcall CreateInstance(IUnknown *pUnkOuter, const IID& iid, void** ppv);
        virtual HRESULT __stdcall CreateInstanceWPar(const IID& iid, void** ppv, int a);

        virtual HRESULT __stdcall LockServer(BOOL bLock);
};

extern "C" HRESULT __stdcall __declspec(dllexport) DllGetClassObject(const CLSID& clsid, const IID& iid, void** ppv);
