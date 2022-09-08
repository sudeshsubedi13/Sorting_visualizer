#include "bubble_sort.hpp"


bool BubbleSort::sort() {
    for(int j=1; j<columns->size(); j++) {
        for(int i=0; i<j; i++) {
            if(columns->at(i).getHeight() > columns->at(j).getHeight()) {
                // auto temp_height = columns->at(i).getHeight();
                // columns->at(i).setHeight( columns->at(j).getHeight() );
                // columns->at(j).setHeight(temp_height);
                this->swap_elems(i, j);
            }
            update();
            // window->clear(sf::Color::Black);

            // // drawing stuff
            // for(int i = 0; i<columns->size(); i++) {
            //     window->draw(columns->at(i));
            // }

            // window->display();
            // std::this_thread::sleep_for(std::chrono::milliseconds(200));
        }
    }
    return true;
}