#include "Player.h"
#include "globals.h"
#include <iostream>
#include <ctime>
#include <cstdlib>	
using namespace std;



Player::Player(Arena* ap, int r, int c)
{
    if (ap == nullptr)
    {
        cout << "***** The player must be in some Arena!" << endl;
        exit(1);
    }
    if (r < 1 || r > ap->rows() || c < 1 || c > ap->cols())
    {
        cout << "**** Player created with invalid coordinates (" << r
            << "," << c << ")!" << endl;
        exit(1);
    }
    m_arena = ap;
    m_row = r;
    m_col = c;
    m_age = 0;
    m_dead = false;
}

int Player::row() const
{
    // TODO: TRIVIAL:  DONE!!!!!!!!!!!!!!!!
    return m_row;
}

int Player::col() const
{
    // TODO: TRIVIAL:  DONE!!!!!!!!!!!!!!!!
    return m_col;
}

int Player::age() const
{
    // TODO:  TRIVIAL:  DONE!!!!!!!!!!!!!!
    return m_age;
}

string Player::takeComputerChosenTurn()
{
    // TODO:  Replace this implementation:
    //int save = m_arena->nRobotsAt(row() + 1, col());
    bool temp = true;


    /*if (m_arena->nRobotsAt(row() + 1, col()) > 0 && m_arena->nRobotsAt(row() - 1, col()) > 0 && m_arena->nRobotsAt(row(), col() + 1) > 0 && m_arena->nRobotsAt(row(), col() - 1) > 0) {
        stand();
        return "Stood";
    }*/

    bool isSurrounded =
        m_arena->nRobotsAt(row() + 1, col()) > 0 &&  // Below
        m_arena->nRobotsAt(row() - 1, col()) > 0 &&  // Above
        m_arena->nRobotsAt(row(), col() + 1) > 0 &&  // Right
        m_arena->nRobotsAt(row(), col() - 1) > 0;    // Left

    if (isSurrounded) {
        stand();
        return "Stood"; // Stay in place since all moves are unsafe
    }


    if (m_arena->nRobotsAt(row() + 1, col()) == 0 && m_arena->nRobotsAt(row() - 1, col()) == 0)
    {
        if (m_arena->nRobotsAt(row(), col() + 1) == 0 && m_arena->nRobotsAt(row(), col() - 1) == 0)
        {
            for (int i = 0; i < 5; i++)
            {
                if (m_arena->nRobotsAt(row() - i, col()) > 0) {
                    //shoot(UP);
                    if (shoot(UP) == temp)
                        return "Shot and hit!";
                    else
                        return "Shot and missed!";
                }

                if (m_arena->nRobotsAt(row() + i, col()) > 0) {
                    shoot(UP);
                    if (shoot(DOWN) == temp)
                        return "Shot and hit!";
                    else
                        return "Shot and missed!";
                }

                if (m_arena->nRobotsAt(row(), col() - i) > 0) {
                    shoot(UP);
                    if (shoot(LEFT) == temp)
                        return "Shot and hit!";
                    else
                        return "Shot and missed!";
                }

                if (m_arena->nRobotsAt(row(), col() + i) > 0) {
                    shoot(UP);
                    if (shoot(RIGHT) == temp)
                        return "Shot and hit!";
                    else
                        return "Shot and missed!";
                }

            }


        }
    }

    if (m_arena->nRobotsAt(row(), col() + 1) == 0 && m_arena->nRobotsAt(row() - 1, col() + 1) == 0 && m_arena->nRobotsAt(row(), col() + 2) == 0 && m_arena->nRobotsAt(row() + 1, col() + 1) == 0)
        if (m_col + 1 < m_arena->cols() + 1) {
            move(RIGHT);
            return "Moved.";
        }

    if (m_arena->nRobotsAt(row(), col() - 1) == 0 && m_arena->nRobotsAt(row() - 1, col() - 1) == 0 && m_arena->nRobotsAt(row(), col() - 2) == 0 && m_arena->nRobotsAt(row() + 1, col() - 1) == 0)
        if (m_col - 1 >= 1) {
            move(LEFT);
            return "Moved.";
        }



    if (m_arena->nRobotsAt(row() - 1, col()) == 0 && m_arena->nRobotsAt(row() - 1, col() - 1) == 0 && m_arena->nRobotsAt(row() - 2, col()) == 0 && m_arena->nRobotsAt(row() - 1, col() + 1) == 0)
        if (m_row - 1 >= 1) {
            move(UP);
            return "Moved.";
        }




    if (m_arena->nRobotsAt(row() + 1, col()) == 0 && m_arena->nRobotsAt(row() + 1, col() - 1) == 0 && m_arena->nRobotsAt(row() + 2, col()) == 0 && m_arena->nRobotsAt(row() + 1, col() + 1) == 0)
        if (m_row + 1 < m_arena->rows() + 1) {
            move(DOWN);
            return "Moved.";
        }


    
    // Your replacement implementation should do something intelligent
    // and return a string that describes what happened.  When you've
    // decided what action to take, take it by calling move, shoot, or stand.
    // This function must return one of the following four strings:
    //     "Moved."
    //     "Shot and hit!"
    //     "Shot and missed!"
    //     "Stood."

    // Here's one possible strategy:
    //   If moving in some direction would put me in less immediate danger
    //     than standing, then move in that direction.
    //   else shoot in the direction of the nearest robot I can hit.

    // A more aggressive strategy is possible, where you hunt down robots.
    stand();
    return "stood";
}

