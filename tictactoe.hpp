
#include <iostream>
#include <string>


using bitboard = uint32_t; 
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
            std::string arrayboard[9] = {" - ", " - ", " - ", " - ", " - ", " - ", " - ", " - ", " - "};
           

            bitboard player_positions[2] = {pos, pos ^ mask};  // instead of using (currentPlayer() == 1 ? pos : pos ^ mask)
            std::string markers[3] = {" - ", " X ", " O "};
            
            for (int i = 0; i < 9; i++) {
                // this one was hard to think of
                arrayboard[i] = markers[((((bitboard)1 << i) & mask) != 0) + ((((bitboard)1 << i) & player_positions[currentPlayer() ^ 1]) != 0)]; 
                //arrayboard[i] = markers[(((bitboard)1 << i) & player_positions[currentPlayer()]) != 0];
                //arrayboard[i] = markers[(((((bitboard)1 << i) & player_positions[currentPlayer() ^ 1] != 0)))];

                 
            }

            std::cout << "-----------------" << std::endl;
            std::cout << "| 2 |" << arrayboard[6] << "|" << arrayboard[7] << "|" << arrayboard[8] << "|" << std::endl;
            std::cout << "-----------------" << std::endl;
            std::cout << "| 1 |" << arrayboard[3] << "|" << arrayboard[4] << "|" << arrayboard[5] << "|" << std::endl;
            std::cout << "-----------------" << std::endl;
            std::cout << "| 0 |" << arrayboard[0] << "|" << arrayboard[1] << "|" << arrayboard[2] << "|" << std::endl;
            std::cout << "-----------------" << std::endl;
            std::cout << "|   | 0 | 1 | 2 |" << std::endl;
            std::cout << "-----------------" << std::endl;
        }
};