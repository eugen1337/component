#pragma once

#include "Interfaces.h"


class FSManager: public IFileManager, public IFolderManager
{
	private:
        int fRefCount;


    public:
        FSManager();
        FSManager(int a);
        ~FSManager();

        virtual HRESULT __stdcall QueryInterface(const IID& iid, void** ppv);
        virtual ULONG __stdcall AddRef();
        virtual ULONG __stdcall Release();

        virtual HRESULT __stdcall CreateThisFile(char *path);
        virtual HRESULT __stdcall DeleteFile(char *path);

        virtual HRESULT __stdcall CreateFolder(char *path);
        virtual HRESULT __stdcall DeleteFolder(char *path);

};

