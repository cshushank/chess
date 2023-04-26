// 
// Created by Shushank Chaudhary on 3/17/23.
//

#include "Board.h"

void Board::handle_move_on_piece(int i, int j, int a, int b, vector<tuple<int, int>> &v) {
    bool same_color = ((board[i][j]->get_piece()->is_white() && board[a][b]->get_piece()->is_white()) || (!board[i][j]->get_piece()->is_white() && !board[a][b]->get_piece()->is_white()));
    if (!same_color)
    {
        tuple<int, int> position = make_tuple(a, b);
        v.push_back(position);
    }
}

void Board::get_valid_moves(vector<tuple<int, int>> &v, tuple<int, int> &pos){
    // Returns the valid move v for piece on pos in the board
    int i = std::get<0>(pos);
    int j = std::get<1>(pos);

    Piece* piece = board[i][j]->get_piece();

    if (piece->get_type() == "WhitePawn")
    {
        // if final square
        if (j  == 7)
        {
            // give the option to change to other pieces
        }
        else
        {
            if (!board[i][j+1]->has_piece())
            {
                tuple<int, int> pos1 = make_tuple(i, j+1);
                v.push_back(pos1);
            }

            if (j == 1 && !board[i][j+2]->has_piece()){              // if first pawn move, then it can move two squares
                tuple<int, int> pos2 = make_tuple(i, j+2);
                v.push_back(pos2);
            }
        }
        if (i != 7 && j != 7 && board[i+1][j+1]->has_piece())
            handle_move_on_piece(i, j, i+1, j+1, v);

        if (i != 0 && j != 7 && board[i-1][j+1]->has_piece())
            handle_move_on_piece(i, j, i-1, j+1, v);

    }
    else if (piece->get_type() == "BlackPawn")
    {
        if (j == 0)
        {
            // give the option to change to other pieces
        }
        else {
            if (!board[i][j-1]->has_piece())
            {
                tuple<int, int> pos1 = make_tuple(i, j - 1);
                v.push_back(pos1);
            }

            if (j == 6 && !board[i][j-2]->has_piece()) {                                              // if first pawn move, then it can move two squares
                tuple<int, int> pos2 = make_tuple(i, j - 2);
                v.push_back(pos2);
            }
        }
        if (i != 7 && j != 0 && board[i+1][j-1]->has_piece())
            handle_move_on_piece(i, j, i+1, j-1, v);

        if (i != 0 && j != 0 && board[i-1][j-1]->has_piece())
            handle_move_on_piece(i, j, i-1, j-1, v);
    }
    else if (piece->get_type() == "WhiteRook" || piece->get_type() == "BlackRook")
    {
        int a = i-1;
        int b = i+1;
        int c = j-1;
        int d = j+1;
        while (a >= 0)
        {
            if (board[a][j]->has_piece())
            {
                handle_move_on_piece(i, j, a, j, v);
                break;
            }

            tuple<int, int> position = make_tuple(a, j);
            v.push_back(position);
            a--;
        }
        while (b <= 7)
        {
            if (board[b][j]->has_piece())
            {
                handle_move_on_piece(i, j, b, j, v);
                break;
            }
            tuple<int, int> position = make_tuple(b, j);
            v.push_back(position);
            b++;
        }
        while (c >= 0)
        {
            if (board[i][c]->has_piece())
            {
                handle_move_on_piece(i, j, i, c, v);
            }
            tuple<int, int> position = make_tuple(i, c);
            v.push_back(position);
            c--;
        }
        while (d <= 7)
        {
            if (board[i][d]->has_piece())
            {
                handle_move_on_piece(i, j, i, d, v);
                break;
            }
            tuple<int, int> position = make_tuple(i, d);
            v.push_back(position);
            d++;
        }
    }
    else if (piece->get_type() == "WhiteBishop" || piece->get_type() == "BlackBishop")
    {
        int a = i+1;
        int b = j+1;
        while (a <= 7 && b <= 7)
        {
            if (board[a][b]->has_piece())
            {
                handle_move_on_piece(i, j, a, b, v);
                break;
            }

            tuple<int, int> position = make_tuple(a, b);
            v.push_back(position);

            a++;
            b++;
        }

        a = i-1;
        b = j-1;
        while (a >= 0 && b >= 0)
        {
            if (board[a][b]->has_piece())
            {
                handle_move_on_piece(i, j, a, b, v);
                break;
            }
            tuple<int, int> position = make_tuple(a, b);
            v.push_back(position);

            a--;
            b--;
        }

        a = i+1;
        b = j-1;
        while (a <= 7 && b >= 0)
        {
            if (board[a][b]->has_piece())
            {
                handle_move_on_piece(i, j, a, b, v);
                break;
            }
            tuple<int, int> position = make_tuple(a, b);
            v.push_back(position);

            a++;
            b--;
        }

        a = i-1;
        b = j+1;
        while (a >= 0 && b <= 7)
        {
            if (board[a][b]->has_piece()) {
                handle_move_on_piece(i, j, a, b, v);
                break;
            }
            tuple<int, int> position = make_tuple(a, b);
            v.push_back(position);

            a--;
            b++;
        }
    }
    else if (piece->get_type() == "WhiteKnight" || piece->get_type() == "BlackKnight")
    {
        int a = i+2;
        int b = j+1;
        if (a <= 7 && b <= 7)
        {
            if (!board[a][b]->has_piece())
            {
                tuple<int, int> position = make_tuple(a, b);
                v.push_back(position);
            }
            else
            {
                handle_move_on_piece(i, j, a, b, v);
            }
        }

        a = i-2;
        b = j+1;
        if (a >= 0 && b <= 7)
        {
            if (!board[a][b]->has_piece())
            {
                tuple<int, int> position = make_tuple(a, b);
                v.push_back(position);
            }
            else
            {
                handle_move_on_piece(i, j, a, b, v);
            }
        }

        a = i+1;
        b = j+2;
        if (a <= 7 && b <= 7)
        {
            if (!board[a][b]->has_piece())
            {
                tuple<int, int> position = make_tuple(a, b);
                v.push_back(position);
            }
            else
            {
                handle_move_on_piece(i, j, a, b, v);
            }
        }

        a = i-1;
        b = j+2;
        if (a >= 0 && b <= 7)
        {
            if (!board[a][b]->has_piece())
            {
                tuple<int, int> position = make_tuple(a, b);
                v.push_back(position);
            }
            else
            {
                handle_move_on_piece(i, j, a, b, v);
            }
        }

        a = i+1;
        b = j-2;
        if (a <= 7 && b >= 0)
        {
            if (!board[a][b]->has_piece())
            {
                tuple<int, int> position = make_tuple(a, b);
                v.push_back(position);
            }
            else
            {
                handle_move_on_piece(i, j, a, b, v);
            }
        }

        a = i-1;
        b = j-2;
        if (a >= 0 && b >= 0)
        {
            if (!board[a][b]->has_piece())
            {
                tuple<int, int> position = make_tuple(a, b);
                v.push_back(position);
            }
            else
            {
                handle_move_on_piece(i, j, a, b, v);
            }
        }

        a = i+2;
        b = j-1;
        if (a <= 7 && b >= 0)
        {
            if (!board[a][b]->has_piece())
            {
                tuple<int, int> position = make_tuple(a, b);
                v.push_back(position);
            }
            else
            {
                handle_move_on_piece(i, j, a, b, v);
            }
        }

        a = i-2;
        b = j-1;
        if (a >= 0 && b >= 0)
        {
            if (!board[a][b]->has_piece())
            {
                tuple<int, int> position = make_tuple(a, b);
                v.push_back(position);
            }
            else
            {
                handle_move_on_piece(i, j, a, b, v);
            }
        }
    }
    else if (piece->get_type() == "WhiteQueen" || piece->get_type() == "BlackQueen")
    {
        int a = i-1;
        int b = i+1;
        int c = j-1;
        int d = j+1;
        while (a >= 0)
        {
            if (board[a][j]->has_piece())
            {
                handle_move_on_piece(i, j, a, j, v);
                break;
            }
            tuple<int, int> position = make_tuple(a, j);
            v.push_back(position);

            a--;
        }
        while (b <= 7)
        {
            if (board[b][j]->has_piece())
            {
                handle_move_on_piece(i, j, b, j, v);
                break;
            }
            tuple<int, int> position = make_tuple(b, j);
            v.push_back(position);
            b++;
        }
        while (c >= 0)
        {
            if (board[i][c]->has_piece())
            {
                handle_move_on_piece(i, j, i, c, v);
                break;
            }
            tuple<int, int> position = make_tuple(i, c);
            v.push_back(position);

            c--;
        }
        while (d <= 7)
        {
            if (board[i][d]->has_piece())
            {
                handle_move_on_piece(i, j, i, d, v);
                break;
            }
            tuple<int, int> position = make_tuple(i, d);
            v.push_back(position);

            d++;
        }

        a = i+1;
        b = j+1;
        while (a <= 7 && b <= 7)
        {
            if (board[a][b]->has_piece()) {
                handle_move_on_piece(i, j, a, b, v);
                break;
            }
            tuple<int, int> position = make_tuple(a, b);
            v.push_back(position);

            a++;
            b++;
        }

        a = i-1;
        b = j-1;
        while (a >= 0 && b >= 0)
        {
            if (board[a][b]->has_piece()) {
                handle_move_on_piece(i, j, a, b, v);
                break;
            }
            tuple<int, int> position = make_tuple(a, b);
            v.push_back(position);

            a--;
            b--;
        }

        a = i+1;
        b = j-1;
        while (a <= 7 && b >= 0)
        {
            if (board[a][b]->has_piece()) {
                handle_move_on_piece(i, j, a, b, v);
                break; }
            tuple<int, int> position = make_tuple(a, b);
            v.push_back(position);

            a++;
            b--;
        }

        a = i-1;
        b = j+1;
        while (a >= 0 && b <= 7)
        {
            if (board[a][b]->has_piece()) {
                handle_move_on_piece(i, j, a, b, v);
                break;
            }
            tuple<int, int> position = make_tuple(a, b);
            v.push_back(position);

            a--;
            b++;
        }
    }
    else if (piece->get_type() == "WhiteKing" || piece->get_type() == "BlackKing")
    {
        int a = i+1;
        int b = j+1;
        if (a <= 7 && b <= 7)
        {
            if (!board[a][b]->has_piece())
            {
                tuple<int, int> position = make_tuple(a, b);
                v.push_back(position);
            }
            else
            {
                handle_move_on_piece(i, j, a, b, v);
            }

        }
        a = i;
        b = j+1;
        if (b <= 7)
        {
            if (!board[a][b]->has_piece())
            {
                tuple<int, int> position = make_tuple(a, b);
                v.push_back(position);
            }
        }

        a = i+1;
        b = j;
        if (a <= 7)
        {
            if (!board[a][b]->has_piece())
            {
                tuple<int, int> position = make_tuple(a, b);
                v.push_back(position);
            }
        }

        a = i-1;
        b = j-1;
        if (a >= 0 && b >= 0)
        {
            if (!board[a][b]->has_piece())
            {
                tuple<int, int> position = make_tuple(a, b);
                v.push_back(position);
            }
        }

        a = i-1;
        b = j;
        if (a >= 0)
        {
            if (!board[a][b]->has_piece())
            {
                tuple<int, int> position = make_tuple(a, b);
                v.push_back(position);
            }
        }

        a = i;
        b = j-1;
        if (b >= 0)
        {
            if (!board[a][b]->has_piece())
            {
                tuple<int, int> position = make_tuple(a, b);
                v.push_back(position);
            }
        }

        a = i-1;
        b = j+1;
        if (a >= 0 && b <= 7)
        {
            if (!board[a][b]->has_piece())
            {
                tuple<int, int> position = make_tuple(a, b);
                v.push_back(position);
            }
        }

        a = i+1;
        b = j-1;
        if (a <= 7 && b >= 0)
        {
            if (!board[a][b]->has_piece())
            {
                tuple<int, int> position = make_tuple(a, b);
                v.push_back(position);
            }
        }
    }
}

