#ifndef OS_H
#define OS_H
#pragma once
class OS{
public:
    int getSec()
    {
        return security;//value from 1 to 5 of system's security efficient
                //1- system is totaly incapable for protection
                //5- none virus can destroy it
    }
    bool getInfect()
    {
        return isInfected;
    }
    void setInfect(bool l)
    {
        isInfected = l;
    }
    OS() : isInfected(false)
    {}
    OS(bool t) : isInfected(t)
    {}
protected:
    bool isInfected;
    int security;

};
#endif // OS_H
