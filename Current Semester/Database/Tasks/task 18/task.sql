#Utilizando a base de dados de Piloto, crie visões para cada uma das consultas abaixo:
#1) Selecionar o nome dos pilotos e nome dos circuitos que eles participaram

CREATE VIEW Piloto_Circuito AS SELECT p.nomepil, c.nomecir FROM piloto p 
INNER JOIN pospilotoprova p2 ON p2.codpil = p.codpil 
INNER JOIN circuito c ON c.codcirc = p2.codcirc 
GROUP BY p.codpil, c.codcirc;

SELECT * FROM Piloto_Circuito;

#2) Selecionar o nome de todos os pilotos do banco de dados e para aqueles que participaram de prova, listar a data da prova, duração e posição do piloto na prova.

CREATE VIEW Pilotos_Provas AS
SELECT p.nomepil, p3.`data`, p3.duracao, p2.posicao FROM piloto p 
LEFT JOIN pospilotoprova p2 ON p2.codpil = p.codpil
LEFT JOIN prova p3 ON p3.codcirc = p2.codcirc AND p3.`data` = p2.`data`;


#3) Selecionar o nome do piloto, seu país de origem, nome da equipe e país da equipe.

CREATE VIEW Formula1 AS
SELECT p.nomepil, p3.nomepais origem, e.nomeeq, p2.nomepais pais_eqp FROM piloto p 
INNER JOIN equipe e ON e.codeq = p.codeq 
INNER JOIN pais p2 ON p2.codpais = e.codpais 
INNER JOIN pais p3 ON p3.codpais = p.codpais; 

#4) Listar o nome das equipes que não possuem piloto

CREATE VIEW Equipe_Vazia AS
SELECT e.nomeeq FROM equipe e 
WHERE e.codeq NOT IN (SELECT p.codeq  FROM piloto p)

#Usando a visões criadas, selecione:
#5) Para cada nome de piloto, indique quantos circuitos eles participaram

SELECT nomepil, COUNT(pc.nomecir) FROM Piloto_Circuito pc GROUP BY nomepil 

#6) Listar o nome do piloto e o nome da sua equipe

SELECT f.nomepil, f.nomeeq FROM Formula1 f 

#7) Listar os pilotos que são do mesmo país que a sua equipe

SELECT f.nomepil FROM Formula1 f WHERE f.pais_eqp = f.origem  

#8) Inserir um novo piloto no banco de dados

INSERT INTO piloto VALUES (13, 'Fulano', 1, 1)

#9) Execute um select * na view criada na questão 2) e diga o que ocorreu.

# Seleciona a tabela PILOTO e Junta com a Tabela POSPILOTOPROVA, 
# preservando os dados de PILOTO que não se correlacionam com POSPILOTOPROVA.
# Após isso Junta com a tabela PROVA, que novamente Preserva os Dados da Primeira Junção que
# Não se relacionam. Por fim apresenta o nome do piloto, data, duraçã e posição na prova. 