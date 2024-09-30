const path = require("path");
const fs = require("node:fs");
const solc = require("solc");

const loterialFile = "loteria.sol";

const loteriaPath = path.join(__dirname, loterialFile);

const source = fs.readFileSync(loteriaPath, "utf-8");

const input = {
  language: "Solidity",
  sources: {
    [loterialFile]: { content: source },
  },
  settings: {
    outputSelection: {
      "*": {
        "*": ["*"],
      },
    },
  },
};

let contratoCompilado = JSON.parse(solc.compile(JSON.stringify(input)));

module.exports = contratoCompilado.contracts[loterialFile].Loteria;
