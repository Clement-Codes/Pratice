import java.util.Scanner;

public class BubbleSort{
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
            int done = 1; 
            for(int j = i+1; j < array.length; j++){
                if (array[i]>array[j]){
                    int temp = array[i];
                    array[i] = array[j];
                    array[j] = temp;
                    done = 0;
                }
            }  
            if(done==1){
                break;
            }
        }

        System.out.print("After: ");
        for(int i : array){
            System.out.printf("%d,", i);
        }
        
    }
}