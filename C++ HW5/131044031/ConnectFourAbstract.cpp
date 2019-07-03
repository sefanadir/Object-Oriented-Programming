#include "ConnectFourAbstract.h"
namespace sefanadir {

    /* The no parameter constructor creates a 5x5 game */
    ConnectFourAbstract::ConnectFourAbstract() {
        setGameBoardWidth(5);
        setGameBoardHeight(5);
        createGameBoard();
        setPlayer(true);
        setPlayerOption('P');
    }

    /* The copy constructor */
    ConnectFourAbstract::ConnectFourAbstract(const ConnectFourAbstract& object) {

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

    /* The constructor takes number of rows and columns as parameters */
    ConnectFourAbstract::ConnectFourAbstract(int width, int height) {
        setGameBoardWidth(width);
        setGameBoardHeight(height);
        createGameBoard();
    }

    /* Destructor */
    ConnectFourAbstract::~ConnectFourAbstract() {
        for (int i = 0; i < getGameBoardHeight(); ++i) {
            delete [] gameBoard[i];
        }
        delete [] gameBoard;
    }

    /* Assignment operator overloading */
    ConnectFourAbstract & ConnectFourAbstract::operator=(const ConnectFourAbstract & object) {

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

    /* This function plays the game by asking the user the board      *
     *  size first then asks the user to play and the computer plays. */
    void ConnectFourAbstract::playGame() {
        getHeightFromUser();
        getWeightFromUser();
        choosePlayer();
        createGameBoard();
        initialGameBoard();
        printGameBoard();
        int tempTargetCol = 0;
        if (getPlayerOption() == 'P' || getPlayerOption() == 'p')
            play(tempTargetCol);
        else if (getPlayerOption() == 'C' || getPlayerOption() == 'c')
            play();
    }

    /* This function retrieves the weight information of the game board           *
     * from the user and checks whether the size of the game board is wrong       */
    int ConnectFourAbstract::getWeightFromUser() {
        int sizeFlag = 1, gameBoardWidth = 0;
        do {
            cout << " Enter weight: ";
            cin>>gameBoardWidth;
            if (cin.fail() || gameBoardWidth < MINIMUM_BOARD_WEIGHT) {
                cin.clear();
                cin.ignore();
                cout << " Weight must be greater than '4'" << endl;
            } else {
                sizeFlag = 0;
            }
        } while (sizeFlag);
        cin.ignore(1000, '\n');
        setGameBoardWidth(gameBoardWidth);
        return gameBoardWidth;
    }

    /* This function retrieves the height information of the game board           *
     * from the user and checks whether the size of the game board is wrong       */
    int ConnectFourAbstract::getHeightFromUser() {
        int sizeFlag = 1, gameBoardHeight = 0;
        do {
            cout << " Enter height: ";
            cin>>gameBoardHeight;
            if (cin.fail() || gameBoardHeight < MINIMUM_BOARD_HEIGHT) {
                cin.clear();
                cin.ignore();
                cout << " Height must be greater than '4'" << endl;
            } else {
                sizeFlag = 0;
            }
        } while (sizeFlag);
        cin.ignore(1000, '\n');
        setGameBoardHeight(gameBoardHeight);
        return gameBoardHeight;
    }

    void ConnectFourAbstract::deleteGameBoard() {
        for (int i = 0; i < getGameBoardHeight(); ++i) {
            delete [] gameBoard[i];
        }
        delete [] gameBoard;
    }

    void ConnectFourAbstract::initialGameBoard() {
        for (int i = 0; i < getGameBoardHeight(); i++) {
            for (int j = 0; j < getGameBoardWidth(); j++) {
                Cell singleCell(i, j, '*');
                gameBoard[i][j] = singleCell;
            }
        }
    }

    void ConnectFourAbstract::createGameBoard() {
        gameBoard = new Cell*[getGameBoardHeight()];
        for (int i = 0; i < getGameBoardHeight(); i++)
            gameBoard[i] = new Cell[getGameBoardWidth()];
    }

    /* This function will show the game board after each move */
    void ConnectFourAbstract::printGameBoard() {
        int tempLocation = DECIMAL_LOWER_A;
        int countSize = 0;
        char realLocation;
        cout << endl;
        for (int i = tempLocation; countSize < getGameBoardWidth(); ++i, ++countSize) {
            realLocation = i;
            cout << " " << realLocation;
        }
        cout << endl;
        for (int i = 0; i < getGameBoardHeight(); i++) {
            for (int j = 0; j < getGameBoardWidth(); j++) {
                if (gameBoard[i][j].getGameStone() == 'X')
                    cout << " " << BOLDBLUE << gameBoard[i][j].getGameStone() << RESET;
                else if (gameBoard[i][j].getGameStone() == 'O')
                    cout << " " << BOLDRED << gameBoard[i][j].getGameStone() << RESET;
                else if (gameBoard[i][j].getGameStone() == 'o' || gameBoard[i][j].getGameStone() == 'x')
                    cout << " " << BOLDGREEN << gameBoard[i][j].getGameStone() << RESET;
                else
                    cout << " " << gameBoard[i][j].getGameStone();
            }
            cout << endl;
        }
    }

    /* This function asks the user whether the game will be played                *
     * against computer or against a player and checks error status               */
    char ConnectFourAbstract::choosePlayer() {
        int playerFlag = 1;
        char playerOption;
        do {
            cout << " Player | Computer: ";
            cin>>playerOption;
            if (playerOption >= 'a' && playerOption <= 'z')
                playerOption -= 32;
            if (!(playerOption == 'C' || playerOption == 'P'))
                cerr << " Invalid game option" << endl;
            else
                playerFlag = 0;
        } while (playerFlag);
        cin.ignore(1000, '\n');
        setPlayerOption(playerOption);
        return playerOption;
    }

    /* This function invokes the necessary functions for the game played          *
     * against the computer or player and starts the game                         */
    void ConnectFourAbstract::startConnectFourGame() {

        if (getPlayerOption() == 'C' || getPlayerOption() == 'c')
            playComputerUser();
        else if (getPlayerOption() == 'P' || getPlayerOption() == 'p')
            playUser1User2();
    }

    void ConnectFourAbstract::findHeightAndWeight(const string & fName) {
        unsigned int boardHeight = 0, boardWidth = 0;
        string line = "";
        fstream gameFile(fName);
        if (gameFile.is_open()) {
            while (getline(gameFile, line)) {
                if (line.size() > boardWidth)
                    boardWidth = line.size();
                ++boardHeight;
            }
        }
        gameFile.close();
        setGameBoardHeight(boardHeight);
        setGameBoardWidth(boardWidth);
    }

    /* This function retrieves the column information from the player and places a    *
     * stone in the empty space in that column.If the column is full or the wrong     *
     * column information is entered, it prompts the player to enter the column again.*/
    int ConnectFourAbstract::getPosition(bool& checkCol, int& playerNo, bool pVc) {
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
                if (saveAndLoad[0] == 'S' || saveAndLoad[0] == 's' ||
                        saveAndLoad[0] == 'L' || saveAndLoad[0] == 'l') {
                    /* Separate command and file name */
                    for (int i = 0; i < stringSize; ++i) {
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
                    } else {
                        cerr << " Invalid command syntax" << endl;
                    }
                } else {
                    cerr << " Invalid command or column" << endl;
                }
            }
        } while (checkCol);
        checkCol = true;
        return tempTargetCol;
    }

