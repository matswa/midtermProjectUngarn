//
// Created by Mats Almeland on 26.04.2018.
//

#include "car.h"
#include "bus.h"

//Construct
bus::bus() {
    capacity = 0;
}

bus::bus(string np, int by, string fl, float km, int rp, int cap):car(np, by, fl, km, rp) {
    capacity = cap;
}

//Destruct
bus::~bus() {

}
//Getters
int bus::get_capacity(){
    return capacity;
}
//Setter
void bus::set_capacity(int c){
    capacity = c;
}

