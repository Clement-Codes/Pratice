import java.util.Scanner;

public class InsertionSort{
    public static void main(String args[]){
        Scanner sc = new Scanner(System.in);
        int array[] = new int[5];
        for(int i = 0; i < array.length; i++){
            array[i] = sc.nextInt();
        }

        System.out.print("Before: ");
        for(int i : array){
            System.out.printf("%d,", i);
        }

        for(int i = 0; i < array.length; i++){
            int key =i;
            int j = key - 1;
            while(j>=0 && array[key]<array[j]){
                int temp = array[key];
                array[key] = array[j];
                array[j] = temp;
                key = j;
                j -= 1;
            }
        }

        System.out.print("After: ");
        for(int i : array){
            System.out.printf("%d,", i);
        }
        
    }
}