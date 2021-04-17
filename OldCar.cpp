#include "OldCar.h"

OldCar::OldCar()
{
    setMilage(0);
}
   OldCar::OldCar(string v, string ma, string mo, int y, float p, string c, int m):Car(v, ma, mo, y, p, c)
    {
        setMilage(m);
    }


   void OldCar::setData(string v, string ma, string mo, int y, float p, string c, int m)
{
    Car::setData(v, ma, mo, y, p, c);
    setMilage(m);
}

   void OldCar::setMilage(int m)
{
    milage = m;
}

   int OldCar::getMilage() const
{
    return milage;
}

   void OldCar::printCar() const
{
    Car::printCar();
   cout << " Milage: " <<  OldCar::getMilage();
    cout <<endl;
}
