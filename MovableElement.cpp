#include "MovableElement.h"

MovableElement::MovableElement(float x, float y, float w, float h, float dx, float dy) :
    Object {x,y,w,h}, m_dx {dx}, m_dy {dy}
{

}

MovableElement::~MovableElement()
{}

void MovableElement::move()
{
    m_posX += m_dx;
    m_posY += m_dy;
}

void MovableElement::setDx(float dx)
{
    m_dx = dx;
}

void MovableElement::setDy(float dy)
{
    m_dy = dy;
}

bool MovableElement::collision(MovableElement* m)
{
    const float leftA = m_posX; //Cote gauche de la balle
    const float rightA = m_posX + m_w; //Le droit
    const float topA = m_posY; //Le Haut
    const float bottomA = m_posY + m_h; //Le bas

    const float leftB = m->getX();
    const float rightB = m->getX() + m->getW();
    const float topB = m->getY();
    const float bottomB = m->getY() + m->getH();

    if(bottomA <= topB)
        return false;
    if(topA >= bottomB)
        return false;
    if(rightA <= leftB)
        return false;
    if(leftA >= rightB)
        return false;

    return true;
}