    /* This function checks whether the entered column                            *
     * information is within the valid range of characters                        */
    bool ConnectFourAbstract::checkValidColumn(int column, bool computer) {
        int tempLocation = DECIMAL_LOWER_A;
        decltype(tempLocation) countSize = 0;
        bool checkCol = true;
        for (int i = tempLocation; countSize < getGameBoardWidth(); ++i, ++countSize) {
            if (i == column)
                checkCol = false;
        }
        if (checkCol && computer == true)
            cerr << " Invalid target column" << endl;
        return checkCol;
    }

    /* This function checks whether the capacity of the column is full */
    bool ConnectFourAbstract::checkColumnCapasity(int col, bool computer) {
        bool capacity = true;
        int availableLocation = 0;
        int j = col - DECIMAL_LOWER_A;
        for (int i = getGameBoardHeight() - 1; i >= 0; --i) {
            if (gameBoard[i][j].getGameStone() == '*')
                ++availableLocation;
        }
        if (availableLocation == 0) {
            if (computer)
                cerr << " Invalid move current column" << endl;
            capacity = false;
        }
        return capacity;
    }

    /* This function removes extra spaces in the command and file name */
    string ConnectFourAbstract::destroySpaceCharacters(string commandSaveLoad, int& stringSize) {
        string saveAndLoad = "";
        int size = 0;
        for (int i = 0; commandSaveLoad[i] != '\0'; ++i) {
            if (commandSaveLoad[i] != ' ') {
                saveAndLoad.push_back(commandSaveLoad[i]);
                ++size;
            }
        }
        stringSize = size;
        return saveAndLoad;
    }

    /* This function checks the extension information of the file */
    bool ConnectFourAbstract::checkFileName(const string& fileName) {
        string fileExtension = "";
        int fileSize = fileName.size();
        for (int i = fileSize - FILE_EXTENSION; i < fileSize; ++i)
            fileExtension.push_back(fileName[i]);
        if (fileExtension == ".txt" || fileExtension == ".TXT")
            return true;
        else {
            cerr << " Invalid file extension" << endl;
            return false;
        }
    }

