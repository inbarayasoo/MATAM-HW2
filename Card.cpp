#include "Card.h"
#include "utilities.h"

Card::Card(CardType type, const CardStats& stats) : m_effect(type), m_stats(stats)
{}

void Card::printInfo() const
{
    if (m_effect == CardType::Buff)
    {
        printBuffCardInfo(m_stats);
    }
    else if (m_effect == CardType::Battle)
    {
        printBattleCardInfo(m_stats);
    }
    else if (m_effect == CardType::Treasure)
    {
        printTreasureCardInfo(m_stats);
    }
    else
    {
        printHealCardInfo(m_stats);
    }
}

void Card::applyEncounter(Player& player) const
{
    if (m_effect == CardType::Buff || m_effect == CardType::Heal)
    {
        if (player.pay(m_stats.cost))
        {
            if (m_effect == CardType::Buff)
            {
                player.buff(m_stats.buff);
            } else
            {
                player.heal(m_stats.heal);
            }
        }

    }
    else if (m_effect == CardType::Battle)
    {
        bool win = false;
        if (m_stats.force <= player.getAttackStrength())
        {
            win = true;
            player.levelUp();
            player.addCoins(m_stats.loot);
        }
        else
        {
            player.damage(m_stats.hpLossOnDefeat);
        }
        printBattleResult(win);
    }
    else
    {
        player.addCoins(m_stats.loot);
    }
}


