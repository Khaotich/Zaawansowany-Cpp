#ifndef TANK_H
#define TANK_H

//#include <mutex>

class Tank
{
private:
    unsigned int fuel;
    
public:
    Tank(unsigned int fuel_) : fuel(fuel_) {};
    unsigned int download(unsigned int fuelToDownload);
};
#endif //TANK_H