class Node:
    def __init__(self, data):
        self.data = data
        self.prev = None
        self.next = None


class DoubleCircularLinkedList:
    def __init__(self):
        self.head = None
    
    
    def traverse(self):
        temp = self.head
        temp2 = temp
        print("Forward: ")
        while True:
            temp2 = temp
            print(temp.data," ", end='')
            temp = temp.next
            if (temp == None or temp==self.head):
                break
        
        print("Backward: ")
        while True:
            print(temp2.data," ", end='')
            temp2 = temp2.prev
            if (temp2 == None or temp2==self.head.prev):
                break
    
    
    def insertAtBeginning(self, data):
        temp = Node(data)
        if(self.head==None):
            (self.head) = temp
            return
        else:
            temp.next = (self.head)
            (self.head).prev = temp
            temp2 = (self.head)
            while(temp2.next != None and temp2.next != self.head):
                temp2 = temp2.next
            
            temp2.next = temp
            temp.prev = temp2
            (self.head) = temp
            return
        
    
    
    def insertAtEnd(self, data):
        temp = Node(data)
        if(self.head==None):
            (self.head) = temp
            return
        
        else:
            temp2 = (self.head)
            while(temp2.next != None and temp2.next != self.head):
                temp2 = temp2.next
            
            temp.next = temp2.next
            temp2.next.prev=temp
            temp2.next = temp
            temp.prev = temp2
            return

    def insertAtPosition(self, position, data):
        temp = Node(data)
        if(self.head==None):
            (self.head) = temp
            return
        else:
            temp2 = (self.head)
            i = 1 
            while(i<position and temp2.next != None and temp2.next != self.head):
                i+=1
                temp2 = temp2.next
            temp.next = temp2.next
            temp2.next.prev=temp
            temp2.next = temp
            temp.prev = temp2
            return

    def deleteAtBeginning(self):
        if(self.head == None):
            print("No Data")
        else:
            temp = (self.head).next
            temp.prev = (self.head).prev 
            (self.head).prev.next = temp
            (self.head) = temp
    
    def deleteAtEnd(self):
        if(self.head == None):
            print("No Data")
        
        else:
            temp = (self.head)
            while(temp.next != None and temp.next != (self.head)):
                temp = temp.next
            
            temp.next.prev=temp.prev
            temp.prev.next=temp.next

    
    def deleteAtPosition(self, position):
        if(self.head == None):
            print("No Data")
        
        else:
            temp = (self.head)
            i = 1
            while(i<position and temp.next != None and temp.next != (self.head)):
                i += 1
                temp = temp.next
            temp.next.prev=temp.prev
            temp.prev.next=temp.next

if __name__ == "__main__":
    DCLL = DoubleCircularLinkedList()
    DCLL.insertAtBeginning('D')
    DCLL.insertAtBeginning('C')
    DCLL.insertAtBeginning('B')
    DCLL.insertAtBeginning('A')
    DCLL.insertAtEnd('G')
    DCLL.insertAtPosition(4, 'E')
    DCLL.insertAtPosition(5, 'F')
    DCLL.traverse()
    DCLL.deleteAtBeginning()
    DCLL.deleteAtEnd()
    DCLL.traverse()
    DCLL.deleteAtPosition(3)
    DCLL.traverse()
