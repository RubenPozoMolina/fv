#ifndef VERSION_H
#define VERSION_H

#include <iostream>

class version
{
public:
    version(const std::string pFileName );
    void printVersion();
    bool getFileVersion();
private:
    std::string fileName;
    std::string fileVersion;
};

#endif // VERSION_H
