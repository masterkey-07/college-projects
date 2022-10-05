class Stack:
    def __init__(self):
        self.__array = []

    def push(self, item: int):
        self.__array.append(item)

    def pop(self):
        return self.__array.pop()
