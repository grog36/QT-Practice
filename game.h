//The tic tac toe game class
#include "coordinate.h"
#include <vector>
#include <iostream>

class Game {
    private:
        //The "grid" of markers
        std::vector<std::vector<char>> grid;

        //A grid of coordinates corresponding to the empty spaces in "grid"
        std::vector<Coordinate> emptySpaces;
        
        //Player 1 Marker
        char player1Marker = 'X';

        //Player 2 Marker
        char player2Marker = 'O';

        //The character corresponding to whose turn it is
        char whoseTurn = 'X';

    public:
        /**
        * 1-Parameter Constructor
        *
        * @param whoGoesFirst (int) - An int corresponding to which player goes first
        *       1 for human, 2 for bot
        */
        Game(int whoGoesFirst) {
            if (whoGoesFirst == 1 || whoGoesFirst == 2) {
                for (int i = 0; i < 3; i++) {
                    std::vector<char> row;
                    row.push_back(' ');
                    row.push_back(' ');
                    row.push_back(' ');
                    grid.push_back(row);
                    for (int j = 0; j < 3; j++) {
                        emptySpaces.push_back(Coordinate(i, j));
                    }
                }
                whoseTurn = ((whoGoesFirst == 1) ? 'X' : 'O');
            }
        }

        /**
        * 1-Parameter Constructor
        *
        * @param prevGame (Game*) - A pointer to the old game board to copy over
        */
        Game(
            std::vector<std::vector<char>> oldGrid,
            std::vector<Coordinate> oldEmptySpaces,
            char oldPlayer1Marker,
            char oldPlayer2Marker,
            char oldWhoseTurn
            ) {
                for (int i = 0; i < 3; i++) {
                    std::vector<char> row;
                    for (int j = 0; j < 3; j++) {
                        row.push_back(oldGrid[i][j]);
                    }
                    grid.push_back(row);
                }
                for (unsigned int i = 0; i < oldEmptySpaces.size(); i++) {
                    Coordinate c = oldEmptySpaces.at(i);
                    emptySpaces.push_back(Coordinate(c.getRowIndex(), c.getColumnIndex()));
                }
                player1Marker = oldPlayer1Marker;
                player2Marker = oldPlayer2Marker;
                whoseTurn = oldWhoseTurn;
        }

        /**
        * Gets the "emptySpaces" field
        *
        * @return std::vector<Coordinate> - Returns the "emptySpaces" field
        */
        std::vector<Coordinate> getEmptySpaces() {
            return emptySpaces;
        }

        /**
        * Gets the "grid" field
        *
        * @return std::vector<std::vector<char>> - Returns the "grid" field
        */
        std::vector<std::vector<char>> getGrid() {
            return grid;
        }

        /**
        * Gets the current "grid" field as a formatted string
        *
        * @return std::string - Returns the "grid" field as a formatted string
        */
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

        /**
        * Gets the "player1Marker" field
        *
        * @return char - Returns the "player1Marker" field
        */
        char getPlayer1Marker() {
            return player1Marker;
        }
        /**
        * Gets the "player2Marker" field
        *
        * @return char - Returns the "player2Marker" field
        */
        char getPlayer2Marker() {
            return player2Marker;
        }
        /**
        * Gets the "whoseTurn" field
        *
        * @return char - Returns the "whoseTurn" field
        */
        char getWhoseTurn() {
            return whoseTurn;
        }

        /**
        * Checks to see if there is a win on the current board for a given player
        *
        * @param playerMarker (char) - The marker of the player to check for a win for
        * @return bool - True if the player has won, false otherwise
        */
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

        /**
        * Checks to see if there is a tie on the current board
        *
        * @return bool - True if the board is a tie, false otherwise
        */
        bool checkForTie() {
            if (checkForWin(player1Marker) == false && checkForWin(player2Marker) == false &&
                emptySpaces.size() == 0) {
                    return true;
            }
            return false;
        }

        /**
        * Attempts to play a move, plays the move if it is valid
        *
        * @param rowIndex (int) - The row index of the move to play
        * @param colIndex (int) - The column index of the move to play
        * @return bool - True if the move was played, false otherwise (invalid move)
        */
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

        /**
        * Gets the player marker at a given grid space (row/column)
        *
        * @param rowIndex (int) - The index of the row to check
        * @param colIndex (int) - The index of the column to check
        * @return char - The character at a given (row/column) in "grid"
        */
        char getPlayerMarkerAt(int rowIndex, int colIndex) {
            if (rowIndex >= 0 && rowIndex < 3 && colIndex >= 0 && colIndex < 3) {
                return grid[rowIndex][colIndex];
            }
            return ' ';
        }

        /**
        * Finds the best move for a given game state
        *
        * @return Coordinate - Returns the best coordinate to play in the position
        */
        Coordinate findBestMove() {
            char enemyMarker = (whoseTurn == player1Marker) ? player2Marker : player1Marker;
            bool player1Win = checkForWin(player1Marker);
            bool player2Win = checkForWin(player2Marker);
            bool tie = checkForTie();
            bool gameIsStillGoingOn = !(player1Win || player2Win || tie);
            if (gameIsStillGoingOn) {
                //Checks to see if a move wins the game
                for (unsigned int i = 0; i < emptySpaces.size(); i++) {
                    Coordinate c = emptySpaces.at(i);
                    Game tempGame = Game(grid, emptySpaces, player1Marker, player2Marker, whoseTurn);
                    tempGame.playMove(c.getRowIndex(), c.getColumnIndex());
                    if (tempGame.checkForWin(whoseTurn)) {
                        return c;
                    }
                }
                //Checks to see if move prevents a loss
                for (unsigned int i = 0; i < emptySpaces.size(); i++) {
                    Coordinate c = emptySpaces.at(i);
                    Game tempGame = Game(grid, emptySpaces, player1Marker, player2Marker, enemyMarker);
                    tempGame.playMove(c.getRowIndex(), c.getColumnIndex());
                    if (tempGame.checkForWin(enemyMarker)) {
                        return c;
                    }
                }
                return emptySpaces.at(0);
            }
            return Coordinate(100, 100);
        }

        /**
        * Allows the bot to play a move
        *
        * The bot can only move if there is a valid move in the position
        * and uses whichever marker "whoseTurn" is currently set at
        */
        void botPlaysMove() {
            Coordinate bestMove = findBestMove();
            if (bestMove.getRowIndex() != 100) {
                playMove(bestMove.getRowIndex(), bestMove.getColumnIndex());
            }
        }

        /**
        * Checks to see if the current game session is in a game-over state
        *
        * @return bool - Returns true if a player has won or there is a tie, false otherwise
        */
        bool isGameOver() {
            return (emptySpaces.size() == 0);
        }
};