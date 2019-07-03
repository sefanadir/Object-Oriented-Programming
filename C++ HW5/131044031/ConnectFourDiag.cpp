#include "ConnectFourDiag.h"
namespace sefanadir {

    /* No parameter constructor */
    ConnectFourDiag::ConnectFourDiag() : ConnectFourAbstract(5,5) {

    }

    /* The copy constructor */
    ConnectFourDiag::ConnectFourDiag(const ConnectFourDiag& object) {
        setPlayer(true);
        setPlayerOption(object.getPlayerOption());

        setGameBoardHeight(object.getGameBoardHeight());
        setGameBoardWidth(object.getGameBoardWidth());

        createGameBoard();

        for (int i = 0; i < getGameBoardHeight(); i++) {
            for (int j = 0; j < getGameBoardWidth(); j++) {
                gameBoard[i][j].setGameStone(object.gameBoard[i][j].getGameStone());
                gameBoard[i][j].setStoneRow(i);
                gameBoard[i][j].setStoneCol(j);
            }
        }
    }

    /* Assignment operator overloading */
    ConnectFourDiag& ConnectFourDiag::operator=(const ConnectFourDiag& object) {
        if (gameBoardHeight != object.gameBoardHeight && gameBoardWidth != object.gameBoardWidth) {
            for (int i = 0; i < getGameBoardHeight(); ++i) {
                delete [] gameBoard[i];
            }
            delete [] gameBoard;
            gameBoard = nullptr;
            setGameBoardHeight(object.gameBoardHeight);
            setGameBoardWidth(object.gameBoardWidth);

            createGameBoard();
        }
        fileName = object.fileName;
        playerOption = object.playerOption;

        for (int i = 0; i < getGameBoardHeight(); ++i) {
            for (int j = 0; j < getGameBoardWidth(); ++j) {
                gameBoard[i][j].setGameStone(object.gameBoard[i][j].getGameStone());
                gameBoard[i][j].setStoneCol(object.gameBoard[i][j].getStoneCol());
                gameBoard[i][j].setStoneRow(object.gameBoard[i][j].getStoneRow());
            }
        }
        return *this;
    }

    /* This function works when two players mutually play. The order of the game           *
     * continues in an alternating fashion and if the player succeeds in bringing          *
     * the four pieces side by side horizontally,vertically or diagonally, the game is won.*/
    void ConnectFourDiag::playUser1User2() {
        int playerNo = 0;
        bool checkCol = true, game = true;
        /* If game variable is true, the game continues to play.If the            *
         * game board is full or one of the players wins, the game is over.       */
        while (game) {
            if (getPlayer()) {
                cout << " PLAYER 1" << endl;
                userStone = 'X';
                playerNo = 1;
            }
            if (!getPlayer()) {
                cout << " PLAYER 2" << endl;
                userStone = 'O';
                playerNo = 2;
            }
            setTargetCol(getPosition(checkCol, playerNo, false));
            if (playerNo == 1) {
                userStone = 'X';
            } else {
                userStone = 'O';
            }
            putStone(getTargetCol());

            printGameBoard();
            if (userStone == 'X') {
                setPlayer(false);
            } else {
                setPlayer(true);
            }
            /* Check if there are any winners after each move */
            if (checkDiagonal() >= FOUR) {
                game = false;
                cout << endl;
                cout << " Winning Status" << endl;
                printGameBoard();
                cout << " Player" << playerNo << " won the game" << endl;
            }
            if (game)
                game = checkEmptyArea();
        }
    }

