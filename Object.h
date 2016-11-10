#ifndef OBJECT_H_INCLUDED
#define OBJECT_H_INCLUDED

class Object
{
protected:
    float m_posX;
    float m_posY;
    float m_w;
    float m_h;
public:
    Object(float x, float y, float w, float h);
    virtual ~Object();
    float getX() const;
    float getY() const;
    float getW() const;
    float getH() const;
    void setX(float x);
    void setY(float y);
};

#endif // OBJECT_H_INCLUDED
