#include "maze.h"
#include "test_utils.hpp"
#include <ctime>
#include <stdlib.h>

int main(const int argc, const char **argv) {
  return test_wrapper(argc, argv, []() {
    time_t seed;
    srand(time(&seed));

    int rows = rand() % 3 + 3;
    string *matrix = build_matrix(rows);

    for (int i = 0; i < rows; i++) {
      if (matrix[i] != "")
        return false;
    }

    return true;
  });
}
