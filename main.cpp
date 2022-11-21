#include "tictactoe.hpp"

int isNotZero(unsigned int n) { //logarithmic 
    n |= n >> 16;
    n |= n >> 8;
    n |= n >> 4;
    n |= n >> 2;
    n |= n >> 1;
    return n & 1;
};
TicTacToe game = TicTacToe();
typedef void(*function)();

void getMove() { 
    game.print();
    unsigned int move;
    
    std::cout << "Enter move: " << std::endl;
    std::cin >> move;

    game.makeMove(1 << (move - 1));
}

void gameEndMessage() {
    game.print();
    static std::string end[4] = {"", "Game is a draw!", "Crosses win!", "Circles win!"};
    std::cout << end[isNotZero(game.isWin()) + 1 + (game.currentPlayer() ^ 1)] << std::endl;
}


void runGame() {
    function f[] = {runGame, gameEndMessage};

    getMove();
    f[game. () | game.isDraw()]();
    
}


int main() {
    runGame();
    



    return 0;
}