#include "./lib/Interfaces.h"
#include <objbase.h>
#include <iostream>

int main()
{
    std::cout<<"main start"<<std::endl;
    
    CoInitialize(NULL);

    IClassFactory* PCF = NULL;

    HRESULT resFactory = CoGetClassObject(CLSID_IFSManager, CLSCTX_INPROC_SERVER, NULL, IID_IClassFactory1, (void**) &PCF);

    if (!SUCCEEDED(resFactory))
    {
        std::cout<<"No factory"<<std::endl;
        throw "No factory";
    }

    IFileManager* pifile = NULL;
    HRESULT resInstance = PCF->CreateInstance(NULL, IID_IFileManager, (void**) &pifile);

    if (!SUCCEEDED(resInstance))
    {
        throw "No instance";
    }

    IFolderManager* pifold = NULL;
    HRESULT resQuery = pifile->QueryInterface(IID_IFolderManager, (void**) &pifold);

    if (!SUCCEEDED(resQuery))
    {
        throw "No QueryInterface";
    }
    
    IFSMInfo* piinfo = NULL;
    HRESULT resQuery2 = pifold->QueryInterface(IID_IFSMInfo, (void**) &piinfo);

    if (!SUCCEEDED(resQuery2))
    {
        throw "No QueryInterface 2";
    }

    PCF->Release();

    pifile -> CreateThisFile("New File");
    pifold -> CreateFolder("New Folder");
    piinfo -> fileInfo("test");

    std::cout<<"main end!!"<<std::endl;
    
    return 0;
}