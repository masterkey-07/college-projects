from classes.User import User
from classes.Car import Car
from classes.Owner import Ownership


class System:

    def __init__(self):
        self.users = []
        self.cars = []
        self.ownerships = []

    def add_user(self, user: User):
        self.users.append(user)
        return len(self.users) - 1

    def add_car(self, car: Car):
        self.cars.append(car)
        return len(self.cars) - 1

    def give_ownership(self, user_index, car_index, start_date, end_date):
        user = self.users[user_index]
        car = self.cars[car_index]

        for ownership in self.ownerships:
            if (ownership.car == car):
                return False

        new_owership = Ownership(user, car, start_date, end_date)

        self.ownerships.append(new_owership)

        return True

    def remove_ownership(self, car_index):
        car = self.cars[car_index]

        to_remove = None

        for ownership in self.ownerships:
            if (ownership.car == car):
                to_remove = ownership

        if (to_remove != None):
            self.ownerships.remove(to_remove)
            return True
        else:
            return False

    def calculate_user_debt(self, user_index):
        sum = 0.0

        user = self.users[user_index]
    
        for ownership in self.ownerships:
            if (ownership.user == user):
                sum += ownership.calculate_price()

        return sum
