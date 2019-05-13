//
// Created by Mats Almeland on 11.05.2018.
//

#include "functions.h"
#include <iostream>
#include <fstream>
#include <string>
#include "stdlib.h"
using namespace std;


void readCarToVector (vector<car> &CV, string IS){
    ifstream file1(IS.c_str(),ifstream::in);
    string tmp1, tmp2;
    size_t pos;
    car vectorCar;


    if (file1.is_open()){
            while (!file1.eof()) {
                    getline(file1, tmp1);
                    if (tmp1 != "") {
                        pos = tmp1.find(';'); //Finds first ;
                        tmp2 = tmp1.substr(0, pos);
                        vectorCar.setnumber_plate(tmp2); //Sets numberplate value to vectorCar object
                        tmp1 = tmp1.substr(pos + 1);

                        pos = tmp1.find(';'); //Finds second ;
                        tmp2 = tmp1.substr(0, pos);
                        vectorCar.setbuild_year(atoi(tmp2.c_str())); //Sets converted buildyear value to vectorCar object
                        tmp1 = tmp1.substr(pos + 1);

                        pos = tmp1.find(';'); // Finds third ;
                        tmp2 = tmp1.substr(0, pos);
                        vectorCar.setfuel_type(tmp2); //Sets Fueltype value to vectorCar object
                        tmp1 = tmp1.substr(pos + 1);

                        pos = tmp1.find(';'); //Finds forth ;
                        tmp2 = tmp1.substr(0, pos);
                        vectorCar.setkms(stof(tmp2.c_str())); //Sets converted kms value to vectorCar object
                        tmp1 = tmp1.substr(pos + 1);

                        pos = tmp1.find(';'); //Finds fifth and last ;
                        tmp2 = tmp1.substr(0, pos);
                        vectorCar.setrental_price(atoi(tmp2.c_str())); // Sets converted price value to vectorCar object

                        CV.push_back(vectorCar); //Appends all the values of a car object into a vector.
                    }
                }
            }
    file1.close();
}

void readBusToVector (vector<bus> &BV, string IS){
    ifstream file1(IS.c_str(),ifstream::in);
    string tmp1, tmp2;
    size_t pos;
    bus vectorBus;

    if (file1.is_open()){
        while (!file1.eof()) {
            getline(file1, tmp1);
            if (tmp1 != "") {
                pos = tmp1.find(';'); //Finds first ;
                tmp2 = tmp1.substr(0, pos);
                vectorBus.setnumber_plate(tmp2); //Sets numberplate value to vectorBus object
                tmp1 = tmp1.substr(pos + 1);

                pos = tmp1.find(';'); //Finds second ;
                tmp2 = tmp1.substr(0, pos);
                vectorBus.setbuild_year(atoi(tmp2.c_str())); //Sets converted buildyear value to vectorBus object
                tmp1 = tmp1.substr(pos + 1);

                pos = tmp1.find(';'); // Finds third  ;
                tmp2 = tmp1.substr(0, pos);
                vectorBus.setfuel_type(tmp2); //Sets Fueltype value to vectorBus object
                tmp1 = tmp1.substr(pos + 1);

                pos = tmp1.find(';'); //Finds forth  ;
                tmp2 = tmp1.substr(0, pos);
                vectorBus.setkms(stof(tmp2.c_str())); //Sets converted kms value to vectorBus object
                tmp1 = tmp1.substr(pos + 1);

                pos = tmp1.find(';'); //Finds fifth ;
                tmp2 = tmp1.substr(0, pos);
                vectorBus.setrental_price(atoi(tmp2.c_str())); // Sets converted price value to vectorBus object
                tmp1 = tmp1.substr(pos + 1);

                pos = tmp1.find(';'); //Finds sixth and last ; for bus
                tmp2 = tmp1.substr(0, pos);
                vectorBus.set_capacity(atoi(tmp2.c_str())); //Sets converted capacity value to vectorBus object

                BV.push_back(vectorBus); //Appends all the values of a car object into a vector.
            }
        }
    }
    file1.close();
}

void readRentalToVector (vector<rental> &RV, string IS){
    ifstream file1(IS.c_str(),ifstream::in);
    string tmp1, tmp2;
    size_t pos;

    int startdate;
    int enddate;
    string number_plate;
    int build_year;
    string fuel;
    float kms;
    int price;

    if (file1.is_open()){
        while (!file1.eof()) {
            getline(file1, tmp1);
            if (tmp1 != "") {
                pos = tmp1.find(';'); //The same procedure as the above readCar and readBus functions.
                tmp2 = tmp1.substr(0, pos);
                startdate = atoi(tmp2.c_str());
                tmp1 = tmp1.substr(pos + 1);

                pos = tmp1.find(';');
                tmp2 = tmp1.substr(0, pos);
                enddate = atoi(tmp2.c_str());
                tmp1 = tmp1.substr(pos + 1);

                pos = tmp1.find(';');
                tmp2 = tmp1.substr(0, pos);
                number_plate = tmp2;
                tmp1 = tmp1.substr(pos + 1);

                pos = tmp1.find(';');
                tmp2 = tmp1.substr(0, pos);
                build_year=atoi(tmp2.c_str());
                tmp1 = tmp1.substr(pos + 1);

                pos = tmp1.find(';');
                tmp2 = tmp1.substr(0, pos);
                fuel = tmp2;
                tmp1 = tmp1.substr(pos + 1);

                pos = tmp1.find(';');
                tmp2 = tmp1.substr(0, pos);
                kms = stof(tmp2.c_str());
                tmp1 = tmp1.substr(pos + 1);

                pos = tmp1.find('\n');
                tmp2 = tmp1.substr(0, pos);
                price = atoi(tmp2.c_str());

                rental rentalVector(startdate, enddate, number_plate, build_year, fuel, kms, price); //Creates rentalvector

                RV.push_back(rentalVector); //Appends all the values of a car object into a vector.
            }
        }
    }
    file1.close();
}

int countElectric(vector<rental> RV){
    int cnt=0;
    for (int i=0;i<RV.size();i++){
        if(RV[i].get_rentedCar().getfuel_type() == "electric"){ //If the for loop finds keyword "electric" adds 1 to cnt variable.
            cnt++;
        }
    }

    return cnt;
}

int totalIncome(vector<rental> RV){
    int sumTotal = 0;

    for (int i=0;i<RV.size();i++){ //Sums up all the rentalprices
        sumTotal += RV[i].price();
    }

    return sumTotal;
}

/*
void carorbus (vector<int> &SC, string IS){ // This function counts the # of ; in each line of the file
    ifstream file1(IS.c_str(), ifstream::in);// 4 = car and 5 = bus
    string tmp1;
    int cnt=0;

    if (file1.is_open()){
        while(!file1.eof()){
            getline(file1, tmp1); // Put the whole line in tmp
            if(tmp1!=""){
                cnt=0; // Reset the count for each line in the file
                for(int i=0;i<tmp1.size();i++){ //Counts every ; in the line
                    if(tmp1[i] == ';'){
                        cnt++;
                    }
                }SC.push_back(cnt); //Appends the results to SC vector
            }
        }
    }file1.close();

}
*/