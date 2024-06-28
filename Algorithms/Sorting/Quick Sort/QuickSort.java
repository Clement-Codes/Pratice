import java.util.Scanner;

public class QuickSort {
    static int partition(int array[], int s, int l){
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

    static void quicksort(int array[], int s, int l){
        if(s<l){
            int pivot = partition(array, s, l);
            quicksort(array, s, pivot-1);
            quicksort(array, pivot+1, l);
        }
    }

    public static void main(String args[]){
        Scanner sc = new Scanner(System.in);

        int array[] = {0,0,0,0,0};

        for(int i = 0; i<array.length; i++){
            array[i] = sc.nextInt(); 
        }

        System.out.print("Before: ");
        for(int i: array){
            System.out.printf("%d,",i);
        }
        System.out.printf("\n");

        quicksort(array, 0 , array.length - 1);

        System.out.print("After: ");
        for(int i: array){
            System.out.printf("%d,",i);
        }
        System.out.printf("\n");
    }
}