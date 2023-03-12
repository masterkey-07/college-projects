import queue
from stack import Stack
from queue2 import Queue2


def test_stack():
    stack = Stack()
    stack.push(1)
    stack.push(2)
    stack.push(3)
    p = stack.pop()
    assert p == 3


def test_queue():
    queue = Queue2()
    queue.enqueue(1)
    queue.enqueue(2)
    queue.enqueue(3)
    p = queue.dequeue()
    assert p == 1


test_queue()
test_stack()