void Square::add_piece(Piece *a_p) {
    // Adds the piece to the square
    m_piece = a_p;
}

Piece* Square::remove_piece(){
    // Returns the piece on the square
    if (m_piece != nullptr)
    {
        Piece* temp = m_piece;
        m_piece = nullptr;
        return temp;
    }
    return nullptr;
}

Board::Board() {
    // Creates an initial board
    auto *white_pawn_texture = new sf::Texture();
    auto *black_pawn_texture = new sf::Texture();
    auto *white_knight_texture = new sf::Texture();
    auto *black_knight_texture = new sf::Texture();
    auto *white_bishop_texture = new sf::Texture();
    auto *black_bishop_texture = new sf::Texture();
    auto *black_king_texture = new sf::Texture();
    auto *white_king_texture = new sf::Texture();
    auto *black_queen_texture = new sf::Texture();
    auto *white_queen_texture = new sf::Texture();
    auto *white_rook_texture = new sf::Texture();
    auto *black_rook_texture = new sf::Texture();

    if (!white_pawn_texture->loadFromFile("white_pawn.png"))
        cout << "Error loading white pawn." << endl;
    if (!black_pawn_texture->loadFromFile("black_pawn.png"))
        cout << "Error loading black pawn." << endl;
    if (!white_knight_texture->loadFromFile("white_knight.png"))
        cout << "Error loading white knight." << endl;
    if (!black_knight_texture->loadFromFile("black_knight.png"))
        cout << "Error loading black knight." << endl;
    if (!white_bishop_texture->loadFromFile("white_bishop.png"))
        cout << "Error loading white bishop." << endl;
    if (!black_bishop_texture->loadFromFile("black_bishop.png"))
        cout << "Error loading black bishop." << endl;
    if (!white_king_texture->loadFromFile("white_king.png"))
        cout << "Error loading white king." << endl;
    if (!black_king_texture->loadFromFile("black_king.png"))
        cout << "Error loading black king." << endl;
    if (!white_queen_texture->loadFromFile("white_queen.png"))
        cout << "Error loading white queen." << endl;
    if (!black_queen_texture->loadFromFile("black_queen.png"))
        cout << "Error loading white bishop." << endl;
    if (!white_rook_texture->loadFromFile("white_rook.png"))
        cout << "Error loading white rook." << endl;
    if (!black_rook_texture->loadFromFile("black_rook.png"))
        cout << "Error loading black rook." << endl;

    auto white_pawn_sprite = new sf::Sprite(*white_pawn_texture);
    auto black_pawn_sprite = new sf::Sprite(*black_pawn_texture);
    auto white_knight_sprite = new sf::Sprite(*white_knight_texture);
    auto black_knight_sprite = new sf::Sprite(*black_knight_texture);
    auto white_bishop_sprite = new sf::Sprite(*white_bishop_texture);
    auto black_bishop_sprite = new sf::Sprite(*black_bishop_texture);
    auto white_king_sprite = new sf::Sprite(*white_king_texture);
    auto black_king_sprite = new sf::Sprite(*black_king_texture);
    auto white_queen_sprite = new sf::Sprite(*white_queen_texture);
    auto black_queen_sprite = new sf::Sprite(*black_queen_texture);
    auto black_rook_sprite = new sf::Sprite(*black_rook_texture);
    auto white_rook_sprite = new sf::Sprite(*white_rook_texture);

    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            board[i][j] = new Square(i, j);
        }
    }

    // add white pieces
    auto *white_knight = new Piece("WhiteKnight");
    white_knight->set_color(true);
    white_knight->set_sprite(*white_knight_sprite);
    auto *white_rook = new Piece("WhiteRook");
    white_rook->set_color(true);
    white_rook->set_sprite(*white_rook_sprite);
    auto *white_bishop = new Piece("WhiteBishop");
    white_bishop->set_color(true);
    white_bishop->set_sprite(*white_bishop_sprite);
    auto *white_queen = new Piece("WhiteQueen");
    white_queen->set_color(true);
    white_queen->set_sprite(*white_queen_sprite);
    auto *white_king = new Piece("WhiteKing");
    white_king->set_color(true);
    white_king->set_sprite(*white_king_sprite);
    auto *white_pawn = new Piece("WhitePawn");
    white_pawn->set_color(true);
    white_pawn->set_sprite(*white_pawn_sprite);

    board[0][0]->add_piece(white_rook);
    board[7][0]->add_piece(white_rook);
    board[1][0]->add_piece(white_knight);
    board[6][0]->add_piece(white_knight);
    board[2][0]->add_piece(white_bishop);
    board[5][0]->add_piece(white_bishop);
    board[3][0]->add_piece(white_queen);
    board[4][0]->add_piece(white_king);

    for (int i = 0; i < 8; i++)
    {
        board[i][1]->add_piece(white_pawn);
    }

    // add black pieces
    auto *black_knight = new Piece("BlackKnight");
    black_knight->set_sprite(*black_knight_sprite);
    auto *black_rook = new Piece("BlackRook");
    black_rook->set_sprite(*black_rook_sprite);
    auto *black_bishop = new Piece("BlackBishop");
    black_bishop->set_sprite(*black_bishop_sprite);
    auto *black_queen = new Piece("BlackQueen");
    black_queen->set_sprite(*black_queen_sprite);
    auto *black_king = new Piece("BlackKing");
    black_king->set_sprite(*black_king_sprite);
    auto *black_pawn = new Piece("BlackPawn");
    black_pawn->set_sprite(*black_pawn_sprite);

    board[0][7]->add_piece(black_rook);
    board[7][7]->add_piece(black_rook);
    board[1][7]->add_piece(black_knight);
    board[6][7]->add_piece(black_knight);
    board[2][7]->add_piece(black_bishop);
    board[5][7]->add_piece(black_bishop);
    board[3][7]->add_piece(black_queen);
    board[4][7]->add_piece(black_king);

    for (int i = 0; i < 8; i++)
    {
        board[i][6]->add_piece(black_pawn);
    }
    white_pieces_on_dock = 0;
    black_pieces_on_dock = 0;
    white_row = 0;
    black_row = 4;
    pieces_on_dock_row = int((screen_width - 8 * square_height) / square_height);
}
void Board::draw_board() {
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            Square *current_square = board[i][j];
            window->draw(*(current_square->get_square()));
            if (current_square->has_piece())
            {
                auto square_piece = current_square->get_piece();
                auto piece_sprite = square_piece->get_sprite();
                piece_sprite.setPosition(i * square_height + (square_height/4), j * square_height + (square_height/4));
                window->draw(piece_sprite);
            }
        }
    }
    window->draw(*draw_dock);
}

