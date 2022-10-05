export type point = { x: number; y: number };

export type dataset = [number, number, number];

export type Test = {
  size: number;
  entries: Array<dataset>;
};

export type adjacencyMatrix = Array<Array<boolean>>;
