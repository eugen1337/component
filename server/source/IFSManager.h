#pragma once

#include "IFileManager.h"
#include "IFolderManager.h"

class IFSManager: public IFileManager, public IFolderManager
{
	private:
        int fRefCount;


    public:
        IFSManager();
        ~IFSManager();

        virtual HRESULT_ __stdcall QueryInterface(const IID_& iid, void** ppv);
        virtual ULONG_ __stdcall AddRef();
        virtual ULONG_ __stdcall Release();

        virtual HRESULT_ __stdcall CreateFile(char *path);
        virtual HRESULT_ __stdcall DeleteFile(char *path);

        virtual HRESULT_ __stdcall CreateFolder(char *path);
        virtual HRESULT_ __stdcall DeleteFolder(char *path);

};

 HRESULT_ __stdcall CreateInstance(const CLSID_& clsid, const IID_& iid, void** ppv);