from entities.user import User
from errors.duplicateusererror import DuplicateUserError
from errors.invalidpassworderror import InvalidPasswordError


class SignUp:
    def __init__(self, userrepo, hash_service):
        self.userrepo = userrepo
        self.hash_service = hash_service

    def perform(self, user_name, user_email, user_password):
        if invalid(user_password):
            raise InvalidPasswordError()
        if self.userrepo.find_by_email(user_email) != None:
            raise DuplicateUserError()
        hashed_password = self.hash_service.hash(user_password)
        user = User(user_name, user_email, hashed_password)
        self.userrepo.add(user)


def invalid(user_password):
    length = len(user_password)
    if length < 6 or length > 15:
        return True
    lower_letters = [c for c in user_password if c.islower()]
    upper_letters = [c for c in user_password if c.isupper()]
    numbers = [c for c in user_password if c.isnumeric()]
    special_characters = [c for c in user_password if not c.isalnum()]
    if not lower_letters or not upper_letters or not numbers or not special_characters:
        return True
    return False
