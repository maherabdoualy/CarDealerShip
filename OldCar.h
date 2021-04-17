#ifndef OldCar_H
#define OldCar_H
#include <iostream>
#include <string>
#include "Car.h"

using namespace std;

class  OldCar : public Car
{
public:
    OldCar();
     OldCar(string, string, string, int, float, string, int);
    void setData(string, string, string, int, float, string, int);
    void setMilage(int);
    int getMilage() const;
    void printCar() const;
    
private:
    int milage;
    
  
};

#endif // !OLDCAR_H
