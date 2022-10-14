import { IEntity } from "./IEntity";
import { ITask } from "./ITask";

export interface IList extends IEntity {
  tasks: ITask[];
}
