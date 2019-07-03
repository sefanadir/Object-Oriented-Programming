/*--------------------------------CONNECT FOUR--------------------------------------*
 * This program will play the game of Connect Four. The game of Connect Four        *
 * is played by two players computer-user or user1-user2 on a two dimensional       *
 * board(vector of vector) with rectangular cells. 5 objects of class ConnectFour   *
 * and play the games at the same time Each cell is either computer, user, or empty.*/
#ifndef CONNECTFOUR_H
#define CONNECTFOUR_H
#include <iostream>
#include <fstream>
#include <cmath>
#include <vector>
#include <string>
#define FOUR 4
#define OBJECT_NUM 5
#define COMMAND_SIZE 4
#define FILE_EXTENSION 4
#define DECIMAL_LOWER_A 97
#define ARTIFICAL_MOVE_NUM 2
#define CONVERT_LOWER_CASE 32
#define DECIMAL_CONVERT_NUM 48
#define MINIMUM_BOARD_HEIGHT 4
#define MINIMUM_BOARD_WEIGHT 4
#define RESET     "\033[0m"
#define BOLDRED   "\033[1m\033[31m"
#define BOLDBLUE  "\033[1m\033[34m"
#define BOLDGREEN "\033[1m\033[32m" 
using namespace std;

class ConnectFour{
public:
    ConnectFour();
    ConnectFour(const ConnectFour & object);
    ConnectFour(const string &fName);
    ConnectFour(int width, int height);
    ConnectFour(const string &fName, char playerOption, const string &mode);
    ~ConnectFour();
    void playGame();
    char choosePlayer();
    
    /* Getters */
    inline int getGameBoardHeight()   const { return gameBoardHeight; }
    inline int getGameBoardWidth()    const { return gameBoardWidth;  }
    inline char getPlayerOption()     const { return playerOption;    }
    inline string getGameMode()       const { return gameMode;        }
    inline bool getFinishObje()       const { return finishObje;      }
    inline static int getLivingCells()      { return livingCells;     }
    /* Setters */
    inline void setGameBoardHeight(int boardHeight   ) { gameBoardHeight=boardHeight; }
    inline void setGameBoardWidth (int boardWeight   ) { gameBoardWidth =boardWeight; }
    inline void setPlayerOption   (int playerOpt     ) { playerOption   =playerOpt;   }
    inline void setGameMode       (string modeOption ) { gameMode       =modeOption;  }
    inline void setLivingCells    (int increaseCell  ) { livingCells    =increaseCell;}
    /* Operator Overloading */
    bool operator ==(const ConnectFour & object) const;
    bool operator !=(const ConnectFour & object) const;
    ConnectFour & operator =(const ConnectFour &object);
    
private:
    
    class Cell{
    public:
        Cell();
        Cell(int row, int col, char stone);
        enum cellState{ empty, user1, user2, computer };
        /* Getters */
        inline int  getStoneRow()  const{ return stoneRow;  }
        inline int  getStoneCol()  const{ return stoneCol;  }
        inline char getGameStone() const{ return gameStone; }
        /* Setters */
        inline void setStoneRow(int row){ stoneRow=row; }
        inline void setStoneCol(int col){ stoneCol=col; }
        inline void setGameStone(char stone){ gameStone=stone; }
        /* Operator Overloading */
        void operator++();
        void operator++(int ignoreMe);
        void operator--();
        void operator--(int ignoreMe);
        bool operator ==(const Cell & object) const;
        friend istream & operator >>(istream & inp, Cell &object);
        friend ostream & operator <<(ostream & out, const Cell & object);
    private:
        int stoneRow;
        int stoneCol;
        char gameStone;
        cellState state;
    };
    
    Cell **gameBoard;
    static int livingCells;
    string gameMode;
    int gameBoardHeight;
    int gameBoardWidth;
    char playerOption;
    char userStone;
    int tempComputerMove;
    bool computerMove;
    
    bool player;
    inline int  getPlayer()          const { return player;       }
    inline void setPlayer(bool playerOrder){ player=playerOrder;  }
    
    int  tempTargetCol;
    inline int  getTargetCol()       const { return tempTargetCol;}
    inline void setTargetCol(int column)   { tempTargetCol=column;}
    
    bool finishObje;
    inline void setFinishObje(bool finish) { finishObje=finish;   } 
    
    int  multiGame;
    inline int  getMultiGame()       const { return multiGame;    }
    inline void setMultiGame(int gameFlag) { multiGame=gameFlag;  }
    
    string fileName;
    inline string getFileName()      const { return fileName;     }
    inline void setFileName(const string &fName){ fileName=fName; }
    void deleteGameBoard();
    void initalGameBoard();
    void initalGameBoard(const string &fName);
    void createGameBoard();
    void printGameBoard();
    void startConnectFourGame();
    void playUser1User2();
    void playComputerUser();
    
    void play();
    void play(int tempTargetCol);
    
    int  getHeightFromUser();
    int  getWeightFromUser();
    int  getPosition(bool &checkCol, int &playerNo, bool pVc=true);
    void findHeightAndWeight(const string & fName);
    void putStone(int tempTargetCol);
    bool computerStoneMove(int tempTargetCol);
    bool checkValidColumn(int column, bool computer=true);
    bool checkColumnCapasity(int col, bool computer=true);
    bool checkEmptyArea();

    int  checkDiagonal();
    int  checkHorizontal(); 
    int  checkVertical();
    void convertToLowerCase(int wonIndeks[][2], int maxStone);
    
    void saveGameToFile( const string &fileName, int playerNo = 0);
    void loadGameFromFile( string fileName, int & playerNo, bool pVc);
    
    string destroySpaceCharacters(string commandSaveLoad, int &stringSize);
    bool checkFileName(const string &fileName);
    int  convertStringToNumber(const string &fileString);
    
    friend istream & operator >>(istream & inp, ConnectFour::Cell &object);
    friend ostream & operator <<(ostream & out, const ConnectFour::Cell & object);
};
#endif /* CONNECTFOUR_H */
