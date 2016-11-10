#include "Model.h"

#include <iostream>
#include <fstream>
using namespace std;

int Model::increment=0;
bool Model::gameOver=false;
bool Model::win=false;

//=======================================
// Constructeurs
//=======================================
Model::Model(int w, int h)
    :  m_w(w), m_h(h)
{
    m_player = new Player(380,525,23,14,0,0);

    for (int i=0; i<11 ; i++)
    {
        for(int j=0; j<5; j++)
        {
            Enemies *e = new Enemies(100+i*50, 150+j*25,35,25,15,0);
            m_enemies.insert(e);
        }
    }
}

//=======================================
// Destructeurs
//=======================================
Model::~Model()
{
    delete m_player;
    for(Missile* m : m_missile)
        delete m;
    for(Missile* m: m_missileEnemies)
        delete m;
    for(Enemies* e: m_enemies)
        delete e;
    m_missile.clear();
    m_missileEnemies.clear();
    m_enemies.clear();
}

//=======================================
// Calcul la prochaine étape
//=======================================
void Model::nextStep()
{
    deleteElement();
    if(!gameOver && !win)
    {
        if(m_enemies.empty())
        {
            win = true;
            m_score += 1000;
        }
        else
        {
            m_player->moving();
            m_player->move();

            if(m_player->getLife() <= 0)
                gameOver = true;

            for(Missile* m : m_missile)
            {
                m->move();
            }
            for(Missile* m : m_missileEnemies)
            {
                m->move();
            }
            for(Enemies* e: m_enemies)
            {
                if(e->getY() >495)
                {
                    cout << "GAME OVER" << endl;
                    gameOver = true;
                }

                if(e->shoot())
                {
                    Missile* m = new Missile(e->getX()+11, e->getY(), 1,6,0,0.15+(difficulty/100),false, true);
                    m_missileEnemies.insert(m);
                }

                if((e->getX()+e->getW() >= m_w-5) || (e->getX()<= 5))
                {
                    e->changeSens();
                    for(Enemies* e: m_enemies)
                    {
                        e->setY(e->getY()+20);
                        e->move();
                    }
                }
                if(increment%750==0)
                {
                    e->move();
                    increment=0;
                }
            }

            for(Enemies* e: m_enemies)
            {
                for(Missile* m : m_missile)
                {
                    if(e->collision(m))
                    {
                        m_score +=100;
                        m_trash.insert(e);
                        m_trash.insert(m);
                    }
                }
            }
            for(Missile* m : m_missileEnemies)
            {
                if(m->collision(m_player))
                {
                    m_player->damage();
                    m_trash.insert(m);
                }
            }
            increment++;
        }
    }
}

void Model::deleteElement()
{
    for(MovableElement* e : m_trash)
    {
        if(dynamic_cast<Missile*>(e) != nullptr)
        {
            if(dynamic_cast<Missile*>(e)->getOrigin())
                m_missile.erase(m_missile.find(dynamic_cast<Missile*>(e)));
            else
                m_missileEnemies.erase(m_missileEnemies.find(dynamic_cast<Missile*>(e)));
        }

        else if(dynamic_cast<Enemies*>(e) != nullptr)
            m_enemies.erase(m_enemies.find(dynamic_cast<Enemies*>(e)));
        delete e;
    }
    m_trash.clear();
}

void Model::getPlayerPosition(float &x, float &y) const
{
    x = m_player->getX();
    y = m_player->getY();
}

Player* Model::getPlayer() const
{
    return m_player;
}

void Model::playerShot()
{
    Missile* m = new Missile(m_player->getX()+11, m_player->getY()-5, 1,6,0,-0.15,true, false);
    m_missile.insert(m);
}

std::set<Missile*> Model::getMissiles() const
{
    return m_missile;
}

std::set<Missile*> Model::getMissilesEnemies() const
{
    return m_missileEnemies;
}

std::set<Enemies*> Model::getEnemies() const
{
    return m_enemies;
}

int Model::getScore() const
{
    return m_score;
}
bool Model::gameOverr() const
{
    return gameOver;
}

bool Model::winner() const
{
    return win;
}

void Model::reset()
{
    delete m_player;
    for(Missile* m : m_missile)
        delete m;
    for(Missile* m: m_missileEnemies)
        delete m;
    for(Enemies* e: m_enemies)
        delete e;
    m_missile.clear();
    m_missileEnemies.clear();
    m_enemies.clear();

    m_player = new Player(380,525,23,14,0,0);

    for (int i=0; i<11 ; i++)
    {
        for(int j=0; j<5; j++)
        {
            Enemies *e = new Enemies(100+i*50, 150+j*25,35,25,15,0);
            m_enemies.insert(e);
        }
    }

    m_score = 0;
    gameOver = false;
    win = false;
    increment = 0;
}

void Model::nextStage()
{
    difficulty +=5;
    delete m_player;
    m_player = new Player(380,525,23,14,0,0);
gameOver = false;
    win = false;
    for (int i=0; i<11 ; i++)
    {
        for(int j=0; j<5; j++)
        {
            Enemies *e = new Enemies(100+i*50, 150+j*25,35,25,15+difficulty,0);
            m_enemies.insert(e);
        }
    }
}
