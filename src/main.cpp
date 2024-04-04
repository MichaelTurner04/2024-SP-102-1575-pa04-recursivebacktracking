/* Declare any non-required functions above main.
 * The duty of main here is to interact with the user, take in input, and manage
 * wrapping output and runtime. Remember, if you are considering putting
 * something in main or a function, double check the specifications. Each
 * function should only do what it is specified to do, and no more.
 */

#include "maze.h"

int main() {

  bool keep_going = true;
  int rows;
  string *matrix;
  int matrix_num = 0;
  int row, col;
  bool solved_maze;

  while (keep_going) {
    cin >> rows;
    cin.ignore();

    if (rows != 0) {
      matrix = build_matrix(rows);
      fill_matrix(matrix, rows);
      find_start(matrix, rows, row, col);
      solved_maze = find_exit(matrix, row, col);

      matrix[row][col] = 'S';

      cout << "Map " << matrix_num << " -- ";

      if (!solved_maze)
        cout << "No solution found:\n";
      else
        cout << "Solution found:\n";

      print_matrix(matrix, rows);

      cout << endl;

      delete_matrix(matrix);

      matrix_num++;
    } else {
      keep_going = false;
    }
  }

  return 0;
}
