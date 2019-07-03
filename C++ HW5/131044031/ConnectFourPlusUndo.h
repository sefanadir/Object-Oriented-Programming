/* The class ConnectFourPlusUndo will be very similar to ConnectFourPlus.It can  *
 * undo the moves of the user or the computer until the beginning of the game    */
#ifndef CONNECTFOURPLUSUNDO_H
#define CONNECTFOURPLUSUNDO_H
#include "ConnectFourPlus.h"
#include "Undo.h"
namespace sefanadir {

    class ConnectFourPlusUndo : public ConnectFourPlus {
    public:
        ConnectFourPlusUndo();
        ConnectFourPlusUndo(const ConnectFourPlusUndo & object);
        ConnectFourPlusUndo & operator=(const ConnectFourPlusUndo &object);
    protected:
        Undo undoBoard[100];
        static int liveUndoBoardNum;
        int checkArea();
        void saveGameToUndoBoard(int &playerNo);
        void loadGameFromUndoBoard(int &playerNo);
        virtual int getPosition(bool& checkCol, int& playerNo, bool pVc = true) override final;
    };
}
#endif /* CONNECTFOURPLUSUNDO_H */

