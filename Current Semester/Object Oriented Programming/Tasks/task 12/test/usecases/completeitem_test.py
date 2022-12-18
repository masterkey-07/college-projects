from src.entities .priority import Priority
from src.usecases.createtodoitem import CreateTodoItem
from src.usecases.createtodolist import CreateTodoList
from src.usecases.signup import SignUp
from src.usecases.completeitem import CompleteItem
from test.usecases.inmemorytodolistrepository import InMemoryTodoListRepository
from test.usecases.inmemoryuserrepository import InMemoryUserRepository
from test.usecases.fakehashservice import FakeHashService


def test_complete_item():
    user_repo = InMemoryUserRepository()
    todolist_repo = InMemoryTodoListRepository()
    hash_service = FakeHashService()
    user_name = 'Joe Doe'
    user_email = 'joe@doe.com'
    user_password = 'test1234TEST&'

    SignUp(user_repo, hash_service).perform(
        user_name, user_email, user_password)

    CreateTodoList(user_repo, todolist_repo).perform(user_email)

    usecase = CreateTodoItem(todolist_repo)

    item_description = 'call mom'

    second_item_description = item_description + ' 2'

    item_priority = Priority.HIGH

    usecase.perform(user_email, item_description, item_priority)

    usecase.perform(user_email, second_item_description, item_priority)

    usecase = CompleteItem(todolist_repo)

    usecase.perform(user_email, second_item_description)

    todo_list = todolist_repo.find_by_email(user_email)

    first_item = todo_list.get(0)

    second_item = todo_list.get(1)

    assert first_item.description == item_description

    assert first_item.completed == False

    assert second_item.description == second_item_description

    assert second_item.completed == True
