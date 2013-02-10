#ifndef WINDOWS_H
#define WINDOWS_H
#include "OS.h"
class Windows : public OS {
public:
    Windows() : OS()
    {
        security = 2;
    }
    Windows(bool l) : OS(l)
    {
        security = 2;
    }
};

#endif // WINDOWS_H
