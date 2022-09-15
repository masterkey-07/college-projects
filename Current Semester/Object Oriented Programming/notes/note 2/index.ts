import Bike from "./classes/Bike";
import User from "./classes/User";

const user = new User("Ana", "panalara@gmail.com", 21);

const bike = new Bike("a", "b", "c", 2000);

const from: Date = new Date();

const day: number = 1000 * 60 * 60 * 24;

const to: Date = new Date(from.getTime() + 15 * day);

user.setRent(bike, from, to);

user.rent?.displayPeriod();
