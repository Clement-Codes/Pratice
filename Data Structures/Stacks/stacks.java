import java.util.Stack;
public class stacks {
    public static void main(String[] args){
        Stack<Integer> s = new Stack<>();
        s.push(1);
        s.push(2);
        s.push(3);
        System.out.printf("Length: %d\n", s.size());
        System.out.printf("Length: %b\n", s.isEmpty());
        while (!s.isEmpty()) {
            System.out.println(s.peek());
            s.pop();
        }
    }
}
