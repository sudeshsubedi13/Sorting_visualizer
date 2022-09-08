#include <iostream>
#include <vector>
#include <random>
#include <iterator>
#include <algorithm>


#include <SFML/Graphics.hpp>

#include "column.hpp"
#include "bubble_sort.hpp"
#include "quick_sort.hpp"



#define WIDTH 1200
#define HEIGHT 675


int main() {
    int no_of_columns = 100; // 600;
    std::vector<float> heights(no_of_columns);

    // take input from user for no of columns
    
    // make random unsorted heights
    std::random_device rnd_device;
    // Specify the engine and distribution.
    std::mt19937 mersenne_engine {rnd_device()};  // Generates random integers
    std::uniform_int_distribution<int> dist {1, 500};
    
    auto gen = [&dist, &mersenne_engine](){
                   return dist(mersenne_engine);
               };

    generate(begin(heights), end(heights), gen);


    // heights = {50, 200, 100, 450, 350};
    float width = WIDTH / heights.size();
    // init columns
    std::vector<Column> columns;
    int i = 0;
    for(auto const height : heights) {
        Column temp;
        temp.setSize(sf::Vector2f(width, height));
        temp.setPosition(i*width, HEIGHT-height);
        // temp.setFillColor(sf::Color{ i*(255 / 100), 255, 255 });
        temp.setFillColor(sf::Color::White);
        temp.initLocal();
        columns.push_back(temp);
        i++;
    }


    sf::RenderWindow window(sf::VideoMode(1200, 675), "Sorting", sf::Style::Close | sf::Style::Titlebar);
    
    BubbleSort sort(&columns);
    // QuickSort sort(&columns);
    sort.setWindow(&window);

    bool sorted = false;
    while(window.isOpen()) {
        sf::Event event;

        while(window.pollEvent(event)) {
            
            if(event.type == sf::Event::Closed) {
                window.close();
            }
        }
        if(!sorted) {
            sorted = sort.sort();
        }
        window.clear(sf::Color::Black);

        // drawing stuf
        for(auto const column: columns) {
            window.draw(column);
        }

        window.display();
        
        
    }    
    return 0;
}

