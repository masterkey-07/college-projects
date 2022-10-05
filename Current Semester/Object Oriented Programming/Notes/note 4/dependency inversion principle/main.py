import abc
from abc import ABC, abstractmethod


class Bakable(ABC):
    @abstractmethod
    def bake(self):
        pass


class Bread(Bakable):
    def bake(self):
        print("Smells like bread")


class Cookie(Bakable):
    def bake(self):
        print("Smells like cookie")


def cook(food: Bakable):
    food.bake()


cook(Bread())
cook(Cookie())


def test(number: str):
    print(number)


test(10)
