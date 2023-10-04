const net = require("net");
const readline = require("readline");

const SERVER_ADDRESS = "localhost";
const SERVER_PORT = 5000;

const sockets = new net.Socket();

const readlinePrompt = readline.createInterface({
  input: process.stdin,
  output: process.stdout,
});

readlinePrompt.question("Coloca o nome do seu usuário: ", (answer) => {
  const username = answer;

  sockets.connect(SERVER_PORT, SERVER_ADDRESS, () => {
    console.log("conectado ao chat como " + username);

    sockets.write(`O usuário \"${username}\" entrou no chat\n`);

    readlinePrompt.prompt();
  });

  sockets.on("data", (data) => {
    console.log(data.toString());
    readlinePrompt.prompt();
  });

  readlinePrompt.on("line", (input) => {
    if (input.includes("quit") && input.length === "quit".length) {
      sockets.write(`O usuário \"${username}\" saiu do chat\n`);

      return sockets.destroy();
    }

    sockets.write(`(${username}) ${input}\n`);

    readlinePrompt.prompt();
  });

  sockets.on("close", () => {
    readlinePrompt.close();
    console.log("desconectado do chat");
  });

  sockets.on("error", (err) => {
    console.error("Error:", err.message);
    readlinePrompt.close();
  });
});
