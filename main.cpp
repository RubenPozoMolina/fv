#include "version.h"

int main(int argc, char *argv[])
{
    if (argc!=2){
        std::cout << "usage: fv {path to file} " << std::endl;
    } else {
        version *fv = new version(argv[1]);
        fv->printVersion();
        delete fv;
    }
}
