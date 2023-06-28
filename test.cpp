#include <iostream>
#include "entety.hpp"

int main() {

    int users_input = 2;
    int squares = ( users_input + 1 )*4; 
    int checkers_num = users_input; 
    Player white = Player(checkers_num, white_checker);
    Player black = Player(checkers_num, black_checker);
    Board board = Board( squares, white, black );
    int* field = board.get_board();
    for( int  i = 0; i < squares; i++ ) {

        std::cout << '[' << field[i] << ']'; 

    }

    std::cout << std::endl;

}
