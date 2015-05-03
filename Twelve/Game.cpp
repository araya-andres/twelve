//
//  Game.cpp
//  Twelve
//
//  Created by Andres Araya Rojas on 5/2/15.
//  Copyright (c) 2015 edu.self. All rights reserved.
//

#include "Game.h"

Game::Game(Gosu::Window& window)
{
}

void Game::draw()
{
}

void Game::handle_mouse_down(double x, double y)
{
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
