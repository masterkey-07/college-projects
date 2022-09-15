import Bike from "./Bike";
import Rent from "./Rent";

class User {
  name: string;
  email: string;
  age: number;
  rent?: Rent;

  constructor(name: string, email: string, age: number) {
    this.name = name;
    this.email = email;
    this.age = age;
  }

  public setRent(bike: Bike, from: Date, to: Date): void {
    this.rent = new Rent(bike, from, to);
  }
}

export default User;
