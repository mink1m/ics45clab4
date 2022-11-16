#include "Movie.h"
#include <iostream>

using namespace std;

Movie::Movie(std::string inputCode, std::string inputName) {
    movieCode = inputCode;
    movieName = inputName;
}

Movie::Movie() {
    movieCode = "";
    movieName = "";
}

void Movie::setMovieCode(std::string inputCode) {
    this->movieCode = inputCode;
}

std::string Movie::getMovieCode() {
    return movieCode;
}

void Movie::setMovieName(std::string inputName) {
    this->movieName = inputName;
}

std::string Movie::getMovieName() {
    return movieName;
}

void Movie::rentMovie(Renter inputRent) {
    if (renters.size() >= 10) {
        throw RenterLimitException();
    }
    for (int i = 0; i < renters.size(); i++) {
        if (renters[i].getRenterID() == inputRent.getRenterID()) {
            throw DuplicateRenterException();
        }
    }
    renters.push_back(inputRent);
}

void Movie::returnRental(int inputID) {
    if (renters.size() == 0) {
        throw EmptyRenterListException();
    }
    int checker = 1;
    for (int i = 0; i < renters.size(); i++) {
        if (renters[i].getRenterID() == inputID) {
            checker = 0;
            renters.erase(renters.begin() + i);
        }
    }
    if (checker == 1) {
        throw RenterNotFoundException();
    }
}

bool Movie::isBeingRented() {
    if (renters.size() == 0) {
        return false;
    }
    else {
        return true;
    }
}

void Movie::printMovieInfo() {
    std::cout << movieCode << "\n" << movieName << "\n";
    for (int i = 0; i <= renters.size(); i++) {
        std::cout << renters[i].getRenterID() << renters[i].getRenterFirstName() << renters[i].getRenterLastName();
    }
}
