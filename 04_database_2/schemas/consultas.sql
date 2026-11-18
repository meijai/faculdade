DROP SCHEMA IF EXISTS biblioteca;
CREATE SCHEMA IF NOT EXISTS biblioteca;
USE biblioteca;

CREATE TABLE autor (
    id INT AUTO_INCREMENT PRIMARY KEY,
    nome VARCHAR(150) NOT NULL
) ENGINE = InnoDB;

CREATE TABLE livro (
    id INT AUTO_INCREMENT PRIMARY KEY,
    titulo VARCHAR(150) NOT NULL,
    isbn VARCHAR(20) NULL,
    ano_publicacao INT NULL,
    preco DECIMAL(10, 2) NOT NULL DEFAULT 0.00,
    quantidade INT NOT NULL DEFAULT 0,
    id_autor INT NULL
) ENGINE = InnoDB;

INSERT INTO autor (id, nome) VALUES
(1, 'Ana Souza'),
(2, 'Carlos Lima');

INSERT INTO livro (id, titulo, ano_publicacao, preco, quantidade, id_autor) VALUES
(1, 'SQL Essencial', 2020, 80.00, 5, 1),
(2, 'Modelagem Relacional', 2022, 120.00, 3, 2),
(3, 'Introdução ao MySQL', 2022, 60.00, 8, 1),
(4, 'SQL Avançado', 2024, 150.00, 2, NULL),
(5, 'Projeto de Dados', 2024, 90.00, 4, NULL);

-- Ex. 1 · Inspecionar Identifique as chaves primárias de autor e livro. Verifique se livro.id_autor existe e documente seu tipo.

DESCRIBE autor;
DESCRIBE livro;

-- Ex. 2 · Relacionar Implemente 1:N com ALTER TABLE se necessário. Associe os livros e crie a FOREIGN KEY. Teste uma referência inexistente e explique o resultado.

ALTER TABLE livro
ADD CONSTRAINT fk_livro_autor
FOREIGN KEY (id_autor)
REFERENCES autor(id);

-- Linha de teste comentada pra nao quebrar o codigo, inserido um valor 999 (que nao existe autor cadastrado com esse ID)
-- e retorna erro, pois nao aceita valores que nao existem
-- INSERT INTO livro (titulo, preco, id_autor) VALUES ('Livro Inválido', 50.00, 999);

-- Ex. 3 Cadastre registros de teste: um autor sem livros e, se o esquema permitir, um livro sem autor.

-- Autor sem livros
INSERT INTO autor (nome) VALUES ('Marina Costa');

-- Livro sem autor
INSERT INTO livro (titulo, ano_publicacao, preco, quantidade, id_autor)
VALUES ('Compiladores Modernos', 2023, 110.00, 6, NULL);

-- Ex. 4 Use INNER JOIN para retornar título e autor, em ordem alfabética.

-- Retorna so registro com correspondeicia igual, ordenado alfabeticamente.
SELECT 
    l.titulo, 
    a.nome AS autor
FROM livro AS l
INNER JOIN autor AS a ON l.id_autor = a.id
ORDER BY a.nome ASC, l.titulo ASC;

-- Ex. 5 Use LEFT JOIN para listar todos os autores. Explique os NULL retornados.

-- Retorna todos os autores
-- NULL: Para autores sem livros vinculados, as colunas da tabela 'livro' retornam como NULL pq nao existe registro nelas
SELECT 
    a.nome AS autor, 
    l.titulo
FROM autor AS a
LEFT JOIN livro AS l ON l.id_autor = a.id
ORDER BY a.nome ASC;

-- Ex. 6 Reescreva o exercício 5 com RIGHT JOIN e compare os resultados.

-- O resultado e exatamente o mesmo, pq 'autor' ta a direita
SELECT 
    a.nome AS autor, 
    l.titulo
FROM livro AS l
RIGHT JOIN autor AS a ON l.id_autor = a.id
ORDER BY a.nome ASC;

-- Ex. 7 Localize livros sem autor. Explique a diferença para uma referência inválida barrada pela FK.

-- id_autor NULL nesse caso é valido pq foi definido como NULL ao invez de NOT NULL
-- Uma ref invalida e rejeitada pelo SGBD via FK (erro 1452)
-- pq tenta criar uma relacao com uma entidade que n existe
SELECT 
    l.id, 
    l.titulo, 
    l.preco
FROM livro AS l
WHERE l.id_autor IS NULL;

-- Ex. 8 Conte livros por autor, incluindo autores sem livros, com COUNT(l.id) e GROUP BY.

-- N podemos usar COUNT(*) pq ele conta a linha completa
SELECT 
    a.id, 
    a.nome AS autor,
    COUNT(l.id) AS total_livros
FROM autor AS a
LEFT JOIN livro AS l ON l.id_autor = a.id
GROUP BY a.id, a.nome
ORDER BY total_livros DESC;

-- Ex. 9 · Filtrar grupos Autores com mais de um livro: HAVING COUNT(l.id) > 1.

-- Retorna apenas os autores com mais de 1 titulo cadastrado
SELECT 
    a.nome AS autor,
    COUNT(l.id) AS titulos
FROM autor AS a
LEFT JOIN livro AS l ON l.id_autor = a.id
GROUP BY a.id, a.nome
HAVING COUNT(l.id) > 1
ORDER BY titulos DESC;

-- Ex. 10 · Integrar Por autor: nome, quantidade de títulos, total de exemplares SUM(quantidade) e valor estimado de estoque
-- SUM(preco * quantidade), em ordem decrescente de valor.

-- Apresenta titulos, total de exemplares e valor em estoque estimado por autor.
-- COALESCE converte o resultado de autores sem livros de NULL para 0.
SELECT 
    a.nome AS autor,
    COUNT(l.id) AS titulos,
    COALESCE(SUM(l.quantidade), 0) AS exemplares,
    COALESCE(SUM(l.preco * l.quantidade), 0.00) AS valor_estoque
FROM autor AS a
LEFT JOIN livro AS l ON l.id_autor = a.id
GROUP BY a.id, a.nome
ORDER BY valor_estoque DESC;