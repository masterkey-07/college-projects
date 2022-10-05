import { Point } from "../src/point";
import { Square } from "../src/square";

const createSquare = (length) => {
  const pointA = new Point(0, length);
  const pointB = new Point(length, length);
  const pointC = new Point(0, 0);
  const pointD = new Point(length, 0);

  return new Square(pointA, pointB, pointC, pointD);
};

describe("Square", () => {
  it("should create a square at the origin", () => {
    const square = createSquare(2);
  });

  it("should calculate the area of the square", () => {
    const square = createSquare(2);

    expect(square.area()).toEqual(4);
  });
});
