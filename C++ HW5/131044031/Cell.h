#ifndef CELL_H
#define CELL_H
using namespace std;
namespace sefanadir{
    class Cell {
    public:
        Cell();
        Cell(int row, int col, char stone);
        /* Getters */
        inline int getStoneRow() const  { return stoneRow; }
        inline int getStoneCol() const  { return stoneCol; }
        inline char getGameStone() const{ return gameStone;}
        /* Setters */
        inline void setStoneRow(int row){ stoneRow = row;  }
        inline void setStoneCol(int col){ stoneCol = col;  }
        inline void setGameStone(char stone){gameStone = stone;}
    private:
        int stoneRow;
        int stoneCol;
        char gameStone;
    };
}
#endif /* CELL_H */

