INSERT INTO autores (nome) VALUES
('Machado de Assis'), ('Jose de Alencar'), ('Allan Kardec');
INSERT INTO livros (titulo, ano_publicacao) VALUES
('Dom Casmurro', 1899),
('Iracema', 1865),
('O Livro dos Espiritos', 1857);
INSERT INTO livros_autores (livro_id, autor_id)
VALUES (1,1), (2,2), (3,3);
INSERT INTO exemplares (livro_id, codigo_patrimonio)
VALUES (1,'PAT-001'), (1,'PAT-002'), (2,'PAT-003');
