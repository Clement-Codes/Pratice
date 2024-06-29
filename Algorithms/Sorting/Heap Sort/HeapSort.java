import java.util.Scanner;

public class HeapSort
{
    static int array[] = {0,0,0,0,0};

    public static void heap(int array[], int N, int i){
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
    
    public static void heapsorting(int array[], int N){
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
    public static void main(String args []){
        Scanner sc = new Scanner(System.in);

        for(int i = 0; i<array.length; i++){
            array[i] = sc.nextInt(); 
        }
    
        System.out.print("Before: ");
        for(int i: array){
            System.out.printf("%d ,",i);
        }

        System.out.printf("\n");
    
        heapsorting(array, array.length);
    
        System.out.print("After: ");

        for(int i: array){
            System.out.printf("%d ,",i);
        }
        System.out.printf("\n");
    
   }
}
