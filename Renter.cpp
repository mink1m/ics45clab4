#include "Renter.h"

using namespace std;

Renter::Renter(int input_renterID, std::string input_firstName, std::string input_lastName) {
    renterID = input_renterID;
    renterFirstName = input_firstName;
    renterLastName = input_lastName;
}

Renter::Renter() {
    renterID = 0;
    renterFirstName = "";
    renterLastName = "";
}

void Renter::setRenterID(int inputID) {
    this->renterID = inputID; 
}

int Renter::getRenterID() {
    return renterID;
}

void Renter::setRenterFirstName(std::string inputFirst) {
    this->renterFirstName = inputFirst;
}

std::string Renter::getRenterFirstName() {
    return renterFirstName;
}

void Renter::setRenterLastName(std::string inputLast) {
    this->renterLastName = inputLast;
}

std::string Renter::getRenterLastName() {
    return renterLastName;
}