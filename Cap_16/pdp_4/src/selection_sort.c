#include "..\include\selection_sort.h"

void selectionSort(Prod a[], int n){
    if(n == 0)
        return;

    int idxMax = 0;
    Prod temp;

    for(int i = 0; i < n; i++){
        if(a[idxMax].id < a[i].id){
            idxMax = i;
        }
    }

    temp = a[n - 1];
    a[n - 1] = a[idxMax];
    a[idxMax] = temp;

    selectionSort(a, n - 1);
}