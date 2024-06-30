import java.util.Scanner;

public class LinearSearch {

    public static void main(String args[]){
        int array[] = {0,0,0,0,0};
        Scanner sc = new Scanner(System.in);
        for(int i = 0; i<array.length; i++){
            array[i] = sc.nextInt(); 
        }
    
        int x = sc.nextInt();
    
        boolean found = false;
    
        for (int i: array){
            if (x == i){
                found = true;
                break;
            }
        }
    
        System.out.println(found);
    }
    
}
