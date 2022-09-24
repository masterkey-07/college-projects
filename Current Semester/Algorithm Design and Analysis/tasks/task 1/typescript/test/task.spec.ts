import { Task } from "../src/Task";
import { Test } from "../src/types";

describe("Task 1", () => {
  it("test first input", () => {
    const test: Test = {
      size: 10,
      entries: [
        [40, 40, 10],
        [60, 60, 20],
      ],
    };

    const task = new Task(test);

    expect(task.resolve()).toEqual([50, 50, 30]);
  });

  it("test second input", () => {
    const test: Test = {
      size: 2,
      entries: [
        [2, 2, 10],
        [6, 6, 20],
        [1000, 500, 31],
        [300, 1000, 31],
      ],
    };

    const task = new Task(test);

    expect(task.resolve()).toEqual([298, 998, 31]);
  });
});
