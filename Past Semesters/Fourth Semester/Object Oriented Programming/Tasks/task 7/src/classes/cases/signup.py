from ..entities.user import User
from err.duplicateusererror import DuplicateUserError


class SignUp:
    def __init__(self, user_repo, hash_service):
        self.user_repo = user_repo
        self.hash_service = hash_service

    def perform(self, user_name, user_email, user_password):
        if self.user_repo.find_by_email(user_email) != None:
            raise DuplicateUserError()

        hashed_password = self.hash_service.encrypt(user_password)

        user = User(user_name, user_email, hashed_password)

        self.user_repo.add(user)
