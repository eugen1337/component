#pragma once

#include "./Interfaces.h"

class FSManager: public IFolderManager, public IFileManager, public IFSMInfo, public IDispatch
{
    private:
        int fRefCount;
        int testInt;
        IFSMInfo* pinfo;
        std::string path;

    public:
        FSManager();
        FSManager(std::string lpath);
        ~FSManager();
        
        // IUnknown methods
        virtual HRESULT __stdcall QueryInterface(const IID& iid, void** ppv);
        virtual ULONG __stdcall AddRef();
        virtual ULONG __stdcall Release();

        // Component methods
        virtual HRESULT __stdcall CreateFolder(std::string path);
        virtual HRESULT __stdcall DeleteFolder(std::string path);

		virtual HRESULT __stdcall CreateThisFile();
		virtual HRESULT __stdcall DeleteThisFile();

        virtual HRESULT __stdcall fileInfo();
        //

        // IDispatch methods
        virtual HRESULT __stdcall GetIDsOfNames(REFIID riid, LPOLESTR *rgszNames, UINT cNames, LCID lcid, DISPID *rgDispId);
        virtual HRESULT __stdcall Invoke(DISPID dispIdMember, REFIID riid, LCID lcid, WORD wFlags, DISPPARAMS *pDispParams, VARIANT *pVarResult,
                                         EXCEPINFO *pExcepInfo, UINT *puArgErr);

        virtual HRESULT __stdcall GetTypeInfoCount(UINT *pctinfo);
        virtual HRESULT __stdcall GetTypeInfo(UINT iTInfo, LCID lcid, ITypeInfo **ppTInfo);
};

class FSMFactory : public IClassFactory, public IFSMFactory
{
    private:
        int fRefCount;
        
    public:
        FSMFactory();
        ~FSMFactory();

        // IUnknown methods
        virtual HRESULT __stdcall QueryInterface(const IID& iid, void** ppv);
        virtual ULONG __stdcall AddRef();
        virtual ULONG __stdcall Release();

        // IClassFactory methods
        virtual HRESULT __stdcall CreateInstance(IUnknown* pUnknownOuter, const IID& iid, void** ppv);
        virtual HRESULT __stdcall LockServer(BOOL bLock); 

        // IFSMFactory method
        virtual HRESULT __stdcall CreateInstance(const IID& iid, void** ppv, std::string path);
};