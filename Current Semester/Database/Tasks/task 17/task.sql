USE VictorChaves

#1) Selecionar o nome dos pilotos , nome dos circuitos e data em que eles participaram

SELECT p.nomepil, c.nomecir , p2.`data` FROM piloto p 
INNER JOIN pospilotoprova p2 ON p2.codpil = p.codpil 
INNER JOIN circuito c ON c.codcirc = p2.codcirc;

#2) Selecionar o nome de todos os pilotos do banco de dados e para aqueles que participaram
#de prova, listar a data da prova, duração e posição do piloto na prova.

SELECT p.nomepil, p3.`data`, p3.duracao, p2.posicao FROM piloto p 
LEFT OUTER JOIN pospilotoprova p2 ON p2.codpil = p.codpil
LEFT JOIN prova p3 ON p3.codcirc = p2.codcirc AND p3.`data` = p2.`data`;


#3) Selecionar o nome do piloto, seu país de origem, nome da equipe e país da equipe.

SELECT p.nomepil, p3.nomepais origem, e.nomeeq  ,p2.nomepais pais_eqp FROM piloto p 
INNER JOIN equipe e ON e.codeq = p.codeq 
INNER JOIN pais p2 ON p2.codpais = e.codpais 
INNER JOIN pais p3 ON p3.codpais = p.codpais 

#4) Listar o nome das equipes que não possuem piloto.



#5) Listar os nomes dos países que não existem pilotos (usar NOT EXISTS)

#6) Selecionar o nome do piloto que foi campeão (ficou em primeiro lugar) mais do quequalquer outro piloto. USE ALL

#7) Selecionar o nome das equipes que possuem pelo menos um piloto que é do mesmo país que a equipe.

#8) Listar o nome dos amigos de cada piloto; DICA: use 2x a tabela Piloto no 
#FROM
#SELECT ...
#FROM piloto p1, piloto p2, ..
#WHERE …

#9) Obter os países que tem equipes e pilotos e que foram sede de um circuito em 2009. use função year . Ex: year(data)= ‘2009’

#10) Para cada circuito que em 2009 houve mais que uma prova obter o código do circuito, o nome do circuito e o número de provas.

#11) Obter o nome dos pilotos que participaram de todas as provas da Inglaterra
#(mesmo que obter nome dos pilotos tal que, não existe prova realizada na Inglaterra na qual
#ele não tenha participado)
#Insira na PosPilotoProva as seguintes tuplas:
#4,’2010-09-15’,2, 4
#2, ‘2018-10-20’,3,2

#12) Obter uma tabela com três colunas: nome do país, nome de circuito e data da
#prova. Atabela deve conter uma linha para cada prova com duração de mais de 60
#minutos no circuito em questão no país em questão. Países sem circuitos devem
#aparecer ficando as demais colunas vazias(NULL).
#Circuitos nos quais não ocorreram provas ou nos quais as provas não excederam 60 minutos
#devem aparecer também, com a data da prova vazia (NULL).