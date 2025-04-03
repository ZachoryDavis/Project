#include "Arena.h"
#include "globals.h"
#include "Arena.h"
#include "globals.h"
#include <string>
#include <iostream>
using namespace std;

Arena::Arena(int nRows, int nCols)
{
    if (nRows <= 0 || nCols <= 0 || nRows > MAXROWS || nCols > MAXCOLS)
    {
        cout << "***** Arena created with invalid size " << nRows << " by "
            << nCols << "!" << endl;
        exit(1);
    }
    m_rows = nRows;
    m_cols = nCols;
    m_player = nullptr;
    m_nRobots = 0;
}

Arena::~Arena()
{
    // TODO:  Delete the player and all remaining dynamically allocated robots.

    for (int i = 0; i < m_nRobots; i++) {
        delete[] m_robots[i];
    }
    delete m_player;
}

int Arena::rows() const
{
    // TODO:  TRIVIAL:  DONE!!!!!!!!!!!!
    return m_rows;
}

int Arena::cols() const
{
    // TODO:  TRIVIAL:  DONE!!!!!!!!!!!!!!
    return m_cols;
}

Player* Arena::player() const
{
    return m_player;
}

int Arena::robotCount() const
{
    return m_nRobots;
}

int Arena::isRobotAlive(int r, int c) const
{
    for (int i = 0; i < m_nRobots; i++) {
        if (m_robots[i]->row() - 1 == r && m_robots[i]->col() - 1 == c) {
            if (m_robots[i]->health() <= 0)
                return 0;
            else if (m_robots[i]->health() == 1)
                return 1;
            else
                return 2;

        }

    }
}

//My Function!!!!!!!!!!!!
void Arena::decreaseRobots() {
    m_nRobots -= 1;
}

int Arena::nRobotsAt(int r, int c) const
{
    // TODO:  Return the number of robots at row r, column c.
    int count = 0;
    for (int i = 0; i < m_nRobots; i++) {
        if (m_robots[i]->row() == r && m_robots[i]->col() == c)
            count++;

    }
    return count;

    // This implementation compiles, but is incorrect.
}

void Arena::display(string msg) const
{
    // Position (row,col) in the arena coordinate system is represented in
    // the array element grid[row-1][col-1]
    char grid[MAXROWS][MAXCOLS];
    int r, c;

    // Fill the grid with dots
    for (r = 0; r < rows(); r++)
        for (c = 0; c < cols(); c++)
            grid[r][c] = '.';

    // Indicate each robot's position
  // TODO:  If one robot is at some grid point, set the char to 'R'.
  //        If it's 2 though 8, set it to '2' through '8'.
  //        For 9 or more, set it to '9'.
    //DONE**************************

    for (r = 0; r < rows(); r++)
        for (c = 0; c < cols(); c++) {
            switch (nRobotsAt(r + 1, c + 1)) {
            case 1:
                grid[r][c] = 'R';
                break;
            case 2:
                grid[r][c] = '2';
                break;
            case 3:
                grid[r][c] = '3';
                break;
            case 4:
                grid[r][c] = '4';
                break;
            case 5:
                grid[r][c] = '5';
                break;
            case 6:
                grid[r][c] = '6';
                break;
            case 7:
                grid[r][c] = '7';
                break;
            case 8:
                grid[r][c] = '8';
                break;
            default:
                if (nRobotsAt(r, c) >= 9)
                    grid[r][c] = '9';
                break;
            }

        }




    for (r = 0; r < rows(); r++)
        for (c = 0; c < cols(); c++)
            if (grid[r][c])

                // Indicate player's position
                if (m_player != nullptr)
                {
                    // Set the char to '@', unless there's also a robot there,
                    // in which case set it to '*'.
                    cout << m_player->row() - 1;
                    char& gridChar = grid[m_player->row() - 1][m_player->col() - 1];
                    if (gridChar == '.')
                        gridChar = '@';
                    else
                        gridChar = '@'; //Wasn't even running the else statment when debbuging??? Not sure how was set
                }                       //to * instead of @ because if else was completely removed then player would be @ again
                                        //signifying that if statment is running as true???


                // Draw the grid
    clearScreen();
    for (r = 0; r < rows(); r++)
    {
        for (c = 0; c < cols(); c++)
            cout << grid[r][c];
        cout << endl;
    }
    cout << endl;

    // Write message, robot, and player info
    cout << endl;
    if (msg != "")
        cout << msg << endl;
    cout << "There are " << robotCount() << " robots remaining." << endl;
    if (m_player == nullptr)
        cout << "There is no player." << endl;
    else
    {
        if (m_player->age() > 0)
            cout << "The player has lasted " << m_player->age() << " steps." << endl;
        if (m_player->isDead())
            cout << "The player is dead." << endl;
    }
}

bool Arena::addRobot(int r, int c)
{
    // If MAXROBOTS have already been added, return false.  Otherwise,
    // dynamically allocate a new robot at coordinates (r,c).  Save the
    // pointer to the newly allocated robot and return true.

    // TODO:  Implement this.

    if (m_nRobots >= MAXROBOTS)
        return false;
    m_robots[m_nRobots] = new Robot(this, r, c);
    m_nRobots++;
    return true;



}

bool Arena::addPlayer(int r, int c)
{
    // Don't add a player if one already exists
    if (m_player != nullptr)
        return false;

    // Dynamically allocate a new Player and add it to the arena
    m_player = new Player(this, r, c);
    return true;
}

void Arena::damageRobotAt(int r, int c)
{
    // TODO:  Damage one robot at row r, column c if at least one is there.
    // If the robot does not survive the damage, destroy it.
    for (int i = 0; i < m_nRobots; i++) {
        if (m_robots[i]->row() == r && m_robots[i]->col() == c) {
            if (m_robots[i]->helperTakeDamageAndLive(m_robots[i]->health()) == false) {
                delete m_robots[i];
                decreaseRobots();

                for (int k = i; k < MAXROBOTS - 1; k++) {
                    m_robots[k] = m_robots[k + 1];
                }
                
                break;
            }

        }


    }



}

bool Arena::moveRobots()
{
    for (int k = 0; k < m_nRobots; k++)
    {
        // TODO:  Have the k-th robot in the arena make one move.
        //        If that move results in that robot being in the same
        //        position as the player, the player dies.
        //****************NOT SURE IF WORKS*****************
        m_robots[k]->move();
        if (m_robots[k]->row() - 1 == m_player->row() - 1 && m_robots[k]->col() - 1 == m_player->col() - 1) {
            m_player->setDead();
            return m_player->isDead();
            //k = m_nRobots;
        }

    }

    // return true if the player is still alive, false otherwise
    return !m_player->isDead();
}