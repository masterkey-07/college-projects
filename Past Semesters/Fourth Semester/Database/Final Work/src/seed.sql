INSERT INTO Usuário (chapa, senha, email, nome)
VALUES (1, 'abc123', 'pedro@gmail.com', 'Pedro'),
    (2, 'abc123', 'maria@gmail.com', 'Maria'),
    (3, 'abc123', 'tom@gmail.com', 'Tom'),
    (4, 'abc123', 'erika@gmail.com', 'Erika'),
    (5, 'abc123', 'john@gmail.com', 'John'),
    (6, 'abc123', 'emilia@gmail.com', 'Emilia'),
    (7, 'abc123', 'robert@gmail.com', 'Robert'),
    (8, 'abc123', 'robert@gmail.com', 'José'),
    (9, 'abc123', 'enzo@gmail.com', 'Enzo');
INSERT INTO Técnico (chapa)
VALUES (1),
    (2),
    (3);
INSERT INTO Comprador (chapa)
VALUES (4),
    (5),
    (6),
    (9);
INSERT INTO Operador (chapa)
VALUES (7),
    (8),
    (9);
INSERT INTO Maquina (descrição, critico)
VALUES ('Centro de Torneamento', TRUE),
    ('Centro de Tratamento', TRUE),
    ('Retificadora', TRUE),
    ('Máquina Jateamento', FALSE),
    ('Tamboreamento', FALSE),
    ('Prensa de Bancada Hidráulica', TRUE);
INSERT INTO Material (descrição, classe)
VALUES ('Motor', 'Preventivo'),
    ('Modulo de Potencia', 'Preventivo'),
    ('Manta Cinza', 'Consumo'),
    ('Bomba Hidraulica', 'Preventivo'),
    ('Cabo Conexão', 'Corretivo'),
    ('Filtro', 'Consumo'),
    ('Lampada', 'Consumo'),
    ('Valvula Pneumatica', 'Corretivo');
INSERT INTO Fornecedor (nome)
VALUES ('NIKKEYPAR'),
    ('SIEMENS'),
    ('BOSCH'),
    ('OKUMA'),
    ('THEVAL'),
    ('NORTEL');
INSERT INTO Preventiva (
        id_maquina,
        id_tecnico,
        periodicidade,
        meses,
        descrição
    )
VALUES (1, 3, 'SM', 'Jan,Jun', 'Prevenção de Incêndio'),
    (2, 3, 'SM', 'Jan,Jun', 'Prevenção de Incêndio'),
    (3, 3, 'SM', 'Jan,Jun', 'Prevenção de Incêndio'),
    (2, 3, 'SM', 'Jan,Jun', 'Prevenção de Incêndio'),
    (4, 3, 'SM', 'Jan,Jun', 'Prevenção de Incêndio'),
    (5, 3, 'SM', 'Jan,Jun', 'Prevenção de Incêndio'),
    (3, 3, 'AN', 'Fev', 'Troca de Motor'),
    (5, 3, 'AN', 'Fev', 'Troca de Motor'),
    (1, 3, 'AN', 'Fev', 'Troca de Motor'),
    (4, 3, 'AN', 'Fev', 'Troca do Revestimento'),
    (6, 2, 'AN', 'Fev', 'Troca do Revestimento');
# Exemplo de Inserção na Tabela Nota
INSERT INTO Nota (
        operador_criador,
        id_maquina,
        descrição,
        rejeitado,
        criação
    )
VALUES (1, 3, 'Sons Altos', TRUE, '2023-01-011'),
    (1, 2, 'Alta Temperatura', FALSE, '2023-01-012'),
    (3, 5, 'Peça Caiu', TRUE, '2023-01-013'),
    (2, 5, 'Alarme', FALSE, '2023-01-08'),
    (2, 4, 'Baixa Temperatura', FALSE, '2023-01-09'),
    (2, 2, 'Alarme', TRUE, '2023-01-10'),
    (1, 3, 'Alta Vibração', FALSE, '2023-01-10'),
    (3, 5, 'Sons Altos', TRUE, '2023-01-11'),
    (2, 4, 'Falta de Energia', FALSE, '2023-01-01'),
    (1, 6, 'Painel Desligou', FALSE, '2023-01-05');
INSERT INTO Ordem (id_nota, id_tecnico, encerramento, tipo)
VALUES (1, 1, '2023-01-15', 'ZMI'),
    (2, 2, NULL, 'ZMG'),
    (4, NULL, NULL, 'ZMG'),
    (9, NULL, NULL, 'ZMI'),
    (10, NULL, NULL, 'ZMI');
INSERT INTO PlanejamentoPreventiva (id_preventiva, id_nota)
VALUES (8, 4),
    (2, 2);
INSERT INTO FornecimentoMaterial (
        id_material,
        id_fornecedor,
        preço
    )
VALUES (8, 1, 123),
    (2, 1, 32),
    (2, 2, 65),
    (3, 2, 43),
    (3, 3, 123),
    (4, 3, 87),
    (4, 4, 435),
    (5, 4, 49),
    (5, 5, 39),
    (6, 5, 21),
    (6, 6, 10),
    (7, 6, 100);
INSERT INTO ConsumoMaterial (
        id_material,
        id_ordem,
        id_maquina,
        quantidade
    )
VALUES (1, 1, 5, 10),
    (4, 1, 1, 1),
    (4, 2, 5, 3),
    (8, 2, 6, 2),
    (7, 3, 4, 5),
    (2, 3, 4, 1),
    (3, 4, 6, 8),
    (5, 4, 1, 1);
INSERT INTO PedidoCompra (
        id_fornecedor,
        id_comprador,
        criação,
        remessa,
        entrada,
        frete
    )
VALUES (
        1,
        1,
        '2023-01-01',
        '2023-01-10',
        '2023-01-12',
        10
    ),
    (
        2,
        1,
        '2023-01-02',
        '2023-02-01',
        '2023-01-08',
        20
    ),
    (3, 2, '2023-01-03', '2023-03-01', NULL, 30),
    (4, 2, '2023-01-04', '2023-04-01', NULL, 10),
    (5, 3, '2023-01-05', '2023-05-01', NULL, 33),
    (6, 3, '2023-01-06', '2023-06-01', NULL, 25);
INSERT INTO Relatório (id_pedido, descrição)
VALUES (1, 'Material Correto'),
    (2, 'Material Incorreto');
INSERT INTO Requisição (
        id_material,
        id_ordem,
        id_compra,
        quantidade
    )
VALUES (8, 1, 1, 12),
    (2, 1, 1, 3),
    (2, 2, 2, 6),
    (3, 3, 2, 12),
    (4, 3, 3, 8),
    (4, 4, 3, 4),
    (5, 4, 4, 4),
    (5, 5, 4, 3),
    (6, 5, 5, 2),
    (6, 5, 6, 2),
    (7, 1, 6, 1);