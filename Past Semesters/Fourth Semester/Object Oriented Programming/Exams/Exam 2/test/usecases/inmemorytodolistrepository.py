from src.usecases.ports.todolistrepository import TodoListRepository
import copy


class InMemoryTodoListRepository(TodoListRepository):
    def __init__(self):
        self.todolists = []

    def add(self, todolist):
        self.todolists.append(todolist)

    def find_by_email(self, email):
        for todolist in self.todolists:
            if todolist.owner.email == email:
                return copy.deepcopy(todolist)

    def update(self, user_email, newtodolist):
        for index in range(len(self.todolists)):
            if self.todolists[index].owner.email == user_email:
                self.todolists[index] = newtodolist

    def remove(self, to_remove):
        for index in range(len(self.todolists)):
            if self.todolists[index].owner.email == to_remove.owner.email:
                self.todolists.pop(index)
