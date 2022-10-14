import { ITask } from "./ITask";

interface IProject extends ITask {
  tasks: ITask[];
}