    /* This function checks whether the game board is full */
    bool ConnectFourAbstract::checkEmptyArea() {
        int fullBoard = 0;
        int totalIndex = getGameBoardHeight() * getGameBoardWidth();
        for (int i = 0; i < getGameBoardHeight(); ++i) {
            for (int j = 0; j < getGameBoardWidth(); ++j) {
                if (gameBoard[i][j].getGameStone() != '*')
                    ++fullBoard;
            }
        }
        if (fullBoard == totalIndex) {
            cout << " Game Over Board Ground Full" << endl;
            return false;
        } else
            return true;
    }

    /* This function calculates the number of rows and places the stone at        *
     * the empty position in the column for player move                           */
    void ConnectFourAbstract::putStone(int tempTargetCol) {
        bool availableLocation = false;
        int j = tempTargetCol - DECIMAL_LOWER_A;
        for (int i = getGameBoardHeight() - 1; availableLocation == false; --i) {
            if (gameBoard[i][j].getGameStone() == '*')
                availableLocation = true;
            if (availableLocation) {
                gameBoard[i][j].setGameStone(userStone);
            }
        }
    }

    /* This function places the stone at empty position for computer move */
    void ConnectFourAbstract::play() {
        startConnectFourGame();
    }

    /* This function places the stone at empty position for player move */
    void ConnectFourAbstract::play(int tempTargetCol) {
        setTargetCol(tempTargetCol);
        startConnectFourGame();
    }

