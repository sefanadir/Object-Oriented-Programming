/* The class ConnectFourDiag will derive from the abstract class. It will play *
 * very similar to regular Connect Four but it will only accept diagonally     *
 * connected cells as the goal of the game.                                    */

#ifndef CONNECTFOURDIAG_H
#define CONNECTFOURDIAG_H
#include "ConnectFourAbstract.h"
namespace sefanadir {

    class ConnectFourDiag : public ConnectFourAbstract {
    public:
        ConnectFourDiag();
        ConnectFourDiag(const ConnectFourDiag & object);
        ConnectFourDiag & operator=(const ConnectFourDiag &object);
    protected:
        virtual void playUser1User2() override final;
        virtual void playComputerUser()override final;
    };
}
#endif /* CONNECTFOURDIAG_H */

