#ifndef EX2_Player_H
#define EX2_Player_H
#include <string>
#include "utilities.h"


const int DEFAULT_FORCE = 5;
const int DEFAULT_VALUE = 0;
const int MAX_LEVEL = 10;
const int DEFAULT_MAX_HP = 100;


class Player {
public:
    /*
        * C'tor of the player:
        *
        * @param name - The name of the player.
        * @param maxHP - maxHP of player.
        * @param numOfCards - the force of player.
        * @result
        *      An instance of Mtmchkin
    */
    explicit Player(std::string name, int maxHP = DEFAULT_MAX_HP, int force = DEFAULT_FORCE);

    /*
        * Here we are explicitly telling the compiler to use the default methods
    */
    Player() = default;
    Player(const Player&) = default;
    ~Player() = default;
    Player& operator=(const Player& other) = default;
    /*
    * Rise the player level by one level:
    *
    * @return
    *     void
    */

    void levelUp();
    /*
    * Adding hp points to the player's hp:
    *@param hp - an amount of hp to add the player's hp
    * @return
    *      void
    */
    void heal(int hp);
    /*
        * Prints the player info:
        *
        * @return
        *      void
    */
    void printInfo() const;

    /*
        * @return
        *   int - the level of player
    */
    int getLevel() const;
    /*
        * Adding force points to the player's force:
        * @param force - an amount of force to add the player's force
        * @return
        *      void
    */
    void buff(int force);

    /*
        * Reducing hp points from the player's hp:
        *@param hp - an amount of hp to add the player's hp
        * @return
        *      void
    */
    void damage(int hp);
    /*
        *returns if the hp of player is up to zero (knocked out) or not
        * @return
        *      true - if the player knocked out, otherwise return false
    */
    bool isKnockedOut() const;
    /*
    *returns the attack strength of player:
    * @return
    *      int - sum of the level and force of player
*/
    int getAttackStrength() const;
    /*
        * Adding coins to the player's coins:
        *@param coins - an amount of coins to add the player's coins
        * @return
        *      void
    */
    void addCoins(int coins);
    /*
        * returns if we can reduce coins from the player's coins:
        *@param coins - an amount of coins to reduce the player's coins
        * @return
        *      true - if payment was successful and reduce from player's coins
        *      otherwise, return false and don't reduce from player's coins
    */
    bool pay(int coins);



private:

    std::string m_name;
    int m_level;
    int m_force;
    int m_maxHP;
    int m_hp;
    int m_coins;

};

#endif