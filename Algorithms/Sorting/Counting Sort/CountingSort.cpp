#include<iostream>
using namespace std;

int max(int array[], int N){
    int max = array[0];
    for(int i = 0; i<N;i++){
        if (i>max){
            max = i;
        }
    }
    return max;
}

void countsort(int array[], int N){
    int output[5];
    int count[6] = {0};

    for(int i=0; i<N;i++){
        count[array[i]] += 1;
    }

    for(int i=1; i<6;i++){
        count[i] += count[i-1];
    }

    for(int i=N-1; i>=0;i--){
        output[count[array[i]] - 1] = array[i];
        count[array[i]] -= 1;
    }

    for(int i=0; i<N;i++){
        array[i] = output[i];
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

    countsort(array, sizeof(array)/sizeof(array[0]));

    cout << "After: ";
    for(int i: array){
        cout << i << ',';
    }
    cout << endl;

    return 0;
}