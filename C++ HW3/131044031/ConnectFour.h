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
#define RESET    "\033[0m"
#define BOLDRED  "\033[1m\033[31m"
#define BOLDBLUE "\033[1m\033[34m" 
using namespace std;

class ConnectFour{
public:
    ConnectFour();
    ConnectFour(int weight, int height, char gameOption, string mode);
    
    void playGame();
    void play();
    void play(int tempTargetCol);
    void printGameBoard();
    void startConnectFourGame();
    bool compareObjects(ConnectFour &obj);
    bool checkColumnCapasity(int col, bool computer=true);
    /* Getters */
    inline int getGameBoardHeight()   const { return gameBoardHeight; }
    inline int getGameBoardWeight()   const { return gameBoardWeight; }
    inline char getPlayerOption()     const { return playerOption;    }
    inline string getGameMode()       const { return gameMode;        }
    inline bool getFinishObje()       const { return finishObje;      }
    inline static int getLivingCells()      { return livingCells;     }
    /* Setters */
    inline void setGameBoardHeight(int boardHeight   ) { gameBoardHeight=boardHeight; }
    inline void setGameBoardWeight(int boardWeight   ) { gameBoardWeight=boardWeight; }
    inline void setPlayerOption   (int playerOpt     ) { playerOption   =playerOpt;   }
    inline void setGameMode       (string modeOption ) { gameMode       =modeOption;  }
    inline void setLivingCells    (int increaseCell  ) { livingCells    =increaseCell;}
    
private:
    
    class Cell{
    public:
        Cell();
        Cell(int row, int col, char stone);
        inline int  getStoneRow()  const{ return stoneRow;  }
        inline int  getStoneCol()  const{ return stoneCol;  }
        inline char getGameStone() const{ return gameStone; }
        
        inline void setStoneRow(int row){ stoneRow=row; }
        inline void setStoneCol(int col){ stoneCol=col; }
        inline void setGameStone(char stone){ gameStone=stone; }
       
    private:
        int stoneRow;
        int stoneCol;
        char gameStone;
    };
    
    vector< vector<Cell> > gameCells;
    static int livingCells;
    string gameMode;
    int gameBoardHeight;
    int gameBoardWeight;
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
    
    
    void putStone(int tempTargetCol);
    
    void getHeightFromUser();
    void getWeightFromUser();
    
    void initalGameBoard();

    void choosePlayer();
    void playUser1User2();
    void playComputerUser();
    
    int  getPosition(bool &checkCol, int &playerNo, bool pVc=true);
    bool computerStoneMove(int tempTargetCol);
    bool checkValidColumn(int column, bool computer=true);
    bool checkEmptyArea();

    int  checkDiagonal();
    int  checkHorizontal(); 
    int  checkVertical();
    void convertToLowerCase(int wonIndeks[][2], int maxStone);
    
    void saveGameToFile( const string &fileName, int playerNo = 0);
    void loadGameFromFile( string fileName, int & playerNo, bool pVc);
    
    string destroySpaceCharacters(string commandSaveLoad, int &stringSize);
    bool checkFileName(const string &fileName);
    int convertStringToNumber(const string &fileString);
};
#endif /* CONNECTFOUR_H */

