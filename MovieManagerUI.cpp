#include "MovieManagerUI.h"
#include <iostream>

using namespace std;

std::string MovieManagerUI::toUpper(std::string upStr) {
    std::string returnStr = "";
    for (int i = 0; i < upStr.length(); i++) {
        returnStr += toupper(upStr[i]);
    }
    return returnStr;
}

void MovieManagerUI::printMenu() {
    std::cout << "am: Add Movie\ndm: Discontinue Movie\nrm: Rent Movie\nrr: Return Rental\np: Print Movie Inventory\nq: Quit Program\n----------\nEnter Command:\n";
}

std::string MovieManagerUI::getCommand() {
    std::string inputCommand;
    while (true) {
        std::cin >> inputCommand;
        inputCommand = toUpper(inputCommand);
        if (inputCommand == "AM" || inputCommand == "DM" || inputCommand == "RM" || inputCommand == "RR" ||inputCommand == "P" || inputCommand == "Q") {
            return inputCommand;
        }
    }
}

std::string MovieManagerUI::getMovieName() {
    std::string movieName;
    std::cin >> movieName;
    return movieName;
}

std::string MovieManagerUI::getMovieCode() {
    std::string movieCode;
    std::cin >> movieCode;
    return movieCode;
}

int MovieManagerUI::getRenterID() {
    int renterID;
    std::cin >> renterID;
    return renterID;
}

std::string MovieManagerUI::getRenterFirstName() {
    std::string firstName;
    std::cin >> firstName;
    return firstName;
}

std::string MovieManagerUI::getRenterLastName() {
    std::string lastName;
    std::cin >> lastName;
    return lastName;
}

void MovieManagerUI::invalidSelection() {
    std::cout << "Invalid command.\n";
}

void MovieManagerUI::enterToContinue() {
    std::cout << "Press enter to continue.\n";
}

void MovieManagerUI::print(std::string toPrint) {
    std::cout << toPrint;
}
