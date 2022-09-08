#ifndef QUICK_SORT_H
#define QUICK_SORT_H

#include "sort.hpp"


class QuickSort : public Sort
{
public:
    void sortHelper(int low, int high);
    int partition(int low, int high);
public:
    QuickSort(std::vector<Column>* columns): Sort(columns) {};
    bool sort();
};



#endif // BUBBLE_SORT_H