
#include <iostream>
#include <string>

using bitboard = uint32_t; 
class TicTacToe {
    public:
        bitboard pos;
        bitboard mask;
        unsigned int move_counter = 0;


        TicTacToe() {
            pos = 0;
            mask = 0;
        };

        unsigned int currentPlayer() const {
            return move_counter & 1; // using & to check if move_counter is odd or even 
        }
        
        void makeMove(bitboard move) {
            pos ^= mask; // pos becomes other player board by switching the bits
            mask |= move; // add move to mask 
            move_counter++;
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
            std::string array_board[9];
           

            bitboard player_positions[2] = {pos, pos ^ mask};  // instead of using (currentPlayer() == 1 ? pos : pos ^ mask)
            std::string markers[3] = {" \u001b[34mX\u001b[0m ", " \u001b[35mO\u001b[0m "};
            
            try {
                array_board[0] = markers[(((((bitboard)1 << 0) & mask) != 0) + ((((bitboard)1 << 0) & player_positions[currentPlayer() ^ 1]) != 0)) - 1]; 
            } catch (const std::exception) {
                array_board[0] = " 1 ";
            }
            try {
                array_board[1] = markers[(((((bitboard)1 << 1) & mask) != 0) + ((((bitboard)1 << 1) & player_positions[currentPlayer() ^ 1]) != 0)) - 1]; 
            } catch (const std::exception) {
                array_board[1] = " 2 ";
            }
            try {
                array_board[2] = markers[(((((bitboard)1 << 2) & mask) != 0) + ((((bitboard)1 << 2) & player_positions[currentPlayer() ^ 1]) != 0)) - 1]; 
            } catch (const std::exception) {
                array_board[2] = " 3 ";
            }
            try {
                array_board[3] = markers[(((((bitboard)1 << 3) & mask) != 0) + ((((bitboard)1 << 3) & player_positions[currentPlayer() ^ 1]) != 0)) - 1]; 
            } catch (const std::exception) {
                array_board[3] = " 4 ";
            }
            try {
                array_board[4] = markers[(((((bitboard)1 << 4) & mask) != 0) + ((((bitboard)1 << 4) & player_positions[currentPlayer() ^ 1]) != 0)) - 1]; 
            } catch (const std::exception) {
                array_board[4] = " 5 ";
            }
            try {
                array_board[5] = markers[(((((bitboard)1 << 5) & mask) != 0) + ((((bitboard)1 << 5) & player_positions[currentPlayer() ^ 1]) != 0)) - 1]; 
            } catch (const std::exception) {
                array_board[5] = " 6 ";
            }
            try {
                array_board[6] = markers[(((((bitboard)1 << 6) & mask) != 0) + ((((bitboard)1 << 6) & player_positions[currentPlayer() ^ 1]) != 0)) - 1]; 
            } catch (const std::exception) {
                array_board[6] = " 7 ";
            }
            try {
                array_board[7] = markers[(((((bitboard)1 << 7) & mask) != 0) + ((((bitboard)1 << 7) & player_positions[currentPlayer() ^ 1]) != 0)) - 1]; 
            } catch (const std::exception) {
                array_board[7] = " 8 ";
            }
            try {
                array_board[8] = markers[(((((bitboard)1 << 8) & mask) != 0) + ((((bitboard)1 << 8) & player_positions[currentPlayer() ^ 1]) != 0)) - 1]; 
            } catch (const std::exception) {
                array_board[8] = " 9 ";
            }

            
            
            std::cout << "-------------" << std::endl;
            std::cout << "|" << array_board[2] << "|" << array_board[5] << "|" << array_board[8] << "|" << std::endl;
            std::cout << "-------------" << std::endl;
            std::cout << "|" << array_board[1] << "|" << array_board[4] << "|" << array_board[7] << "|" << std::endl;
            std::cout << "-------------" << std::endl;
            std::cout << "|" << array_board[0] << "|" << array_board[3] << "|" << array_board[6] << "|" << std::endl;
            std::cout << "-------------" << std::endl;
        }
};