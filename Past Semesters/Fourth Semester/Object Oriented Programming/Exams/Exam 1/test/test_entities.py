from classes import User
from classes import Car
from classes import Ownership


def test_create_user():
    user = User('Victor', 'email', 'abc')
    assert user != None


def test_create_car():
    car = Car('a', 'b', 2000, 10)
    assert car != None


def test_ownership():
    user = User('Victor', 'email', 'abc')
    car = Car('a', 'b', 2000, 10)
    ownership = Ownership(user, car, '2020-10-05', '2020-10-25')

    assert ownership != None
    assert ownership.user == user
    assert ownership.car == car
    assert ownership.calculate_price() == (10.0 * 20.0) * 1.15
