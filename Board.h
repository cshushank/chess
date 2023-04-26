//
// Created by Shushank Chaudhary on 3/17/23.
//

#ifndef CHESS_BOARD_H
#define CHESS_BOARD_H

#include <iostream>
#include <string>
#include <tuple>
#include <vector>
#include "Piece.h"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>

using namespace std;

class Square{
private:
    int m_i, m_j;
    string m_name;
    Piece *m_piece;
    sf::RectangleShape *m_square;
public:
    Square(){
        m_i = 0;
        m_j = 0;
        m_name = "";
        m_piece = nullptr;
        m_square = nullptr;
    }

    Square(int a_i, int a_j)
    {
        m_i = a_i;
        m_j = a_j;
        m_name = (char) (a_i + 97) + to_string(a_j+1);
    }
    ~Square()
    {
        delete m_piece;
        delete m_square;
    }
    void add_piece(Piece *a_p);
    Piece* remove_piece();
    bool has_piece() {return (m_piece != nullptr);}
    Piece* get_piece() {return m_piece;}
    void set_piece(Piece &a_p){m_piece = &a_p;}
    void set_square(sf::RectangleShape *a_square){m_square = a_square;}
    sf::RectangleShape* get_square(){return m_square;}
};

class Board {
private:
    Square *board[8][8];
    unsigned int screen_width;
    unsigned int screen_height;
    unsigned int square_height;
    unsigned int square_width;
    unsigned int dock_width;
    int white_pieces_on_dock;
    int black_pieces_on_dock;
    int pieces_on_dock_row;
    int white_row;
    int black_row;
    sf::RectangleShape *draw_dock;
    sf::RenderWindow *window;
    void handle_move_on_piece(int i, int j, int a, int b, vector<tuple<int, int>> &v);
    void move_to_dock(Piece* piece);
public:
    Board();
    void get_valid_moves(vector<tuple<int, int>> &v, tuple<int, int> &pos);
    void graphics();
    void draw_board();
    ~Board()
    {
        for (int i = 0; i < 8; i++)
        {
            for (int j = 0; j < 8; j++)
            {
                delete board[i][j];
            }
        }
        delete window;
    }
};


#endif //CHESS_BOARD_H
