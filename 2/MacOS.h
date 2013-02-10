#ifndef MACOS_H
#define MACOS_H
#include "OS.h"
class MacOS : public OS {
public:
    MacOS() : OS()
    {
        security = 3;
    }
    MacOS(bool l) : OS(l)
    {
        security = 3;
    }
};

#endif // MACOS_H
