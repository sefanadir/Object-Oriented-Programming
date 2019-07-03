/*----------------------------CONNECT FOUR------------------------------------*/
/* This program will play the game of Connect Four. The game of Connect Four  *
 * is played by two players computer-user or user1-user2 on a two dimensional *
 * board with rectangular cells. Each cell is either computer, user, or empty.*/
#include <iostream>
#define CONNECT_FOUR 4
#define MIN_INVALID_SIZE 3
#define MAX_INVALID_SIZE 21
#define DECIMAL_LOWER_A 97
#define CONVERT_LOWER_CASE 32
#define ARTIFICAL_MOVE_NUM 2
using namespace std;

int  getGameBoardSize();
void checkBoardSize(int &boardSize);
int  choosePlayer();
void initialGameBoard(char gameBoard[][20], int gameBoardSize);
void printGameBoard(char gameBoard[][20], int gameBoardSize);
void startConnectFourGame(char gameBoard[][20], int gameBoardSize, char playerOption);
void playComputerUser(char gameBoard[][20], int gameBoardSize);
void playUser1User2(char gameBoard[][20], int gameBoardSize);
int  getPosition(char gameBoard[][20], int gameBoardSize, bool &checkCol);
bool checkValidColumn(int column, int gameBoardSize, bool computer = true);
bool checkColumnCapasity(char gameBoard[][20], int col, bool computer = true);
void checkEmptyArea(bool &game, int& fullBoard, int gameBoardSize);
void putStone(char gameBoard[][20], int gameBoardSize, int tempTargetCol, char gameStone);
int  checkDiagonal(char gameBoard[][20], int gameBoardSize, char gameStone);
int  checkVertical(char gameBoard[][20], int gameBoardSize, char gameStone);
int  checkHorizontal(char gameBoard[][20], int gameBoardSize, char gameStone);
bool computerStoneMove(char gameBoard[][20], int gameBoardSize, int tempTargetCol, char gameStone);
void convertToLowerCase(char gameBoard[][20], int wonIndeks[][2], int maxStone, char gameStone);

int main(int argc, char** argv) {
    int gameBoardSize = 0;
    char connectFour[20][20], playerOption = 0;
    gameBoardSize = getGameBoardSize();
    checkBoardSize(gameBoardSize);
    playerOption = choosePlayer();
    initialGameBoard(connectFour, gameBoardSize);
    printGameBoard(connectFour, gameBoardSize);
    startConnectFourGame(connectFour, gameBoardSize, playerOption);
    return 0;
}

/* This function retrieves the size information of the game board 
   from the user and checks whether the size of the game board is wrong       */
int getGameBoardSize() {
    int sizeFlag = 1, gameBoardSize = 0;
    do {
        cout << " Please enter size of game board: ";
        cin>>gameBoardSize;
        if (cin.fail()) {
            cin.clear();
            cin.ignore();
            cout << " Size must be even number between 4 and 20" << endl;
        } else {
            sizeFlag = 0;
        }
    } while (sizeFlag);
    return gameBoardSize;
}

/* This function checks whether the size of the board is an even number 
   and a number between 4 and 20                                              */
void checkBoardSize(int &boardSize) {
    int checkSize = 0;
    while (checkSize == 0) {
        if (!(boardSize % 2 == 0 && boardSize > MIN_INVALID_SIZE && boardSize < MAX_INVALID_SIZE)) {
            cerr << " Size must be even number between 4 and 20" << endl;
            boardSize = getGameBoardSize();
        } else
            checkSize = 1;
    }
}

/* This function asks the user whether the game will be played
   against computer or against a player and checks error status               */
int choosePlayer() {
    int playerFlag = 1;
    char playerOption;
    cout << " Computer - Player : C" << endl;
    cout << " Player1  - Player2: P" << endl;
    do {
        cout << " Choose game option: ";
        cin>>playerOption;
        if (playerOption >= 'a' && playerOption <= 'z')
            playerOption -= 32;
        if (!(playerOption == 'C' || playerOption == 'P'))
            cerr << " Invalid game option" << endl;
        else
            playerFlag = 0;
    } while (playerFlag);
    return playerOption;
}

/* This function invokes the necessary functions for the game played against 
   the computer or player and starts the game                                 */
void startConnectFourGame(char gameBoard[][20], int gameBoardSize, char playerOption) {
    if (playerOption == 'C')
        playComputerUser(gameBoard, gameBoardSize);
    else
        playUser1User2(gameBoard, gameBoardSize);
}

