-- Resolução das Atividades Propostas - Banco de Dados II
-- Projeto: Biblioteca

USE biblioteca;

-- ==========================================
-- Exercícios 1 a 5: Inserir e Atualizar
-- ==========================================

-- 1. Inserir um novo autor e confirmar com SELECT
INSERT INTO autor (nome, nacionalidade) VALUES ('Ariano Suassuna', 'Brasileiro');
SELECT id, nome, nacionalidade FROM autor WHERE nome = 'Ariano Suassuna';

-- 2. Cadastrar três livros com referências válidas a autores
INSERT INTO livro (titulo, isbn, preco, quantidade, id_autor, ano_publicacao) VALUES
('O Alienista', '9788508153620', 45, 100, 1, '1882-01-01'),
('Quincas Borba', '9788508153621', 55, 80, 1, '1891-01-01'),
('Helena', '9788508153622', 40, 120, 1, '1876-01-01');

-- 3. Criar tabela auxiliar e preenchê-la com INSERT INTO ... SELECT
CREATE TABLE IF NOT EXISTS livro_apoio AS SELECT id, titulo, preco FROM livro WHERE 1=0;

INSERT INTO livro_apoio (id, titulo, preco)
SELECT id, titulo, preco FROM livro WHERE preco > 50;

-- 4. Atualizar o preço de um livro, verificando antes e depois
SELECT id, titulo, preco FROM livro WHERE id = 1;
UPDATE livro SET preco = 95 WHERE id = 1;
SELECT id, titulo, preco FROM livro WHERE id = 1;

-- 5. Reajustar condicionalmente preços e registrar quantas linhas foram afetadas
UPDATE livro SET preco = ROUND(preco * 1.10, 2) WHERE preco < 80;
SELECT ROW_COUNT() AS linhas_afetadas;

-- 6. Excluir um livro específico após conferir suas dependências
SELECT id, titulo FROM livro WHERE id = 9;
DELETE FROM livro WHERE id = 9;

-- 7. Consultar título, autor, preço e quantidade com JOIN
SELECT l.titulo, a.nome AS autor, l.preco, l.quantidade
FROM livro AS l
LEFT JOIN autor AS a ON a.id = l.id_autor
ORDER BY l.titulo;

-- 8. Produzir relatório de estoque por autor com GROUP BY e SUM
SELECT 
    a.nome AS autor, 
    COUNT(l.id) AS quantidade_titulos, 
    COALESCE(SUM(l.quantidade), 0) AS total_exemplares, 
    COALESCE(SUM(l.preco * l.quantidade), 0) AS valor_estoque
FROM autor AS a
LEFT JOIN livro AS l ON a.id = l.id_autor
GROUP BY a.id, a.nome
ORDER BY valor_estoque DESC;

-- 9. Testar ROLLBACK e COMMIT em atualização de estoque
START TRANSACTION;
UPDATE livro SET quantidade = quantidade - 1 WHERE id = 1 AND quantidade > 0;
SELECT ROW_COUNT() AS linhas_afetadas;
COMMIT;

-- ROLLBACK;
