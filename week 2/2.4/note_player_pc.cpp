#include "note_player_pc.hpp"
#include "iostream"
#include <fstream>


void note_player_pc::play( const note & n ){
    std::ofstream melody;
    melody.open("melody.cpp", std::ofstream::app);
    melody << "     p.play( note{" << n.frequency << ", " << n.duration << "}); \n";
    melody.close();
}
