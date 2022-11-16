#include "CustomException.h"

using namespace std;

const char* DuplicateMovieException::what() {
  return "duplicate movie\n";
}

const char* DuplicateRenterException::what() {
  return "duplicate renter\n";
}

const char* EmptyMovieInfoException::what() {
  return "empty movie info\n";
}

const char* EmptyMovieListException::what() {
  return "empty movie list\n";
}

const char* EmptyRenterListException::what() {
  return "empty renter list\n";
}

const char* EmptyRenterNameException::what() {
  return "empty renter name\n";
}

const char* InvalidRenterIDException::what() {
  return "invalid renter id\n";
}

const char* MovieLimitException::what() {
  return "movie limit exceeded\n";
}

const char* MovieNotFoundException::what() {
  return "movie not found\n";
}

const char* RentedMovieException::what() {
  return "movie is rented\n";
}

const char* RenterLimitException::what() {
  return "renter limit exceeded\n";
}

const char* RenterNotFoundException::what() {
  return "renter not found\n";
}


