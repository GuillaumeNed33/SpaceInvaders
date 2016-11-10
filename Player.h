#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED

#include "MovableElement.h"

class Player : public MovableElement {
private:
    int m_life = 3;
    bool m_left = false;
    bool m_right = false;

public:
    Player(float x, float y, float w, float h, float dx, float dy);
    ~Player();
    void moving();
    void setLeft(bool b);
    void setRight(bool b);
    int getLife() const;
    void damage();
};


#endif // PLAYER_H_INCLUDED
