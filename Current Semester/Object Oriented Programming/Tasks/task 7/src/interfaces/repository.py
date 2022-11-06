from abc import ABC, abstractmethod


class UserRepository(ABC):

    @abstractmethod
    def add(self, user):
        raise (NotImplementedError)

    @abstractmethod
    def find_by_email(self, email):
        raise (NotImplementedError)
