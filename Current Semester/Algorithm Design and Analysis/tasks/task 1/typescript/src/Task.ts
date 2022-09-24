import { dataset, Test } from "./types";

class Region {
  private x: number;
  private y: number;
  private weight: number;
  private relations: Array<Region>;

  constructor(params: dataset) {
    const [x, y, w] = params;

    this.x = x;
    this.y = y;
    this.weight = w;
    this.relations = [];
  }

  public relate(region: Region, size: number): void {
    const x = Math.abs(this.x - region.x);
    const y = Math.abs(this.y - region.y);

    size *= 2;

    const relatable = x > y ? x <= size : y <= size;

    if (relatable) this.relations.push(region);
  }

  public resolve(): dataset {
    return [0, 0, 0];
  }
}

export class Task {
  private readonly test: Test;

  constructor(test: Test) {
    this.test = test;
  }

  public resolve(): dataset {
    const { size, entries } = this.test;

    const regions = entries.map((entry) => new Region(entry));

    regions.forEach((regionA) =>
      regions.forEach(
        (regionB) => regionA !== regionB && regionA.relate(regionB, size)
      )
    );

    return [0, 0, 0];
  }
}
