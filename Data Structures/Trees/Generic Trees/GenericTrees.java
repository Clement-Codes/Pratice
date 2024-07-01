package Trees;
import java.util.ArrayList;

public class GenericTrees {
    int data;
    ArrayList<GenericTrees> childrens;
    GenericTrees(int data){
        this.data = data;
        this.childrens = new ArrayList<GenericTrees>();
    }
}
