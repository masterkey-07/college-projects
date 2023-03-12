-- Subconsulta
-- 16. Listar nomes das Clinicas que tem especialidade
SELECT c.nome from Clinica c 
WHERE c.cod IN (SELECT ec.clinica_cod FROM EspecialidadeClinica ec);

-- 17. Listar nomes dos médicos que não tem consulta
SELECT * FROM Medico m 
WHERE m.cod NOT IN (SELECT c2.medico_cod  FROM Consulta c2);
-- 18. Listar nomes dos médicos que atendem na Clinica ortocentro
SELECT * FROM Medico m 
WHERE m.cod IN (SELECT mc.medico_cod  FROM MedicoClinica mc 
				WHERE mc.clinica_cod = ALL (SELECT c.cod  FROM Clinica c WHERE c.nome = 'ortocentro'));
-- 19. Listar nome do médico que teve a consulta mais antiga – usar min(data)
SELECT m.nome FROM Medico m 
WHERE m.cod IN (SELECT c2.medico_cod FROM Consulta c2 WHERE c2.`data` = (SELECT MIN(c.`data`) FROM Consulta c)); 
-- 20. Crie a tabela Folha_pagto e insira os dados:
-- CREATE TABLE Folha_Pagto ( medico_cod int, consulta_cod int, valor float,
-- primary key(medico_cod, consulta_cod),
-- foreign key (medico_cod) references Medico(cod),
-- foreign key (consulta_cod) references Consulta(cod) );
-- INSERT INTO Folha_Pagto VALUES (1,1,100), (1,2,150),(2,3,100), (2, 4, 150), (3,5,50);
-- 21. Listar nomes dos médicos que recebem valor da consulta maior que a média
-- Inventar 3 consultas que use: IN ou NOT IN ou ANY ou ALL

# Caso IN
SELECT m.nome FROM Medico m 
WHERE m.cod IN (SELECT fp.medico_cod FROM Folha_Pagto fp WHERE fp.valor > (SELECT AVG(fp2.valor) FROM Folha_Pagto fp2));

# Caso NOT IN
SELECT m.nome FROM Medico m 
WHERE m.cod NOT IN (SELECT m2.cod FROM Medico m2 
WHERE m2.cod NOT IN (SELECT fp.medico_cod FROM Folha_Pagto fp)
OR m2.cod IN (SELECT fp2.medico_cod FROM Folha_Pagto fp2 GROUP BY fp2.medico_cod HAVING MAX(fp2.valor) < (SELECT AVG(fp3.valor) FROM Folha_Pagto fp3)));

# Caso ANY
SELECT m.nome FROM Medico m 
WHERE (SELECT AVG(fp2.valor) FROM Folha_Pagto fp2) < ANY (SELECT fp.valor FROM Folha_Pagto fp WHERE fp.medico_cod = m.cod);

