#include "doctest.h"
#include "Board.hpp"
using namespace ariel;


TEST_CASE("cheak that empty-horizontal"){
    Board board;
    CHECK(board.read(0, 0, Direction::Horizontal, 0) == "");
    CHECK(board.read(5, 5, Direction::Horizontal, 1) == "_");
    CHECK(board.read(5, 5, Direction::Horizontal, 3) == "___");
    CHECK(board.read(10, 299, Direction::Horizontal, 4) == "____");
}

TEST_CASE("cheak that empty-vertical"){
    Board board;
    CHECK(board.read(0, 0, Direction::Vertical, 0) == "");
    CHECK(board.read(5, 5, Direction::Vertical, 1) == "_");
    CHECK(board.read(5, 5, Direction::Vertical, 3) == "___");
    CHECK(board.read(10, 299, Direction::Vertical, 4) == "____");
}

TEST_CASE("post & read"){
Board board;
//check Horizontal
    board.post(0, 0, Direction::Horizontal, "hello world");
    CHECK(board.read(0, 0, Direction::Horizontal, 5) == "hello");

    board.post(0, 0, Direction::Horizontal, "hello world");
    CHECK(board.read(0, 0, Direction::Horizontal, 11) == "hello_world");

    board.post(0, 6, Direction::Horizontal, "hello world");
    CHECK(board.read(0, 0, Direction::Horizontal, 10) == "_____hello");

    board.post(100, 100, Direction::Horizontal, "hello world");
    CHECK(board.read(100, 100, Direction::Horizontal, 5) == "hello");

    board.post(100, 100, Direction::Horizontal, "hello world");
    CHECK(board.read(100, 100, Direction::Horizontal, 11) == "hello_world");

    board.post(100, 6, Direction::Horizontal, "hello world");
    CHECK(board.read(100, 100, Direction::Horizontal, 10) == "_____hello");

//check Vertical

    board.post(0, 0, Direction::Vertical, "hello world");
    CHECK(board.read(0, 0, Direction::Vertical, 5) == "hello");

    board.post(0, 0, Direction::Vertical, "hello world");
    CHECK(board.read(0, 0, Direction::Vertical, 11) == "hello_world");

    board.post(0, 6, Direction::Vertical, "hello world");
    CHECK(board.read(0, 0, Direction::Vertical, 10) == "_____hello");

    board.post(100, 100, Direction::Vertical, "hello world");
    CHECK(board.read(100, 100, Direction::Vertical, 5) == "hello");

    board.post(100, 100, Direction::Vertical, "hello world");
    CHECK(board.read(100, 100, Direction::Vertical, 11) == "hello world");

    board.post(100, 6, Direction::Vertical, "hello world");
    CHECK(board.read(100, 100, Direction::Vertical, 10) == "_____hello");

//check Horizontal & Vertical

    board.post(0, 0, Direction::Horizontal, "hello world");
    CHECK(board.read(0, 0, Direction::Vertical, 5) == "h____");

    board.post(0, 0, Direction::Horizontal, "hello world");
    CHECK(board.read(0, 0, Direction::Vertical, 11) == "h__________");

    board.post(0, 6, Direction::Horizontal, "hello world");
    CHECK(board.read(0, 0, Direction::Horizontal, 10) == "h_________");

//check Vertical & Horizental

    board.post(0, 0, Direction::Vertical, "hello world");
    CHECK(board.read(0, 0, Direction::Horizontal, 5) == "h____");

    board.post(0, 0, Direction::Vertical, "hello world");
    CHECK(board.read(0, 0, Direction::Horizontal, 11) == "h__________");

    board.post(0, 6, Direction::Vertical, "hello world");
    CHECK(board.read(0, 0, Direction::Horizontal, 10) == "h_________");
}


