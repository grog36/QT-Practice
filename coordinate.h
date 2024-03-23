#include <string>

class Coordinate {
    private:
        //The index of the column the coordinate is located at
        int columnIndex;

        //The index of the row the coordinate is located at
        int rowIndex;
    
    public:
        /**
        * 2-Parameter Constructor
        *
        * @param rowIn (int) - The row index for the coordinate
        * @param colIn (int) - The column index for the coordinate
        */
        Coordinate(int rowIn, int colIn) {
            if (rowIn >= 0 && rowIn < 3 && colIn >= 0 && colIn < 3) {
                columnIndex = colIn;
                rowIndex = rowIn;
            }
        }

        /**
        * Gets the "columnIndex" field
        *
        * @return int - Returns the "columnIndex" field
        */ 
        int getColumnIndex() {
            return columnIndex;
        }

        /**
        * Gets the "rowIndex" field
        *
        * @return int - Returns the "rowIndex" field
        */
        int getRowIndex() {
            return rowIndex;
        }

        /**
        * Gets the current coordinate represented as a string
        *
        * @return std::string - The current coordinate represented as a string
        */
        std::string toString() {
            std::string output = "Row: ";
            output += std::to_string(rowIndex);
            output += "\tCol: ";
            output += std::to_string(columnIndex);
            return output;
        }
};