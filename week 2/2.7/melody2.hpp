#ifndef _MELODY2_HPP
#define _MELODY2_HPP

#include "melody.hpp"
#include "note_player.hpp"

// an abstract melody

class melody2 : public melody {
public:
   void play( note_player & p ) override;
};

#endif
