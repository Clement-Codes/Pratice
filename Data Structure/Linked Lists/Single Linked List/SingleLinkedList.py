class Node:
    def __init__(self, data):
        self.data = data
        self.next = None   
    
class SingleLinkedList :
    def __init__(self):
       self.head = None


    def search(self, target):
        temp = self.head

        while(temp!=None):
            if(temp.data == target):
                return True
            
            temp = temp.next
        
        return False
    
    
    def traverse(self):
        temp = self.head
        while(temp!=None):
            print(temp.data)
            temp = temp.next
        
    
    
    def length (self):
        length = 0
        temp = self.head
        while (temp!=None):
            length+=1
            temp=temp.next
        return length
    
    
    def insertionAtBeginning(self, data):
        temp = Node(data)
        temp.next = self.head
        self.head = temp
    
    
    def insertionAtEnd(self, data):
        temp = Node(data)
        head_temp = self.head
        if (self.head == None):
            self.head = temp
        else:
            while(head_temp.next != None):
                head_temp = head_temp.next
            
            head_temp.next = temp
        
    
    
    def insertionAtPosition(self, position, data):
        temp = Node(data)
        headTemp = self.head
        if(position == 0 or headTemp == None):
            temp.next = headTemp
            headTemp = temp
            return
        
        for _ in range(position):
            if(headTemp.next != None):
                headTemp = headTemp.next
        
        temp.next = headTemp.next
        headTemp.next = temp
    
    
    def deletionAtBeginning(self):
        if(self.head == None):
            print("No node")
            return
        
        self.head = self.head.next
    
    
    def deletionAtEnd(self):
        if(self.head == None):
            print("No node")
            return

        if(self.head.next == None):
            self.head = None
            return
    
        temp = self.head
    
        while(temp.next.next != None):
            temp = temp.next
        
        temp.next = None
    
    
    def deletionAtPosition(self, position):
        if(self.head == None):
            print("No node")
            return
        
    
        if(position==0):
            self.head = self.head.next
            return
        
    
        temp = self.head
    
        for _ in range(position):
            if(temp.next != None):
                temp = temp.next
        
    
        if(temp.next != None):
            temp.next = temp.next.next
        else:
            print("No node")
            return
        
    


if __name__ == '__main__':
    sll = SingleLinkedList()
    sll.insertionAtEnd("B")
    sll.insertionAtEnd("C")
    sll.insertionAtEnd("D")
    sll.traverse()
    print(sll.search("D"))
    print("Length", sll.length())
    sll.insertionAtBeginning("A")
    sll.insertionAtEnd("F")
    sll.insertionAtPosition( 3, "E")
    sll.deletionAtBeginning()
    sll.deletionAtEnd()
    sll.deletionAtPosition(1)
    sll.traverse()
    


