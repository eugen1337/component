#include "FSManager.h"
#include <iostream>
//#include <windows.h>

FSManager::FSManager()
{
    std::cout<<"IFSManager Consructor"<<std::endl;
    fRefCount = 0;
}

FSManager::FSManager(int a)
{
    std::cout<<"IFSManager Consructor2"<<std::endl;
    fRefCount = 0;
}

FSManager::~FSManager()
{
    std::cout<<"IFSManager Destruct"<<std::endl;
    fRefCount = 0;
}

HRESULT_ FSManager::QueryInterface(const IID_& iid, void** ppv)
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

ULONG_ FSManager::AddRef()
{
    std::cout<<"IFSManager AddRef"<<std::endl;
    fRefCount++;

    return fRefCount;
}

ULONG_ FSManager::Release()
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

HRESULT_ FSManager::CreateFile(char *path)
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

HRESULT_ FSManager::DeleteFile(char *path)
{
    std::cout<<"IFSManager::CreateFile"<<std::endl;
    return 0;  
}
HRESULT_ FSManager::CreateFolder(char *path)
{
    std::cout<<"IFSManager::CreateFolder"<<std::endl;
    return 0;
}
HRESULT_ FSManager::DeleteFolder(char *path)
{
    std::cout<<"IFSManager::DeleteFolder"<<std::endl;
    return 0;
}
