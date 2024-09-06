class TrieNode{
    TrieNode child[] = new TrieNode[26];
    boolean endWord;

    TrieNode(){
        for(int i=0; i<26; i++){
            child[i] = null;
        }
        endWord = false;
    }
};


public class trie {
    public static void insert_key(TrieNode root, String word){
        for(int i = 0; i < word.length(); i++){
            int index = (int)word.charAt(i) - (int)'a';
            if(root.child[index] == null){
                TrieNode temp = new TrieNode();
                root.child[index] = temp;
            }
            root = root.child[index];
        }
        root.endWord = true;
    };

    public static boolean search_key(TrieNode root, String word){
        for(int i = 0; i < word.length(); i++){
            int index = (int)word.charAt(i) - (int)'a';
            if(root.child[index] == null){
                return false;
            }
            root = root.child[index];
        }
        return root.endWord;
    };

    public static void main(String args[]){
        TrieNode root = new TrieNode();
        String arr[] = {"and", "ant", "do", "geek", "dad", "ball"};
        for(String word :arr)
            insert_key(root, word);
    
        String search_keys[] = {"do", "gee", "bat"};
        for (String s : search_keys){
            System.out.printf("Key : %s", s);
            if (search_key(root, s)){
                System.out.println(" Present") ;
            }
            else{
                System.out.println(" Not Present");
            }
        }
    }
}