    /* This function checks whether there are four stones diagonally */
    int ConnectFourAbstract::checkDiagonal() {
        int wonIndeks[4][2];
        int col = 0, row = 0, tempRow = 0;
        int maxStone = 0, countStone = 0, store = 0;
        int gameBoardSize = 0;
        if (getGameBoardHeight() > getGameBoardWidth())
            gameBoardSize = getGameBoardHeight();
        else
            gameBoardSize = getGameBoardWidth();

        while (row < gameBoardSize) {
            while (row >= 0) {
                if (row < getGameBoardHeight() && col < getGameBoardWidth()) {
                    if (gameBoard[row][col].getGameStone() == userStone) {
                        /* Store the location information of matching stones */
                        if (store < FOUR) {
                            wonIndeks[store][0] = row;
                            wonIndeks[store][1] = col;
                            ++store;
                        }
                        ++countStone;
                        /* Determine the number of the most repeated stones in the diagonal */
                        if (countStone > maxStone) {
                            maxStone = countStone;
                            convertToLowerCase(wonIndeks, maxStone);
                        }
                    } else {
                        /* If the stone is not equal to player stone, reset *
                         * number of countStone and store in column change  */
                        countStone = 0, store = 0;
                    }
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
                if (row < getGameBoardHeight() && col < getGameBoardWidth()) {
                    if (gameBoard[row][col].getGameStone() == userStone) {
                        if (store < FOUR) {
                            /* Store the location information of matching stones */
                            wonIndeks[store][0] = row;
                            wonIndeks[store][1] = col;
                            ++store;
                        }
                        ++countStone;
                        /* Determine the number of the most repeated stones in the diagonal */
                        if (countStone > maxStone) {
                            maxStone = countStone;
                            convertToLowerCase(wonIndeks, maxStone);
                        }
                    } else {
                        /* If the stone is not equal to player stone, reset *
                         * number of countStone and store in column change  */
                        countStone = 0, store = 0;
                    }
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
                if (row < getGameBoardHeight() && col < getGameBoardWidth()) {
                    if (gameBoard[row][col].getGameStone() == userStone) {
                        if (store < FOUR) {
                            /* Store the location information of matching stones */
                            wonIndeks[store][0] = row;
                            wonIndeks[store][1] = col;
                            ++store;
                        }
                        ++countStone;
                        /* Determine the number of the most repeated stones in the diagonal */
                        if (countStone > maxStone) {
                            maxStone = countStone;
                            convertToLowerCase(wonIndeks, maxStone);
                        }
                    } else {
                        /* If the stone is not equal to player stone, reset *
                         * number of countStone and store in column change  */
                        countStone = 0, store = 0;
                    }
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
                if (row < getGameBoardHeight() && col < getGameBoardWidth()) {
                    if (gameBoard[row][col].getGameStone() == userStone) {
                        if (store < FOUR) {
                            /* Store the location information of matching stones */
                            wonIndeks[store][0] = row;
                            wonIndeks[store][1] = col;
                            ++store;
                        }
                        ++countStone;
                        /* Determine the number of the most repeated stones in the diagonal */
                        if (countStone > maxStone) {
                            maxStone = countStone;
                            convertToLowerCase(wonIndeks, maxStone);
                        }
                    } else {
                        /* If the stone is not equal to player stone, reset *
                         * number of countStone and store in column change  */
                        countStone = 0, store = 0;
                    }
                }
                ++row, ++col;
            }
            --tempRow;
            row = tempRow, col = 0;
            countStone = 0, store = 0;
        }
        return maxStone;
    }

    /* This function checks whether there are four stones horizontally */
    int ConnectFourAbstract::checkHorizontal() {
        int wonIndeks[4][2];
        int maxStone = 0, countStone = 0, store = 0;
        for (int i = 0; i < getGameBoardHeight(); ++i) {
            for (int j = 0; j < getGameBoardWidth(); ++j) {
                if (gameBoard[i][j].getGameStone() == userStone) {
                    /* Store the location information of matching stones */
                    if (store < FOUR) {
                        wonIndeks[store][0] = i;
                        wonIndeks[store][1] = j;
                        ++store;
                    }
                    ++countStone;
                    /* Determine the number of the most repeated stones in the horizontal */
                    if (countStone > maxStone) {
                        maxStone = countStone;
                        convertToLowerCase(wonIndeks, maxStone);
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

    /* This function checks whether there are four stones vertically */
    int ConnectFourAbstract::checkVertical() {
        int wonIndeks[4][2];
        int maxStone = 0, countStone = 0, store = 0;
        for (int i = 0; i < getGameBoardWidth(); ++i) {
            for (int j = 0; j < getGameBoardHeight(); ++j) {
                if (gameBoard[j][i].getGameStone() == userStone) {
                    /* Store the location information of matching stones */
                    if (store < FOUR) {
                        wonIndeks[store][0] = j;
                        wonIndeks[store][1] = i;
                        ++store;
                    }
                    ++countStone;
                    /* Determine the number of the most repeated stones in the vertical */
                    if (countStone > maxStone) {
                        maxStone = countStone;
                        convertToLowerCase(wonIndeks, maxStone);
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

    /* This function checks whether there are four stones vertically */
    void ConnectFourAbstract::convertToLowerCase(int wonIndeks[][2], int maxStone) {
        if (maxStone >= FOUR) {
            for (int i = 0; i < FOUR; ++i) {
                for (int j = 0; j < 1; ++j) {
                    gameBoard[wonIndeks[i][j]][wonIndeks[i][j + 1]].setGameStone(userStone + CONVERT_LOWER_CASE);
                }
            }
        }
    }

    /* When save command is entered, the last state of the game, the size of    *
     * the game board and the information of the player are stored in the file. */
    void ConnectFourAbstract::saveGameToFile(const string& fileName, int playerNo) {
        ofstream gameFile(fileName);
        if (!gameFile.is_open())
            cerr << " Cannot to open the file" << endl;
        else {
            gameFile << getGameBoardWidth() << '\n';
            gameFile << getGameBoardHeight() << '\n';
            for (int i = 0; i < getGameBoardHeight(); i++) {
                for (int j = 0; j < getGameBoardWidth(); j++) {
                    gameFile << gameBoard[i][j].getGameStone();
                }
                gameFile << '\n';
            }
            gameFile << playerNo << '\n';
        }
        gameFile.close();
    }

    /* When the load command is entered, last state of the game, the size of the    *
     * game board and the information of the player are installed from file to game */
    void ConnectFourAbstract::loadGameFromFile(string fileName, int& playerNo, bool pVc) {
        string line = "";
        fstream gameFile(fileName);
        if (!gameFile.is_open())
            cerr << " Cannot to open the file" << endl;
        else {
            getline(gameFile, line);
            setGameBoardWidth(convertStringToNumber(line));

            getline(gameFile, line);
            setGameBoardHeight(convertStringToNumber(line));
            deleteGameBoard();
            initialGameBoard();

            for (int i = 0; i < getGameBoardHeight(); i++) {
                getline(gameFile, line);
                for (int j = 0; j < getGameBoardWidth(); j++) {
                    gameBoard[i][j].setGameStone(line[j]);
                }
            }
            getline(gameFile, line);
            playerNo = convertStringToNumber(line);
            printGameBoard();
            if (pVc)
                cout << " PLAYER" << endl;
            else
                cout << " PLAYER " << playerNo << endl;
        }
    }

    /* This function converts the strings read from the file to numbers */
    int ConnectFourAbstract::convertStringToNumber(const string& fileString) {
        char numberCharacter;
        int stringSize = fileString.size();
        decltype(stringSize) realNumber = 0;
        for (int i = 0; i < stringSize; ++i) {
            numberCharacter = fileString[i];
            realNumber += (numberCharacter - DECIMAL_CONVERT_NUM) * pow(10, stringSize - 1 - i);
        }
        return realNumber;
    }

    /* This function puts a stone in the selected position by the computer */
    bool ConnectFourAbstract::computerStoneMove(int tempTargetCol) {
        putStone(tempTargetCol);
        cout << " Computer Move" << endl;
        printGameBoard();
        cout << endl;
        return false;
    }
}