from src.usecases.errors.invalidusererror import InvalidUserError


class RemoveItem:

    def __init__(self, todolist_repo):
        self.__repo = todolist_repo

    def perform(self, user_email, item_description):
        todolist = self.__repo.find_by_email(user_email)

        if not todolist:
            raise InvalidUserError()

        item = todolist.find(item_description)

        if item:
            todolist.remove_by_description(item_description)

        self.__repo.update(user_email, todolist)
