#pragma once

#include "IFileManager.h"
#include "IFolderManager.h"

class IFSManager: public IFileManager, public IFolderManager
{
	private:
        int fRefCount;

        int a;
        int b;
    public:
        IFSManager();
        ~IFSManager();

        virtual HRESULT_ __stdcall QueryInterface(const IID_& iid, void** ppv);
        virtual ULONG_ __stdcall AddRef();
        virtual ULONG_ __stdcall Release();

        virtual HRESULT_ __stdcall CreateFile(char *path)=0;
        virtual HRESULT_ __stdcall DeleteFile(char *name)=0;

        virtual HRESULT_ __stdcall CreateFile(char *path)=0;
        virtual HRESULT_ __stdcall DeleteFile(char *name)=0;

};

 HRESULT_ __stdcall CreateInstance(const CLSID_& clsid, const IID_& iid, void** ppv);