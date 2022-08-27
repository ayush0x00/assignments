#include <bits/stdc++.h>
#include "seqLinearList.hpp"
#include "sorting.hpp"

int main(){
    LinearList<double> test(5);
    test.insert(0,10.12);
    test.insert(1,4.06);
    test.insert(2,8.96);
    test.insert(3,15.37);
    test.deleteElement(2,5.67);

    Sort<float> s;
    // s.insertionSort(test,0,3);
    // s.mergeSort(test,0,3);
    // s.quickSort(test,0,3);
    for(int i=0;i<4;i++) cout<<test[i]<<" ";
    return 0;
}