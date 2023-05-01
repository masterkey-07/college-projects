//Victor Jorge - 156740
//Leonardo Fonseca - 133680

abstract class Queue {
  protected implementer: ArrayImplementer;

  abstract dequeue(): any;
  abstract enqueue(obj: any);
  abstract isEmpty(): boolean;
  abstract size(): number;
}

class FIFOQueue extends Queue {
  constructor(implementer: ArrayImplementer) {
    super();

    this.implementer = implementer;
  }

  dequeue(): any {
    return this.implementer.remove() || new Object();
  }
  enqueue(obj: any) {
    this.implementer.insert(obj);
  }
  isEmpty(): boolean {
    return this.implementer.size() === 0;
  }
  size(): number {
    return this.implementer.size();
  }
}

interface ArrayImplementer {
  remove(): any;
  insert(obj: any);
  size(): number;
}

class ArrayListQueue implements ArrayImplementer {
  private array: any[];
  constructor(list: any[]) {
    this.array = list;
  }
  remove(): any {
    return this.array.pop() || new Object();
  }
  insert(obj: any) {
    this.array.push(obj);
  }
  size(): number {
    return this.array.length;
  }
}

class VectorQueue implements ArrayImplementer {
  private vector: any[];
  constructor(list: any[]) {
    this.vector = list;
  }
  remove(): any {
    return this.vector.pop() || new Object();
  }
  insert(obj: any) {
    this.vector.push(obj);
  }
  size(): number {
    return this.vector.length;
  }
}

const fifo = new FIFOQueue(new VectorQueue([1, 2, 3, 4, 5]));

console.log(fifo.dequeue());
console.log(fifo.dequeue());
console.log(fifo.isEmpty());
console.log(fifo.size());
