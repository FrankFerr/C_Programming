#include "..\include\quicksort.h"

int split(Prod arr[], int low, int high){
    Prod partitionElem = arr[low];

    for(;;){
        while(low < high && partitionElem.id <= arr[high].id)
            high--;

        if(low >= high)
            break;

        arr[low++] = arr[high];

        while(low < high && arr[low].id <= partitionElem.id)
            low++;

        if(low >= high)
            break;
            
        arr[high--] = arr[low];
    }

    arr[high] = partitionElem;

    return high;
}

void quicksort(Prod arr[], int low, int high){
    int middle;

    if(low >= high)
        return;
    
    middle = split(arr, low, high);
    quicksort(arr, low, middle - 1);
    quicksort(arr, middle + 1, high);
}

