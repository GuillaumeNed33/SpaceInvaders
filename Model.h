#ifndef _MODEL_
#define _MODEL_

#include "Player.h"
#include "Missile.h"
#include "Enemies.h"
#include <set>

class Model
{
private:
    int m_w, m_h;
    Player* m_player;
    std::set<Missile*> m_missile;
    std::set<Missile*> m_missileEnemies;
    std::set<Enemies*> m_enemies;
    std::set<MovableElement*> m_trash;
    static int increment;
    static bool gameOver, win;
    int m_score = 0;
    int difficulty = 0;

public:

    Model(int w, int h);
    ~Model();

    void nextStep();
    void getPlayerPosition(float &x, float &y) const;
    Player* getPlayer() const;
    void playerShot();
    std::set<Missile*> getMissiles() const;
    std::set<Missile*> getMissilesEnemies() const;
    std::set<Enemies*> getEnemies() const;
    void deleteElement();
    int getScore() const;
    bool gameOverr() const;
    bool winner() const;
    void reset();
    void nextStage();
};
#endif
