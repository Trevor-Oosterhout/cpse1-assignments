#ifndef _NOTE_PLAYER_PC_HPP
#define _NOTE_PLAYER_PC_HPP


#include "note.hpp"
#include "note_player.hpp"

class note_player_pc : public note_player {
private:

public:
    void play( const note & n ) override;


};

#endif
