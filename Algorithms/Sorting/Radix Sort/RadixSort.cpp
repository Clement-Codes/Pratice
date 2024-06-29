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

void countsort(int array[], int N, int e){
    int nn = sizeof(array)/sizeof(array[0]); 
    int output[5];
    int count[10] = {0};

    for(int i=0; i<N;i++){
        count[(array[i]/e) % 10] += 1;
    }

    for(int i=1; i<10;i++){
        count[i] += count[i-1];
    }

    cout << "M: ";
    for(int i=0; i<10;i++){
        cout << count[i] << ',';
    }
    cout << endl;

    for(int i=N-1; i>=0;i--){
        output[count[(array[i]/e) % 10] - 1] = array[i];
        count[(array[i]/e) % 10] -= 1;
    }

    for(int i=0; i<N;i++){
        array[i] = output[i];
    }
}

void radixsort(int array[], int N){
    int m = max(array, N);

    for(int e=1; m/e>1; e*=10){
         countsort(array, N, e);
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

    radixsort(array, sizeof(array)/sizeof(array[0]));

    cout << "After: ";
    for(int i: array){
        cout << i << ',';
    }
    cout << endl;

    return 0;
}