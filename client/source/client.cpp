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
    HRESULT resInstance = PCF -> CreateInstance(NULL, IID_IFileManager, (void**) &pifile);

    if (!SUCCEEDED(resInstance))
    {
        std::cout<<"No instance"<<std::endl;
        throw "No instance";
    }

    IFolderManager* pifold = NULL;
    HRESULT resQuery = pifile -> QueryInterface(IID_IFolderManager, (void**) &pifold);

    if (!SUCCEEDED(resQuery))
    {
        std::cout<<"No QueryInterface"<<std::endl;
        throw "No QueryInterface";
    }
    
    IFSMInfo* piinfo = NULL;
    HRESULT resQuery2 = pifold -> QueryInterface(IID_IFSMInfo, (void**) &piinfo);

    if (!SUCCEEDED(resQuery2))
    {
        std::cout<<"No QueryInterface 2"<<std::endl;
        throw "No QueryInterface 2";
    }

    PCF->Release();

    std::string folderPath = "C:/Users/EUgen/Desktop/Component/component/files/cppCreatedThis";
    pifold -> CreateFolder(folderPath);

    // pifold -> DeleteFolder(folderPath);

    std::string filePath = "C:/Users/EUgen/Desktop/Component/component/files/cppTest.txt";
    pifile -> CreateThisFile(filePath);

    // pifile -> DeleteThisFile(filePath);

    piinfo -> fileInfo(filePath);

    pifold -> Release();
    pifile -> Release();
    piinfo -> Release();

    std::cout<<"main end!!"<<std::endl;
    
    return 0;
}