    /* This function works when the game is played against the computer.          * 
     * First, the player moves and then the computer moves. When the computer     *
     * moves, it tries to prevent the player from winning and makes logical moves */
    void ConnectFourDiag::playComputerUser() {
        int randomMove = 1, stoneNumber = 0, playerNo = 1;
        bool game = true, checkCol = true, computer = false;
        computerMove = true;
        while (game) {
            if (getPlayer()) {
                userStone = 'X';
                while (checkCol) {
                    setTargetCol(getPosition(checkCol, playerNo));
                    putStone(getTargetCol());
                    printGameBoard();
                    cout << endl;
                    checkCol = false;
                }
                /* Check if there are any winners after each move */
                if (checkDiagonal() >= FOUR) {
                    game = false;
                    cout << " Winning Status" << endl;
                    printGameBoard();
                    cout << " Player won the game" << endl;
                }
                if (game)
                    game = checkEmptyArea();
                checkCol = true;
                setPlayer(false);
            }
            if (!getPlayer() && game) {
                /* According to the player's move, the computer makes a logical move */
                while (computerMove) {
                    switch (randomMove) {
                        case 1:
                            userStone = 'X';
                            stoneNumber = checkDiagonal();
                            if (stoneNumber == 2) {
                                if (!checkValidColumn(getTargetCol() - 1, computer)
                                        && checkColumnCapasity(getTargetCol() - 1, computer)) {
                                    userStone = 'O';
                                    tempComputerMove = getTargetCol() - 1;
                                    computerMove = computerStoneMove(tempComputerMove);
                                }
                            } else if (stoneNumber == 3) {
                                if (!checkValidColumn(getTargetCol() + 1, computer)
                                        && checkColumnCapasity(getTargetCol() + 1, computer)) {
                                    userStone = 'O';
                                    tempComputerMove = getTargetCol() + 1;
                                    computerMove = computerStoneMove(tempComputerMove);
                                }
                            }
                            break;
                        case 2:
                            userStone = 'X';
                            stoneNumber = checkDiagonal();
                            if (stoneNumber == 2 || stoneNumber == 3) {
                                if (!checkValidColumn(getTargetCol(), computer)
                                        && checkColumnCapasity(getTargetCol(), computer)) {
                                    userStone = 'O';
                                    tempComputerMove = getTargetCol();
                                    computerMove = computerStoneMove(tempComputerMove);
                                }
                            }
                            break;
                        case 3:
                            userStone = 'X';
                            stoneNumber = checkDiagonal();
                            if (stoneNumber == 1 || stoneNumber == 2) {
                                if (!checkValidColumn(getTargetCol() + 1, computer)
                                        && checkColumnCapasity(getTargetCol() + 1, computer)) {
                                    userStone = 'O';
                                    tempComputerMove = getTargetCol() + 1;
                                    computerMove = computerStoneMove(tempComputerMove);
                                }
                            }
                            if (stoneNumber == 3) {
                                if (!checkValidColumn(getTargetCol() - 1, computer)
                                        && checkColumnCapasity(getTargetCol() - 1, computer)) {
                                    userStone = 'O';
                                    tempComputerMove = getTargetCol() - 1;
                                    computerMove = computerStoneMove(tempComputerMove);
                                }
                            }
                            break;
                        case 4:
                            setTargetCol(getTargetCol() - ARTIFICAL_MOVE_NUM);
                            if (getTargetCol() < DECIMAL_LOWER_A)
                                setTargetCol(DECIMAL_LOWER_A);
                            for (int i = 0; i < getGameBoardWidth(); i++) {
                                if (checkColumnCapasity(getTargetCol(), computer)) {
                                    userStone = 'O';
                                    tempComputerMove = getTargetCol();
                                    computerMove = computerStoneMove(tempComputerMove);
                                    i = getGameBoardWidth();
                                }
                                setTargetCol(getTargetCol() + 1);
                                if (getTargetCol() > DECIMAL_LOWER_A + getGameBoardWidth() - 1)
                                    setTargetCol(DECIMAL_LOWER_A);
                            }
                            break;
                    }
                    if (randomMove <= FOUR)
                        ++randomMove;
                    else
                        randomMove = 1;
                }
                /* Check if there are any winners after each move */
                if (checkDiagonal() >= FOUR) {
                    game = false;
                    cout << " Winning Status" << endl;
                    printGameBoard();
                    cout << " Computer won the game" << endl;
                }
                if (game)
                    game = checkEmptyArea();

                setPlayer(true);
                computerMove = true;
            }
        }
    }
}