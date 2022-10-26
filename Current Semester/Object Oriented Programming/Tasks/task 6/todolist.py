from user import User
from todoitem import TodoItem


class TodoList:
    def __init__(self, owner: User):
        self.owner = owner
        self.list = []

    def add(self, item: TodoItem):
        self.list.append(item)
        self.list.sort(reverse=True, key=lambda item: item.priority.value)

    def get(self, index):
        return self.list[index]

    def get_owner(self):
        return self.owner

    def complete_item(self, index):
        self.list[index].complete()

    def remove(self, index):
        self.list.pop(index)

    def size(self):
        return len(self.list)

    def find(self, description):
        for item in self.list:
            if item.description == description:
                return item
