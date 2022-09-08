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

enum Algo {
    BUBBLE, QUICK
};

int chooseAlgo();

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


    

    // choosing sorting algorithm
    auto sortb = new BubbleSort(&columns);
    auto sortq = new QuickSort(&columns);
    int opt = chooseAlgo(); 
    switch (opt)
    {
    case QUICK:
        delete sortb;
        break;
    case BUBBLE:
    default:
        delete sortq;
        break;
    }

    sf::RenderWindow window(sf::VideoMode(1200, 675), "Sorting", sf::Style::Close | sf::Style::Titlebar);
    switch (opt)
    {
    case QUICK:
        sortq->setWindow(&window);
        break;
    case BUBBLE:
    default:
        sortb->setWindow(&window);
        break;
    }

    bool sorted = false;
    while(window.isOpen()) {
        sf::Event event;

        while(window.pollEvent(event)) {
            
            if(event.type == sf::Event::Closed) {
                window.close();
            }
        }
        if(!sorted) {
            switch (opt)
            {
            case QUICK:
                sortq->sort();
                break;
            case BUBBLE:
            default:
                sortb->sort();
                break;
            }

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



int chooseAlgo() {
    std::vector<std::string> algo_names;
    algo_names.push_back("Bubble sort");
    algo_names.push_back("Quick sort");
    int opt;
    std::cout << "Please choose an algorithm, (default = 1)\n";
    for(int i = 0; i<algo_names.size(); i++) {
        std::cout << i+1 << ".  "  << algo_names.at(i) << "\n";
    }

    std::cin >> opt;
    if(opt <= 0 || opt > algo_names.size()) {
        std::cout << "option " << opt << " not available. using default option.\n";
        return 0;
    }

    return opt-1;
}