void Board::move_to_dock(Piece *piece) {
    if (piece->is_white())
    {
        if (white_pieces_on_dock > pieces_on_dock_row)
        {
            white_pieces_on_dock %= pieces_on_dock_row;
            white_row++;
        }
        auto piece_sprite = piece->get_sprite();
        piece_sprite.setPosition(8*square_height + white_pieces_on_dock * square_height + (square_height/4), white_row * square_height + (square_height/4));
        window->draw(piece_sprite);
        white_pieces_on_dock++;
    }
    else
    {
        if (black_pieces_on_dock > pieces_on_dock_row)
        {
            black_pieces_on_dock %= pieces_on_dock_row;
            black_row++;
        }
        auto piece_sprite = piece->get_sprite();
        piece_sprite.setPosition(8*square_height + black_pieces_on_dock * square_height + (square_height/4), black_row * square_height + (square_height/4));
        window->draw(piece_sprite);
        black_pieces_on_dock++;
    }
}

void Board::graphics()
{
    screen_width = sf::VideoMode::getDesktopMode().width;
    screen_height = sf::VideoMode::getDesktopMode().height;
    square_width = screen_width / 8;
    square_height = screen_height / 9;

    dock_width = screen_width - 8 * square_height;

    window = new sf::RenderWindow(sf::VideoMode(screen_width,  screen_height), "Chess", sf::Style::Close | sf::Style::Resize);

    auto *lightSquareColor = new sf::Color(205, 133, 63);
    auto *darkSquareColor = new sf::Color(101,67,33);

    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            auto *square = new sf::RectangleShape(sf::Vector2f((float) square_height, (float) square_height));
            square->setOutlineThickness(2.f);
            square->setOutlineColor(sf::Color::Black);
            square->setPosition(i*square_height, j*square_height);
            if ((i+j)% 2 == 0) {
                square->setFillColor(*lightSquareColor);
                board[i][j]->set_square(square);
            }
            else{
                square->setFillColor(*darkSquareColor);
                board[i][j]->set_square(square);
            }
        }
    }

    auto *draw_dockBColor = new sf::Color(255, 255, 0);

    draw_dock = new sf::RectangleShape(sf::Vector2f(dock_width, screen_height));

    draw_dock->setOutlineThickness(2.f);
    draw_dock->setOutlineColor(sf::Color::Black);
    draw_dock->setPosition(8*square_height, 0);
    draw_dock->setFillColor(*draw_dockBColor);

    vector<tuple<int, int>> previous_valids;
    int prev_i;
    int prev_j;
    bool previous_click = false;
    bool move_piece = false;
    bool just_moved = false;
    while (window->isOpen())
    {
        sf::Event event;
        while (window->pollEvent(event))
        {
            if (event.type == event.Closed) {
                window->close();
            }
            bool break_out = false;
            if (event.type == sf::Event::MouseButtonPressed){
                if (previous_click)
                {
                    if (move_piece)
                    {
                        int i, j;
                        for (i = 0; i < 8; i++)
                        {
                            for (j = 0; j < 8; j++)
                            {
                                if (board[i][j]->get_square()->getGlobalBounds().contains(sf::Vector2f(event.mouseButton.x, event.mouseButton.y)))
                                {
                                    tuple<int, int> t = make_tuple(i, j);
                                    auto it = find(previous_valids.begin(), previous_valids.end(), t);
                                    if (it != previous_valids.end())
                                    {
                                        auto moving_piece = board[prev_i][prev_j]->remove_piece();
                                        if (board[i][j]->has_piece())
                                            move_to_dock(board[i][j]->remove_piece());
                                        board[i][j]->set_piece(*moving_piece);
                                        move_piece = false;
                                        just_moved = true;
                                        break;
                                    }
                                }
                            }
                        }
                    }
                    for (auto pos: previous_valids)
                    {
                        int a = get<0>(pos);
                        int b = get<1>(pos);
                        if ((a+b)% 2 == 0)
                            board[a][b]->get_square()->setFillColor(*lightSquareColor);
                        else
                            board[a][b]->get_square()->setFillColor(*darkSquareColor);
                    }
                    if ((prev_i+prev_j)% 2 == 0)
                        board[prev_i][prev_j]->get_square()->setFillColor(*lightSquareColor);
                    else
                        board[prev_i][prev_j]->get_square()->setFillColor(*darkSquareColor);
                }
                if (just_moved)
                {
                    just_moved = false;
                    continue;
                }
                int i, j;
                for (i = 0; i < 8; i++)
                {
                    for (j = 0; j < 8; j++)
                    {
                        if (board[i][j]->get_square()->getGlobalBounds().contains(sf::Vector2f(event.mouseButton.x, event.mouseButton.y)))
                        {
                            if (board[i][j]->has_piece())
                            {
                                vector<tuple<int, int>> v;
                                tuple<int, int> position = make_tuple(i, j);
                                get_valid_moves(v, position);
                                if (v.empty())
                                {
                                    auto *redColor = new sf::Color(255, 0, 0);
                                    board[i][j]->get_square()->setFillColor(*redColor);
                                }
                                else
                                {
                                    auto *blueColor = new sf::Color(173, 216, 230);
                                    for (auto pos: v)
                                    {
                                        int a = get<0>(pos);
                                        int b = get<1>(pos);
                                        board[a][b]->get_square()->setFillColor(*blueColor);
                                    }
                                }
                                previous_valids = v;
                                move_piece = true;
                            }
                            break_out = true;
                            break;
                        }
                    }
                    if (break_out)
                    {
                        break_out = false;
                        break;
                    }
                }
                previous_click = true;
                prev_i = i;
                prev_j = j;
            }
        }
        window->clear();
        draw_board();

        window->display();
    }
}
