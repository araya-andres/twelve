#include <algorithm>
#include <assert.h>
#include <vector>

#include "Board.h"
#include "Game.h"
#include "Square.h"

int get_index(int row, int col)
{
    return Board::ROWS * row + col;
}

Game::Game(Gosu::Graphics& g, Gosu::Font& f)
    : _color_list({ Square::Color::red, Square::Color::green, Square::Color::blue })
{
    _squares.reserve(Board::ROWS * Board::COLS);
    for (int row = 0; row < Board::ROWS; ++row)
        for (int col = 0; col < Board::COLS; ++col)
            _squares.push_back(Square(g, f, col, row));

    assert(Board::ROWS * Board::COLS % _color_list.size() == 0);
    _color_list.reserve(Board::ROWS * Board::COLS);
    for (size_t i = 1, n = _color_list.size(); i < Board::ROWS * Board::COLS / n; ++i)
        _color_list.insert(_color_list.end(), _color_list.begin(), _color_list.begin() + n);

    restart();
}

void Game::draw() const
{
    for (auto& square : _squares)
        square.draw();
}

void Game::restart()
{
    assert(_squares.size() == _color_list.size());
    std::random_shuffle(_color_list.begin(), _color_list.end());
    int i = 0;
    for (Square& s : _squares)
        s.set(_color_list[i++], 1);
}

void Game::handle_mouse_down(double x, double y)
{
    int row = ((int)y - Board::BORDER) / Square::SIDE;
    int col = ((int)x - Board::BORDER) / Square::SIDE;
    _start_square = &_squares.at(get_index(row, col));
}

void Game::handle_mouse_up(double x, double y)
{
    int row = ((int)y - Board::BORDER) / Square::SIDE;
    int col = ((int)x - Board::BORDER) / Square::SIDE;
    _end_square = &_squares.at(get_index(row, col));
    assert(_start_square && _end_square);
    move(*_start_square, *_end_square);
}

void Game::move(Square& square1, Square& square2)
{
    if (square1.number() == 0 || square2.number() == 0) return;
    if (square1.color() != square2.color()) return;
    std::vector<Square*> squares;
    if (square1.row() == square2.row()) {
        squares = squares_between_in_row(square1, square2);
    } else if (square1.column() == square2.column()) {
        squares = squares_between_in_column(square1, square2);
    } else {
        return;
    }
    int non_empty_squares = std::count_if(
        squares.begin(), squares.end(),
        [] (Square* s) { return s->number() > 0; }
    );
    if (non_empty_squares != 2) return;
    square2.set(square2.color(), square2.number() + square1.number());
    square1.clear();
}

std::vector<Square*> Game::squares_between_in_row(
    const Square& square1,
    const Square& square2)
{
    auto boundary = std::minmax(
        square1, square2,
        [] (const Square& s1, const Square& s2) { return s1.column() < s2.column(); }
    );
    std::vector<Square*> squares;
    for (int row = square1.row(), col = boundary.first.column(); col <= boundary.second.column(); ++col) {
        squares.push_back(&_squares.at(get_index(row, col)));
    }
    return squares;
}

std::vector<Square*> Game::squares_between_in_column(
    const Square& square1,
    const Square& square2)
{
    auto boundary = std::minmax(
        square1, square2,
        [] (const Square& s1, const Square& s2) { return s1.row() < s2.row(); }
    );
    std::vector<Square*> squares;
    for (int row = boundary.first.row(), col = square1.column(); row <= boundary.second.row(); ++row) {
        squares.push_back(&_squares.at(get_index(row, col)));
    }
    return squares;
}
