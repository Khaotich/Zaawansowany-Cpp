#include "tank.h"

using namespace std;

unsigned int Tank::download(unsigned int fuelToDownload)
{
   if(fuel < fuelToDownload) return 0;
   else
   {
       fuel -= fuelToDownload;
       return fuel;
   }
}
