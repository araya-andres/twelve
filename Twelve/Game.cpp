//
//  Game.cpp
//  Twelve
//
//  Created by Andres Araya Rojas on 5/2/15.
//  Copyright (c) 2015 edu.self. All rights reserved.
//

#include <algorithm>
#include <assert.h>
#include <vector>

#include "Game.h"
#include "Square.h"

Game::Game(Gosu::Window& window, Gosu::Font& font)
{
    std::vector<Square::Color> color_list {
        Square::Color::red,
        Square::Color::green,
        Square::Color::blue,
    };
    assert(ROWS * COLS % color_list.size() == 0);
    for (size_t i = 1, n = color_list.size(); i < ROWS * COLS / n; ++i) {
        color_list.insert(color_list.end(), color_list.begin(), color_list.begin() + n);
    }
    color_list.reserve(ROWS * COLS);
    //std::random_shuffle(color_list.begin(), color_list.end());
    for (int row = 0; row < ROWS; ++row) {
        for (int col = 0; col < COLS; ++col) {
            _squares.push_back(
                Square(window, font, col, row, color_list[ROWS * row + col])
            );
        }
    }
}

void Game::draw()
{
    for (auto& square : _squares) {
        square.draw();
    }
}

void Game::handle_mouse_down(double x, double y)
{
    int row = ((int)y - 20) / Square::SIDE;
    int col = ((int)x - 20) / Square::SIDE;
}

void Game::handle_mouse_up(double x, double y)
{
}

Square& Game::get_square(int row, int col)
{
    return _squares[0];
}

void Game::move(Square&, Square&)
{
}

std::vector<Square> Game::squares_between_in_row(Square&, Square&)
{
    return std::vector<Square>();
}

std::vector<Square> Game::squares_between_in_column(Square&, Square&)
{
    return std::vector<Square>();
}
