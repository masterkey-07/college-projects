import { Point } from "../src/point";

describe("Point", () => {
  it("should create a point at the origin", () => {
    const p1: Point = new Point(0, 0);
  });

  it("should calculate distance between two points", () => {
    const pointA = new Point(0, 0);
    const pointB = new Point(2, 0);

    const distance = pointA.distance(pointB);

    expect(distance).toEqual(2);
  });
});
