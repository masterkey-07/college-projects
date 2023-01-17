CREATE DATABASE FinalWork;
USE FinalWork;
CREATE TABLE Usuário(
    chapa INTEGER,
    senha VARCHAR(256) NOT NULL,
    email VARCHAR(256) NOT NULL,
    nome VARCHAR(256) NOT NULL,
    PRIMARY KEY (chapa)
);
CREATE TABLE Técnico(
    id INTEGER AUTO_INCREMENT,
    chapa INTEGER,
    PRIMARY KEY (id),
    FOREIGN KEY (chapa) REFERENCES Usuário(chapa)
);
CREATE TABLE Comprador(
    id INTEGER AUTO_INCREMENT,
    chapa INTEGER,
    PRIMARY KEY (id),
    FOREIGN KEY (chapa) REFERENCES Usuário(chapa)
);
CREATE TABLE Operador(
    id INTEGER AUTO_INCREMENT,
    chapa INTEGER,
    PRIMARY KEY (id),
    FOREIGN KEY (chapa) REFERENCES Usuário(chapa)
);
CREATE TABLE Maquina(
    id INTEGER AUTO_INCREMENT,
    descrição VARCHAR(200),
    critico BOOLEAN,
    PRIMARY KEY(id)
);
CREATE TABLE Material(
    id INTEGER AUTO_INCREMENT,
    descrição VARCHAR(200),
    classe VARCHAR(50),
    PRIMARY KEY(id)
);
CREATE TABLE Fornecedor(
    id INTEGER AUTO_INCREMENT,
    nome VARCHAR(200),
    PRIMARY KEY(id)
);
CREATE TABLE Preventiva(
    id INTEGER AUTO_INCREMENT,
    id_maquina INTEGER,
    periodicidade VARCHAR(2),
    meses VARCHAR(12),
    descrição VARCHAR(200),
    PRIMARY KEY (id),
    FOREIGN KEY (id_maquina) REFERENCES Maquina(id)
);
CREATE TABLE Nota(
    id INTEGER AUTO_INCREMENT,
    operador_criador INTEGER,
    id_maquina INTEGER,
    descrição VARCHAR(200),
    rejeitado BOOLEAN,
    criação DATE,
    PRIMARY KEY (id),
    FOREIGN KEY (operador_criador) REFERENCES Operador(id),
    FOREIGN KEY (id_maquina) REFERENCES Maquina(id)
);
CREATE TABLE Ordem(
    id INTEGER AUTO_INCREMENT,
    id_nota INTEGER UNIQUE,
    Tipo VARCHAR(3),
    PRIMARY KEY(id)
);
CREATE TABLE PlanejamentoPreventiva(
    id_preventiva INTEGER,
    id_nota INTEGER,
    PRIMARY KEY (id_preventiva, id_nota)
);
CREATE TABLE FornecimentoMaterial(
    id_material INTEGER,
    id_fornecedor INTEGER,
    preço FLOAT,
    PRIMARY KEY (id_material, id_fornecedor),
    FOREIGN KEY (id_fornecedor) REFERENCES Fornecedor(id)
);
CREATE TABLE ConsumoMaterial(
    id_material INTEGER,
    id_ordem INTEGER,
    id_maquina INTEGER,
    quantidade INTEGER,
    PRIMARY KEY (id_material, id_ordem, id_maquina),
    FOREIGN KEY (id_material) REFERENCES Material(id),
    FOREIGN KEY (id_ordem) REFERENCES Ordem(id),
    FOREIGN KEY (id_maquina) REFERENCES Maquina(id)
);
CREATE TABLE PedidoCompra(
    id INTEGER AUTO_INCREMENT,
    id_fornecedor INTEGER,
    id_comprador INTEGER,
    criação DATE,
    remessa DATE,
    entrada DATE,
    frete FLOAT,
    PRIMARY KEY(id),
    FOREIGN KEY (id_fornecedor) REFERENCES Fornecedor(id),
    FOREIGN KEY (id_comprador) REFERENCES Comprador(id)
);
CREATE TABLE Relatório(
    id_pedido INTEGER,
    descrição VARCHAR(500),
    PRIMARY KEY (id_pedido),
    FOREIGN KEY (id_pedido) REFERENCES PedidoCompra(id)
);
CREATE TABLE Requisição(
    id_material INTEGER,
    id_ordem INTEGER,
    id_compra INTEGER,
    quantidade INTEGER,
    PRIMARY KEY (id_material, id_ordem, id_compra),
    FOREIGN KEY (id_material) REFERENCES Material(id),
    FOREIGN KEY (id_ordem) REFERENCES Ordem(id),
    FOREIGN KEY (id_compra) REFERENCES PedidoCompra(id)
);