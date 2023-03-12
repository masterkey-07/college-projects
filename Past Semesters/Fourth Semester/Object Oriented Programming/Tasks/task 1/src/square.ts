import { Point } from "./point";

export class Square {
  private pointTopLeft: Point;
  private pointTopRight: Point;
  private pointBottomLeft: Point;
  private pointBottomRight: Point;

  constructor(
    pointTopLeft: Point,
    pointTopRight: Point,
    pointBottomLeft: Point,
    pointBottomRight: Point
  ) {
    this.pointTopLeft = pointTopLeft;
    this.pointTopRight = pointTopRight;
    this.pointBottomLeft = pointBottomLeft;
    this.pointBottomRight = pointBottomRight;
  }

  public area(): number {
    return Math.pow(this.pointTopLeft.distance(this.pointTopRight), 2);
  }
}
