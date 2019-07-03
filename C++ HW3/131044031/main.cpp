/*----------------------------CONNECT FOUR------------------------------------*
 * This program will play the game of Connect Four. The game of Connect Four  *
 * is played by two players computer-user or user1-user2 on a two dimensional *
 * board with rectangular cells. Each cell is either computer, user, or empty.*/
#include "RequiredIncludes.h"
string getGameModeFromUser();
int getWeightFromUser();
int getHeightFromUser();
char choosePlayer();
int selectObject();
void compare(int &compareFlag);
int getTargetColumn(ConnectFour &game);

int main(int argc, char** argv) {
    string gameMode;
    char objectOption;
    int objectWeight = 0, objectHeight = 0;
    int compareFlag = 0, compareObj = 0, objectNumber = 0;

    gameMode = getGameModeFromUser();
    MultipleObject gameObjects[OBJECT_NUM];

    if (gameMode == "M" || gameMode == "m") {
        for (int i = 0; i < OBJECT_NUM; i++) {
            cout << " Object" << i + 1 << endl;

            objectWeight = getWeightFromUser();
            gameObjects[i].setWeight(objectWeight);

            objectHeight = getHeightFromUser();
            gameObjects[i].setHeight(objectHeight);

            objectOption = choosePlayer();
            gameObjects[i].setOption(objectOption);
            cout << endl;
        }
    }
    ConnectFour game;
    ConnectFour compGame(4, 4, 'P', "M");
    ConnectFour gameObj1(gameObjects[0].getWeight(), gameObjects[0].getHeight(), gameObjects[0].getOption(), gameMode);
    ConnectFour gameObj2(gameObjects[1].getWeight(), gameObjects[1].getHeight(), gameObjects[1].getOption(), gameMode);
    ConnectFour gameObj3(gameObjects[2].getWeight(), gameObjects[2].getHeight(), gameObjects[2].getOption(), gameMode);
    ConnectFour gameObj4(gameObjects[3].getWeight(), gameObjects[3].getHeight(), gameObjects[3].getOption(), gameMode);
    ConnectFour gameObj5(gameObjects[4].getWeight(), gameObjects[4].getHeight(), gameObjects[4].getOption(), gameMode);

    if (gameMode == "S" || gameMode == "s") {
        game.playGame();
    } else if (gameMode == "M" || gameMode == "m") {
        while (gameObj1.getFinishObje() || gameObj2.getFinishObje() ||
                gameObj3.getFinishObje() || gameObj4.getFinishObje() || gameObj5.getFinishObje()) {
            objectNumber = selectObject();
            ++compareFlag;
            cout << endl;

            switch (objectNumber) {

                case 1:
                    if (gameObj1.getFinishObje()) {

                        gameObj1.printGameBoard();
                        if (gameObj1.getPlayerOption() == 'P') {
                            gameObj1.play(getTargetColumn(gameObj1));

                            if (gameObj1.getFinishObje())
                                gameObj1.play(getTargetColumn(gameObj1));

                        } else {
                            gameObj1.play(getTargetColumn(gameObj1));
                            if (gameObj1.getFinishObje())
                                gameObj1.play();
                        }

                        if (compareFlag == 2) {
                            if (gameObj1.compareObjects(compGame))
                                cout << " 1. game is better than " << compareObj << ". game" << endl;
                            else
                                cout << " " << compareObj << ". game is better than 1. game or games are draw" << endl;
                            compareFlag = 0;
                        } else {
                            compGame = gameObj1;
                            compareObj = 1;
                        }
                    } else
                        cerr << " The first game is over" << endl;
                    break;
                case 2:
                    if (gameObj2.getFinishObje()) {

                        gameObj2.printGameBoard();
                        if (gameObj2.getPlayerOption() == 'P') {

                            gameObj2.play(getTargetColumn(gameObj2));

                            if (gameObj2.getFinishObje())
                                gameObj2.play(getTargetColumn(gameObj2));

                        } else {
                            gameObj2.play(getTargetColumn(gameObj2));

                            if (gameObj2.getFinishObje())
                                gameObj2.play();
                        }

                        if (compareFlag == 2) {
                            if (gameObj2.compareObjects(compGame))
                                cout << " 2. game is better than " << compareObj << ". game" << endl;
                            else
                                cout << " " << compareObj << ". game is better than 2. game or games are draw" << endl;
                            compareFlag = 0;
                        } else {
                            compGame = gameObj2;
                            compareObj = 2;
                        }
                    } else
                        cerr << " The second game is over" << endl;
                    break;
                case 3:
                    if (gameObj3.getFinishObje()) {

                        gameObj3.printGameBoard();
                        if (gameObj3.getPlayerOption() == 'P') {
                            gameObj3.play(getTargetColumn(gameObj3));

                            if (gameObj3.getFinishObje())
                                gameObj3.play(getTargetColumn(gameObj3));

                        } else {
                            gameObj3.play(getTargetColumn(gameObj3));
                            if (gameObj3.getFinishObje())
                                gameObj3.play();
                        }
                        if (compareFlag == 2) {
                            if (gameObj3.compareObjects(compGame))
                                cout << " 3. game is better than " << compareObj << ". game" << endl;
                            else
                                cout << " " << compareObj << ". game is better than 4. game or games are draw" << endl;
                            compareFlag = 0;
                        } else {
                            compGame = gameObj3;
                            compareObj = 3;
                        }
                    } else
                        cerr << " The third game is over" << endl;
                    break;
                case 4:
                    if (gameObj4.getFinishObje()) {

                        gameObj4.printGameBoard();
                        if (gameObj4.getPlayerOption() == 'P') {
                            gameObj4.play(getTargetColumn(gameObj4));

                            if (gameObj4.getFinishObje())
                                gameObj4.play(getTargetColumn(gameObj4));
                        } else {
                            gameObj4.play(getTargetColumn(gameObj4));
                            if (gameObj4.getFinishObje())
                                gameObj4.play();
                        }
                        if (compareFlag == 2) {
                            if (gameObj4.compareObjects(compGame))
                                cout << " 4. game is better than " << compareObj << ". game" << endl;
                            else
                                cout << " " << compareObj << ". game is better than 4. game or games are draw" << endl;
                            compareFlag = 0;
                        } else {
                            compGame = gameObj4;
                            compareObj = 4;
                        }
                    } else
                        cerr << " The fourth game is over" << endl;
                    break;
                case 5:
                    if (gameObj5.getFinishObje()) {

                        gameObj5.printGameBoard();
                        if (gameObj5.getPlayerOption() == 'P') {
                            gameObj5.play(getTargetColumn(gameObj5));

                            if (gameObj5.getFinishObje())
                                gameObj5.play(getTargetColumn(gameObj5));

                        } else {
                            gameObj5.play(getTargetColumn(gameObj5));

                            if (gameObj5.getFinishObje())
                                gameObj5.play();
                        }
                        if (compareFlag == 2) {
                            if (gameObj5.compareObjects(compGame))
                                cout << " 5. game is better than " << compareObj << ". game" << endl;
                            else
                                cout << " " << compareObj << ". game is better than 5. game or games are draw" << endl;
                            compareFlag = 0;
                        } else {
                            compGame = gameObj5;
                            compareObj = 5;
                        }
                    } else
                        cerr << " The fifth game is over" << endl;
                    break;
                default:
                    cerr << " Invalid object number" << endl;
            }
        }
        cerr << " All game is over" << endl;
    }
    return 0;
}

