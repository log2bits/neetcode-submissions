class Node:
    def __init__(self, val, next=None):
        self.val = val
        self.next = next

class LinkedList:

    def __init__(self):
        self.head = None
        self.tail = None
        self.size = 0

    def get(self, index: int) -> int:
        if index < 0 or index >= self.size:
            return -1
        node = self.head
        for _ in range(index):
            node = node.next
        return node.val

    def insertHead(self, val: int) -> None:
        self.head = Node(val, self.head)
        if self.tail is None:
            self.tail = self.head
        self.size += 1

    def insertTail(self, val: int) -> None:
        node = Node(val)
        if self.tail is None:
            self.head = node
        else:
            self.tail.next = node
        self.tail = node
        self.size += 1

    def remove(self, index: int) -> bool:
        if index < 0 or index >= self.size:
            return False
        if index == 0:
            self.head = self.head.next
            if self.head is None:
                self.tail = None
        else:
            prev = self.head
            for _ in range(index - 1):
                prev = prev.next
            prev.next = prev.next.next
            if prev.next is None:
                self.tail = prev
        self.size -= 1
        return True

    def getValues(self) -> List[int]:
        values = []
        node = self.head
        while node:
            values.append(node.val)
            node = node.next
        return values