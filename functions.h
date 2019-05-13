//
// Created by Mats Almeland on 11.05.2018.
//
#include <vector>
#include "car.h"
#include "bus.h"
#include "rental.h"

using namespace std;

#ifndef OOPPROJECT_FUNCTIONS_H
#define OOPPROJECT_FUNCTIONS_H

#endif //OOPPROJECT_FUNCTIONS_H

void readCarToVector (vector<car> &CV, string IS);

void readBusToVector (vector<bus> &BV, string IS);

void readRentalToVector (vector<rental> &RV, string IS);

int countElectric(vector<rental> RV);

int totalIncome(vector<rental> RV);

//void carorbus (vector<int> &SC, string IS);