class Node:
    def __init__(self, data):
        self.data = data
        self.next = None
        self.prev = None
    
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
        temp2 = self.head
        print("Forward: ")
        while(temp!=None):
            print(temp.data, end=" ")
            temp2 = temp
            temp = temp.next

        print("\nBackward: ")
        while(temp2!=None):
            print(temp2.data, end=" ")
            temp2 = temp2.prev        
    
    
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
        if(self.head != None):
            self.head.prev = temp
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
            temp.prev = head_temp
        
    
    
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
        temp.prev = headTemp
        headTemp.next.prev = temp
        headTemp.next = temp
    
    
    def deletionAtBeginning(self):
        if(self.head == None):
            print("No node")
            return
        
        self.head.next.prev = None
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
        
        temp.next.prev = None
        temp.next = None

    
    
    def deletionAtPosition(self, position):
        if(self.head == None):
            print("No node")
            return
        
    
        if(position==0):
            self.head = self.head.next
            return
        
    
        temp = self.head
    
        for _ in range(1, position):
            if(temp.next != None):
                temp = temp.next
        
    
        if(temp.next != None):
            temp.next.next.prev = temp
            temp.next = temp.next.next

        else:
            print("No node")
            return
        
    


if __name__ == '__main__':
    sll = SingleLinkedList()
    sll.insertionAtBeginning("D")
    sll.insertionAtBeginning("C")
    sll.insertionAtBeginning("B")
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
    


