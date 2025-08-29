-- Postos(nroPosto, CEP, fone, end, bairro)
CREATE TABLE Postos(
    nroPosto INT PRIMARY KEY ,
    CEP VARCHAR(20),
    fone VARCHAR(20),
    endereço VARCHAR(100),
    bairro VARCHAR(100)
);

-- Funcionários (Codf, nome, CPF, salario, #nroPosto)
CREATE TABLE Funcionarios(
    Codf INT PRIMARY KEY,
    nome VARCHAR(200),
    CPF VARCHAR(20),
    salario FLOAT,
    nroPosto INT,
    FOREIGN KEY (nroPosto) REFERENCES Postos(nroPosto)
);

-- Médicos (codM, CRM, nome, especialidade, endereco, fone, #nroPosto)
CREATE TABLE Medicos(
    codM INT PRIMARY KEY,
    CRM INT,
    nome VARCHAR(200),
    especialidade VARCHAR(200),
    endereco VARCHAR(200),
    fone VARCHAR(20),
    nroPosto INT,
    FOREIGN KEY (nroPosto) REFERENCES Postos(nroPosto)
);