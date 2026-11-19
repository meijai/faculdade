USE biblioteca_copia;

-- 1. view do catalogo (titulo, autor, preco e quantidade)
CREATE OR REPLACE VIEW vw_catalogo AS
SELECT l.id, l.titulo, a.nome AS autor,
       l.preco, l.quantidade,
       l.preco * l.quantidade AS valor_estoque
FROM livro AS l
LEFT JOIN autor AS a ON a.id = l.id_autor;

-- 2. view do estoque por autor (titulos, exemplares e valor total)
CREATE OR REPLACE VIEW vw_estoque_autor AS
SELECT a.id, a.nome AS autor,
       COUNT(l.id) AS titulos,
       COALESCE(SUM(l.quantidade), 0) AS exemplares,
       COALESCE(SUM(l.preco * l.quantidade), 0) AS valor_estoque
FROM autor a
LEFT JOIN livro l ON l.id_autor = a.id
GROUP BY a.id, a.nome;

-- 3. consultando as duas views
SELECT titulo, autor, preco
FROM vw_catalogo
WHERE quantidade > 0
ORDER BY titulo;

SELECT * FROM vw_estoque_autor;

-- por que a vw_estoque_autor nao e atualizavel?
-- porque usa GROUP BY e funcoes de agregacao (COUNT, SUM). cada linha da view
-- junta varias linhas de livro, entao o mysql nao sabe qual linha alterar.
