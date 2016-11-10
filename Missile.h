#ifndef MISSILE_H_INCLUDED
#define MISSILE_H_INCLUDED

#include "MovableElement.h"

class Missile : public MovableElement {
private:
    bool m_player;
    bool m_enemies;
public:
    Missile(float x, float y, float w, float h, float dx, float dy, bool player, bool enemies);
    ~Missile();
    bool getOrigin() const;
};

#endif // MISSILE_H_INCLUDED
