DROP SCHEMA IF EXISTS biblioteca_copia;
CREATE SCHEMA IF NOT EXISTS biblioteca_copia;
USE biblioteca_copia;

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