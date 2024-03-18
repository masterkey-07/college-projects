require("dotenv").config();

const HDWalletProvider = require("@truffle/hdwallet-provider");

const Web3 = require("web3");

const { abi, evm } = require("./compile");

const provider = new HDWalletProvider({
  mnemonic: { phrase: process.env.mnemonic },
  providerOrUrl: process.env.provider,
});

const web3 = new Web3(provider);

const deploy = async () => {
  const accounts = await web3.eth.getAccounts();

  const deploymentAccount = accounts[0];

  const privateKey =
    provider.wallets[accounts[0].toLowerCase()].privateKey.toString("hex");

  console.log("Conta usada para o deploy", accounts[0]);

  try {
    let contract = await new web3.eth.Contract(abi)
      .deploy({ data: evm.bytecode.object, arguments: [] })
      .encodeABI();

    let transactionObject = {
      gas: 4000000,
      data: contract,
      from: deploymentAccount,
    };

    let signedTransactionObject = await web3.eth.accounts.signTransaction(
      transactionObject,
      "0x" + privateKey
    );

    let result = await web3.eth.sendSignedTransaction(
      signedTransactionObject.rawTransaction
    );

    console.log("Contract deployed to", result.contractAddress);
  } catch (error) {
    console.log(error);
  }
  provider.engine.stop();
};

deploy();
