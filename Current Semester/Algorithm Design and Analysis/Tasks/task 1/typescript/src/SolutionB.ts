import { ISolution } from "./ITask";
import { adjacencyMatrix, dataset, point, Test } from "./types";

export class SolutionB implements ISolution {
  private readonly test: Test;

  constructor(test: Test) {
    this.test = test;
  }

  private relate(a: dataset, b: dataset): boolean {
    if (a === b) return false;

    const x = Math.abs(a[0] - b[0]);
    const y = Math.abs(a[1] - b[1]);

    return x > y ? x <= this.test.size * 2 : y <= this.test.size * 2;
  }

  private find(a: number, b: number): number {
    const value = a > b ? a : b;

    return value - this.test.size > 0 ? value - this.test.size : 0;
  }

  private solution(index: number, matrix: adjacencyMatrix): dataset {
    const row = matrix[index];

    const regions = this.test.entries;

    let x: number = 0;
    let y: number = 0;
    let w: number = 0;
    for (let j = 0; j < row.length; j++) {
      let sum: number = 0;
      let a: number = 0;
      let b: number = 0;

      if (row[j]) {
        a = this.find(regions[index][0], regions[j][0]);
        b = this.find(regions[index][1], regions[j][1]);
        sum = regions[index][2] + regions[j][2];

        for (let k = 0; k < row.length; k++)
          if (matrix[k][j] && matrix[k][index]) {
            sum += regions[k][2];
            console.log(a, b, sum);

            a = this.find(a, regions[k][0]);
            b = this.find(b, regions[k][1]);
          }
      }

      if (sum > w) {
        w = sum;
        x = a;
        y = b;
      }
    }

    console.log(x, y, w);

    return [x, y, w];
  }

  private compare(datasetA: dataset, datasetB: dataset) {
    const [xA, yA, weightA] = datasetA;
    const [xB, yB, weightB] = datasetA;

    if (weightA === weightB) return xA + yA < xB + yB ? datasetA : datasetB;

    return weightA < weightB ? datasetB : datasetA;
  }

  public resolve(): dataset {
    const matrix: adjacencyMatrix = [];

    const regions = this.test.entries;

    regions.forEach((regionA, i) => {
      matrix.push([]);
      regions.forEach((regionB, j) =>
        matrix[i].push(this.relate(regionA, regionB))
      );
    });

    let output: dataset = [0, 0, 0];

    for (let i = 0; i < matrix.length; i++) {
      output = this.compare(output, this.solution(i, matrix));
    }

    return [0, 0, 0];
  }
}
