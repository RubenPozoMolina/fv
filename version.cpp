#include <windows.h>
#include "version.h"

version::version(const std::__cxx11::string pFileName)
{
    fileName = pFileName;
}

void version::printVersion()
{
    if (getFileVersion()){
        std::cout << fileVersion << std::endl;
    } else {
        std::cout << "Error getting version" << std::endl;
    }
}

bool version::getFileVersion()
{
    fileVersion = "";
    const char* localFilePath = fileName.c_str();
    void* versionInfo = NULL;
    UINT len;
    DWORD infoSize;
    DWORD uselessParm;
    VS_FIXEDFILEINFO* fixedVerInfoPtr;
    bool returnValue = false;

    if ((infoSize = GetFileVersionInfoSizeA (localFilePath, &uselessParm))) {
        versionInfo = malloc (infoSize);
        if (GetFileVersionInfoA (localFilePath, 0, infoSize, versionInfo)){
            if (VerQueryValue (versionInfo, TEXT("\\"), (void **)&fixedVerInfoPtr, &len)){
                /* Get the Product Version */
                sprintf ((char*)versionInfo, "%d.%d.%d.%d",
                         (fixedVerInfoPtr->dwProductVersionMS & 0xffff0000) >> 16,
                         (fixedVerInfoPtr->dwProductVersionMS & 0xffff),
                         (fixedVerInfoPtr->dwProductVersionLS & 0xffff0000) >> 16,
                         (fixedVerInfoPtr->dwProductVersionLS & 0xffff));
                fileVersion = std::string((char*)versionInfo);
                returnValue = true;
            }
        }
    }

    return returnValue;
}
