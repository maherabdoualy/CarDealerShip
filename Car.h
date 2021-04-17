#ifndef CAR_H
#define CAR_H
#include <iostream>
#include <string>

using namespace std;

class Car
{
public:
    Car();
    Car(string, string, string, int, float, string);
    void setData(string, string, string, int, float, string);
    void setVIN(string);
    void setMake(string);
    void setModel(string);
    void setYear(int);
    void setPrice(float);
    void setCategory(string);
    
    string getVIN() const;
    string getMake() const;
    string getModel() const;
    int getYear() const;
    float getPrice() const;
    string getCategory() const;
    virtual void printCar() const;
    
private:
    string VIN;
    string make;
    string model;
    int year;
    float price;
    string category;
};

#endif // ! CAR_H
