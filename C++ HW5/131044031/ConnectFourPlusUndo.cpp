#include "ConnectFourPlusUndo.h"
namespace sefanadir {

    int ConnectFourPlusUndo::liveUndoBoardNum = 0;

    /* No parameter constructor */
    ConnectFourPlusUndo::ConnectFourPlusUndo(): ConnectFourPlus(){

    }

    /* The copy constructor */
    ConnectFourPlusUndo::ConnectFourPlusUndo(const ConnectFourPlusUndo& object) {
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

    /* The assignment operator overloading */
    ConnectFourPlusUndo& ConnectFourPlusUndo::operator=(const ConnectFourPlusUndo& object) {
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

    /* This function retrieves the column information from the player and places a    *
     * stone in the empty space in that column.If the column is full or the wrong     *
     * column information is entered, it prompts the player to enter the column again.*/
    int ConnectFourPlusUndo::getPosition(bool& checkCol, int& playerNo, bool pVc) {
        char targetCol;
        string saveAndLoad;
        decltype(saveAndLoad) fileName;
        decltype(saveAndLoad) tempCommand;
        int tempTargetCol = 0, stringSize = 0;
        do {
            cout << " Target Position: ";
            saveAndLoad = "", fileName = "", tempCommand = "";
            getline(cin, saveAndLoad);
            saveAndLoad = destroySpaceCharacters(saveAndLoad, stringSize);
            if (stringSize == 0)
                exit(0);
            else if (stringSize == 1) {
                /* If entered string is single character,         *
                 * assign zero index string to character variable */
                targetCol = saveAndLoad[0];
                if (targetCol >= 'A' && targetCol <= 'Z') {
                    tempTargetCol = targetCol;
                    tempTargetCol += 32;
                } else {
                    tempTargetCol = targetCol;
                }
                if (checkValidColumn(tempTargetCol) == false &&
                        checkColumnCapasity(tempTargetCol) == true)
                    checkCol = false;
            } else {
                if (saveAndLoad[0] == 'S' || saveAndLoad[0] == 's'
                        || saveAndLoad[0] == 'L' || saveAndLoad[0] == 'l'
                        || saveAndLoad[0] == 'U' || saveAndLoad[0] == 'u') {
                    /* Separate command and file name */
                    for (int i = 0; i < stringSize; i++) {
                        if (i < COMMAND_SIZE)
                            tempCommand.push_back(saveAndLoad[i]);
                        else
                            fileName.push_back(saveAndLoad[i]);
                    }
                    /* Check the file name if save command is entered and call saveGameToFile function */
                    if ((tempCommand == "SAVE" || tempCommand == "save") && checkFileName(fileName)) {
                        saveGameToFile(fileName, playerNo);
                        /* Check the file name if load command is entered and call loadGameFromFile function */
                    } else if ((tempCommand == "LOAD" || tempCommand == "load") && checkFileName(fileName)) {
                        loadGameFromFile(fileName, playerNo, pVc);
                    } else if ((tempCommand == "UNDO" || tempCommand == "undo")) {
                        if (checkArea() > 0)
                            loadGameFromUndoBoard(playerNo);
                        else
                            cerr << " Undo can not be performed" << endl;
                    } else {
                        cerr << " Invalid command syntax" << endl;
                    }
                } else {
                    cerr << " Invalid command or column" << endl;
                }
            }
        } while (checkCol);
        saveGameToUndoBoard(playerNo);
        checkCol = true;
        return tempTargetCol;
    }

    /* This function saves game board after each move */
    void ConnectFourPlusUndo::saveGameToUndoBoard(int &playerNo) {

        for (int i = 0; i < getGameBoardHeight(); i++) {
            for (int j = 0; j < getGameBoardWidth(); j++) {
                undoBoard[liveUndoBoardNum].gameBoardUndo[i][j] = gameBoard[i][j].getGameStone();
            }
        }
        undoBoard[liveUndoBoardNum].playerNo = playerNo;
        ++liveUndoBoardNum;
    }

    /* This function can undo the moves of the user or the  *
     * computer until the beginning of the game.            */
    void ConnectFourPlusUndo::loadGameFromUndoBoard(int &playerNo) {
        for (int i = 0; i < getGameBoardHeight(); i++) {
            for (int j = 0; j < getGameBoardWidth(); j++) {
                gameBoard[i][j].setGameStone('*');
            }
        }
        if (liveUndoBoardNum >= 0)
            for (int i = 0; i < getGameBoardHeight(); i++) {
                for (int j = 0; j < getGameBoardWidth(); j++) {
                    gameBoard[i][j].setGameStone(undoBoard[liveUndoBoardNum - 1].gameBoardUndo[i][j]);
                }
            }
        playerNo = undoBoard[liveUndoBoardNum - 1].playerNo;
        --liveUndoBoardNum;
        printGameBoard();
    }

    /* THis function checks game board area for undo operations */
    int ConnectFourPlusUndo::checkArea() {
        int fullBoard = 0;
        for (int i = 0; i < getGameBoardHeight(); ++i) {
            for (int j = 0; j < getGameBoardWidth(); ++j) {
                if (gameBoard[i][j].getGameStone() != '*')
                    ++fullBoard;
            }
        }
        return fullBoard;
    }
}