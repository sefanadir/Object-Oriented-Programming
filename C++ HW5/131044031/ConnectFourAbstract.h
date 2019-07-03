/*--------------------------------CONNECT FOUR--------------------------------*
 * This program will play the game of Connect Four. The game of Connect Four  *
 * is played by two players computer-user or user1-user2 on a two dimensional *
 * board(vector of vector) with rectangular cells.                            */
#ifndef CONNECTFOURABSTRACT_H
#define CONNECTFOURABSTRACT_H
#include "Cell.h"
#include <iostream>
#include <fstream>
#include <cmath>
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
namespace sefanadir{
class ConnectFourAbstract{
    
public:
    ConnectFourAbstract();
    ConnectFourAbstract(const ConnectFourAbstract & object);
    ConnectFourAbstract(const string &fName);
    ConnectFourAbstract(int width, int height);
    ~ConnectFourAbstract();
    void playGame();
    
    /* Getters */
    inline int getGameBoardHeight()   const { return gameBoardHeight; }
    inline int getGameBoardWidth()    const { return gameBoardWidth;  }
    inline char getPlayerOption()     const { return playerOption;    }
    /* Setters */
    inline void setGameBoardHeight(int boardHeight   ) { gameBoardHeight=boardHeight; }
    inline void setGameBoardWidth (int boardWeight   ) { gameBoardWidth =boardWeight; }
    inline void setPlayerOption   (int playerOpt     ) { playerOption   =playerOpt;   }
    /* Operator Overloading */
    ConnectFourAbstract & operator =(const ConnectFourAbstract &object);
protected:
    Cell **gameBoard;
    bool computerMove;
    char playerOption, userStone;
    int  gameBoardHeight, gameBoardWidth, tempComputerMove;
    
    bool player;
    inline int  getPlayer()          const { return player;       }
    inline void setPlayer(bool playerOrder){ player=playerOrder;  }
    
    int  tempTargetCol;
    inline int  getTargetCol()       const { return tempTargetCol;}
    inline void setTargetCol(int column)   { tempTargetCol=column;}
    
    string fileName;
    inline string getFileName()      const { return fileName;     }
    inline void setFileName(const string &fName){ fileName=fName; }
    
    void deleteGameBoard();
    void initialGameBoard();
    void createGameBoard();
    void printGameBoard();
    void startConnectFourGame();
    virtual void playUser1User2()  =0;
    virtual void playComputerUser()=0;

    int  checkDiagonal();
    int  checkHorizontal(); 
    int  checkVertical();
    
    void play();
    void play(int tempTargetCol);
    
    char choosePlayer();
    int  getHeightFromUser();
    int  getWeightFromUser();

    virtual int  getPosition(bool &checkCol, int &playerNo, bool pVc=true);

    void findHeightAndWeight(const string & fName);
    void putStone(int tempTargetCol);
    bool computerStoneMove(int tempTargetCol);
    bool checkValidColumn(int column, bool computer=true);
    bool checkColumnCapasity(int col, bool computer=true);
    bool checkEmptyArea();

    void convertToLowerCase(int wonIndeks[][2], int maxStone);
    void saveGameToFile( const string &fileName, int playerNo = 0);
    void loadGameFromFile( string fileName, int & playerNo, bool pVc);
    string destroySpaceCharacters(string commandSaveLoad, int &stringSize);
    bool checkFileName(const string &fileName);
    int  convertStringToNumber(const string &fileString);
};
}
#endif /* CONNECTFOURABSTRACT_H */

