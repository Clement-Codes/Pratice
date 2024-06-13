package Arrays;
import java.util.*;

public class Arrays
{
    public static void main(String args[]){
        int size;
        Scanner sc = new Scanner(System.in);
        size = sc.nextInt();
        int array[] = new int[size];
        System.out.printf("Size entered is %d",size);
        for(int i: array){
            System.out.println(i);
        }
    }
}

