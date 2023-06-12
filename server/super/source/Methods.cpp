#include "./Component.h"


HRESULT FSManager::fileInfo(std::string path)
{
    std::cout<<"FSManager::fileInfo()"<<std::endl;
    return pinfo -> fileInfo(path);
}

HRESULT FSManager::CreateThisFile(std::string path)
{ 
    std::cout<<"FSManager::CreateFile()"<<std::endl;

    HANDLE h = CreateFile(path.c_str(),    // name of the file
                          GENERIC_WRITE, // open for writing
                          (FILE_SHARE_READ | FILE_SHARE_DELETE), // sharing mode
                          NULL,             // use default security descriptor
                          CREATE_NEW, // overwrite if exists
                          FILE_ATTRIBUTE_NORMAL,
                          NULL);
    if (h)
    {
        std::cout << "CreateFile() succeeded\n";
    }
    else
    {
        std::cerr << "CreateFile() failed:" << GetLastError() << "\n";
    }
    std::string strText = "now I can write in the created file))";
    if (strText != "")
    {
        // writing text in created file
        std::cout << "before writing in file\n";
        DWORD bytesWritten;
        WriteFile(
            h,               // Handle to the file
            strText.c_str(), // Buffer to write
            strText.size(),  // Buffer size
            &bytesWritten,   // Bytes written
            nullptr);        // Overlapped

        CloseHandle(h);
        std::cout << "after writing in file\n";
    }

    return S_OK;
}

HRESULT FSManager::DeleteThisFile(std::string path)
{
    std::cout<<"FSManager::DeleteFile"<<std::endl;

    bool success = DeleteFile(path.c_str());

    if(success) 
    {
        std::cout << "DeleteFile() succeeded\n";
    }
    else 
    {
        std::cout << "DeleteFile() error\n";
        if (GetLastError() == ERROR_FILE_NOT_FOUND) 
        {
            std::cout << "File not found\n";
        }
        if (GetLastError() == ERROR_ACCESS_DENIED) 
        {
            std::cout << "Access denied\n";
        }
    }

    return S_OK;  
}
HRESULT FSManager::CreateFolder(std::string path)
{
    std::cout<<"FSManager::CreateFolder"<<std::endl;
    bool success = CreateDirectory(
        path.c_str(),
        NULL
    );

    if(success) 
    {
        std::cout << "CreateFolder() succeeded\n";
    }
    else 
    {
        std::cout << "CreateFolder() error\n";
        if (GetLastError() == ERROR_ALREADY_EXISTS) 
        {
            std::cout << "Folder already exist\n";
        }
        if (GetLastError() == ERROR_PATH_NOT_FOUND) 
        {
            std::cout << "Path not found\n";
        }
    }
    return S_OK;  
}
HRESULT FSManager::DeleteFolder(std::string path)
{
    std::cout<<"FSManager::DeleteFolder"<<std::endl;

    bool success = RemoveDirectory(path.c_str());

    if(success) 
    {
        std::cout << "DeleteFolder() succeeded\n";
    }
    else
    {
        std::cout << "DeleteFolder() error\n";
        if (GetLastError() == ERROR_DIR_NOT_EMPTY) 
        {
            std::cout << "Folder not empty\n";
        }
        
        // find files in directory
        // WIN32_FIND_DATA data;
        // HANDLE hFind = FindFirstFile("C:\\semester2\\*", &data); // DIRECTORY

        // if (hFind != INVALID_HANDLE_VALUE)
        // {
        //     do
        //     {
        //         std::cout << data.cFileName << std::endl;
        //     } while (FindNextFile(hFind, &data));
        //     FindClose(hFind);
        // }
    }

    return S_OK;    
}