#ifndef UNDO_H
#define UNDO_H

using namespace std;
namespace sefanadir {

    class Undo {
    public:
        Undo(){
            playerNo=0;
            for (int i = 0; i < 100; i++) {
                for (int j = 0; j < 100; j++) {
                    gameBoardUndo[i][j]='*';
                }
            }
        }
        int playerNo;
        char gameBoardUndo[100][100];
    };
}
#endif /* UNDO_H */

