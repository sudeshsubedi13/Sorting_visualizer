#ifndef BUBBLE_SORT_H
#define BUBBLE_SORT_H

#include "sort.hpp"


class BubbleSort : public Sort
{
public:
    BubbleSort(std::vector<Column>* columns): Sort(columns) {};
    bool sort();
};



#endif // BUBBLE_SORT_H