from abc import ABC, abstractmethod


class HashService(ABC):

    @abstractmethod
    def encrypt(self, password):
        raise (NotImplementedError)

    @abstractmethod
    def verify(self, password, hashed):
        raise (NotImplementedError)
