#1. o número de atrizes.
SELECT COUNT(*) AS QTD_ATRIZES FROM ATOR WHERE sexo = 'f';

#2. o nome do artista e o número de filmes em que participou;
SELECT a.nomeart ,COUNT(f.codf) FROM FILME f 
INNER JOIN PERSONAGEM p ON f.codf = p.codf  
INNER JOIN ATOR a ON a.coda = p.coda  
GROUP BY a.coda;

#3. para cada ator que não ganhou oscar, listar o seu nome, ano de seu filme mais antigo e do mais novo;
SELECT a.nomeart , MIN(f.ano), Max(f.ano) FROM FILME f 
INNER JOIN PERSONAGEM p ON f.codf = p.codf  
INNER JOIN ATOR a ON a.coda = p.coda  
WHERE a.num_oscar = 0
GROUP BY a.coda;

#4. para cada filme listar: o nome do filme, média de cachês pagos por filme, cachê mais alto, cachê mais baixo, e total dos cachês pagos;
SELECT f.nome ,AVG(p.cache) ,MIN(p.cache), Max(p.cache), SUM(p.cache) FROM FILME f 
INNER JOIN PERSONAGEM p ON f.codf = p.codf  
GROUP BY f.codf;

#5. o nome do artista e o número de filmes em que participou, para todo artista que participou de no mínimo 2 filmes;
SELECT * FROM (
	SELECT a.nomeart ,COUNT(f.codf) AS QTD FROM FILME f 
	INNER JOIN PERSONAGEM p ON f.codf = p.codf  
	INNER JOIN ATOR a ON a.coda = p.coda  
	GROUP BY a.coda
) dt WHERE dt.QTD >= 2;


#6. o número de caches distintos maiores do que 2000 pagos em cada filme, para todo filme onde
#a soma dos cachês destes artistas foi inferior a 8000. ( use count (distinct cache) )

	SELECT  f.codf, COUNT(DISTINCT(p.cache)) FROM FILME f 
	INNER JOIN PERSONAGEM p ON f.codf = p.codf  
	WHERE p.cache > 2000
	GROUP BY f.codf 
	HAVING SUM(p.cache) < 8000;

#7. Para cada filme, listar o numero de personagens. 
SELECT  f.codf ,COUNT(p.codf) AS QTD FROM FILME f 
INNER JOIN PERSONAGEM p ON f.codf = p.codf  
GROUP BY f.codf; 

#8.  Listar para cada ano a quantidade de filmes.
SELECT  f.ano  ,COUNT(f.codf) AS QTD FROM FILME f 
GROUP BY f.ano;

#9. Listar nome dos artistas que recebem cache maior que a média.
SELECT a.nomeart , SUM(p.cache) FROM ATOR a 
INNER JOIN PERSONAGEM p ON a.coda = p.coda 
WHERE p.cache > (SELECT AVG(pe.cache) FROM PERSONAGEM pe)
GROUP BY a.coda;