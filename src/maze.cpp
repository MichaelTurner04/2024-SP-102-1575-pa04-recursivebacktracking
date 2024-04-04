/* Here in the .cpp you should define and implement everything declared in the
 * .h file.
 */

#include "maze.h"

string *build_matrix(int rows) {


}

void fill_matrix(string *matrix, int rows) {

}

// Free function!
void print_matrix(const string *matrix, int rows) {
  for (int j = 0; j < rows; j++) {
    cout << matrix[j] << "\n";
  }
}

void delete_matrix(string *&matrix) {

}

void find_start(string *matrix, int rows, int &row, int &col) {

}

bool find_exit(string *matrix, int row, int col) {


}

bool at_end(const string *matrix, int row, int col) {


}

bool valid_move(const string *matrix, int row, int col,
                const string &direction) {


}
