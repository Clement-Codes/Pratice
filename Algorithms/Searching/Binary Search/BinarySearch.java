import java.util.Scanner;

public class BinarySearch {

    public static void main(String args[]){
        int array[] = {0,0,0,0,0};
        Scanner sc = new Scanner(System.in);
        for(int i = 0; i<array.length; i++){
            array[i] = sc.nextInt(); 
        }
    
        int x = sc.nextInt();
    
        boolean found = false;
    

        int low = 0, high = array.length - 1;
        int mid;
        while (low<=high){
            mid = low + (high - low)/2;
            if (array[mid] == x){
                found = true;
                break;
            }
            else if(array[mid] < x){
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }
    
    
        System.out.println(found);
    }
    
}
