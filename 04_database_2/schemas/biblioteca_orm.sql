CREATE DATABASE biblioteca_orm;
USE biblioteca_orm;
CREATE TABLE autores (
 id INT AUTO_INCREMENT PRIMARY KEY,
 nome VARCHAR(150) NOT NULL,
 nacionalidade VARCHAR(80)
);
CREATE TABLE livros (
 id INT AUTO_INCREMENT PRIMARY KEY,
 titulo VARCHAR(200) NOT NULL,
 isbn VARCHAR(13) UNIQUE,
 ano_publicacao INT
);
CREATE TABLE livros_autores (
 livro_id INT NOT NULL,
 autor_id INT NOT NULL,
 PRIMARY KEY (livro_id, autor_id),
 FOREIGN KEY (livro_id) REFERENCES livros(id),
 FOREIGN KEY (autor_id) REFERENCES autores(id)
);
CREATE TABLE exemplares (
 id INT AUTO_INCREMENT PRIMARY KEY,
 livro_id INT NOT NULL,
 codigo_patrimonio VARCHAR(30) UNIQUE,
 status ENUM('disponivel','emprestado','manutencao')
 NOT NULL DEFAULT 'disponivel',
 FOREIGN KEY (livro_id) REFERENCES livros(id)
);
