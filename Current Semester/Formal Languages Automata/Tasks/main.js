const rules = {
  A: ["A", "B"],
  B: ["A", "C"],
  C: ["C", "C"],
};

const startState = "A";
const finalState = "C";

let presentState = "";

const evaluateRule = (state, input) => {
  console.log("anterior", state);
  console.log("resultado", rules[state][input]);
  return rules[state][input];
};

const processInput = (startState, finalState, inputs = []) => {
  const state = inputs.reduce(evaluateRule, startState);

  return state === finalState;
};

console.log(processInput(startState, finalState, process.argv[2].split("")));
