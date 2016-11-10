#ifndef _VIEW_
#define _VIEW_

#include <SFML/Graphics.hpp>

const std::string BACKGROUND_IMAGE = "Images/city.png";
const std::string PLAYER = "Images/player.png";
const std::string MISSILE = "Images/missile.png";
const std::string ENEMIES = "Images/enemies.png";

class Model;

class View
{
private:
    int m_w, m_h;

    sf::RenderWindow * m_window;
    Model * m_model;

    sf::Texture m_texturePlayer;
    sf::Sprite m_player;

    sf::Texture m_textureMissile;
    sf::Sprite m_missile;

    sf::Texture m_textureAlien;
    sf::Sprite m_alien;

    sf::Font m_font;
    sf::Text m_score;
    sf::Text m_life;
    sf::Text win;
    sf::Text gameOver;
    sf::Text menu;
    sf::Text info;
    sf::Text pauseT;



public:
    View(int w, int h);
    ~View();

    void setModel(Model * model);
    void draw();
    bool treatEvents();
    void synchronize();
    void showMenu();
    bool game = false;
    bool pause = false;

};
#endif
