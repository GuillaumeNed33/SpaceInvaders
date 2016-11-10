#ifndef MOVABLEELEMENT_H_INCLUDED
#define MOVABLEELEMENT_H_INCLUDED

#include "Object.h"

class MovableElement : public Object {
protected:
    float m_dx;
    float m_dy;
public:
    MovableElement(float x, float y, float w, float h, float dx, float dy);
    virtual ~MovableElement();
    virtual void move();
    void setDx(float dx);
    void setDy(float dy);
    bool collision(MovableElement* m);
};

#endif // MOVABLEELEMENT_H_INCLUDED
