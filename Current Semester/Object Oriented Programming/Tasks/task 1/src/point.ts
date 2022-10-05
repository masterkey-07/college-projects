export class Point {
  private x: number;
  private y: number;

  constructor(x: number, y: number) {
    this.x = x;
    this.y = y;
  }

  private;

  public distance(point: Point): number {
    const diffX = Math.pow(this.x - point.x, 2);
    const diffY = Math.pow(this.y - point.y, 2);

    return Math.sqrt(diffX + diffY);
  }
}
