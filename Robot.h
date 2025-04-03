#pragma once
#include <string>
#include "Arena.h"

class Arena;

class Robot
{
public:
    // Constructor
    Robot(Arena* ap, int r, int c);

    // Accessors
    int  row() const;
    int  col() const;
    int health();
    //********** bool health(); ??? ****************************

    // Mutators
    void move();
    bool helperTakeDamageAndLive(int health);
    bool takeDamageAndLive();
    void decreaseHealth();

private:
    Arena* m_arena;
    int    m_row;
    int    m_col;
    int m_health;
    // TODO: You'll probably find that a robot object needs an additional
    // data member to support your implementation of the behavior affected
    // by being hit and taking damage.
};