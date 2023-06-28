#pragma once

#include <iostream>

const int white_checker = 1;
const int black_checker = 2;
const int free_square   = 0;


const int show_must_go_on = 1;
const int game_is_over    = 0;


class Board;

class Player {

    private:
    
        int checkers_num;
        int score;
        int color;

        int choose_checker( Board board );


    public:

        Player(const int checkers_num, const int color) {

            this->checkers_num = checkers_num;
            this->color = color;
            this->score = 0;

        }

        Player() = default;

        ~Player() = default;

        int get_color(){

            return this->color;

        }

        int get_score(){

            return this->score;

        }

        int make_move( Board board );

};


class Board {

    private:

        int squares;
        int* board;
        Player white;
        Player black;
        bool is_white_turn;

        int game_end();

    public:

        Board(int squares, Player white, Player black) {

            this->squares = squares;
            this->white = white;
            this->black = black;
            this->is_white_turn = true;
            this->board = new int[this->squares];
            
            for( int i = 1; i < (squares/4); i++ ) {

                board[i] = white.get_color();
                board[squares - squares/4 - i] = black.get_color();
                board[squares - i ] = free_square;
                board[squares/4 + i] = free_square;

            }

            board[0] = free_square;
            board[squares/4] = free_square;
            board[2 * squares/4] = free_square;
            board[3 * squares/4] = free_square;

        }   
        
        ~Board() {

            if (board != nullptr)
                delete board;            
        }

        int* get_board() {

            return board;

        }

        void draw();

        int turn() {

            Player player;

            if( is_white_turn )
                player = this->white;

            else
                player = this->black;
            
            player.make_move( *this );

            if ( player.get_score() ==  ( squares/4 - 1 ) )
                return game_end();

            is_white_turn = !is_white_turn;

            return show_must_go_on;

        }

};

int Player::choose_checker( Board board ) {

    /*

        Логика выбора шашки
        Вероятнее всего нужно реализовать через графику. Пользователь в графическом интерфейсе (окне WxWidgets) тыкает на изображение шашки,
        после чего мы получаем в переменные checker_pos позицию тыка, если на этом месте шашка цвета игрока, то выбор подтверждён и мы возвращаем выбранное значение 

    */

}

int Player::make_move( Board board ) {

    /*

        Логика совершения хода
    */

    int pos = choose_checker( board );

    /*

        Позицию куда пойдёт шашка игрок выбирает также, как он выбирал шашку, т.е. тыкает на клетку, если клетка свободна, то на неё можно сходить
        Здесь нужно обрабатывать случай, когда пешку можно съесть, т.е. если тыкнули на позицию не рядом с пешкой, а на растоянии клетка от неё, но приэтом выбранная клетка свободна,
        а на пути пешки к клетке стоит вражеска пешка, то мы перемещаемся на эту позицию, стираем съеденную пешку с доски и прибовляем себе плюсик к счёту
        Нужна проверка, что если мы кого-то съели, и можем съесть ещё, то ходим ещё раз
        Или можно ограничить выбор игрока, подсвечивая поля, куда он может сходить (рисовать их не белой клеткой, а красной, например) 


    */

}

void Board::draw() {

    /*

        Рисование доски по полю board

    */


}

int Board::game_end() {

    /*

        можно нарисовать экран поздравления победителя или сделать функцию не void, а с возвращаемым значением, чтобы останавливать главный игровой цикл

    */

}