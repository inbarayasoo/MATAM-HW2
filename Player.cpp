#include "Player.h"
#include "utilities.h"

/*
        * returns the default maxHP if parameter is below or equal tp zero
        *otherwise returns the positive maxHP
        *@param maxHP - maximum HP of player
        * @return
        *      int
*/
// check if force is negative and if yes change the value of the parameter to default.
static int getForce(int force)
{
    if (force > 0)
    {
        force = force;
    }
    else
    {
        force = DEFAULT_FORCE;
    }
    return force;
}
// check if maxHP is negative and if yes change the value of the parameter to default.
static int getMaxHp(int maxHP)
{
    if (maxHP > 0)
    {
        return maxHP;
    }
    else
    {
        return DEFAULT_MAX_HP;
    }
}



Player::Player(std::string name, int maxHP, int force) :
    m_name(name), m_level(1), m_force(getForce(force)), m_maxHP(getMaxHp(maxHP)), m_hp(getMaxHp(maxHP)),
    m_coins(0) 
{}

void Player::levelUp()
{
    if(m_level < MAX_LEVEL)
    {
        m_level++;
    }
}

void Player::heal(int hp)
{
    if(hp <= 0)
    {
        hp = DEFAULT_VALUE;
    }
    if (m_hp + hp <= m_maxHP)
    {
        m_hp = m_hp + hp;
    }
    else
    {
        m_hp = m_maxHP;
    }
}

void Player::printInfo() const
{
    printPlayerInfo(m_name.c_str(), m_level, m_force, m_hp , m_coins);
}

int Player::getLevel() const
{
	return m_level;
}

void Player::buff(int force)
{
    if (force > 0)
    {
        m_force = force + m_force;
    } else
    {
        force = DEFAULT_VALUE;
    }
}

void Player::damage(int hp)
{
    if(hp <= 0)
    {
        hp = DEFAULT_VALUE;
    }

    if (m_hp <= hp)
    {
        m_hp = 0;
    }
    else
    {
        m_hp = m_hp - hp;
    }
}

bool Player::isKnockedOut() const
{
    return m_hp<=0;
}

int Player::getAttackStrength() const
{
    return (m_force + m_level) ;
}

void Player::addCoins(int coins)
{
    if (coins <= 0)
    {
        coins = DEFAULT_VALUE;
    }
    m_coins += coins;
}

bool Player::pay(int coins)
{
    if (coins <= 0)
    {
        coins = DEFAULT_VALUE;
    }
    if (m_coins < coins)
    {
        return false;
    }
    m_coins -= coins;
    return true;
}
