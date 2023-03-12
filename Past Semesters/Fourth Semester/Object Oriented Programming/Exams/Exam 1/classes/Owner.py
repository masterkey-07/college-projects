from .Car import Car
from .User import User
from datetime import datetime, timedelta

class Ownership:
    def __init__(self, user: User, car: Car, start_date: str, end_date: str):
        self.user = user
        self.car = car
        self.start_date = datetime.fromisoformat(start_date)
        self.end_date = datetime.fromisoformat(end_date)

    def calculate_price(self):
        length = (self.end_date - self.start_date).days

        return 1.15 * (length * self.car.price)
