#pragma once

#include "./Interfaces.h"

class FSMInfo: public IFSMInfo
{
    private:
        int fRefCount;

    public:
        FSMInfo();
        ~FSMInfo();
        
        virtual HRESULT __stdcall QueryInterface(const IID& iid, void** ppv);
        virtual ULONG __stdcall AddRef();
        virtual ULONG __stdcall Release();
        
        virtual HRESULT __stdcall fileInfo();
};

class InfoFactory : public IClassFactory, public IInfoFactory
{
    private:
        int fRefCount;
        
    public:
        InfoFactory();
        ~InfoFactory();

        virtual HRESULT __stdcall QueryInterface(const IID& iid, void** ppv);
        virtual ULONG __stdcall AddRef();
        virtual ULONG __stdcall Release();

        virtual HRESULT __stdcall CreateInstance(IUnknown* pUnknownOuter, const IID& iid, void** ppv);
        virtual HRESULT __stdcall CreateInstance(const IID& iid, void** ppv, int a);

        virtual HRESULT __stdcall LockServer(BOOL bLock);  
};