void Player::stand()
{
    m_age++;
}

void Player::move(int dir)
{
    m_age++;
    switch (dir)
    {
    case UP:
        // TODO:  Move the player up one row if possible.
        if (m_row - 1 >= 1)
            m_row -= 1;
        break;
    case DOWN:
        if (m_row + 1 < m_arena->rows() + 1)
            m_row += 1;
        break;
    case LEFT:
        if (m_col - 1 >= 1)
            m_col -= 1;
        break;
    case RIGHT:
        if (m_col + 1 < m_arena->cols() + 1)
            m_col += 1;
        break;
    default:
        stand();
        break;
        // TODO:  Implement the other movements.
        //break;
    }

}

bool Player::shoot(int dir)
{
    m_age++;

    if (rand() % 3 == 0)  // miss with 1/3 probability
        return false;
    // TODO:  Damage the nearest robot in direction dir, returning
    // true if a robot is hit and damaged, false if not hit.
    else {
        switch (dir)
        {
        case UP:
            for (int i = 0; i < 5; i++) {
                if (m_arena->nRobotsAt(row() - i, col()) >= 1) {
                    m_arena->damageRobotAt(row() - i, col());
                    return true;
                }
            }
            break;

        case DOWN:
            for (int i = 0; i < 5; i++) {
                if (m_arena->nRobotsAt(row() + i, col()) >= 1) {
                    m_arena->damageRobotAt(row() + i, col());
                    return true;
                }
            }
            break;

        case LEFT:
            for (int i = 0; i < 5; i++) {
                if (m_arena->nRobotsAt(row(), col() - i) >= 1) {
                    m_arena->damageRobotAt(row(), col() - i);
                    return true;
                }
            }
            break;

        case RIGHT:
            for (int i = 0; i < 5; i++) {
                if (m_arena->nRobotsAt(row(), col() + i) >= 1) {
                    m_arena->damageRobotAt(row(), col() + i);
                    return true;
                }
            }
            break;

        default:
            stand();
            break;
        }
    }



    return false;  // This implementation compiles, but is incorrect.
}

bool Player::isDead() const
{
    // TODO:  TRIVIAL:  DONE!!!!!!!!!!!!!
    return m_dead;
}

void Player::setDead()
{
    m_dead = true;
}