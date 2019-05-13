//
// Created by Mats Almeland on 26.04.2018.
//
#include <iostream>
#include <string>
#include "car.h"

using namespace std;

#ifndef OOPPROJECT_BUS_H
#define OOPPROJECT_BUS_H


class bus: public car {
public:
    //Construct
    bus();
    bus(string, int, string, float, int, int);

    //Destruct
    virtual ~bus();

    //Getters
    int get_capacity();
    //Setters
    void set_capacity(int);

protected:

private:
    int capacity;
};


#endif //OOPPROJECT_BUS_H
