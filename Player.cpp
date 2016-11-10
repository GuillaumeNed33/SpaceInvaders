#include "Player.h"

Player::Player(float x, float y, float w, float h, float dx, float dy) :
    MovableElement {x,y,w,h,dx,dy}
{

}

Player::~Player()
{

}

void Player::moving()
{
    if(m_left && m_posX > 10 && !m_right)
    {
        setDx(-0.3);
    }
    else if(m_right && m_posX < 790 && !m_left)
    {
        setDx(0.3);
    }
    else if(!m_left && !m_right)
    {
        setDx(0);
    }
    if(m_posX > 790)
        m_posX = 790;
    if(m_posX < 10)
        m_posX = 10;
}

void Player::setLeft(bool b)
{
    m_left = b;
}

void Player::setRight(bool b)
{
    m_right = b;
}

int Player::getLife() const
{
    return m_life;
}

void Player::damage()
{
    if(m_life >0)
        m_life--;
}
