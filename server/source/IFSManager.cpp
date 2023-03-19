#include "IFSManager.h"
#include <iostream>
//#include <windows.h>

HRESULT_ CreateInstance(const CLSID_& clsid, const IID_& iid, void** ppv)
{
    IUnknown_* piu = NULL;

    if (clsid == CLSID_IFSManager)
    {
        piu = (IUnknown_*) (IFileManager*) new IFSManager();
    }
    else
    {
        *ppv = NULL;
        return E_NOCOMPONENT_;
    }

    piu -> AddRef();
    HRESULT_ res = piu -> QueryInterface(iid, ppv);
    piu -> Release();
    
    return res;
}


IFSManager::IFSManager()
{
    std::cout<<"IFSManager Consructor"<<std::endl;
    fRefCount = 0;
}

IFSManager::~IFSManager()
{
    std::cout<<"IFSManager Destruct"<<std::endl;
    fRefCount = 0;
}

HRESULT_ IFSManager::QueryInterface(const IID_& iid, void** ppv)
{
    if (iid == IID_IUnknown_)
    {
        *ppv = (IUnknown_*) (IFileManager*) this;
    }
    else if (iid == IID_IFileManager)
    {
        *ppv = static_cast<IFileManager*>(this);
    }
    else if (iid == IID_IFolderManager)
    {
        *ppv = static_cast<IFolderManager*>(this);
    }
    else
    {
        *ppv = NULL;
        return E_NOINTERFACE_;
    }
    
    this->AddRef();

    return S_OK_;
}

ULONG_ IFSManager::AddRef()
{
    std::cout<<"IFSManager AddRef"<<std::endl;
    fRefCount++;

    return fRefCount;
}

ULONG_ IFSManager::Release()
{
    std::cout<<"IFSManager Release"<<std::endl;
    fRefCount--;

    if (fRefCount == 0)
    {
        delete this;
        std::cout<<"Delete object"<<std::endl;
    }
    
    return fRefCount;
}

HRESULT_ IFSManager::CreateFile(char *path)
{ /*
    HANDLE hFile;
    LPCTSTR lpFileName = (LPCTSTR) "D:\\somefile.txt"; // имя файла
    DWORD dwDesiredAccess = GENERIC_READ; // права доступа к файлу
    DWORD dwShareMode = 0; // режим совместного доступа
    LPSECURITY_ATTRIBUTES lpSecurityAttributes = NULL; // указатель на структуру безопасности
    DWORD dwCreationDisposition = OPEN_EXISTING; // что делать, если файл существует
    DWORD dwFlagsAndAttributes = FILE_ATTRIBUTE_NORMAL; // атрибуты файла
    HANDLE hTemplateFile = NULL; // дескриптор файла-шаблона

    hFile = CreateFile(lpFileName, dwDesiredAccess, dwShareMode, lpSecurityAttributes,
    dwCreationDisposition, dwFlagsAndAttributes, hTemplateFile);

    if (hFile == INVALID_HANDLE_VALUE)
    {
    std::cout << "Error opening file.";
    return 1;
    }

    std::cout << "File opened successfully.";

    CloseHandle(hFile); // закрытие дескриптора файла
    */
    std::cout<<"IFSManager::CreateFile"<<std::endl;
    return 0;
}

HRESULT_ IFSManager::DeleteFile(char *path)
{
    std::cout<<"IFSManager::CreateFile"<<std::endl;
    return 0;  
}
HRESULT_ IFSManager::CreateFolder(char *path)
{
    std::cout<<"IFSManager::CreateFolder"<<std::endl;
    return 0;
}
HRESULT_ IFSManager::DeleteFolder(char *path)
{
    std::cout<<"IFSManager::DeleteFolder"<<std::endl;
    return 0;
}
