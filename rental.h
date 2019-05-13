//
// Created by Mats Almeland on 26.04.2018.
//
#include <iostream>
#include <string>
#include "car.h"
using namespace std;


#ifndef OOPPROJECT_RENTAL_H
#define OOPPROJECT_RENTAL_H


class rental {
public:
    //construct
    rental();
    rental(int, int ,car);
    rental(int, int, string, int, string, float, int);

    //destruct
    virtual ~rental();

    //Getters
    int get_startD();
    int get_endD();
    car get_rentedCar();

    //Setter
    void set_startD(int);
    void set_endD(int);
    void set_rentedCar(car rentcar);

    //class functions
    int length_of_rental();
    int price();
    bool check_date(int, int);

protected:
    int start_d;
    int end_d;
    car rented_car;
private:
};


#endif //OOPPROJECT_RENTAL_H
