import java.util.Scanner;

public class SelectionSort{
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
            int min = i; 
            for(int j = i+1; j < array.length; j++){
                if (array[min]>array[j]){
                    min = j;
                }
            }  
            if(min!=i){
                int temp = array[i];
                array[i] = array[min];
                array[min] = temp;
            }      
        }

        System.out.print("After: ");
        for(int i : array){
            System.out.printf("%d,", i);
        }
        
    }
}