#include "Mtmchkin.h"


Mtmchkin::Mtmchkin(const char* playerName, const Card* cardsArray, int numOfCards) : 
    m_player(playerName), m_gameStatus(GameStatus::MidGame), m_cardIndex(0),
    m_numberOfCards(numOfCards)
{
    m_cards = new Card[numOfCards];
    for (int i = 0; i < numOfCards; i++)
    {
        m_cards[i] = cardsArray[i];
    }   
}

Mtmchkin::~Mtmchkin()
{
    delete[] m_cards;
}

void Mtmchkin::playNextCard()
{
    m_cards[m_cardIndex].printInfo();
    m_cards[m_cardIndex].applyEncounter(m_player);
    m_player.printInfo();

    if (m_player.getLevel() == MAX_LEVEL) {
        m_gameStatus = GameStatus::Win;
    }
    else if (m_player.isKnockedOut())
    {
        m_gameStatus = GameStatus::Loss;
    }
    if (m_cardIndex == (m_numberOfCards - 1))
    {
        m_cardIndex = 0;
    }
    else
    {
        m_cardIndex++;
    }
}

bool Mtmchkin::isOver() const
{
    return ((m_gameStatus == GameStatus::Win) || (m_gameStatus == GameStatus::Loss));
}

GameStatus Mtmchkin::getGameStatus() const
{
    return m_gameStatus;
}