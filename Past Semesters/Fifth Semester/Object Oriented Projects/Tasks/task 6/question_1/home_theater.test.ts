//Victor Jorge - 156740
//Leonardo Fonseca - 133680

import { HomeTheaterFacade } from "./question_1";

const controller = HomeTheaterFacade.getControler();

controller.iniciaSessao();

controller.pausa();

controller.despausa();

controller.muta();

controller.desmuta();

controller.desliga();
