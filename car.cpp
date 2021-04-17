#include "Car.h"

//CONSTRUCTORS
Car::Car()
{
    setData("no VIN", "no make", "no model", 0, 0.0, "no category");
}

Car::Car(string v, string ma, string mo, int y, float p, string c)
{
    setData(v,ma,mo,y,p,c);
}


//SET FUNCTIONS
void Car::setData(string v, string ma, string mo, int y, float p, string c)
{
     setVIN(v);
     setMake(ma);
     setModel(mo);
     setYear(y);
     setPrice(p);
     setCategory(c);
}

void Car::setVIN(string v)
{
    VIN = v;
}

void Car::setMake(string ma)
{
    make = ma;
}

void Car::setModel(string mo)
{
    model = mo;
}

void Car::setYear(int y)
{
    year = y;
}

void Car::setPrice(float p)
{
    price = p;
}

void Car::setCategory(string c)
{
    category = c;
}


//GET FUNCTIONS
string  Car::getVIN() const
{
    return VIN;
}

string Car::getMake() const
{
    return make;
}

string Car::getModel() const
{
    return model;
}

int Car::getYear() const
{
    return year;
}

float Car::getPrice() const
{
    return price;
}

string Car::getCategory() const
{
    return category;
}

void Car::printCar() const
{
    cout << Car::getCategory() << " " << Car::getMake() << " " << Car::getModel() << " " << Car::getYear() << " ";
    cout << " VIN: " << Car::getVIN() << " Price: " << Car::getPrice();
}



