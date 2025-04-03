#include "Robot.h"
#include "globals.h"
#include <iostream>	
using namespace std;

Robot::Robot(Arena* ap, int r, int c)
{
    if (ap == nullptr)
    {
        cout << "***** A robot must be in some Arena!" << endl;
        exit(1);
    }
    if (r < 1 || r > ap->rows() || c < 1 || c > ap->cols())
    {
        cout << "***** Robot created with invalid coordinates (" << r << ","
            << c << ")!" << endl;
        exit(1);
    }
    m_arena = ap;
    m_row = r;
    m_col = c;
    m_health = 1;
}

int Robot::row() const
{
    return m_row;
}

int Robot::col() const
{
    // TODO: TRIVIAL:  DONE!!!!!!!!!
    return m_col;  // This implementation compiles, but is incorrect.
}

int Robot::health()
{

    return m_health;
}

void  Robot::decreaseHealth()
{
    m_health -= 1;
}

void Robot::move()
{
    // Attempt to move in a random direction; if we can't move, don't move
    switch (rand() % 4)
    {
    case UP:
        /*if (takeDamageAndLive(m_health) == false)
            break;*/
        if (m_row - 1 > 1)
            m_row -= 1;
        break;
    case DOWN:
        /*if (takeDamageAndLive(m_health) == false)
            break;*/
        if (m_row + 1 < m_arena->rows() + 1)
            m_row += 1;
        break;
    case LEFT:
        /*if (takeDamageAndLive(m_health) == false)
            break;*/
        if (m_col - 1 > 1)
            m_col -= 1;
        break;
    case RIGHT:
        /*if (takeDamageAndLive(m_health) == false)
            break;*/
        if (m_col + 1 < m_arena->cols() + 1)
            m_col += 1;
        break;
    default:
        break;

    }
}
//int m_health
bool Robot::helperTakeDamageAndLive(int m_health)
{
    decreaseHealth();
    if (m_health > 0) {
        return true;
    }
    if (m_health <= 0)
        return false;
}

bool Robot::takeDamageAndLive()
{
    // TODO:  If the robot has been hit once before, return false (since a
    // second hit kills a robot).  Otherwise, return true (since the robot
    // survived the damage).
    return helperTakeDamageAndLive(m_health);




    //return true; //********TEMPORARY SO CODE RUNS******************
}