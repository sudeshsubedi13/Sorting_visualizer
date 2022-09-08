#ifndef SORT_H
#define SORT_H

#include <vector>
#include <SFML/Graphics.hpp>
#include "column.hpp"
#include <chrono>
#include <thread>


class Sort
{
public:
    void swap_elems(int i, int j);
    void update();
public:
    Sort(std::vector<Column>* columns): columns(columns) {};
    void setWindow(sf::RenderWindow* window) { this->window = window; }

    virtual bool sort()=0;
protected:
    sf::RenderWindow* window;
    std::vector<Column>* columns;
};




#endif // SORT_H