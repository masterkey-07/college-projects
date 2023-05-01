import { FacadeCoordenador } from "./main.ts";

const instanciaA = FacadeCoordenador.getCoordenador();
const instanciaB = FacadeCoordenador.getCoordenador();
const instanciaC = FacadeCoordenador.getCoordenador();

const verifyAB = instanciaA === instanciaB;
const verifyAC = instanciaA === instanciaC;
const verifyBC = instanciaB === instanciaC;

console.log(verifyAB);
console.log(verifyAC);
console.log(verifyBC);
