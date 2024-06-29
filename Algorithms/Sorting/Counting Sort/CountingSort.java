import java.util.Scanner;

public class CountingSort {
    
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

    public static void countsort(int array[], int N){
        int output[] = new int[N];
        int count[] = new int[max(array, N) + 1];

        for(int i=0; i<N;i++){
            count[array[i]] += 1;
        }

        for(int i=1; i<count.length;i++){
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

        countsort(array, array.length);

        System.out.print("After: ");
        for(int i: array){
            System.out.printf("%d, ",i);
        }
        System.out.print('\n');

    }

}