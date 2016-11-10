#include "Missile.h"

Missile::Missile(float x, float y, float w, float h, float dx, float dy, bool player, bool enemies) :
    MovableElement{x,y,w,h,dx,dy}, m_player{player}, m_enemies{enemies}
    {

    }

Missile::~Missile()
{

}

bool Missile::getOrigin() const
{
    return m_player; //True --> Tir du joueur
                    //False --> Tir d'un enemi
}
