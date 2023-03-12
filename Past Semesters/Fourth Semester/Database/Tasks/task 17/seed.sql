
USE VictorChaves

CREATE TABLE circuito (
  codcirc int(11) NOT NULL default '0',
  nomecir varchar(20) default NULL,
  codpais int(11) default NULL,
  PRIMARY KEY  (codcirc),
  KEY codpais (codpais)
) ;


INSERT INTO circuito (codcirc, nomecir, codpais) VALUES
(1, 'Melbourne', 9),
(2, 'Barcelona', 8),
(3, 'Silverstone', 3),
(4, 'Nurburgring', 2),
(5, 'Monza', 5),
(6, 'Interlagos', 1);

-- --------------------------------------------------------

--
-- Estrutura da tabela 'equipe'
--

CREATE TABLE equipe (
  codeq int(11) NOT NULL default '0',
  nomeeq varchar(20) default NULL,
  codpais int(11) default NULL,
  PRIMARY KEY  (codeq),
  KEY codpais (codpais)
);

--
-- Extraindo dados da tabela 'equipe'
--

INSERT INTO equipe (codeq, nomeeq, codpais) VALUES
(1, 'ferrari', 5),
(2, 'MCLaren', 3),
(3, 'Williams', 3),
(4, 'Renault', 7),
(5, 'Jordan', 6);

-- --------------------------------------------------------

--
-- Estrutura da tabela 'pais'
--

CREATE TABLE pais (
  codpais int(11) NOT NULL default '0',
  nomepais varchar(20) default NULL,
  PRIMARY KEY  (codpais)
) ;

--
-- Extraindo dados da tabela 'pais'
--

INSERT INTO pais (codpais, nomepais) VALUES
(1, 'brasil'),
(2, 'alemanha'),
(3, 'inglaterra'),
(4, 'estados unidos'),
(5, 'italia'),
(6, 'irlanda'),
(7, 'franca'),
(8, 'espanha'),
(9, 'australia');

-- --------------------------------------------------------

--
-- Estrutura da tabela 'piloto'
--

CREATE TABLE piloto (
  codpil int(11) NOT NULL default '0',
  nomepil varchar(20) default NULL,
  codeq int(11) default NULL,
  codpais int(11) default NULL,
  PRIMARY KEY  (codpil),
  KEY codpais (codpais),
  KEY codeq (codeq)
) ;


INSERT INTO piloto (codpil, nomepil, codeq, codpais) VALUES
(1, 'Felipe Massa', 1, 1),
(2, 'Kimi Raikkonen', 1, 6),
(3, 'Kovalainen', 2, 6),
(4, 'Lewis Hamiltton', 2, 3),
(5, 'Fernando Alonso', 7, 8),
(6, 'Nico Rosberg', 3, 2),
(7, 'Fernando Alonso', 7, 8);

-- --------------------------------------------------------

--
-- Estrutura da tabela 'pospilotoprova'
--

CREATE TABLE pospilotoprova (
  codcirc int(11) NOT NULL default '0',
  `data` date NOT NULL ,
  codpil int(11) NOT NULL default '0',
  posicao int(11) default NULL,
  PRIMARY KEY  (codcirc,`data`,codpil),
  KEY codpil (codpil),
  KEY `data` (`data`)
) ;


INSERT INTO pospilotoprova (codcirc, data, codpil, posicao) VALUES
(3, '2009-10-21', 4, 1),
(3, '2009-06-20', 1, 3),
(3, '2009-10-21', 1, 1),
(3, '2009-06-20', 4, 1);

-- --------------------------------------------------------

--
-- Estrutura da tabela 'prova'
--

CREATE TABLE prova (
  codcirc int(11) NOT NULL,
  `data` date NOT NULL ,
  duracao int(11) default NULL,
  PRIMARY KEY  (codcirc,`data`)
) ;

--
-- Extraindo dados da tabela 'prova'
--

INSERT INTO prova (codcirc, data, duracao) VALUES
(1, '2009-10-21', 58),
(6, '2009-10-21', 71),
(2, '2009-10-21', 66),
(3, '2009-10-21', 60),
(4, '2009-10-21', 60),
(3, '2009-06-20', 60);



create table amizade (codpiloto1 int, codpiloto2 int, primary key(codpiloto1, codpiloto2));

insert into amizade values(2,3);
insert into amizade values(1,7);
insert into amizade values(4,6);