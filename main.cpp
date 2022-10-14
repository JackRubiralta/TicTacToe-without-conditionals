#include "tictactoe.hpp"

int isNotZero(unsigned int n) { //logarithmic 
    n |= n >> 16;
    n |= n >> 8;
    n |= n >> 4;
    n |= n >> 2;
    n |= n >> 1;
    return n & 1;
};

int main() {
    TicTacToe game = TicTacToe();
    unsigned int moveX;
    unsigned int moveY;

    unsigned int move;

    for (int done = 0; !(game.isWin() | game.isDraw()); ) { // kinda cheating but works
        game.print();
        std::cout << "enter x position: " << std::endl;
        std::cin >> moveX;
        std::cout << "enter y position: " << std::endl;
        std::cin >> moveY;
        move = moveY * 3 + moveX;

        game.makeMove(1 << move);
        
       
        
    }
    game.print();

    std::string end[4] = {"", "game is draw", "crosses win", "circles win"};
    std::cout << end[isNotZero(game.isWin()) + 1 + (game.currentPlayer() ^ 1)] << std::endl;

    return 0;
}