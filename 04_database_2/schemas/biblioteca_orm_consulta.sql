SELECT l.id AS livro_id, l.titulo,
 a.id AS autor_id, a.nome AS autor
FROM livros l
JOIN livros_autores la ON la.livro_id = l.id
JOIN autores a ON a.id = la.autor_id
ORDER BY l.id, a.nome;

SELECT l.id, l.titulo, e.id AS exemplar_id,
 e.codigo_patrimonio, e.status
FROM livros l
LEFT JOIN exemplares e ON e.livro_id = l.id
ORDER BY l.id, e.id;