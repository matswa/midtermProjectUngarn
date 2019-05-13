//
// Created by Mats Almeland on 26.04.2018.
//
#include <iostream>
#include <string>

using namespace std;


#ifndef OOPPROJECT_CAR_H
#define OOPPROJECT_CAR_H

class car {
public:
    enum Errormessage {WrongFuelInput, WrongDateInput};

    //construct
    car();
    car(string, int, string, float, int);

    //destruct
    virtual ~car();

    //Getters
    string getnumber_plate();
    int getbuild_year();
    string getfuel_type();
    float getkms();
    int getrental_price();

    //Setters
    void setnumber_plate(string);
    void setbuild_year(int);
    void setfuel_type(string);
    void setkms(float);
    void setrental_price(int);

    //operator
    car operator+(int addkm) const;

    //Function for cheching fueltype
    bool correct_fuel(string);

protected:
    string number_plate;
    int build_year;
    string fuel_type;
    float kms;
    int rental_price;

private:

};


#endif //OOPPROJECT_CAR_H
