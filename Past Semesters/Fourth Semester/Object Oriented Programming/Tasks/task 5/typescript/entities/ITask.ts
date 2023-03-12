import { IEntity } from "./IEntity";

export interface ITask extends IEntity {
  isDone(): boolean;
  hasExceeded(): boolean;
}
