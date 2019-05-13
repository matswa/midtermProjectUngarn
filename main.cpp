#include <iostream>
#include <vector>
#include "car.h"
#include "bus.h"
#include "rental.h"
#include "functions.h"

//I have changed my task L to task A after we discussed the issue with task L in consultation.

using namespace std;

int main() {
    vector<car> carVector;
    vector<bus> busVector;
    vector<rental> rentalVector;
    string inputcar = "inputcar.txt";
    string inputbus = "inputbus.txt";
    string inputrental = "inputrental.txt";
    string output = "output.txt";
    int cnt;
    int total;

    try {
        readCarToVector(carVector, inputcar);

        for (int i=0;i<carVector.size();i++){ //Show that the readCarToVector works
            cout << carVector[i].getnumber_plate() << ";";
            cout << carVector[i].getbuild_year() << ";";
            cout << carVector[i].getfuel_type()<< ";";
            cout << carVector[i].getkms()<< ";";
            cout << carVector[i].getrental_price() << endl;
        }

        cout << "--------------------------------------" << endl;


        readBusToVector(busVector, inputbus);

        for (int i=0;i<busVector.size();i++){ //Shows that the readBusToVector works
            cout << busVector[i].getnumber_plate() << ";";
            cout << busVector[i].getbuild_year() << ";";
            cout << busVector[i].getfuel_type()<< ";";
            cout << busVector[i].getkms()<< ";";
            cout << busVector[i].getrental_price() << ";";
            cout << busVector[i].get_capacity() << endl;
        }

        cout << "-------------------------------------" << endl;

        readRentalToVector(rentalVector, inputrental);

        for (int i=0;i<rentalVector.size();i++){ //Shows examples of lengt_of_rental and price
            cout << rentalVector[i].get_startD() << ";";
            cout << rentalVector[i].get_endD() << ";";
            cout << rentalVector[i].length_of_rental() << ";";
            cout << rentalVector[i].price() << endl;
        }
        cout << "--------------------------------------" << endl;
        //Shows an example of the + oprator
        car c1;
        int addkm = 2000;

        car c2 = c1 + addkm;

        cout << c2.getkms() << endl;

        cout << "--------------------------------------" << endl;

        total = totalIncome(rentalVector); //Task A

        cout <<"The total income was " << total << endl;

        cout << "--------------------------------------" << endl;

        cnt = countElectric(rentalVector); //Task D

        cout << "The # of electric cars rented is " << cnt << endl;




    }catch (car::Errormessage e){ //Different outputs if an error occure
        if (e==car::WrongFuelInput) {
            cout << "Wrong fuel type entered!" << endl;
        }
        if (e==car::WrongDateInput) {
            cout << "Invalid dates entered" << endl;
        }
    }



    return 0;
}