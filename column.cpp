#include "column.hpp"



void Column::initLocal() {
    m_height = this->getSize().y;
}

void Column::setXpos(float x) {
    this->setPosition(sf::Vector2f(x, this->getPosition().y));
}

void Column::setHeight(float height) {
    this->setPosition(this->getPosition().x, this->getPosition().y+m_height-height);
    this->setSize(sf::Vector2f(this->getSize().x, height));
    m_height = height;
}