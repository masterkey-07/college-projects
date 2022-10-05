import { ISolution } from "./ITask";
import { dataset, point, Test } from "./types";

class Region {
  private position: point;
  private weight: number;
  private relations: Array<Region>;

  constructor(params: dataset) {
    const [x, y, w] = params;

    this.position = { x, y };
    this.weight = w;
    this.relations = [];
  }

  public relate(region: Region, size: number): void {
    const x = Math.abs(this.position.x - region.position.x);
    const y = Math.abs(this.position.y - region.position.y);

    size *= 2;

    const relatable = x > y ? x <= size : y <= size;

    if (relatable) {
      this.relations.push(region);
      region.relations.push(this);
    }
  }

  private max(a: number, b: number): number {
    return a > b ? a : b;
  }

  private setSize(value: number, size: number) {
    return value - size > 0 ? value - size : 0;
  }

  private findPosition(pointA: point, pointB: point, size: number): point {
    const x = this.setSize(this.max(pointA.x, pointB.x), size);
    const y = this.setSize(this.max(pointA.y, pointB.y), size);

    return { x, y };
  }

  public resolve(size: number): dataset {
    let output = this.findPosition(this.position, { x: 0, y: 0 }, size);
    let weight = this.weight;

    this.relations.forEach((selectedRelation) => {
      let sum = this.weight + selectedRelation.weight;

      let position = this.findPosition(
        this.position,
        selectedRelation.position,
        size
      );

      this.relations.forEach((relation) => {
        if (selectedRelation !== relation) {
          if (relation.relations.find((r) => r === selectedRelation)) {
            sum += relation.weight;
            position = this.findPosition(position, relation.position, size);
          }
        }
      });

      if (weight < sum) {
        output = position;
        weight = sum;
      }
    });

    return [output.x, output.y, weight];
  }
}

export class SolutionA implements ISolution {
  private readonly size: number;
  private readonly regions: Array<Region>;

  constructor(test: Test) {
    this.size = test.size;

    this.regions = new Array<Region>();

    test.entries.forEach((entry) => {
      const newRegion = new Region(entry);

      this.regions.forEach((region) => region.relate(newRegion, this.size));

      this.regions.push(newRegion);
    });
  }

  private compare(datasetA: dataset, datasetB: dataset) {
    const [xA, yA, weightA] = datasetA;
    const [xB, yB, weightB] = datasetA;

    if (weightA === weightB) return xA + yA < xB + yB ? datasetA : datasetB;

    return weightA < weightB ? datasetB : datasetA;
  }

  public resolve(): dataset {
    let output: dataset = [0, 0, 0];

    this.regions.forEach(
      (region) => (output = this.compare(output, region.resolve(this.size)))
    );

    return output;
  }
}
