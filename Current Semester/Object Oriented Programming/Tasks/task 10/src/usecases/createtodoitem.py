from src.entities.todoitem import TodoItem
from src.usecases.errors.invalidusererror import InvalidUserError
from src.usecases.errors.invalidtodolisterror import InvalidTodoListError
from src.entities.errors.duplicateitemerror import DuplicateItemError


class CreateTodoItem:
    def __init__(self, user_repo, todolist_repo):
        self.user_repo = user_repo
        self.todolist_repo = todolist_repo

    def perform(self, user_email, item_description, item_priority):
        owner = self.user_repo.find_by_email(user_email)

         
        if not owner:
            raise InvalidUserError

        todolist = self.todolist_repo.find_by_email(user_email)

         
        if not todolist:
            raise InvalidTodoListError

         
        found = todolist.find(item_description)

         
        if found:
            raise DuplicateItemError

        todoitem = TodoItem(item_description, item_priority)

        todolist.add(todoitem)

        self.todolist_repo.update(user_email, todolist)
