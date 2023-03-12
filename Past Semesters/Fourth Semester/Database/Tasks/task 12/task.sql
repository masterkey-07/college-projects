# Question 1 - A
UPDATE ATOR SET sexo = 'm' WHERE nomeart = 'BradPitt'; 
# Question 1 - B
UPDATE PERSONAGEM SET cache = cache * 1.1;
# Question 1 - C
DELETE FROM FILME WHERE nome = 'Tieta'; # Erro por chave estrangeira, que está sendo usada na tabela PERSONAGEM
# Question 1 - D
DELETE FROM PERSONAGEM  WHERE personagem = 'Tootsie'; # Sucedido, pois ele não tem nenhuma refêrencia externa

# Question 2 - A
SELECT * FROM ATOR WHERE sexo = 'f';
# Question 2 - B
SELECT nomeart, sexo FROM ATOR;
# Question 2 - C
SELECT indicacoesoscar, num_oscar FROM ATOR;
# Question 2 - D
SELECT FILME.codf  FROM FILME 
INNER JOIN PERSONAGEM ON FILME.codf = PERSONAGEM.codf 
WHERE PERSONAGEM.cache < 1000;  
# Question 2 - E
SELECT PERSONAGEM.personagem FROM PERSONAGEM 
INNER JOIN ATOR ON ATOR.coda = PERSONAGEM.coda 
WHERE ATOR.nomeart = "Demi Moore";
# Question 2 - F
SELECT FILME.nome  FROM FILME
INNER JOIN PERSONAGEM ON PERSONAGEM.codf = FILME.codf 
INNER JOIN ATOR ON ATOR.coda = PERSONAGEM.coda 
WHERE ATOR.nomeart = "Demi Moore";
# Question 2 - G
SELECT ATOR.nomeart FROM ATOR WHERE ATOR.nomeart LIKE '%Jessica%'; 
# Question 2 - H
SELECT ATOR.nomeart FROM ATOR WHERE ATOR.indicacoesoscar  - ATOR.num_oscar >= 2;
# Question 2 - I
SELECT PERSONAGEM.personagem FROM PERSONAGEM 
INNER JOIN ATOR ON ATOR.coda = PERSONAGEM.coda  
WHERE sexo = 'f';
