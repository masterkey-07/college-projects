from src.entities.todolist import TodoList
from src.usecases.errors.invalidusererror import InvalidUserError
from src.usecases.errors.invalidtodolisterror import InvalidTodoListError


class RemoveTodoList:
    def __init__(self, user_repo, todolist_repo):
        self.user_repo = user_repo
        self.todolist_repo = todolist_repo

    def perform(self, user_email):
        owner = self.user_repo.find_by_email(user_email)

        if not owner:
            raise InvalidUserError

        todo_list = self.todolist_repo.find_by_email(user_email)

        if not todo_list:
            raise InvalidTodoListError

        self.todolist_repo.remove(todo_list)
