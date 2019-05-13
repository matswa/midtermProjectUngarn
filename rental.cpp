//
// Created by Mats Almeland on 26.04.2018.
//

#include "rental.h"
#include "car.h"

//construct
rental::rental(){
    start_d = 0;
    end_d = 0;
    rented_car = car();
}
rental::rental(int sd, int ed ,car rentc){
    if(check_date(sd, ed)){ //Error checking dates
        start_d = sd;
        end_d = ed;
        rented_car = rentc;
    }
    else{
        throw car::WrongDateInput; //Error checking dates
    }

}
rental::rental(int sd, int ed, string np, int by, string ft, float km, int rp){
    start_d = sd;
    end_d = ed;
    rented_car.setnumber_plate(np);
    rented_car.setbuild_year(by);
    rented_car.setfuel_type(ft);
    rented_car.setkms(km);
    rented_car.setrental_price(rp);
}

//destruct
rental::~rental(){

}

//Getters
int rental::get_startD(){
    return start_d;
}
int rental::get_endD(){
    return end_d;
}

car rental::get_rentedCar(){
    return rented_car;
}

//Setter
void rental::set_startD(int sd){
    start_d = sd;
}

void rental::set_endD(int ed){
    end_d = ed;
}

void rental::set_rentedCar(car rentcar){
    rented_car = rentcar;
}

//Class functions
int rental::length_of_rental(){
    return (end_d-start_d);
}
int rental::price(){
    return (rented_car.getrental_price()*length_of_rental());
}
bool rental::check_date(int sd, int ed) { //Used for checking if dates are correct
    if(ed>=sd) {
        return true;
    } else{return false;}
}