#include "maze.h"
#include "test_utils.hpp"
#include <ctime>
#include <stdlib.h>

int main(const int argc, const char **argv) {
  return test_wrapper(argc, argv, []() {
    time_t seed;
    srand(time(&seed));

    string *matrix = new string[3]{"###", "###", "###"};
    matrix[1][1] = 'E';

    if (at_end(matrix, 1, 1) == false) {
      cout << "Failed to identify 'E' as exit charater" << endl;
      return false;
    }

    if (at_end(matrix, 0, 0))
      return false;

    for (int i = 0; i < 3; i++) {
      for (int j = 0; j < 3; j++) {
        if (at_end(matrix, i, j) && !(i == 1 && j == 1)) {
          cout << "Falsely identified '#' as exit character" << endl;
          return false;
        }
      }
    }

    return true;
  });
}
