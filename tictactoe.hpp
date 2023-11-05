
#include <iostream>
#include <string>

// == 
// bool
// !=
// 



using bitboard = uint32_t; 

bitboard isNotZero(bitboard n) { //logarithmic 
    n |= n >> 16;
    n |= n >> 8;
    n |= n >> 4;
    n |= n >> 2;
    n |= n >> 1;
    return n & 1;
};
class TicTacToe {
    public:
        bitboard pos; 
        bitboard mask;
        unsigned int moveCounter = 0;


        TicTacToe() {
            pos = 0;
            mask = 0;
        };

        unsigned int currentPlayer() const { 
            return moveCounter & 1; // using & to check if moveCounter is odd or even 
        }
        
        void makeMove(bitboard move) {
            pos ^= mask; // pos becomes other player board by switching the bits
            mask |= move; // add move to mask 
            moveCounter++;
        };

        unsigned int isWin() const {
            // horizontal 
            bitboard c = pos ^ mask; // bits player who just played is c
            unsigned int w = 0; // cant use if so we w represents a bool
            // w = 0: false
            // w != 0: true
            
            // using XOR instead of == to check condition again
            // !(x ^ y); return 0 if they are not equal

            // check all winning positions
            w |= !((c & 0b111000000) ^ 0b111000000); 
            w |= !((c & 0b000111000) ^ 0b000111000);
            w |= !((c & 0b000000111) ^ 0b000000111);
            w |= !((c & 0b100100100) ^ 0b100100100);
            w |= !((c & 0b010010010) ^ 0b010010010);
            w |= !((c & 0b001001001) ^ 0b001001001);
            w |= !((c & 0b100010001) ^ 0b100010001);
            w |= !((c & 0b001010100) ^ 0b001010100);


            return w;
        };

        unsigned int isDraw() const {
            // using XOR instead of == to check if board is full, all bits are activated

            return !(0b111111111 ^ mask); // samething shown in isWin
        }


        void print() const {
            std::string arrayboard[9];
           

            bitboard player_positions[2] = {pos, pos ^ mask};  // instead of using (currentPlayer() == 1 ? pos : pos ^ mask)
            std::string markers[3] = {" - ", " \u001b[34mX\u001b[0m ", " \u001b[35mO\u001b[0m "};
            
            arrayboard[0] = markers[isNotZero((((bitboard)1 << 0) & mask)) + isNotZero((((bitboard)1 << 0) & player_positions[currentPlayer() ^ 1]))]; 
            arrayboard[1] = markers[isNotZero((((bitboard)1 << 1) & mask)) + isNotZero((((bitboard)1 << 1) & player_positions[currentPlayer() ^ 1]))]; 
            arrayboard[2] = markers[isNotZero((((bitboard)1 << 2) & mask)) + isNotZero((((bitboard)1 << 2) & player_positions[currentPlayer() ^ 1]))]; 
            arrayboard[3] = markers[isNotZero((((bitboard)1 << 3) & mask)) + isNotZero((((bitboard)1 << 3) & player_positions[currentPlayer() ^ 1]))]; 
            arrayboard[4] = markers[isNotZero((((bitboard)1 << 4) & mask)) + isNotZero((((bitboard)1 << 4) & player_positions[currentPlayer() ^ 1]))]; 
            arrayboard[5] = markers[isNotZero((((bitboard)1 << 5) & mask)) + isNotZero((((bitboard)1 << 5) & player_positions[currentPlayer() ^ 1]))]; 
            arrayboard[6] = markers[isNotZero((((bitboard)1 << 6) & mask)) + isNotZero((((bitboard)1 << 6) & player_positions[currentPlayer() ^ 1]))]; 
            arrayboard[7] = markers[isNotZero((((bitboard)1 << 7) & mask)) + isNotZero((((bitboard)1 << 7) & player_positions[currentPlayer() ^ 1]))]; 
            arrayboard[8] = markers[isNotZero((((bitboard)1 << 8) & mask)) + isNotZero((((bitboard)1 << 8) & player_positions[currentPlayer() ^ 1]))]; 
            
            std::cout << "----------------" << std::endl;
            std::cout << "|" << arrayboard[6] << "|" << arrayboard[7] << "|" << arrayboard[8] << "| 3" << std::endl;
            std::cout << "----------------" << std::endl;
            std::cout << "|" << arrayboard[3] << "|" << arrayboard[4] << "|" << arrayboard[5] << "| 2 " << std::endl;
            std::cout << "----------------" << std::endl;
            std::cout << "|" << arrayboard[0] << "|" << arrayboard[1] << "|" << arrayboard[2] << "| 1" << std::endl;
            std::cout << "----------------" << std::endl;
            std::cout << "| 1 | 2 | 3 |" << std::endl;
        }
};