string getGameModeFromUser() {
    string mode;
    int flag = 1;
    do {
        cout << " Select game mode: ";
        cin>>mode;
        if (!(mode.size() == 1) &&((mode == "M" || mode == "m") || (mode == "S" || mode == "s")))
            cerr << " Invalid game mode" << endl;
        else
            flag = 0;
    } while (flag == 1);
    return mode;
}

/* This function retrieves the weight information of the game board           *
 * from the user and checks whether the size of the game board is wrong       */
int getWeightFromUser() {
    int sizeFlag = 1, gameBoardWeight = 0;
    do {
        cout << " Enter weight: ";
        cin>>gameBoardWeight;
        if (cin.fail() || gameBoardWeight < MINIMUM_BOARD_WEIGHT) {
            cin.clear();
            cin.ignore();
            cout << " Weight must be greater than '4'" << endl;
        } else {
            sizeFlag = 0;
        }
    } while (sizeFlag);
    cin.ignore(500, '\n');
    return gameBoardWeight;
}

/* This function retrieves the height information of the game board           *
 * from the user and checks whether the size of the game board is wrong       */
int getHeightFromUser() {
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
    cin.ignore(500, '\n');
    return gameBoardHeight;
}

/* This function asks the user whether the game will be played                *
 * against computer or against a player and checks error status               */
char choosePlayer() {
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
    cin.ignore(500, '\n');
    return playerOption;
}

int selectObject() {
    int sizeFlag = 1, objectNumber = 0;
    do {
        cout << " Select Object:";
        cin>>objectNumber;
        if (cin.fail() || objectNumber > OBJECT_NUM || objectNumber < 1) {
            cin.clear();
            cin.ignore();
            cout << " Object number is  must be between '1'-'5'" << endl;
        } else {
            sizeFlag = 0;
        }
    } while (sizeFlag);
    cin.ignore(500, '\n');
    return objectNumber;
}

int getTargetColumn(ConnectFour &game) {
    int tempLocation = DECIMAL_LOWER_A, countSize = 0;
    bool checkCol = true, capasity = false;
    char targetCol;
    int column;
    do {
        cout << " Target Position: ";
        cin>>targetCol;
        cin.ignore(500, '\n');
        column = targetCol;
        if (column >= 'A' && column <= 'Z') {
            column = targetCol;
            column += 32;
        }
        for (int i = tempLocation; countSize < game.getGameBoardWeight(); ++i, ++countSize) {
            if (i == column) {
                checkCol = false;
                countSize = game.getGameBoardWeight();
            }
        }
        if (checkCol) {
            cerr << " Invalid target column" << endl;
        }
        capasity = game.checkColumnCapasity(column);
    } while (checkCol && !capasity);
    return column;
}