#include "quick_sort.hpp"

bool QuickSort::sort() {
    sortHelper(0, columns->size()-1);
    return true;
}

// void QuickSort::sortHelper(int low, int high) {
//     if(low < high) {
//         auto pi = partition(low, high);
//         sortHelper(low, pi-1);
//         sortHelper(pi+1, high);
//     }
// }

// int QuickSort::partition(int low, int high) {
//     auto& pivot = columns->at(high);
//     int i = low - 1;
//     for(int j = 0; j <= high-1; j++) {
//         auto& temp = columns->at(j);
//         if( ( temp.getHeight() ) < ( pivot.getHeight() ) ) {
//             i++;
//             swap_elems(i, j);
//             update();
//         }
//     }
//     swap_elems(i+1, high);
//     update();
//     return i+1;
// }


int QuickSort::partition(int low, int high) {
    // select the rightmost element as pivot
    auto &pivot = columns->at(high);
  
    // pointer for greater element
    int i = (low - 1);

    // traverse each element of the array
    // compare them with the pivot
    for (int j = low; j < high; j++) {
        if (columns->at(j).getHeight() <= pivot.getHeight() ) {
        
            // if element smaller than pivot is found
            // swap it with the greater element pointed by i
            i++;
      
            // swap element at i with element at j
            if (i != j) {
                swap_elems(i, j);
            }
        }
    }
    swap_elems(i + 1, high);
    return (i+1);
}


void QuickSort::sortHelper(int low, int high)
{
 
    // base case
    if (low >= high)
        return;
 
    // partitioning the array
    int p = partition(low, high);
 
    // Sorting the left part
    sortHelper(low, p - 1);
 
    // Sorting the right part
    sortHelper(p + 1, high);
}