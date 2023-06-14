#include "./lib/Interfaces.h"
#include <objbase.h>
#include <iostream>

int main()
{
    std::cout<<"main start"<<std::endl;
    
    CoInitialize(NULL);

    IFSMFactory* PCF = NULL;

    HRESULT resFactory = CoGetClassObject(CLSID_IFSManager, CLSCTX_INPROC_SERVER, NULL, IID_IFSMFactory, (void**) &PCF);

    if (!SUCCEEDED(resFactory))
    {
        std::cout<<"No factory"<<std::endl;
        throw "No factory";
    }

    std::string path = "C:/Users/EUgen/Desktop/Component/component/files";

    IFileManager* pifile = NULL;
    HRESULT resInstance = PCF -> CreateInstance(IID_IFileManager, (void**) &pifile, path);

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


    //Methods----------------------------------------
    std::string folderPath = "C:/Users/EUgen/Desktop/Component/component/files/cppCreatedThis";
    pifold -> CreateFolder(folderPath);

    // pifold -> DeleteFolder(folderPath);

    std::string filePath = "C:/Users/EUgen/Desktop/Component/component/files/cppTest.txt";
    pifile -> CreateThisFile();

    // pifile -> DeleteThisFile(filePath);

    piinfo -> fileInfo();
    //Methods END----------------------------------------

    pifold -> Release();
    pifile -> Release();
    piinfo -> Release();

    std::cout<<"main end!!"<<std::endl;
    
    return 0;
}