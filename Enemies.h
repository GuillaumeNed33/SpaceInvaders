#ifndef ENEMIES_H_INCLUDED
#define ENEMIES_H_INCLUDED

#include "MovableElement.h"
#include "Missile.h"
#include <set>

class Enemies : public MovableElement {
private:
    static bool gauche;

public:
    Enemies(float x, float y, float w, float h, float dx, float dy);
    ~Enemies();
    void move() override;
    void changeSens();
    bool shoot();
};

#endif // ENEMIES_H_INCLUDED
