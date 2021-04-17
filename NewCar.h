#ifndef NewCar_H
#define NewCar_H
#include <iostream>
#include <string>
#include "Car.h"

using namespace std;

class  NewCar : public Car
{
public:
    NewCar();
    NewCar(string, string, string, int, float, string, string);
    void setData(string, string, string, int, float, string, string);
    void setWarranty(string);
    string getWarranty() const;
    void printCar() const;
    
private:
    string warranty;
    
    // double wingSpan;
};

#endif // !NewCar_H
