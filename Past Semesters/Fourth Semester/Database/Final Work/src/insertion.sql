# Exemplo de Inserção na Tabela Usuário
INSERT INTO Usuário (chapa, senha, email, nome)
VALUES (1, '123', 'user@email.com', 'usuario');
# Exemplo de Inserção na Tabela Técnico
INSERT INTO Técnico (chapa)
VALUES (1);
# Exemplo de Inserção na Tabela Comprador
INSERT INTO Comprador (chapa)
VALUES (1);
# Exemplo de Inserção na Tabela Operador
INSERT INTO Operador (chapa)
VALUES (1);
# Exemplo de Inserção na Tabela Maquina
INSERT INTO Maquina (descrição, critico)
VALUES ('Centro de Torneamento', TRUE);
# Exemplo de Inserção na Tabela Material
INSERT INTO Material (descrição, classe)
VALUES ('Motor', 'Preventivo');
# Exemplo de Inserção na Tabela Fornecedor
INSERT INTO Fornecedor (nome)
VALUES ('NIKKEYPAR');
# Exemplo de Inserção na Tabela Preventiva
INSERT INTO Preventiva (
        id_maquina,
        id_tecnico,
        periodicidade,
        meses,
        descrição
    )
VALUES (1, 1, 'SM', 'Jan,Jun', 'Prevenção de Incêndio');
# Exemplo de Inserção na Tabela Nota
INSERT INTO Nota (
        operador_criador,
        id_maquina,
        descrição,
        rejeitado,
        criação
    )
VALUES (1, 1, 'Sons Altos', FALSE, '2020-01-01');
# Exemplo de Inserção na Tabela Ordem
INSERT INTO Ordem (id_nota, id_tecnico, encerramento, tipo)
VALUES (1, 1, '2020-01-01', 'ZMI');
# Exemplo de Inserção na Tabela PlanejamentoPreventiva
INSERT INTO PlanejamentoPreventiva (id_preventiva, id_nota)
VALUES (1, 1);
# Exemplo de Inserção na Tabela FornecimentoMaterial
INSERT INTO FornecimentoMaterial (
        id_material,
        id_fornecedor,
        preço
    )
VALUES (1, 1, 1.1);
# Exemplo de Inserção na Tabela ConsumoMaterial
INSERT INTO ConsumoMaterial (
        id_material,
        id_ordem,
        id_maquina,
        quantidade
    )
VALUES (1, 1, 1, 10);
# Exemplo de Inserção na Tabela PedidoCompra
INSERT INTO PedidoCompra (
        id_fornecedor,
        id_comprador,
        criação,
        remessa,
        entrada,
        frete
    )
VALUES (1, 1, '2020-01-01', '2020-05-01', NULL, 50);
# Exemplo de Inserção na Tabela Relatório
INSERT INTO Relatório (id_pedido, descrição)
VALUES (1, 'Material Correto');
# Exemplo de Inserção na Tabela Requisição
INSERT INTO Requisição (
        id_material,
        id_ordem,
        id_compra,
        quantidade
    )
VALUES (1, 1, 1, 10);