#include <iostream>

#include "board.h"

int main() {
    auto* board = new Board("r1bk3r/p2pBpNp/n4n2/1p1NP2P/6P1/3P4/P1P1K3/q5b1");
    board->displayBoard();
    delete board;
    return 0;
}
