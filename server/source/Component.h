#pragma once

#include "./Interfaces.h"

class FSManager: public IFolderManager, public IFileManager, public IFSMInfo
{
    private:
        int refCount;
        
    public:
        FSManager();
        ~FSManager();
        
        virtual HRESULT __stdcall QueryInterface(const IID& iid, void** ppv);
        virtual ULONG __stdcall AddRef();
        virtual ULONG __stdcall Release();

        virtual HRESULT __stdcall CreateFolder(char *path);
        virtual HRESULT __stdcall DeleteFolder(char *path);

		virtual HRESULT __stdcall CreateThisFile(char *path);
		virtual HRESULT __stdcall DeleteThisFile(char *path);
        
        virtual HRESULT __stdcall fileInfo(char *path);
};

class FSMFactory : public IClassFactory, public IFSMFactory
{
    private:
        int refCount;
    public:
        FSMFactory();
        ~FSMFactory();

        virtual HRESULT __stdcall QueryInterface(const IID& iid, void** ppv);
        virtual ULONG __stdcall AddRef();
        virtual ULONG __stdcall Release();

        virtual HRESULT __stdcall CreateInstance(IUnknown* pUnknownOuter, const IID& iid, void** ppv);
        virtual HRESULT __stdcall CreateInstance(const IID& iid, void** ppv, int a);

        virtual HRESULT __stdcall LockServer(BOOL bLock);  
};