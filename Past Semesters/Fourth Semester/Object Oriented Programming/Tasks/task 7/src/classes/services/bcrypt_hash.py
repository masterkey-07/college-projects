from bcrypt import hashpw, checkpw

from interfaces.hash_service import HashService


class BycrptService(HashService):
    def __init__(self, salt):
        self.salt = salt

    def __encode(self, string: str):
        return string.encode('utf-8')

    def encrypt(self, password: str):
        return hashpw(self.__encode(password), self.salt)

    def verify(self, password, hashed):
        return checkpw(self.__encode(password), hashed)
