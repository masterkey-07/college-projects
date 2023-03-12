import { Batch } from "./batch";
import { OrderLine } from "./order-line";
import { OutOfStockError } from "./out-of-stock-error";

export function allocate(
  line: OrderLine,
  batches: Batch[]
): string | undefined {
  const allocatableBatches = batches.filter((batch) => batch.canAllocate(line));

  if (allocatableBatches.length === 0) throw new OutOfStockError();

  const selectedBatch = getPreferableBatch(allocatableBatches);

  selectedBatch?.allocate(line);

  return selectedBatch?.reference;
}

function getPreferableBatch(batches: Batch[]): Batch | undefined {
  let selectedBatch = batches.pop();

  for (const batch of batches) {
    if (!batch.eta) {
      selectedBatch = batch;
      break;
    }

    selectedBatch = batch.eta < selectedBatch.eta ? batch : selectedBatch;
  }

  return selectedBatch;
}
