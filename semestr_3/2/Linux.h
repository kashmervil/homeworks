#ifndef LINUX_H
#define LINUX_H
#include "OS.h"
class Linux : public OS {
public:
    Linux() : OS()
    {
        security = 4;
    }
    Linux(bool l) : OS(l)
    {
        security = 4;
    }
};

#endif // LINUX_H
