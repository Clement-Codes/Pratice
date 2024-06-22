
class Node:
    def __init__(self, data):
        self.data = data
        self.next = None
    

class CircularLinkedList:
    def __init__(self):
        self.tail =  None


    def traverse(self):
        if self.tail:
            print("tail= ", self.tail.data)
            print("traverse= ", end='')
            head =  self.tail.next
            if(self.tail.next != None):
                while True:
                    print(head.data, " ", end='')
                    head = head.next
                    if head == self.tail.next:
                        break
            else:
                print(self.tail.data)
        
    

    def insertAtBegining(self, data):
        temp =  Node(data)
        if(self.tail!=None):
            if((self.tail).next!=None):
                temp.next = (self.tail).next
            else:
                temp.next = self.tail
            (self.tail).next = temp
        else:
            self.tail = temp
        

    def insertAtEnd(self, data):
        temp = Node(data)
        if(self.tail != None):
            temp.next = (self.tail).next
            (self.tail).next = temp
            self.tail = temp
        else:
            self.tail = temp
    

    def insertAtPosition(self, position, data):
        temp = Node(data)
        if(self.tail != None):
            positionPointer = self.tail.next
            i = 1
            while(i<position and positionPointer != None and positionPointer.next!=None):
                positionPointer = positionPointer.next
                i = i+1
            temp.next = positionPointer.next
            positionPointer.next = temp
            if(positionPointer == self.tail):
                self.tail = temp
        else:
            self.tail = temp
        
    

    def deleteAtBeginning(self):
        if((self.tail) == None):
            print("No Node")
            return

        if((self.tail).next == None):
            self.tail = None
            return

        if((self.tail).next.next == None):
            (self.tail).next = None
            return
        
        (self.tail).next = (self.tail).next.next
        return
    

    def deleteAtEnd(self):
        temp = self.tail
        while(temp!=None and temp.next!=None and temp.next!=self.tail):
            temp = temp.next
        
        if(temp==None or temp.next==None):
            self.tail = None
            return
        
        temp.next = (self.tail).next
        self.tail = temp 
    

    def deleteAtPosition(self, position):
        temp = (self.tail).next

        i = 1
        while(i<position and temp!=None and temp.next!=None and temp.next!=self.tail):    
            temp = temp.next
            i=i+1
        
        if(temp==None or temp.next==None):
            self.tail = None
            return
        
        if(temp.next == self.tail):
            temp.next = temp.next.next
            (self.tail) = temp
            return
        
        temp.next = temp.next.next
        
    

if __name__ == "__main__":
    cll = CircularLinkedList()
    cll.traverse()
    cll.insertAtBegining('D')
    cll.insertAtBegining('C')
    cll.insertAtBegining('B')
    cll.insertAtBegining('A')
    cll.traverse()
    cll.insertAtEnd('F')
    cll.insertAtPosition(4, 'E')
    cll.insertAtPosition(6, 'G')
    cll.traverse()
    cll.deleteAtBeginning()
    cll.deleteAtEnd()
    # cll.traverse()
    cll.deleteAtPosition(3)
    cll.traverse()

