#include "Enemies.h"
#include "random"
bool Enemies::gauche = false;

Enemies::Enemies(float x, float y, float w, float h, float dx, float dy) :
    MovableElement {x,y,w,h,dx,dy}
{

}

Enemies::~Enemies()
{

}

void Enemies::move()
{
    if(gauche)
        m_posX -= m_dx;

    else
        m_posX += m_dx;
}

void Enemies::changeSens()
{
    if(gauche)
        gauche = false;
    else
        gauche=true;
}

bool Enemies::shoot()
{
    int alea = rand()%10000;
    if(alea == 3)
        return true;
    else
        return false;
}
