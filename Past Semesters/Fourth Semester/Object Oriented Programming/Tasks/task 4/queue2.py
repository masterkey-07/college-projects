class Queue2:
    def __init__(self):
        self.__array = []

    def enqueue(self, item: int):
        self.__array.append(item)

    def dequeue(self):
        output = self.__array[0]
        self.__array.remove(output)
        return output
