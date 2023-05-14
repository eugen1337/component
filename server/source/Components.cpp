#include "Components.h"
#include <iostream>

// DLL --------------------------

BOOL APIENTRY DllMain(HINSTANCE hinstDLL, DWORD fdwReason, LPVOID lpvReserved)
{
    switch (fdwReason)
    {
        case DLL_PROCESS_ATTACH:
            std::cout<<"FSM::DLL CONNECTED"<<std::endl;
            break;

        case DLL_PROCESS_DETACH:
            // detach from process
            break;

        case DLL_THREAD_ATTACH:
            // attach to thread
            break;

        case DLL_THREAD_DETACH:
            // detach from thread
            break;
    }

    return TRUE; // succesful
}

extern "C" HRESULT __stdcall __declspec(dllexport) DllGetClassObject(const CLSID &clsid, const IID &iid, void **ppv)
{
    std::cout << "Components:: GetClassObject" << std::endl;
    IUnknown *s = NULL;

    if (clsid == CLSID_FSMFactory)
    {
        s = (IUnknown *)(IClassFactory *)new FSMFactory();
    }
    else
    {
        *ppv = NULL;
        return E_NOTIMPL;
    }

    s->AddRef();
    HRESULT res = s->QueryInterface(iid, ppv);

    s->Release();
    return res;
}

HRESULT FSMFactory::CreateInstance(const IID& iid, void** ppv)
{
    std::cout << "FSMFactory CreateInstance" << std::endl;
    FSManager* s = new FSManager();

    s -> AddRef();
    HRESULT res =  s -> QueryInterface(iid, ppv);
    s -> Release();
    
    return res;
}

HRESULT FSMFactory::CreateInstance(IUnknown *pUnkOuter, const IID& iid, void** ppv)
{
    std::cout << "FSMFactory CreateInstance" << std::endl;
    FSManager* s = new FSManager();

    s -> AddRef();
    HRESULT res =  s -> QueryInterface(iid, ppv);
    s -> Release();
    
    return res;
}

HRESULT FSMFactory::CreateInstanceWPar(const IID& iid, void** ppv, int a)
{
    std::cout << "FSManager CreateInstanceWPar" << std::endl;
    FSManager* s = new FSManager(a);

    s -> AddRef();
    HRESULT res =  s -> QueryInterface(iid, ppv);
    s -> Release();
    
    return res;
}

FSMFactory::FSMFactory()
{
    std::cout<<"FSMFactory Consructor"<<std::endl;
    fRefCount = 0;
}

FSMFactory::~FSMFactory()
{
    std::cout<<"FSMFactory Destruct"<<std::endl;
}

HRESULT FSMFactory::QueryInterface(const IID& iid, void** ppv)
{
    if (iid == IID_IUnknown)
    {
        *ppv = (IUnknown*) (IClassFactory*) this;
    }
    else if (iid == IID_IClassFactory)
    {
        *ppv = static_cast<IClassFactory*>(this);
    }
    else if (iid == IID_IFSMFactory)
    {
        *ppv = static_cast<IFSMFactory*>(this);
    }
    else
    {
        *ppv = NULL;
        return E_NOINTERFACE;
    }
    
    this->AddRef();

    return S_OK;
}

ULONG FSMFactory::AddRef()
{
    std::cout<<"FSMFactory AddRef"<<std::endl;
    fRefCount++;

    return fRefCount;
}

ULONG FSMFactory::Release()
{
    std::cout<<"FSMFactory Release"<<std::endl;
    fRefCount--;

    if (fRefCount == 0)
    {
        delete this;
        std::cout<<"Delete object"<<std::endl;
    }
    
    return fRefCount;
}

HRESULT FSMFactory::LockServer(BOOL bLock)
{
    return S_OK;
}


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

HRESULT FSManager::QueryInterface(const IID& iid, void** ppv)
{
    if (iid == IID_IUnknown)
    {
        *ppv = (IUnknown*) (IFileManager*) this;
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
        return E_NOINTERFACE;
    }
    
    this -> AddRef();

    return S_OK;
}

ULONG FSManager::AddRef()
{
    std::cout<<"IFSManager AddRef"<<std::endl;
    fRefCount++;

    return fRefCount;
}

ULONG FSManager::Release()
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

HRESULT FSManager::CreateThisFile(char *path)
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

HRESULT FSManager::DeleteFile(char *path)
{
    std::cout<<"IFSManager::CreateFile"<<std::endl;
    return 0;  
}
HRESULT FSManager::CreateFolder(char *path)
{
    std::cout<<"IFSManager::CreateFolder"<<std::endl;
    return 0;
}
HRESULT FSManager::DeleteFolder(char *path)
{
    std::cout<<"IFSManager::DeleteFolder"<<std::endl;
    return 0;
}
