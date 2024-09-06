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