// SPDX-License-Identifier: MIT
pragma solidity ^0.8.2;
contract Loteria {
    address public gerente;

    address payable[] public jogadores;

    constructor () {
        gerente = msg.sender;
        jogadores = new address payable[](0);
    }

    function jogar () public payable {
        require(msg.value > 0.1 ether);
        jogadores.push(msg.sender);
    }

    function random () private view returns (uint) {
        return uint(
                keccak256(
                    abi.encodePacked(
                        block.difficulty,
                        block.timestamp, 
                        jogadores
                        )
                    )
                );
    }

    function sorteio () public verificaGerente {
        uint indice = random() % jogadores.length;
    
        jogadores[indice].transfer(address(this).balance);
        jogadores = new address payable[](0);
    }

    modifier verificaGerente () {
        require(msg.sender == gerente);
        _;
    }

    function getJogadores () public view returns (address payable[] memory) {
        return jogadores;
    }
}

