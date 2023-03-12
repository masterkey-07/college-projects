from classes.services.bcrypt_hash import BycrptService
from classes.repositories.inmemoryuserrepository import InMemoryUserRepository
from classes.cases. signup import SignUp
from err.duplicateusererror import DuplicateUserError
import pytest
from bcrypt import gensalt


def create_hash():
    return BycrptService(gensalt())


def test_signup_with_valid_data():
    user_repo = InMemoryUserRepository()
    user_name = 'Joe Doe'
    user_email = 'joe@doe.com'
    user_password = 'test1234TEST&'
    usecase = SignUp(user_repo, create_hash())
    usecase.perform(user_name, user_email, user_password)
    assert user_repo.find_by_email(user_email).name == user_name


def test_prevent_duplicate_user():
    user_repo = InMemoryUserRepository()
    user_name = 'Joe Doe'
    user_email = 'joe@doe.com'
    user_password = 'test1234TEST&'
    usecase = SignUp(user_repo, create_hash())
    usecase.perform(user_name, user_email, user_password)
    dup_user_name = 'Doe Joe'
    dup_user_email = 'joe@doe.com'
    dup_user_password = 'TEST1234test&'
    with pytest.raises(DuplicateUserError):
        usecase.perform(dup_user_name, dup_user_email, dup_user_password)
