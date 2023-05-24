#pragma once

#include "./Interfaces.h"

class FSManager: public IFolderManager, public IFileManager, public IFSMInfo
{
    private:
        int fRefCount;
        IFSMInfo* pinfo;

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

        // IDispatch (Begin)
        virtual HRESULT __stdcall GetIDsOfNames(REFIID riid, LPOLESTR *rgszNames, UINT cNames, LCID lcid, DISPID *rgDispId);
        virtual HRESULT __stdcall Invoke(DISPID dispIdMember, REFIID riid, LCID lcid, WORD wFlags, DISPPARAMS *pDispParams, VARIANT *pVarResult,
                                         EXCEPINFO *pExcepInfo, UINT *puArgErr);

        virtual HRESULT __stdcall GetTypeInfoCount(UINT *pctinfo);
        virtual HRESULT __stdcall GetTypeInfo(UINT iTInfo, LCID lcid, ITypeInfo **ppTInfo);
        // IDispatch (End)
};

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

        virtual HRESULT __stdcall CreateInstance(IUnknown* pUnknownOuter, const IID& iid, void** ppv);
        virtual HRESULT __stdcall CreateInstance(const IID& iid, void** ppv, int a);

        virtual HRESULT __stdcall LockServer(BOOL bLock);  
};