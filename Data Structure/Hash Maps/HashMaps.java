import java.util.HashMap;
import java.util.Map;

public class HashMaps {
    public static void main(String[] args){
        HashMap <Integer, String> hashmap = new HashMap<>();
        //insert
        hashmap.put(1, "a");
        hashmap.put(2, "b");
        hashmap.put(3, "c");

        //travese
        for(Map.Entry<Integer, String> temp: hashmap.entrySet()){
            System.out.printf("%d: %s",temp.getKey(),temp.getValue());
        }

        //search
        if(hashmap.containsKey(2)){
            hashmap.remove(2);
        }

        //travese
        for(Map.Entry<Integer, String> temp: hashmap.entrySet()){
            System.out.printf("%d: %s",temp.getKey(),temp.getValue());
        }  
    }
}
