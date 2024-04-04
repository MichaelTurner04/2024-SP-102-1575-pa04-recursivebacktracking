#include "maze.h"
#include "test_utils.hpp"
#include <ctime>
#include <stdlib.h>

int main(const int argc, const char **argv) {
  return test_wrapper(argc, argv, []() {
    time_t seed;
    srand(time(&seed));

    string *matrix = new string[3]{"###", "###", "###"};
    int r = rand() % 3;
    int c = rand() % 3;

    matrix[r][c] = 'S';

    int row = -1, col = -1;
    try {
      find_start(matrix, 3, row, col);
    } catch (...) {
      cerr << " Exception thrown";
      return false;
    }

    if (row != r || col != c)
      return false;

    return true;
  });
}
