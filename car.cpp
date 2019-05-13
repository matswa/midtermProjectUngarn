//
// Created by Mats Almeland on 26.04.2018.
//

#include "car.h"

using namespace std;


//construct
car::car(){
    number_plate = "";
    build_year = 0;
    fuel_type= "gas";
    kms = 0.0;
    rental_price = 0;
}
car::car(string np, int by, string ft, float km, int rp){
    if(correct_fuel(ft)){ //Error checking fuel input
        number_plate = np;
        build_year = by;
        fuel_type = ft;
        kms = km;
        rental_price = rp;
    } else{
        throw WrongFuelInput; //Error checking fuel input
    }

}


//destruct
car::~car(){

}

//Getters
string car::getnumber_plate(){
    return number_plate;
}
int car::getbuild_year(){
    return build_year;
}
string car::getfuel_type(){
    return fuel_type;
}
float car::getkms(){
    return kms;
}
int car::getrental_price(){
    return rental_price;
}

//Setters
void car::setnumber_plate(string np){
    number_plate = np;
}
void car::setbuild_year(int by){
    build_year = by;
}
void car::setfuel_type(string ft){
    if(correct_fuel(ft)){ //Error checking fuel input
        fuel_type = ft;
    } else{
        throw WrongFuelInput; //Error checking fuel input
    }

}
void car::setkms(float km){
    kms = km;
}
void car::setrental_price(int rp){
    rental_price = rp;
}
//Operator

car car::operator+(int addkm) const {
    int newkm = kms + addkm;
    return car(number_plate, build_year, fuel_type, newkm, rental_price);
}


bool car::correct_fuel(string s) {
    if (s=="gas"){
        return true;
    }
    else if(s=="diesel"){
        return true;
    }
    else if(s=="hybrid"){
        return true;
    }
    else if(s=="electric"){
        return true;
    }
    else{return false;}

}