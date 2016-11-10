#include "View.h"
#include "Model.h"

#include <sstream>
#include <iostream>
using namespace std;

//=======================================
// Constructeur
//=======================================
View::View(int w, int h): m_w(w), m_h(h)
{
    m_window = new sf::RenderWindow(sf::VideoMode(w, h, 32), "Runner", sf::Style::Close);

    if (!m_texturePlayer.loadFromFile(PLAYER))
        std::cerr << "ERROR when loading image file: " << PLAYER << std::endl;
    if (!m_textureMissile.loadFromFile(MISSILE))
        std::cerr << "ERROR when loading image file: " << MISSILE << std::endl;
    if (!m_textureAlien.loadFromFile(ENEMIES))
        std::cerr << "ERROR when loading image file: " << ENEMIES << std::endl;
    else
    {
        m_player.setTexture(m_texturePlayer);
        m_missile.setTexture(m_textureMissile);

        m_alien.setTexture(m_textureAlien);
        sf::IntRect r(4,0,35,25);
        m_alien.setTextureRect(r);

        m_font.loadFromFile("Font/ARCADECLASSIC.ttf");
        m_score.setFont(m_font);
        m_score.setColor(sf::Color::White);
        m_score.setPosition(600, 25);
        m_life.setFont(m_font);
        m_life.setColor(sf::Color::White);
        m_life.setPosition(50, 25);

        gameOver.setFont(m_font);
        gameOver.setColor(sf::Color::White);
        gameOver.setPosition(300, 200);
        gameOver.setString("GAME OVER");
        gameOver.setCharacterSize(40);

        menu.setFont(m_font);
        menu.setColor(sf::Color::White);
        menu.setPosition(25, 150);
        menu.setString("WELCOME   \nTO  \nSPACE   INVADERS");
        menu.setCharacterSize(60);

        info.setFont(m_font);
        info.setColor(sf::Color::White);
        info.setPosition(175, 450);
        info.setString("Click   any   key   to   start");
        info.setCharacterSize(40);

        pauseT.setFont(m_font);
        pauseT.setColor(sf::Color::White);
        pauseT.setPosition(325, 75);
        pauseT.setString("PAUSE");
        pauseT.setCharacterSize(50);

        win.setFont(m_font);
        win.setColor(sf::Color::White);
        win.setPosition(300, 200);
        win.setString("NEXT STAGE");
        win.setCharacterSize(40);
    }
}

void View::showMenu()
{
    m_window->clear(sf::Color::Black);
    m_window->draw(menu);
    m_window->draw(info);
    m_window->display();
}
//=======================================
// Destructeur
//=======================================
View::~View()
{
    if(m_window!= NULL)
        delete m_window;
}

//=======================================
// Accesseurs en écriture
//=======================================
void View::setModel(Model * model)
{
    m_model = model;
}

//=======================================
// Fonction de dessin
//=======================================
void View::draw()
{
    if(!game)
        showMenu();
    else
    {
        m_window->clear(sf::Color::Black);
        m_window->draw(m_player);
        for(Missile* e : m_model->getMissiles())
        {
            m_missile.setPosition(e->getX(), e->getY());
            m_window->draw(m_missile);
        }

        for(Missile* e : m_model->getMissilesEnemies())
        {
            m_missile.setPosition(e->getX(), e->getY());
            m_window->draw(m_missile);
        }

        for(Enemies* e : m_model->getEnemies())
        {
            m_alien.setPosition(e->getX(), e->getY());
            m_window->draw(m_alien);
        }
        m_window->draw(m_score);
        m_window->draw(m_life);

        if(pause)
            m_window->draw(pauseT);

        sf::Time t = sf::seconds(2);

        if(m_model->gameOverr())
        {
            m_window->clear(sf::Color::Black);
            m_window->draw(gameOver);
            m_window->display();
            sf::sleep(t);
                        m_model->reset();
            game = false;
            pause = false;
        }
        else if(m_model->winner())
        {
            m_window->clear(sf::Color::Black);
            m_window->draw(win);
            m_window->display();
            sf::sleep(t);
            m_model->nextStage();
        }
        m_window->display();
    }
}

//=======================================
// Traitement des evenements
//=======================================
bool View::treatEvents()
{
    bool result = false;
    if(m_window->isOpen())
    {
        result = true;

        sf::Event event;
        while (m_window->pollEvent(event))
        {

            if (event.type == sf::Event::Closed)
            {
                m_window->close();
                result = false;
            }
            else if(event.type == sf::Event::KeyPressed)
            {
                if(!game)
                {
                    game = true;
                }
                else
                {
                    if(event.key.code == sf::Keyboard::Left)
                    {
                        m_model->getPlayer()->setLeft(true);
                        m_model->getPlayer()->setRight(false);
                    }
                    if(event.key.code == sf::Keyboard::Right)
                    {
                        m_model->getPlayer()->setRight(true);
                        m_model->getPlayer()->setLeft(false);
                    }
                    if(event.key.code == sf::Keyboard::Escape)
                    {
                        if(pause)
                            pause = false;
                        else
                            pause = true;
                    }
                }
            }

            else if(event.type == sf::Event::KeyReleased)
            {
                if(event.key.code == sf::Keyboard::Left)
                {
                    m_model->getPlayer()->setLeft(false);
                    m_model->getPlayer()->setRight(false);
                }
                if(event.key.code == sf::Keyboard::Right)
                {
                    m_model->getPlayer()->setRight(false);
                    m_model->getPlayer()->setLeft(false);
                }
                if(event.key.code == sf::Keyboard::Space)
                {
                    m_model->playerShot();
                }
            }
        }
    }
    return result;
}

void View::synchronize()
{
    float x,y;
    m_model->getPlayerPosition(x,y);
    m_player.setPosition(x,y);
    std::stringstream score, life;
    score << m_model->getScore();
    m_score.setString("Score   " + score.str());
    life << m_model->getPlayer()->getLife();
    m_life.setString("Life   " + life.str());
}

