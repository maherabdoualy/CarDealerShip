 #include <iostream>
 #include <string>
 #include "NewCar.h"
 #include "OldCar.h"
 #include <vector>
 #include "Car.h"
 #include <typeinfo>

 using namespace std;

     //old
     OldCar oldcar1("101010","Toyota","Camry",2014,14000,"Old",5000);
     OldCar oldcar2("202020","Nissan","Rogue",2017,20000,"Old",2000);
     OldCar oldcar3("303030","Ford","Fusion",2013,12000,"Old", 10000);
     OldCar oldcar4("404040","Jeep","Renegade", 2018, 18000, "Old", 6000);
     OldCar oldcar5("505050", "Peugeot", "206", 2016, 11000, "Old", 15000);

     //new
     NewCar newcar1("010101","Lamborghini","Huracan",2019,90000,"New", "Provider1");
     NewCar newcar2("020202","Audi", "R8", 2016, 50000,"New","Provider2");
     NewCar newcar3("030303","Renault","Clio",2019, 12000,"New","Provider3");
     NewCar newcar4("040404","Ferarri","Portofino",2020, 100000,"New","Provider4");
     NewCar newcar5("050505","Telsa","Model X", 2017,55000,"New","Provider4");
     
     //add car global variables
     OldCar anOldCar;
     NewCar aNewCar;

     //global vectors
     vector<Car*> cars;
     vector<Car*>::iterator it;
     vector<Car*> leasedCars;

 // INVENTORY FUNCTION
 void inventory(){
     for (it = cars.begin(); it != cars.end(); it++){
        (*it)->printCar();
     }
     cout << endl;
 }


 // SEARCH FUNCTION
 void search(){
     int choice;
     cout << "1. Search by make." << endl;
     cout << "2. Search by model." << endl;
     cout << "3. Search by category." << endl;
     cout << "4. Search by range of price." << endl;
     cout << "Your choice: ";
     cin >> choice;
     cout << endl;
     
     //search by make
     if (choice == 1){
         string make;
         cout << "Enter make: ";
         cin >> make;
         cout << endl;
         for (it = cars.begin(); it != cars.end(); it++){
             if ((*it)->getMake().compare(make) == 0){
                 (*it)->printCar();
             }
         }
     }
     
     else if (choice == 2){
         string model;
         cout << "Enter model: ";
         cin >> model;
         cout << endl;
          for (it = cars.begin(); it != cars.end(); it++){
              if ((*it)->getModel().compare(model) == 0){
                  (*it)->printCar();
              }
          }
     }
     
     else if (choice == 3){
         string category;
         cout << "Enter category: ";
         cin >> category;
         cout << endl;
         for (it = cars.begin(); it != cars.end(); it++){
             if ((*it)->getCategory().compare(category) == 0){
                 (*it)->printCar();
             }
         }
     }
     
     else if (choice == 4){
         int lowerPrice, higherPrice;
         cout << "Enter the lower price: ";
         cin >> lowerPrice;
         cout << endl;
         cout << "Enter the higher price: ";
         cin >> higherPrice;
         cout << endl;
         for (it = cars.begin(); it != cars.end(); it++){
             if (((*it)->getPrice() >= lowerPrice) && ((*it)->getPrice() <= higherPrice)){
                 (*it)->printCar();
             }
         }
     }
     
     else{
         cout << "Choice not valid" << endl;
         search();
     }
     cout << endl;
 }




 void SellOrleaseCar(){
     //lease car
     string make;
     int answer;
     cout <<"Press 0 to lease a car. Press 1 to sell a car: ";
     cin >> answer;
     cout << endl;

     if (answer == 0){
     cout << "Enter the make of the car you want to lease: ";
     cin >> make;
      for (it = cars.begin(); it != cars.end(); it++){
          if ((*it)->getMake().compare(make) == 0){
              leasedCars.push_back((*it));
              cars.erase(it);
              break;
          }
      }
     cout << "Car successfully leased and taken off the inventory." << endl;
     }

     else if (answer == 1){
         cout << "Enter the make of the car you want to sell: ";
         cin >> make;
          for (it = cars.begin(); it != cars.end(); it++){
              if ((*it)->getMake().compare(make) == 0){
                  cars.erase (it);
                  break;
              }
          }
         cout << "Car successfully sold." << endl;
     }

     else {
         SellOrleaseCar();
     }
 }




 void returnCar(){
     for (it = leasedCars.begin(); it != leasedCars.end(); it++){
        (*it)->printCar();
     }
     string make;
        cout << "Enter the make of the car you want to return: ";
        cin >> make;
         for (it = leasedCars.begin(); it != leasedCars.end(); it++){
             if (((*it)->getMake()).compare(make) == 0 ){
                 cars.push_back(*it);
                 leasedCars.erase(it);
                 break;
             }
         }
        cout << "Car successfully return to the inventory." << endl;
 }






 void addCar(){
     string VIN;
     string make;
     string model;
     int year;
     float price;
     string category;
     string warranty;
     int milage;

     int answer;
     cout << "Press 0 to add a new car or 1 to add an old car: ";
     cin >> answer; cout << endl;

 // ADD NEW CAR
     if (answer == 0){
            aNewCar.setCategory("New");
            cout << "Enter the make of the vehicle: ";
            cin >> make;
            aNewCar.setMake(make); cout << endl;
            cout << "Enter the model of the vehicle: ";
            cin >> model;
            aNewCar.setModel(model); cout << endl;
            cout << "Enter the year: ";
            cin >> year;
            aNewCar.setYear(year); cout << endl;
            cout << "Enter the VIN: ";
            cin >> VIN;
            aNewCar.setVIN(VIN); cout << endl;
            cout << "Enter the price: ";
            cin >> price;
            aNewCar.setPrice(price); cout << endl;
            cout << "Enter the warranty provider: ";
            cin >> warranty;
            aNewCar.setWarranty(warranty); cout << endl;


            cars.push_back(&aNewCar);
            cout << "Car successfully added." << endl;
     }

     //ADD OLD CAR
     else if (answer == 1){
            anOldCar.setCategory("Old");
            cout << "Enter the make of the vehicle: ";
            cin >> make;
            anOldCar.setMake(make); cout << endl;
            cout << "Enter the model of the vehicle: ";
            cin >> model;
            anOldCar.setModel(model); cout << endl;
            cout << "Enter the year: ";
            cin >> year;
            anOldCar.setYear(year); cout << endl;
            cout << "Enter the VIN: ";
            cin >> VIN;
            anOldCar.setVIN(VIN); cout << endl;
            cout << "Enter the price: ";
            cin >> price;
            anOldCar.setPrice(price); cout << endl;
            cout << "Enter the milage: ";
            cin >> milage;
            anOldCar.setMilage(milage); cout << endl;


            cars.push_back(&anOldCar);
            cout << "Car successfully added." << endl;
     }
     //if not 0 nor 1
     else{
         addCar();
     }
 }

 void menu(){
     
   
     int option;
     while (option != 6){
         try{
     cout << "================================================= " << endl;
     cout << "Press 1 to show the inventory." << endl;
     cout << "Press 2 to search the inventory." << endl;
     cout << "Press 3 to sell or lease a car." << endl;
     cout << "Press 4 to return a leased car." << endl;
     cout << "Press 5 to add a car to the inventory." << endl;
     cout << "Press 6 to exit..." << endl << endl;
     cout << "Enter your option: ";
     cin >> option;
     cout << endl;
     
         if (option == 1){
             inventory();
         }
         else if (option == 2){
             search();
         }
         else if (option == 3){
             SellOrleaseCar();
         }
         else if (option == 4){
             returnCar();
         }
         else if (option == 5){
             addCar();
         }
         else if (option == 6){
             cout << "PROGRAM ENDED" << endl;
             exit (0);
         }
         else{
             cout <<"Invalid option. Try again." << endl << endl;
         }
         }
         catch (exception e)
         {
             cout << e.what() << endl;
             cin.clear();
             cin >> option;
            
         }
     }

     
 }

 int main(){
      cars.push_back(&oldcar1);
      cars.push_back(&oldcar2);
      cars.push_back(&oldcar3);
      cars.push_back(&oldcar4);
      cars.push_back(&oldcar5);
      cars.push_back(&newcar1);
      cars.push_back(&newcar2);
      cars.push_back(&newcar3);
      cars.push_back(&newcar4);
      cars.push_back(&newcar5);
      
     menu();
 }
