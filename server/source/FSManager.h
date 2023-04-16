#pragma once

#include "IFileManager.h"
#include "IFolderManager.h"

class FSManager: public IFileManager, public IFolderManager
{
	private:
        int fRefCount;


    public:
        FSManager();
        FSManager(int a);
        ~FSManager();

        virtual HRESULT_ __stdcall QueryInterface(const IID_& iid, void** ppv);
        virtual ULONG_ __stdcall AddRef();
        virtual ULONG_ __stdcall Release();

        virtual HRESULT_ __stdcall CreateThisFile(char *path);
        virtual HRESULT_ __stdcall DeleteFile(char *path);

        virtual HRESULT_ __stdcall CreateFolder(char *path);
        virtual HRESULT_ __stdcall DeleteFolder(char *path);

};

