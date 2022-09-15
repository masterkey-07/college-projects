import Bike from "./Bike";

class Rent {
  bike: Bike;
  from: Date;
  to: Date;

  constructor(bike: Bike, from: Date, to: Date) {
    this.bike = bike;
    this.from = from;
    this.to = to;
  }

  private dateToString(date: Date): string {
    return `${date.getDate()}/${date.getMonth() + 1}/${date.getFullYear()}`;
  }

  public displayPeriod(): void {
    console.log(
      `${this.dateToString(this.from)} to ${this.dateToString(this.to)}`
    );
  }
}

export default Rent;
