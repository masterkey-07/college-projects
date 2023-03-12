CREATE DATABASE VictorChaves;
USE VictorChaves;
CREATE TABLE ATOR (
    coda INTEGER,
    nomeart VARCHAR(25),
    nomereal VARCHAR(25),
    nacionalidade VARCHAR(25),
    sexo CHAR,
    indicacoesoscar INTEGER,
    num_oscar INTEGER,
    PRIMARY KEY (coda)
);
CREATE TABLE FILME (
    codf INTEGER,
    nome VARCHAR(20),
    ano INTEGER,
    orcamento FLOAT,
    tempo FLOAT,
    PRIMARY KEY(codf)
);
CREATE TABLE PERSONAGEM(
    coda INTEGER,
    codf INTEGER,
    personagem VARCHAR(25),
    cache FLOAT,
    PRIMARY KEY(coda, codf),
    FOREIGN KEY (coda) REFERENCES ATOR(coda),
    FOREIGN KEY (codf) REFERENCES FILME(codf)
);
INSERT INTO ATOR
VALUES (
        1,
        'Demi Moore',
        'MariadaSilva',
        'USA',
        'f',
        0,
        0
    )
INSERT INTO ATOR
VALUES (2, 'BradPitt', 'Joao Paulo', 'USA', 'f', 10)
INSERT INTO ATOR
VALUES (
        3,
        'Dustin Hoffman',
        'Dustin Hoffman',
        'USA',
        'm',
        2,
        0
    )
INSERT INTO ATOR
VALUES (
        4,
        'Jessica Lange',
        'JessicaLange',
        'USA',
        'f',
        4,
        2
    )
INSERT INTO ATOR
VALUES (
        5,
        'SoniaBraga',
        'SoniaBraga',
        'Brasil',
        'f',
        0,
        0
    )
INSERT INTO FILME
VALUES (1, 'AJurada', 1996, 1000000, 18)
INSERT INTO FILME
VALUES (2, 'A Letra Escarlate', 1995, 10000000, 24)
INSERT INTO FILME
VALUES (3, 'Seven', 1995, 1500000, 20)
INSERT INTO FILME
VALUES (4, 'Tootsie', 1982, 50000, 16)
INSERT INTO FILME
VALUES (5, 'Tieta', 1995, 200000, 18)
INSERT INTO PERSONAGEM
VALUES (1, 1, 'Mary', 3000)
INSERT INTO PERSONAGEM
VALUES (1, 2, 'Sandy', 5000)
INSERT INTO PERSONAGEM
VALUES (2, 3, 'John', 5000)
INSERT INTO PERSONAGEM
VALUES (3, 4, 'Mary', 1000)
INSERT INTO PERSONAGEM
VALUES (4, 4, 'Tootsie', 2000)
INSERT INTO PERSONAGEM
VALUES (5, 5, 'Tieta', 500)