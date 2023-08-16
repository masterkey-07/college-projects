//Victor Jorge - 156740
//Leonardo Fonseca - 133680

abstract class Queue {
  protected implementer: ListImplementer;
  protected length: number;

  constructor(implementer: ListImplementer, length: number) {
    this.implementer = implementer;
    this.length = length;
  }

  abstract dequeue(): any;
  abstract enqueue(obj: any);
  abstract isEmpty(): boolean;
  abstract size(): number;
}

class FIFOQueue extends Queue {
  constructor(implementer: ListImplementer, length: number) {
    super(implementer, length);
  }

  dequeue(): any {
    this.length--;

    if (this.length < 0) return null;

    return this.implementer.remove(this.length) || new Object();
  }
  enqueue(obj: any) {
    this.implementer.add(obj);
  }
  isEmpty(): boolean {
    return this.length === 0;
  }
  size(): number {
    return this.length;
  }
}

interface ListImplementer {
  remove(index: number): any;
  add(obj: any);
}

class ArrayListQueue implements ListImplementer {
  private array: any[];
  constructor(list: any[]) {
    this.array = list;
  }
  remove(index: number): any {
    const output = this.array[index];

    this.array = this.array.slice(0, index).concat(this.array.slice(index + 1));

    return output;
  }
  add(obj: any) {
    this.array.push(obj);
  }
}

class VectorQueue implements ListImplementer {
  private vector: any[];
  constructor(list: any[]) {
    this.vector = list;
  }
  remove(): any {
    return this.vector.pop() || new Object();
  }
  add(obj: any) {
    this.vector.push(obj);
  }
  size(): number {
    return this.vector.length;
  }
}

const fifo = new FIFOQueue(new VectorQueue([1, 2, 3, 4, 5]), 5);

console.log(fifo.dequeue());
console.log(fifo.dequeue());
console.log(fifo.isEmpty());
console.log(fifo.size());
