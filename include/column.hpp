#ifndef COLUMN_H
#define COLUMN_H

#include <SFML/Graphics.hpp>

class Column : public sf::RectangleShape
{
private:
    float m_height;
public:
    // Column();

    void initLocal();

    float getHeight() { return m_height; }

    void setXpos(float x);
    void setHeight(float height);
};


#endif // COLUMN_H