import java.util.Scanner;

public class RadixSort {
    
    static int array [] = new int[5];

    public static int max(int array[], int N){
        int max = array[0];
        for(int i = 0; i<N;i++){
            if (i>max){
                max = i;
            }
        }
        return max;
    }

    public static void countsort(int array[], int N, int e){
        int output[] = new int[N];
        int count[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

        for(int i=0; i<N;i++){
            count[(array[i]/e) % 10] += 1;
        }

        for(int i=1; i<10;i++){
            count[i] += count[i-1];
        }

        for(int i=N-1; i>=0;i--){
            output[count[(array[i]/e) % 10] - 1] = array[i];
            count[(array[i]/e) % 10] -= 1;
        }

        for(int i=0; i<N;i++){
            array[i] = output[i];
        }
    }

    static void radixsort(int array[], int N){
        int m = max(array, N);

        for(int e=1; m/e>1; e*=10){
            countsort(array, N, e);
        }
    }


    public static void main(String args[]){

        Scanner sc = new Scanner(System.in);

        for(int i = 0; i<array.length; i++){
            array[i] = sc.nextInt(); 
        }

        System.out.print("Before: ");
        for(int i: array){
            System.out.printf("%d, ",i);
        }
        System.out.print('\n');

        radixsort(array, array.length);

        System.out.print("After: ");
        for(int i: array){
            System.out.printf("%d, ",i);
        }
        System.out.print('\n');

    }

}