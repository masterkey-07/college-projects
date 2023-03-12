#Usando produto cartesiano:
#1. Obter as especialidades do Dr Paulo 
SELECT e.cod, e.nome  FROM Medico m, MedicoEspecialidade me, Especialidade e  
WHERE me.medico_cod = m.cod AND m.nome = 'Paulo' AND me.especialidade_cod  = e.cod 

#2. Obter as datas das consultas do dr Arthur
SELECT * FROM Consulta c, Medico m2
WHERE m2.nome = 'Arthur' AND c.medico_cod = m2.cod 

#3. Selecione o nome do médico, o nome e endereço da clínica para todas as consultas que possuem especialidade ‘CLINICO GERAL’.
SELECT m.nome, c2.nome, c2.endereco  FROM Medico m, MedicoClinica mc, Consulta c, Especialidade e, Clinica c2  
WHERE e.nome = 'CLiNiCO GERAL' AND 
	  m.cod = mc.medico_cod AND
	  mc.clinica_cod = c.clinica_cod AND
	  e.cod = c.especialidade_cod AND
	  c.medico_cod = m.cod AND 
	  c2.cod = mc.clinica_cod AND
	  c.clinica_cod  = c2.cod;

#5. Mostre o nome e o endereço das clínicas que possuem consulta marcada para 30/03/2010;
SELECT * FROM Consulta c, Clinica c2
WHERE c.clinica_cod = c2.cod AND c.`data` = '2010-03-30';

#6. Recuperar nome dos médicos que atendem na Clínica Bem Estar;
SELECT m.nome FROM Medico m, MedicoClinica mc, Clinica c 
WHERE c.nome = 'clinica bem estar' AND 
	  m.cod = mc.medico_cod AND 
	  mc.clinica_cod = c.cod;

#7. Exiba o nome e endereço das clínicas onde o médico André trabalha;
SELECT c.nome, c.endereco FROM Medico m, MedicoClinica mc, Clinica c 
WHERE m.nome = 'André' AND 
	  m.cod = mc.medico_cod AND 
	  mc.clinica_cod = c.cod;
 
#8. Insira 2 clinicas
INSERT INTO Clinica VALUES (15, 'clinica novinha', 'no paraiso');
INSERT INTO Clinica VALUES (16, 'clinica nova novinha', 'no paraiso 2');
	 
#9. Insira 2 médicos
INSERT INTO Medico  VALUES (15, 'medicon da silva', '010101010');
INSERT INTO Medico  VALUES (16, 'medicon de carvalho', '010101010');

#Usando JOIN:
#10. Liste o Nome das Clinicas e suas especialidades
SELECT c.nome, e.nome FROM Clinica c 
INNER JOIN EspecialidadeClinica ec ON ec.clinica_cod = c.cod 
INNER JOIN Especialidade e ON e.cod = ec.especialidade_cod;

#11. Liste o Nome de todas as clinicas e suas Especialidades.
#Clinicas que não possuem especialidade devem aparecer. Ordenar o resultado pelo nome da Clinica e Especialidade.
SELECT c.nome, e.nome FROM Clinica c
LEFT JOIN EspecialidadeClinica ec ON ec.clinica_cod = c.cod 
LEFT JOIN Especialidade e ON e.cod = ec.especialidade_cod
ORDER BY c.nome, e.nome ASC 

#12. Liste o nome de todos os médicos cadastrados e para aqueles que tem consulta, listar a data e hora da consulta.
SELECT m.nome, c.`data`, c.hora  FROM Medico m 
LEFT JOIN Consulta c ON c.medico_cod = m.cod 

#13. Liste para cada médico, o seu nome e a quantidade de consultas que ele
#possui.
SELECT m.nome, COUNT(c.cod) FROM Medico m 
INNER JOIN Consulta c ON c.medico_cod = m.cod
GROUP BY m.cod 

#14. Liste para cada médico, o seu nome e a quantidade de consultas que ele
#possui. Médicos que não possuem consulta também devem aparecer no resultado.
SELECT m.nome, COUNT(c.cod) FROM Medico m 
LEFT JOIN Consulta c ON c.medico_cod = m.cod
GROUP BY m.cod

#15. Liste o nome dos médicos e nome da clinicas. Os nomes das clinicas que não
#possuem medico, devem aparecer. Ordenado pelo nome da clinica, nome do médico
SELECT c.nome, m.nome  FROM Medico m 
RIGHT JOIN MedicoClinica mc ON mc.medico_cod = m.cod 
RIGHT JOIN Clinica c ON c.cod = mc.clinica_cod 
ORDER BY c.nome, m.nome ASC 

