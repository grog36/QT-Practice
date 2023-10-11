//The tic tac toe game class
#include "coordinate.h"
#include <vector>

class Game {
    private:
        std::vector<Coordinate> emptySpaces = {Coordinate(0, 0), Coordinate(1, 0), Coordinate(2, 0),
            Coordinate(0, 1), Coordinate(1, 1), Coordinate(2, 1),
            Coordinate(0, 2), Coordinate(1, 2), Coordinate(2, 2)};
        std::vector<std::vector<char>> grid;
        char player1Marker = 'X';
        char player2Marker = 'O';
        char whoseTurn = 'X';
        

        std::string boolToString(bool b) {
            return ((b == true) ? "true": "false");
        }

    public:
        Game(int whoGoesFirst) {
            if (whoGoesFirst == 1 || whoGoesFirst == 2) {
                for (int i = 0; i < 3; i++) {
                    std::vector<char> row;
                    row.push_back(' ');
                    row.push_back(' ');
                    row.push_back(' ');
                    grid.push_back(row);
                }
                whoseTurn = ((whoGoesFirst == 1) ? 'X' : 'O');
            }
            else {
                //Print error message
            }
        }

        std::vector<Coordinate> getEmptySpaces() {
            return emptySpaces;
        }

        std::vector<std::vector<char>> getGrid() {
            return grid;
        }

        std::string toString() {
            std::string output = "";
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    output += "[";
                    output += grid[i][j];
                    output += "] ";
                }
                output += "\n";
            }
            return output;
        }

        char getPlayer1Marker() {
            return player1Marker;
        }
        char getPlayer2Marker() {
            return player2Marker;
        }
        char getWhoseTurn() {
            return whoseTurn;
        }

        bool checkForWin(char playerMarker) {
            //Checks rows and columns
            for (int i = 0; i < 3; i++) {
                if (grid[i][0] == grid[i][1] && grid[i][1] == grid[i][2]) {
                    if (grid[i][0] == playerMarker) {
                        return true;
                    }
                }
                else if (grid[0][i] == grid[1][i] && grid[1][i] == grid[2][i]) {
                    if (grid[0][i] == playerMarker) {
                        return true;
                    }
                }
            }

            //Checks diagonals
            if ((grid[0][0] == grid[1][1] && grid[1][1] == grid[2][2]) ||
                (grid[0][2] == grid[1][1] && grid[1][1] == grid[2][0])) {
                    if (grid[1][1] == playerMarker) {
                        return true;
                    }
            }
            //No win
            return false;
        }

        bool checkForTie() {
            if (checkForWin(player1Marker) == false && checkForWin(player2Marker) == false &&
                emptySpaces.size() == 0) {
                    return true;
            }
            return false;
        }

        bool playMove(int rowIndex, int colIndex) {
            if (!(checkForWin(player1Marker) || checkForWin(player2Marker) || checkForTie())) {
                for (unsigned int i = 0; i < emptySpaces.size(); i++) {
                    Coordinate c = emptySpaces.at(i);
                    if (c.getRowIndex() == rowIndex && c.getColumnIndex() == colIndex) {
                        grid[rowIndex][colIndex] = whoseTurn;
                        whoseTurn = (whoseTurn == 'X') ? 'O' : 'X';
                        emptySpaces.erase(emptySpaces.begin() + i);
                        return true;
                    }
                }
            }
            return false;
        }

        char getPlayerMarkerAt(int rowIndex, int colIndex) {
            if (rowIndex >= 0 && rowIndex <= 3 && colIndex >= 0 && colIndex <= 3) {
                return grid[rowIndex][colIndex];
            }
            return ' ';
        }

        std::string getStatus() {
            std::string output = toString();
            output = output + "Player1Marker: " + player1Marker;
            output = output + "\nPlayer2Marker: " + player2Marker;
            output = output + "\nWhose Turn: " + whoseTurn;
            output = output + "\nPlayer 1 Win: " + boolToString(checkForWin(player1Marker));
            output = output + "\nPlayer 2 Win: " + boolToString(checkForWin(player2Marker));
            output = output + "\nTie: " + boolToString(checkForTie());
            output = output + "\nRemaining Moves: [";
            for (int i = 0; i < ((int) emptySpaces.size()); i++) {
                Coordinate e = emptySpaces.at(i);
                output = output + "{Row:" + std::to_string(e.getRowIndex()) + ",Col:";
                output = output + std::to_string(e.getColumnIndex()) + "}";
                if (i != ((int) (emptySpaces.size() - 1)))  {
                    output += ", ";
                }
            }
            output = output + "]\n";
            return output;
        }

};