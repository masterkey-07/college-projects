import { ISolution } from "./ITask";
import { adjacencyMatrix, dataset, point, Test } from "./types";

export class SolutionB implements ISolution {
  private readonly test: Test;

  constructor(test: Test) {
    this.test = test;
  }

  private max = (a: number, b: number): number => (a > b ? a : b);

  private divide(regions: dataset[], start: number, end: number) {
    const middle = (end + start) / 2;
  }

  public resolve(): dataset {
    const regions = this.test.entries.sort(
      (a, b) => this.max(a[0], a[1]) - this.max(b[0], b[1])
    );

    console.log(regions);

    return [0, 0, 0];
  }
}
