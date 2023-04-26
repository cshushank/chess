//
// Created by Shushank Chaudhary on 3/17/23.
//

#ifndef CHESS_PIECE_H
#define CHESS_PIECE_H

#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

using namespace std;

class Piece {
private:
    bool white = false;
    string m_type;
    sf::Sprite *m_sprite;
public:
    Piece(string a_type=""){
        m_type = a_type;
        m_sprite = nullptr;
    }
    ~Piece()
    {
        delete m_sprite;
    }
    string get_type(){return m_type;}
    void set_sprite(sf::Sprite &a_sprite) {m_sprite = &a_sprite;}
    sf::Sprite get_sprite(){return *m_sprite;}
    bool is_white(){return white;}
    void set_color(bool is_white){white = is_white;}
};


#endif //CHESS_PIECE_H