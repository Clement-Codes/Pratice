package Arrays;
import java.util.*;

public class Arrays
{
    public static void main(String args[]){
        int size;
        Scanner sc = new Scanner(System.in);
        size = sc.nextInt();
        int array[] = {0,1,2,3,4,5,6,7,8,9};
        System.out.printf("Size entered is %d",size);
        for(int i: array){
            System.out.println(i);
        }
    }
}

