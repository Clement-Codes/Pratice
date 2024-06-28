#include<iostream>
using namespace std;

int partition(int array[], int s, int l){
    int current = s - 1;
    for(int i=s; i<l; i++){
        if (array[i]<array[l]){
            current++;
            int temp = array[i];
            array[i] = array[current];
            array[current] = temp;
        }
    }
    int temp = array[l];
    array[l] = array[current+1];
    array[current+1] = temp;
    return current+1;
}

void quicksort(int array[], int s, int l){
    if(s<l){
        int pivot = partition(array, s, l);
        quicksort(array, s, pivot-1);
        quicksort(array, pivot+1, l);
    }
}

int main(){
    int array[5] = {0,0,0,0,0};

    for(int i = 0; i<(sizeof(array)/sizeof(array[0])); i++){
        cin >> array[i]; 
    }

    cout << "Before: ";
    for(int i: array){
        cout << i << ',';
    }
    cout << endl;

    quicksort(array, 0 , sizeof(array)/sizeof(array[0]) - 1);

    cout << "After: ";
    for(int i: array){
        cout << i << ',';
    }
    cout << endl;

    return 0;
}