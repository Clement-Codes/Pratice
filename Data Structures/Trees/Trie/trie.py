class TrieNode:
    def __init__(self) -> None:   
        self.child = [None] * 26
        self.endWord = False
    
def insert_key(root, word):
    for i in word:
        index = ord(i) - ord('a')
        if root.child[index] is None:
            temp = TrieNode()
            root.child[index] = temp
        root = root.child[index]
    root.endWord = True

def search_key(root, word):
    for i in word:
        index = ord(i) - ord('a')
        if root.child[index] is None:
            return False
        root = root.child[index]
    return root.endWord
    
if __name__ == "__main__":
    root = TrieNode()
    arr = ["and", "ant", "do", "geek", "dad", "ball"]
    for s in arr:
        insert_key(root, s)

    search_keys = ["do", "gee", "bat"]
    for s in search_keys:
        print(f"Key : {s}")
        if search_key(root, s):
            print("Present")
        else:
            print("Not Present")