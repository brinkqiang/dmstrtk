
#include "dmstrtk.h"

int main( int argc, char* argv[] ) {

    Idmstrtk* module = dmstrtkGetModule();
    if (module)
    {
        module->Test();
        module->Release();
    }
    return 0;
}