/* This function fills with the point character to show the game board as empty */
void initialGameBoard(char gameBoard[][20], int gameBoardSize) {
    for (int i = 0; i < gameBoardSize; ++i) {
        for (int j = 0; j < gameBoardSize; ++j) {
            gameBoard[i][j] = '.';
        }
    }
}

/* This function will show the game board after each move */
void printGameBoard(char gameBoard[][20], int gameBoardSize) {
    int tempLocation = DECIMAL_LOWER_A;
    int countSize = 0;
    char realLocation;
    for (int i = tempLocation; countSize < gameBoardSize; ++i, ++countSize) {
        realLocation = i;
        cout << " " << realLocation;
    }
    cout << endl;
    for (int i = 0; i < gameBoardSize; ++i) {
        for (int j = 0; j < gameBoardSize; ++j) {
            cout << " " << gameBoard[i][j];
        }
        cout << endl;
    }
}

/* This function puts a stone in the selected position by the computer */
bool computerStoneMove(char gameBoard[][20], int gameBoardSize, int tempTargetCol, char gameStone) {
    putStone(gameBoard, gameBoardSize, tempTargetCol, gameStone);
    printGameBoard(gameBoard, gameBoardSize);
    cout << endl;
    return false;
}

/* This function works when the game is played against the computer.          * 
 * First, the player moves and then the computer moves. When the computer     *
 * moves, it tries to prevent the player from winning and makes logical moves */
void playComputerUser(char gameBoard[][20], int gameBoardSize) {
    bool player = true, game = true, checkCol = true;
    bool computer = false, computerMove = true;
    int fullBoard = 0, tempTargetCol = 0, randomMove = 1, stoneNumber = 0;
    char gameStone;
    while (game) {
        if (player) {
            gameStone = 'X';
            while (checkCol) {
                tempTargetCol = getPosition(gameBoard, gameBoardSize, checkCol);
                putStone(gameBoard, gameBoardSize, tempTargetCol, gameStone);
                printGameBoard(gameBoard, gameBoardSize);
                cout << endl;
                checkCol = false;
            }
            /* Check if there are any winners after each move */
            if (checkDiagonal(gameBoard, gameBoardSize, gameStone) >= CONNECT_FOUR ||
                    checkHorizontal(gameBoard, gameBoardSize, gameStone) >= CONNECT_FOUR ||
                    checkVertical(gameBoard, gameBoardSize, gameStone) >= CONNECT_FOUR) {
                game = false;
                cout << " Winning Moves" << endl;
                printGameBoard(gameBoard, gameBoardSize);
                cout << " Player won the game" << endl;
            }
            checkEmptyArea(game, fullBoard, gameBoardSize);
            checkCol = true, player = false;
        }
        if (!player && game) {
            /* According to the player's move, the computer makes a logical move */
            while (computerMove) {
                gameStone = 'O';
                switch (randomMove) {
                    case 1:
                        stoneNumber = checkHorizontal(gameBoard, gameBoardSize, 'X');
                        if (stoneNumber == 2) {
                            if (!checkValidColumn(tempTargetCol - 1, gameBoardSize, computer)
                                    && checkColumnCapasity(gameBoard, tempTargetCol - 1, computer))
                                computerMove = computerStoneMove(gameBoard, gameBoardSize, tempTargetCol - 1, gameStone);
                        }
                        if (stoneNumber == 3) {
                            if (!checkValidColumn(tempTargetCol + 1, gameBoardSize, computer)
                                    && checkColumnCapasity(gameBoard, tempTargetCol + 1, computer))
                                computerMove = computerStoneMove(gameBoard, gameBoardSize, tempTargetCol + 1, gameStone);
                        }
                        break;
                    case 2:
                        stoneNumber = checkVertical(gameBoard, gameBoardSize, 'X');
                        if (stoneNumber == 2 || stoneNumber == 3) {
                            if (!checkValidColumn(tempTargetCol, gameBoardSize, computer)
                                    && checkColumnCapasity(gameBoard, tempTargetCol, computer))
                                computerMove = computerStoneMove(gameBoard, gameBoardSize, tempTargetCol, gameStone);
                        }
                        break;
                    case 3:
                        stoneNumber = checkDiagonal(gameBoard, gameBoardSize, 'X');
                        if (stoneNumber == 1 || stoneNumber == 2) {
                            if (!checkValidColumn(tempTargetCol + 1, gameBoardSize, computer)
                                    && checkColumnCapasity(gameBoard, tempTargetCol + 1, computer))
                                computerMove = computerStoneMove(gameBoard, gameBoardSize, tempTargetCol + 1, gameStone);
                        }
                        if (stoneNumber == 3) {
                            if (!checkValidColumn(tempTargetCol - 1, gameBoardSize, computer)
                                    && checkColumnCapasity(gameBoard, tempTargetCol - 1, computer))
                                computerMove = computerStoneMove(gameBoard, gameBoardSize, tempTargetCol - 1, gameStone);
                        }
                        break;
                    case 4:
                        tempTargetCol -= ARTIFICAL_MOVE_NUM;
                        if (tempTargetCol < DECIMAL_LOWER_A)
                            tempTargetCol = DECIMAL_LOWER_A;
                        for (int i = 0; i < gameBoardSize; i++) {
                            if (checkColumnCapasity(gameBoard, tempTargetCol, computer)) {
                                computerMove = computerStoneMove(gameBoard, gameBoardSize, tempTargetCol, gameStone);
                                i = gameBoardSize;
                            }
                            tempTargetCol = tempTargetCol + 1;
                            if (tempTargetCol > DECIMAL_LOWER_A + gameBoardSize - 1)
                                tempTargetCol = DECIMAL_LOWER_A;
                        }
                        break;
                }
                if (randomMove <= CONNECT_FOUR)
                    ++randomMove;
                else
                    randomMove = 1;
            }
            /* Check if there are any winners after each move */
            if (checkDiagonal(gameBoard, gameBoardSize, gameStone) >= CONNECT_FOUR ||
                    checkHorizontal(gameBoard, gameBoardSize, gameStone) >= CONNECT_FOUR ||
                    checkVertical(gameBoard, gameBoardSize, gameStone) >= CONNECT_FOUR) {
                game = false;
                cout << " Winning Status" << endl;
                printGameBoard(gameBoard, gameBoardSize);
                cout << " Computer won the game" << endl;
            }
            checkEmptyArea(game, fullBoard, gameBoardSize);
            player = true, computerMove = true;
        }
    }
}

