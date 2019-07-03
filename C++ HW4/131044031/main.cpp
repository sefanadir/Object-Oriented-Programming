/*----------------------------CONNECT FOUR------------------------------------*
 * This program will play the game of Connect Four. The game of Connect Four  *
 * is played by two players computer-user or user1-user2 on a two dimensional *
 * board with rectangular cells. Each cell is either computer, user, or empty.*/
#include "RequiredIncludes.h"
string getGameModeFromUser();
int selectObject();

int main(int argc, char** argv) {
    string gameMode, fileName = "";
    int objectNumber = 0;
    ConnectFour game;

    gameMode = getGameModeFromUser();
    MultipleObject gameObjects[OBJECT_NUM];

    if (gameMode == "M" || gameMode == "m") {
        for (int i = 0; i < OBJECT_NUM; i++) {
            cout << " Object" << i + 1 << endl;
            cout << " Board file name: ";
            cin>>fileName;
            gameObjects[i].setBoardName(fileName);
            gameObjects[i].setOption(game.choosePlayer());
            cout << endl;
        }
    }
    ConnectFour gameObj1(gameObjects[0].getBoardFile(), gameObjects[0].getOption(), gameMode);
    ConnectFour gameObj2(gameObjects[1].getBoardFile(), gameObjects[1].getOption(), gameMode);
    ConnectFour gameObj3(gameObjects[2].getBoardFile(), gameObjects[2].getOption(), gameMode);
    ConnectFour gameObj4(gameObjects[3].getBoardFile(), gameObjects[3].getOption(), gameMode);
    ConnectFour gameObj5(gameObjects[4].getBoardFile(), gameObjects[4].getOption(), gameMode);
    if (gameMode == "S" || gameMode == "s") {
        game.playGame();
    } else if (gameMode == "M" || gameMode == "m") {
        while (gameObj1.getFinishObje() || gameObj2.getFinishObje() ||
                gameObj3.getFinishObje() || gameObj4.getFinishObje() || gameObj5.getFinishObje()) {

            objectNumber = selectObject();
            cout << endl;
            switch (objectNumber) {
                case 1:
                    if (gameObj1.getFinishObje()) {
                        gameObj1.playGame();
                        if (gameObj1 == gameObj2)
                            cout << " 1. object and 2. object are same " << endl;
                        else if (!(gameObj1 != gameObj2))
                            cout << " 1. object and 2. object are not same " << endl;
                    } else
                        cerr << " The first game is over" << endl;
                    break;
                case 2:
                    if (gameObj2.getFinishObje()) {
                        gameObj2.playGame();
                        if (gameObj2 == gameObj1)
                            cout << " 2. object and 1. object are same " << endl;
                        else if (!(gameObj1 != gameObj2))
                            cout << " 2. object and 1. object are not same " << endl;
                    } else
                        cerr << " The second game is over" << endl;
                    break;
                case 3:
                    if (gameObj3.getFinishObje()) {
                        gameObj3.playGame();
                    } else
                        cerr << " The third game is over" << endl;
                    break;
                case 4:
                    if (gameObj4.getFinishObje()) {
                        gameObj4.playGame();
                    } else
                        cerr << " The fourth game is over" << endl;
                    break;
                case 5:
                    if (gameObj5.getFinishObje()) {
                        gameObj5.playGame();
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

