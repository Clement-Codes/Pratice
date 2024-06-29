#include<iostream>
using namespace std;

void heap(int array[], int N, int i){
    int largest = i;

    int left = i * 2 + 1;
    int right = i * 2 + 2;

    if(left<N && array[left]>=array[largest]){
        largest = left;
    }

    if(right<N && array[right]>=array[largest]){
        largest = right;
    }

    if(largest != i){
        int temp = array[largest];
        array[largest] = array[i];
        array[i] = temp;
        heap(array, N, largest);
    }
}

void heapsort(int array[], int N){
    for(int i = (N/2) - 1; i>=0; i--){
        heap(array, N, i);
    }

    for(int i = N - 1; i>=0; i--){
        int temp = array[i];
        array[i] = array[0];
        array[0] = temp;
        heap(array, i, 0);
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

    heapsort(array, sizeof(array)/sizeof(array[0]));

    cout << "After: ";
    for(int i: array){
        cout << i << ',';
    }
    cout << endl;

    return 0;
}