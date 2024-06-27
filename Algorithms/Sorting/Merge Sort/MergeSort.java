import java.util.Scanner;
public class MergeSort{

    public static void merge(int array[], int left, int middle, int right){
        int leftSize = middle - left + 1;
        int rightSize = right - middle;

        int leftArray[] = new int[leftSize];
        int rightArray[] = new int[rightSize];

        for(int i=0; i<leftSize; i++){
            leftArray[i] = array[left+i];
        }

        for(int i=0; i<rightSize; i++){
            rightArray[i] = array[middle+1+i];
        }

        int ll = 0, rr = 0, cc = left;
        while (ll<leftSize && rr<rightSize) {
            if(leftArray[ll]<=rightArray[rr]){
                array[cc] = leftArray[ll];
                ll++;
            }
            else{
                array[cc] = rightArray[rr];
                rr++;
            }
            cc++;
        }

        while (ll<leftSize) {
            array[cc] = leftArray[ll];
            ll++;
            cc++;
        }

        while (rr<rightSize) {
            array[cc] = rightArray[rr];
            rr++;
            cc++;
        }

    }

    public static void mergesorting(int array[], int left, int right){
        if(left<right){
            int middle = (left + right) / 2;
            mergesorting(array, left, middle);
            mergesorting(array, middle+1, right);
            merge(array, left, middle, right);
        }
    }

    public static void main(String args[]){
        Scanner sc = new Scanner(System.in);

        int array[] = new int[5];
        for(int i = 0; i<array.length; i++){
            array[i] = sc.nextInt();
        }

        System.out.println("Before: ");
        for(int i = 0; i<array.length; i++){
            System.out.printf("%d ", array[i]);
        }

        mergesorting(array, 0, array.length-1);

        System.out.println("\nAfter: ");
        for(int i = 0; i<array.length; i++){
            System.out.printf("%d ", array[i]);
        }
    }
}