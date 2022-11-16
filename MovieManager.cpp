#include "MovieManager.h"

using namespace std;

void MovieManager::run() {
    // catch exceptions here
    while (true)
    {
        try {
            mmUI.printMenu();
            std::string command = mmUI.getCommand();
            if (command == "AM") {
                std::string mName = mmUI.getMovieName();
                std::string mCode = mmUI.getMovieCode();
                Movie inputMovie;
                inputMovie = Movie(mCode, mName);
                addMovie(inputMovie);
            }
            if (command == "DM") {
                std::string mCode = mmUI.getMovieCode();
                discontinueMovie(mCode);
            }
            if (command == "RM") {
                std::string mCode = mmUI.getMovieCode();
                int rID = mmUI.getRenterID();
                std::string rFN = mmUI.getRenterFirstName();
                std::string rLN = mmUI.getRenterLastName();
                Renter inputRenter;
                inputRenter = Renter(rID, rFN, rLN);
                rentMovie(mCode, inputRenter);
            }
            if (command == "RR") {
                std::string mCode = mmUI.getMovieCode();
                int rID = mmUI.getRenterID();
                returnRental(rID, mCode);
            }
            if (command == "P") {
                printInventory();
            }
            if (command == "Q") {
                break;
            }
        }
        catch (std::exception& ex) {
            std::cout << ex.what();
        }
    }    
}

void MovieManager::addMovie(Movie movieToAdd) {
    if (movies.size() >= 20) {
        throw MovieLimitException();
    }
    if (movieToAdd.getMovieCode() == "" || movieToAdd.getMovieName() == "") {
        throw EmptyMovieInfoException();
    }
    for (int i = 0; i < movies.size(); i++) {
        if (movies[i].getMovieCode() == movieToAdd.getMovieCode() || movies[i].getMovieName() == movieToAdd.getMovieName()) {
            throw DuplicateMovieException();
        }
    }
    movies.push_back(movieToAdd);
}

void MovieManager::discontinueMovie(std::string mCode) {
    if (movies.size() == 0) {
        throw EmptyMovieListException();
    }
    int checker = 0;
    int ele = 0;
    for (int i = 0; i < movies.size(); i++) {
        if (movies[i].getMovieCode() == mCode) {
            checker = 1;
            if (movies[i].isBeingRented()) {
                throw RentedMovieException();
            }
            ele = i;
        }
    }
    if (checker == 0) {
        throw MovieNotFoundException();
    }
    movies.erase(movies.begin() + ele);
}

void MovieManager::rentMovie(std::string mCode, Renter s) {
    if (s.getRenterID() < 0) {
        throw InvalidRenterIDException();
    }
    if (s.getRenterFirstName() == "" || s.getRenterLastName() == "") {
        throw EmptyRenterNameException();
    }
    int checker = 0;
    for (int i = 0; i < movies.size(); i++) {
        if (movies[i].getMovieCode() == mCode) {
            checker = 1;
            movies[i].rentMovie(s);
        }
    }
    if (checker == 0) {
        throw MovieNotFoundException();
    }
}

void MovieManager::returnRental(int returnID, std::string mCode) {
    if (returnID < 0) {
        throw InvalidRenterIDException();
    }
    int checker = 0;
    for (int i = 0; i < movies.size(); i++) {
        if (movies[i].getMovieCode() == mCode) {
            checker = 1;
            movies[i].returnRental(returnID);
        }
    }
    if (checker == 0) {
        throw MovieNotFoundException();
    }
}

void MovieManager::printInventory() {
    for (int i = 0; i < movies.size(); i++) {
        std::cout << movies[i].getMovieCode() << movies[i].getMovieName();
    }
}
