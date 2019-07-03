/*----------------------------CONNECT FOUR------------------------------------*
 * This program will play the game of Connect Four. The game of Connect Four  *
 * is played by two players computer-user or user1-user2 on a two dimensional *
 * board with rectangular cells. Each cell is either computer, user, or empty.*/

#include "RequiredIncludes.h"

char selectObject();

int main(int argc, char** argv) {
    ConnectFourPlus gamePlus;
    ConnectFourDiag gameDiag;
    ConnectFourPlusUndo gameUndo;

    char objectType = selectObject();
    if (objectType == 'P')
        gamePlus.playGame();

    if (objectType == 'D')
        gameDiag.playGame();

    if (objectType == 'U')
        gameUndo.playGame();
    return 0;
}

char selectObject() {
    char mode;
    int flag = 1;
    while (flag == 1) {
        cout << " Game object : ";
        cin>>mode;
        if (mode >= 'a' && mode <= 'z')
            mode = mode - 32;
        if (!((mode == 'D') || (mode == 'P') || (mode == 'U')))
            cerr << " Invalid game mode" << endl;
        else
            flag = 0;
    }
    return mode;
}


