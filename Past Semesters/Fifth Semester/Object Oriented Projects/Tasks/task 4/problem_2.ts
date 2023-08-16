class Shape {
  protected x: number;
  protected y: number;
  protected height: number;
  protected width: number;

  constructor(x: number, y: number, height: number, width: number) {
    this.x = x;
    this.y = y;
    this.height = height;
    this.width = width;
  }

  public getX(): number {
    return this.x;
  }

  public getY(): number {
    return this.y;
  }
  public getHeight(): number {
    return this.height;
  }
  public getWidth(): number {
    return this.width;
  }
}

class Coords {
  public x: number;
  public y: number;

  constructor(x: number, y: number) {
    this.x = x;
    this.y = y;
  }
}

class RasterBox {
  private topLeft: Coords;
  private bottomRight: Coords;

  constructor(x1: number, y1: number, x2: number, y2: number) {
    this.topLeft = new Coords(x1, y1);
    this.bottomRight = new Coords(x2, y2);
  }

  public getTopLeft(): Coords {
    return this.topLeft;
  }

  public getBottomRight(): Coords {
    return this.bottomRight;
  }
}

class VectorDraw {
  draw(shape: Shape) {
    console.log(
      `draw shape at (${shape.getX()},${shape.getY()}) by (${shape.getWidth()},${shape.getHeight()})`
    );
  }
}

class RasterBoxAdapter extends Shape {
  constructor(box: RasterBox) {
    const topLeft = box.getTopLeft();
    const bottomRight = box.getBottomRight();

    const x = topLeft.x;
    const y = topLeft.y;
    const width = Math.abs(topLeft.x - bottomRight.x);
    const height = Math.abs(topLeft.y - bottomRight.y);

    super(x, y, height, width);
  }
}

const box = new RasterBox(0, 0, 30, 40);
const shape = new Shape(3, 3, 10, 5);

const drawer = new VectorDraw();

drawer.draw(shape);
drawer.draw(new RasterBoxAdapter(box));