/* This function works when two players mutually play. The order of the game
   continues in an alternating fashion and if the player succeeds in bringing   
   the four pieces side by side horizontally,vertically or diagonally, the game is won.*/
void playUser1User2(char gameBoard[][20], int gameBoardSize) {
    bool player = true, checkCol = true, game = true;
    int tempTargetCol = 0, fullBoard = 0, playerNo = 0;
    char gameStone = ' ';
    /* If game variable is true, the game continues to play.If the            *
     * game board is full or one of the players wins, the game is over.       */
    while (game) {
        if (player) {
            cout << " PLAYER 1" << endl;
            gameStone = 'X';
            playerNo = 1;
        }
        if (!player) {
            cout << " PLAYER 2" << endl;
            gameStone = 'O';
            playerNo = 2;
        }
        tempTargetCol = getPosition(gameBoard, gameBoardSize, checkCol);
        putStone(gameBoard, gameBoardSize, tempTargetCol, gameStone);
        printGameBoard(gameBoard, gameBoardSize);
        if (gameStone == 'X') {
            player = false;
        } else {
            player = true;
        }
        /* Check if there are any winners after each move */
        if (checkDiagonal(gameBoard, gameBoardSize, gameStone) >= CONNECT_FOUR ||
                checkHorizontal(gameBoard, gameBoardSize, gameStone) >= CONNECT_FOUR ||
                checkVertical(gameBoard, gameBoardSize, gameStone) >= CONNECT_FOUR) {
            game = false;
            cout << endl;
            cout << " Winning Moves" << endl;
            printGameBoard(gameBoard, gameBoardSize);
            cout << " Player" << playerNo << " won the game" << endl;
        }
        checkEmptyArea(game, fullBoard, gameBoardSize);
    }
}

/* This function retrieves the column information from the player and places a 
 * stone in the empty space in that column.If the column is full or the wrong
 * column information is entered, it prompts the player to enter the column again.*/
int getPosition(char gameBoard[][20], int gameBoardSize, bool &checkCol) {
    int tempTargetCol = 0;
    char targetCol;
    while (checkCol) {
        cout << " Target Position: ";
        cin >> targetCol;
        if (targetCol >= 'A' && targetCol <= 'Z') {
            tempTargetCol = targetCol;
            tempTargetCol += 32;
        } else {
            tempTargetCol = targetCol;
        }
        if (checkValidColumn(tempTargetCol, gameBoardSize) == false &&
                checkColumnCapasity(gameBoard, tempTargetCol) == true)
            checkCol = false;
    }
    checkCol = true;
    return tempTargetCol;
}

