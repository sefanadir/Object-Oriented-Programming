#include "Cell.h"
namespace sefanadir {

    /* The no parameter constructor takes number of rows and columns and cell type */
    Cell::Cell() : stoneRow(0), stoneCol(0), gameStone('*') {
    }

    /* The constructor for Cell class */
    Cell::Cell(int row, int col, char stone) :
    stoneRow(row), stoneCol(col), gameStone(stone) {
    }
}
