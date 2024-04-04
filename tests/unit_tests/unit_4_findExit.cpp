#include "maze.h"
#include "test_utils.hpp"

int main(const int argc, const char **argv) {
  return test_wrapper(argc, argv, []() {
    string **matrix = new string *[10];
    matrix[0] = new string[3]{"|||||||", "|S   E|", "|||||||"};
    matrix[1] = new string[3]{"|||||||", "|S  |E|", "|||||||"};
    matrix[2] =
        new string[7]{"|||||||||", "|      S|", "||| ||| |", "| |   |||",
                      "| | |||E|", "|       |", "|||||||||"};
    matrix[3] = new string[16]{"||||", "|  |", "|  |", "|S |", "|  |", "|| |",
                               "|| |", "|  |", "|  |", "| ||", "|  |", "|  |",
                               "|  |", "| E|", "|  |", "||||"};
    matrix[4] = new string[7]{"||||||||||||", "|          |", "|       E  |",
                              "|          |", "| S        |", "|          |",
                              "||||||||||||"};
    matrix[5] =
        new string[7]{"|||||||||", "|      S|", "||| ||| |", "| |   |||",
                      "| | |||E|", "|    |  |", "|||||||||"};
    matrix[6] =
        new string[6]{"|||||||||||||", "|       | | |", "| ||| | |E| |",
                      "| | | | ||| |", "|S|   |     |", "|||||||||||||"};
    matrix[7] = new string[8]{"|||||||||||||||||", "|S|   |   |   |E|",
                              "| | | | | | | |||", "| | | | | | | | |",
                              "| | | | | | | | |", "| | | | | | | | |",
                              "|   |   |   |   |", "|||||||||||||||||"};
    matrix[8] =
        new string[6]{"|||||||||||||", "| | ||| | | |", "| |   |     |",
                      "| ||| | | | |", "|S      |E| |", "|||||||||||||"};
    matrix[9] =
        new string[6]{"|||||||||||||", "| | ||| | | |", "| |   |     |",
                      "| ||| | ||| |", "|S      |E| |", "|||||||||||||"};

    bool values[10] = {true,  false, true,  true, true,
                       false, false, false, true, false};
    int start_row[10] = {1, 1, 1, 3, 4, 1, 4, 1, 4, 4};
    int start_col[10] = {1, 1, 7, 1, 2, 7, 1, 1, 1, 1};
    int matrix_rows[10] = {3, 3, 7, 16, 7, 7, 6, 8, 6, 6};

    int maze_tracker = 0;

    try {
      for (int i = 0; i < 10; i++) {
        maze_tracker = i;
        if (find_exit(matrix[i], start_row[i], start_col[i]) != values[i]) {
          cout << "Your find_exit function didn't return the correct value for "
                  "maze "
               << i
               << "\nHere is what the maze looks like after running "
                  "find_exit:\n";
          cout << "Start coords: Row " << start_row[i] << " Column "
               << start_col[i] << endl;
          print_matrix(matrix[i], matrix_rows[i]);
          return false;
        }
      }
    } catch (...) {
      cout << "Exception thrown on maze " << maze_tracker
           << ". This means your find_exit function is broken.\n";
      cout << "Here is what the maze looks like after running "
              "find_exit:\n";
      cout << "Start coords: Row " << start_row[maze_tracker] << " Column "
           << start_col[maze_tracker] << endl;
      try {
        print_matrix(matrix[maze_tracker], matrix_rows[maze_tracker]);
      } catch (...) {
        cout << "Exception thrown while trying to use print_matrix function.\n";
      }
      return false;
    }

    return true;
  });
}

// Maze 0 (True)

// #######
// #S   E#
// #######

// Maze 1 (False)

// #######
// #S  #E#
// #######

// Maze 2 (True)

// #########
// #      S#
// ### ### #
// # #   ###
// # # ###E#
// #       #
// #########

// Maze 3 (True)

// ####
// #  #
// #  #
// #S #
// #  #
// ## #
// ## #
// #  #
// #  #
// # ##
// #  #
// #  #
// #  #
// # E#
// #  #
// ####

// Maze 4 (True)

// ############
// #          #
// #       E  #
// #          #
// # S        #
// #          #
// ############

// Maze 5 (False)

// #########
// #      S#
// ### ### #
// # #   ###
// # # ###E#
// #    #  #
// #########

// Maze 6 (False)

// #############
// #       # # #
// # ### # #E# #
// # # # # ### #
// #S#   #     #
// #############

// Maze 7 (False)

// #################
// #S#   #   #   #E#
// # # # # # # # ###
// # # # # # # # # #
// # # # # # # # # #
// # # # # # # # # #
// #   #   #   #   #
// #################

// Maze 8 (True)

// #############
// # # ### # # #
// # #   #     #
// # ### # # # #
// #S      #E# #
// #############

// Maze 9 (False)

// #############
// # # ### # # #
// # #   #     #
// # ### # ### #
// #S      #E# #
// #############
