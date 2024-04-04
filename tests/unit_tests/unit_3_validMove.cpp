#include "maze.h"
#include "test_utils.hpp"
#include <ctime>
#include <stdlib.h>

int main(const int argc, const char **argv) {
  return test_wrapper(argc, argv, []() {
    time_t seed;
    srand(time(&seed));

    string *matrix = new string[3]{"|||", "|S@", "| |"};

    if (valid_move(matrix, 1, 1, "NORTH")) {
      cout << "Failed because moving 'NORTH' onto '|' was considered valid."
           << endl;
      return false;
    }
    if (valid_move(matrix, 1, 1, "EAST")) {
      cout << "Failed because moving 'EAST' onto '|' was considered valid."
           << endl;
      return false;
    }
    if (valid_move(matrix, 1, 1, "WEST")) {
      cout << "Failed because moving 'WEST' onto '|' was considered valid."
           << endl;
      return false;
    }
    if (valid_move(matrix, 1, 1, "SOUTH") == false) {
      cout << "Failed because moving 'SOUTH' onto ' ' was considered invalid."
           << endl;
      return false;
    }

    string directions[] = {"NORTH", "EAST", "WEST", "SOUTH"};

    matrix[0] = "   ";
    matrix[1] = " S ";
    matrix[2] = "   ";
    for (int i = 0; i < 4; i++) {
      if (!valid_move(matrix, 1, 1, directions[i])) {
        cout << "Failed because moving '" << directions[i]
             << "' onto ' ' was not considered valid." << endl;
        return false;
      }
    }

    matrix[0] = " @ ";
    matrix[1] = "@S@";
    matrix[2] = " @ ";
    for (int i = 0; i < 4; i++) {
      if (valid_move(matrix, 1, 1, directions[i])) {
        cout << "Failed because moving '" << directions[i]
             << "' onto '@' was considered valid." << endl;
        return false;
      }
    }

    matrix[0] = " S ";
    matrix[1] = "SSS";
    matrix[2] = " S ";
    for (int i = 0; i < 4; i++) {
      if (valid_move(matrix, 1, 1, directions[i])) {
        cout << "Failed because moving '" << directions[i]
             << "' onto 'S' was considered valid." << endl;
        return false;
      }
    }

    matrix[0] = " E ";
    matrix[1] = "ESE";
    matrix[2] = " E ";
    for (int i = 0; i < 4; i++) {
      if (!valid_move(matrix, 1, 1, directions[i])) {
        cout << "Failed because moving '" << directions[i]
             << "' onto ' ' was considered valid." << endl;
        return false;
      }
    }

    return true;
  });
}
