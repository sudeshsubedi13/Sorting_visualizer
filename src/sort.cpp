#include "sort.hpp"

void Sort::swap_elems(int i, int j) {
    auto temp_height = columns->at(i).getHeight();
    columns->at(i).setHeight( columns->at(j).getHeight() );
    columns->at(j).setHeight(temp_height);
}

void Sort::update() {
    window->clear(sf::Color::Black);

    // drawing stuff
    for(int i = 0; i<columns->size(); i++) {
        window->draw(columns->at(i));
    }

    window->display();
    //std::this_thread::sleep_for(std::chrono::microseconds(2000));
}