/* This function calculates the number of rows and places the stone at        *
 * the empty position in the column                                           */
void putStone(char gameBoard[][20], int gameBoardSize, int tempTargetCol, char gameStone) {
    int emptyArea = 0;
    for (int i = 0; i < gameBoardSize; i++) {
        if (gameBoard[i][tempTargetCol - DECIMAL_LOWER_A] == '.')
            ++emptyArea;
    }
    if (gameBoard[emptyArea - 1][tempTargetCol - DECIMAL_LOWER_A] == '.')
        gameBoard[emptyArea - 1][tempTargetCol - DECIMAL_LOWER_A] = gameStone;
}

/* This function checks whether the game board is full */
void checkEmptyArea(bool &game, int& fullBoard, int gameBoardSize) {
    int totalIndex = gameBoardSize*gameBoardSize;
    ++fullBoard;
    if (fullBoard == totalIndex) {
        game = false;
        cout << " Game Over Board Ground Full" << endl;
    }
}

/* This function checks whether the entered column information is             *
 * within the valid range of characters                                       */
bool checkValidColumn(int column, int gameBoardSize, bool computer) {
    int tempLocation = DECIMAL_LOWER_A;
    int countSize = 0;
    bool checkCol = true;
    for (int i = tempLocation; countSize < gameBoardSize; ++i, ++countSize) {
        if (i == column)
            checkCol = false;
    }
    if (checkCol && computer == true)
        cerr << " Invalid target column" << endl;
    return checkCol;
}

/* This function checks whether there are four stones vertically */
int checkVertical(char gameBoard[][20], int gameBoardSize, char gameStone) {
    int wonIndeks[4][2];
    int maxStone = 0, countStone = 0, store = 0;
    for (int i = 0; i < gameBoardSize; ++i) {
        for (int j = 0; j < gameBoardSize; ++j) {
            if (gameBoard[j][i] == gameStone) {
                /* Store the location information of matching stones */
                if (store < CONNECT_FOUR) {
                    wonIndeks[store][0] = j;
                    wonIndeks[store][1] = i;
                    ++store;
                }
                ++countStone;
                /* Determine the number of the most repeated stones in the vertical */
                if (countStone > maxStone) {
                    maxStone = countStone;
                    convertToLowerCase(gameBoard, wonIndeks, maxStone, gameStone);
                }
            } else
                /* If the stone is not equal to player stone, reset *
                 * number of countStone and store in column change  */
                countStone = 0, store = 0;
        }
        /* Reset number of countStone and store in column change */
        countStone = 0, store = 0;
    }
    return maxStone;
}

/* This function checks whether there are four stones horizontally */
int checkHorizontal(char gameBoard[][20], int gameBoardSize, char gameStone) {
    int wonIndeks[4][2];
    int maxStone = 0, countStone = 0, store = 0;
    for (int i = 0; i < gameBoardSize; ++i) {
        for (int j = 0; j < gameBoardSize; ++j) {
            if (gameBoard[i][j] == gameStone) {
                /* Store the location information of matching stones */
                if (store < CONNECT_FOUR) {
                    wonIndeks[store][0] = i;
                    wonIndeks[store][1] = j;
                    ++store;
                }
                ++countStone;
                /* Determine the number of the most repeated stones in the horizontal */
                if (countStone > maxStone) {
                    maxStone = countStone;
                    convertToLowerCase(gameBoard, wonIndeks, maxStone, gameStone);
                }
            } else
                /* If the stone is not equal to player stone, reset *
                 * number of countStone and store in column change  */
                countStone = 0, store = 0;
        }
        /* Reset number of countStone and store in column change */
        countStone = 0, store = 0;
    }
    return maxStone;
}

