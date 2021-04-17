#include "NewCar.h"

NewCar::NewCar()
{
    setWarranty("no-warranty");
}

NewCar::NewCar(string v, string ma, string mo, int y, float p, string c, string w):Car(v, ma, mo, y, p, c)
{
    setWarranty(w);
}

void NewCar::setData(string v, string ma, string mo, int y, float p, string c, string w)
{
    Car::setData(v, ma, mo, y, p, c);
    setWarranty(w);
}

void NewCar::setWarranty(string w)
{
    warranty = w;
}

string NewCar::getWarranty() const
{
    return warranty;
}

void NewCar::printCar() const
{
     Car::printCar();
    cout << " Warranty provider: " << NewCar::getWarranty();
    cout << endl;

}
