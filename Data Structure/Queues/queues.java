import java.util.Queue;
import java.util.LinkedList;

public class queues {
    public static void main(String [] args){
        Queue<Integer> q = new LinkedList<>();
        q.add(1);
        q.add(2);
        q.add(3);
        System.out.printf("Length: %d\n", q.size());
        while(!q.isEmpty()){
            System.out.println(q.peek());
            q.remove();
        }
    }
}
