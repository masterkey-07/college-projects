from interfaces.hash_service import HashService


class FakeHash(HashService):
    def encrypt(self, password: str):
        return password[::-1]

    def verify(self, password, hashed):
        return self.encrypt(password) == hashed
