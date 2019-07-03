/* The class ConnectFourPlus will derive from the abstract class. It will play *
 * very similar to regular. Connect Four but it will only accept horizontally  *
 * or vertically connected cells as the goal of the game.                      */
#ifndef CONNECTFOURPLUS_H
#define CONNECTFOURPLUS_H
#include "ConnectFourAbstract.h"
namespace sefanadir {

    class ConnectFourPlus : public ConnectFourAbstract {
    public:
        ConnectFourPlus();
        ConnectFourPlus(const ConnectFourPlus & object);
        ConnectFourPlus & operator=(const ConnectFourPlus &object);
    protected:
        virtual void playUser1User2() override;
        virtual void playComputerUser()override;
    };
}
#endif /* CONNECTFOURPLUS_H */

