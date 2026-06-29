from typing import List

class Node:
    def __init__(self, val, next=None):
        self.val = val
        self.next = next

class LinkedList:

    def __init__(self):
        self.head = None

    def get(self, index: int) -> int:
        node = self.head
        for _ in range(index):
            if node is None:
                return -1
            node = node.next
        return node.val if node else -1

    def insertHead(self, val: int) -> None:
        self.head = Node(val, self.head)

    def insertTail(self, val: int) -> None:
        if self.head is None:
            self.head = Node(val)
            return
        node = self.head
        while node.next:
            node = node.next
        node.next = Node(val)

    def remove(self, index: int) -> bool:
        if self.head is None:
            return False
        if index == 0:
            self.head = self.head.next
            return True
        prev = self.head
        for _ in range(index - 1):
            if prev.next is None:
                return False
            prev = prev.next
        if prev.next is None:
            return False
        prev.next = prev.next.next
        return True

    def getValues(self) -> List[int]:
        values = []
        node = self.head
        while node:
            values.append(node.val)
            node = node.next
        return values