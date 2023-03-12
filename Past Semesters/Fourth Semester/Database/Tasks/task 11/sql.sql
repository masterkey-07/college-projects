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
    ano DATE,
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