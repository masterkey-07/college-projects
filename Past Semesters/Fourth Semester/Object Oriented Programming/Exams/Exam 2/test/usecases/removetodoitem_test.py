from test.usecases.inmemorytodolistrepository import InMemoryTodoListRepository
from test.usecases.inmemoryuserrepository import InMemoryUserRepository
from test.usecases.fakehashservice import FakeHashService
from src.usecases.removetodolist import RemoveTodoList
from src.usecases.createtodolist import CreateTodoList
from src.usecases.signup import SignUp
from src.usecases.errors.invalidusererror import InvalidUserError
from src.usecases.errors.invalidtodolisterror import InvalidTodoListError
import pytest


def test_remove_todolist():
    user_repo = InMemoryUserRepository()
    todolist_repo = InMemoryTodoListRepository()
    hash_service = FakeHashService()

    user_name = 'Joe Doe'
    user_email = 'joe@doe.com'
    user_password = 'test1234TEST&'

    signup = SignUp(user_repo, hash_service)

    signup.perform(user_name, user_email, user_password)

    usecase = CreateTodoList(user_repo, todolist_repo)

    usecase.perform(user_email)

    usecase = RemoveTodoList(user_repo, todolist_repo)

    usecase.perform(user_email)

    todo_list = todolist_repo.find_by_email(user_email)

    assert todo_list is None


def test_remove_todolist_from_invalid_user():
    user_repo = InMemoryUserRepository()
    todolist_repo = InMemoryTodoListRepository()

    user_email = 'joe@doe.com'

    usecase = RemoveTodoList(user_repo, todolist_repo)

    with pytest.raises(InvalidUserError):
        usecase.perform(user_email)


def test_remove_todolist_from_invalid_todolist():
    user_repo = InMemoryUserRepository()
    todolist_repo = InMemoryTodoListRepository()
    hash_service = FakeHashService()

    user_name = 'Joe Doe'
    user_email = 'joe@doe.com'
    user_password = 'test1234TEST&'

    signup = SignUp(user_repo, hash_service)

    signup.perform(user_name, user_email, user_password)

    usecase = RemoveTodoList(user_repo, todolist_repo)

    with pytest.raises(InvalidTodoListError):
        usecase.perform(user_email)
