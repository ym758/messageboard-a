#pragma once
#include <string>
#include "Direction.hpp"


namespace ariel{

    class Board{

    public:


    Board();


    void post (unsigned int x, unsigned int y, Direction direction, std::string string);


    std::string read (unsigned int x, unsigned int y, Direction direction, unsigned longString);


    void show();


    };


    }