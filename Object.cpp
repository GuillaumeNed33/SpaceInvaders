#include "Object.h"

Object::Object(float x, float y, float w, float h) :
    m_posX{x}, m_posY{y},  m_w{w}, m_h{h}
    {

    }
Object::~Object()
{}

float Object::getX() const
{
    return m_posX;
}
float Object::getY() const
{
    return m_posY;
}
float Object::getW() const
{
    return m_w;
}
float Object::getH() const
{
    return m_h;
}

void Object::setX(float x)
{
    m_posX = x;
}

void Object::setY(float y)
{
    m_posY = y;
}
