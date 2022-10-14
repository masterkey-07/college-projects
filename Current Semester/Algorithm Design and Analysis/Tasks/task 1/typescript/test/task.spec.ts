import { SolutionA } from "../src/SolutionA";
import { SolutionB } from "../src/SolutionB";
import { dataset, Test } from "../src/types";

const firtTest: Test = {
  size: 10,
  entries: [
    [40, 40, 10],
    [60, 60, 20],
  ],
};

const firstResult: dataset = [50, 50, 30];

const secondTest: Test = {
  size: 2,
  entries: [
    [2, 2, 10],
    [6, 6, 20],
    [1000, 500, 31],
    [300, 1000, 31],
  ],
};

const secondResult: dataset = [298, 998, 31];

describe("Solution A", () => {
  it("test first input", () => {
    expect(new SolutionA(firtTest).resolve()).toEqual(firstResult);
  });

  it("test second input", () => {
    expect(new SolutionA(secondTest).resolve()).toEqual(secondResult);
  });
});

describe("Solution B", () => {
  it("test first input", () => {
    expect(new SolutionB(firtTest).resolve()).toEqual(firstResult);
  });

  it("test second input", () => {
    expect(new SolutionB(secondTest).resolve()).toEqual(secondResult);
  });
});
