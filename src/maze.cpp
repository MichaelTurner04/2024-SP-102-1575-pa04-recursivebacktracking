/* Here in the .cpp you should define and implement everything declared in the
 * .h file.
 */

#include "maze.h"
#include <string>

string *build_matrix(int rows) {
  string *matrix = new string[rows];
  for (int i = 0; i < rows; ++i) {
    matrix[i] = "";
  }

  return matrix;
}

void fill_matrix(string *matrix, int rows) {
  for (int i = 0; i < rows; ++i) {
    getline(cin, matrix[i]);
  }
}

// Free function!
void print_matrix(const string *matrix, int rows) {
  for (int j = 0; j < rows; j++) {
    cout << matrix[j] << "\n";
  }
}

void delete_matrix(string *&matrix) {
  delete[] matrix;
  matrix = nullptr;
}

void find_start(string *matrix, int rows, int &row, int &col) {
  for (int i = 0; i < rows; ++i) {
    if (matrix[i].find('S') != string::npos) {
      row = i;
      col = static_cast<int>(matrix[i].find('S'));
      return;
    }
  }
}

bool find_exit(string *matrix, int row, int col) {
  if (at_end(matrix, row, col)) {
    return true;
  }

  matrix[row][col] = '@';
  if (valid_move(matrix, row, col, "NORTH") &&
      find_exit(matrix, row - 1, col)) {
    return true;
  }
  if (valid_move(matrix, row, col, "SOUTH") &&
      find_exit(matrix, row + 1, col)) {
    return true;
  }
  if (valid_move(matrix, row, col, "EAST") && find_exit(matrix, row, col + 1)) {
    return true;
  }
  if (valid_move(matrix, row, col, "WEST") && find_exit(matrix, row, col - 1)) {
    return true;
  }
  matrix[row][col] = ' ';
  return false;
}

bool at_end(const string *matrix, int row, int col) {
  if (matrix[row][col] == 'E') {
    return true;
  } else {
    return false;
  }
}

bool valid_move(const string *matrix, int row, int col,
                const string &direction) {
  if (direction == "NORTH") {
    row--;
  } else if (direction == "SOUTH") {
    row++;
  } else if (direction == "EAST") {
    col++;
  } else if (direction == "WEST") {
    col--;
  }
  return (matrix[row][col] == ' ' || matrix[row][col] == 'E');
}