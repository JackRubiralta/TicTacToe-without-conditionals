#include "tictactoe.hpp"

TicTacToe game = TicTacToe();
typedef void(*function)();

void getMove() { 
    system("CLS"); // clear terminal

    game.print();
    char moveX;
    char moveY;
    
    std::cout << "\n" << "Enter move: ";
    std::cin >> moveX >> moveY;
  
    game.makeMove(1 << ((moveY - '0' - 1) * 3 + (moveX - '0' - 1)));
}

void gameEndMessage() {
    system("CLS");
    game.print();
    static std::string end[4] = {"", "Game is a draw!", "Crosses win!", "Circles win!"};
    std::cout << end[isNotZero(game.isWin()) + 1 + (game.currentPlayer() ^ 1)] << std::endl;
}


void runGame() {
    function f[] = {runGame, gameEndMessage};

    getMove();
    f[game.isWin() | game.isDraw()]();
    
}


int main() {
    runGame();
    



    return 0;
}