/* This function checks whether there are four stones diagonally */
int checkDiagonal(char gameBoard[][20], int gameBoardSize, char gameStone) {
    int wonIndeks[4][2];
    int col = 0, row = 0, tempRow = 0;
    int maxStone = 0, countStone = 0, store = 0;

    while (row < gameBoardSize) {
        while (row >= 0) {
            if (gameBoard[row][col] == gameStone) {
                /* Store the location information of matching stones */
                if (store < CONNECT_FOUR) {
                    wonIndeks[store][0] = row;
                    wonIndeks[store][1] = col;
                    ++store;
                }
                ++countStone;
                /* Determine the number of the most repeated stones in the diagonal */
                if (countStone > maxStone) {
                    maxStone = countStone;
                    convertToLowerCase(gameBoard, wonIndeks, maxStone, gameStone);
                }
            } else {
                /* If the stone is not equal to player stone, reset *
                 * number of countStone and store in column change  */
                countStone = 0, store = 0;
            }
            --row, ++col;
        }
        ++tempRow;
        row = tempRow, col = 0;
        countStone = 0, store = 0;
    }
    int tempCol = gameBoardSize - 1;
    row = gameBoardSize - 1;
    tempRow = gameBoardSize - 1;
    col = gameBoardSize - 1;

    while (col > 0) {
        while (col < gameBoardSize) {
            if (gameBoard[row][col] == gameStone) {
                if (store < CONNECT_FOUR) {
                    /* Store the location information of matching stones */
                    wonIndeks[store][0] = row;
                    wonIndeks[store][1] = col;
                    ++store;
                }
                ++countStone;
                /* Determine the number of the most repeated stones in the diagonal */
                if (countStone > maxStone) {
                    maxStone = countStone;
                    convertToLowerCase(gameBoard, wonIndeks, maxStone, gameStone);
                }
            } else {
                /* If the stone is not equal to player stone, reset *
                 * number of countStone and store in column change  */
                countStone = 0, store = 0;
            }
            --row, ++col;
        }
        --tempCol;
        col = tempCol, row = tempRow;
        countStone = 0, store = 0;
    }
    col = gameBoardSize - 1;
    tempCol = gameBoardSize - 1;
    row = 0;

    while (col >= 0) {
        while (col < gameBoardSize) {
            if (gameBoard[row][col] == gameStone) {
                if (store < CONNECT_FOUR) {
                    /* Store the location information of matching stones */
                    wonIndeks[store][0] = row;
                    wonIndeks[store][1] = col;
                    ++store;
                }
                ++countStone;
                /* Determine the number of the most repeated stones in the diagonal */
                if (countStone > maxStone) {
                    maxStone = countStone;
                    convertToLowerCase(gameBoard, wonIndeks, maxStone, gameStone);
                }
            } else {
                /* If the stone is not equal to player stone, reset *
                 * number of countStone and store in column change  */
                countStone = 0, store = 0;
            }
            ++row, ++col;
        }
        --tempCol;
        col = tempCol, row = 0;
        countStone = 0, store = 0;
    }
    row = gameBoardSize - 1;
    tempRow = gameBoardSize - 1;
    col = 0;

    while (row > 0) {
        while (row < gameBoardSize) {
            if (gameBoard[row][col] == gameStone) {
                if (store < CONNECT_FOUR) {
                    /* Store the location information of matching stones */
                    wonIndeks[store][0] = row;
                    wonIndeks[store][1] = col;
                    ++store;
                }
                ++countStone;
                /* Determine the number of the most repeated stones in the diagonal */
                if (countStone > maxStone) {
                    maxStone = countStone;
                    convertToLowerCase(gameBoard, wonIndeks, maxStone, gameStone);
                }
            } else {
                /* If the stone is not equal to player stone, reset *
                 * number of countStone and store in column change  */
                countStone = 0, store = 0;
            }
            ++row, ++col;
        }
        --tempRow;
        row = tempRow, col = 0;
        countStone = 0, store = 0;
    }
    return maxStone;
}
/* This function checks whether there are four stones vertically */
void convertToLowerCase(char gameBoard[][20], int wonIndeks[][2], int maxStone, char gameStone) {
    if (maxStone >= CONNECT_FOUR) {
        for (int i = 0; i < CONNECT_FOUR; ++i) {
            for (int j = 0; j < 1; ++j) {
                gameBoard[wonIndeks[i][j]][wonIndeks[i][j + 1]] = gameStone + CONVERT_LOWER_CASE;
            }
        }
    }
}
/* This function checks whether the capacity of the column is full*/
bool checkColumnCapasity(char gameBoard[][20], int col, bool computer) {
    bool capacity = true;
    if (gameBoard[0][col - DECIMAL_LOWER_A] != '.') {
        if (computer)
            cerr << " Column capacity is full" << endl;
        capacity = false;
    }
    return capacity;
}
