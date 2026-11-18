<?php

require_once __DIR__ . '/../Model/Livro.php';

final class LivroRepository
{
    public function __construct(private PDO $pdo) {}

    // Lista todos os livros ordenados por título (Exercício 05)
    // @return Livro[]
    
    public function listar(): array
    {
        $stmt = $this->pdo->query('SELECT id, titulo, preco, isbn, ano_publicacao, quantidade, id_autor FROM livro ORDER BY titulo');
        $linhas = $stmt->fetchAll();

        return array_map(fn($linha) => new Livro(
            id: (int) $linha['id'],
            titulo: $linha['titulo'],
            preco: (float) $linha['preco'],
            isbn: $linha['isbn'],
            anoPublicacao: $linha['ano_publicacao'] !== null ? (int) $linha['ano_publicacao'] : null,
            quantidade: (int) $linha['quantidade'],
            idAutor: $linha['id_autor'] !== null ? (int) $linha['id_autor'] : null
        ), $linhas);
    }

    // (Exercício 06)

    public function buscarPorId(int $id): ?Livro
    {
        $stmt = $this->pdo->prepare('SELECT id, titulo, preco, isbn, ano_publicacao, quantidade, id_autor FROM livro WHERE id = :id');
        $stmt->bindValue(':id', $id, PDO::PARAM_INT);
        $stmt->execute();

        $linha = $stmt->fetch();
        if ($linha === false) {
            return null;
        }

        return new Livro(
            id: (int) $linha['id'],
            titulo: $linha['titulo'],
            preco: (float) $linha['preco'],
            isbn: $linha['isbn'],
            anoPublicacao: $linha['ano_publicacao'] !== null ? (int) $linha['ano_publicacao'] : null,
            quantidade: (int) $linha['quantidade'],
            idAutor: $linha['id_autor'] !== null ? (int) $linha['id_autor'] : null
        );
    }

    //(Exercício 07)
    
    public function cadastrar(string $titulo, float $preco, ?string $isbn = null, ?int $ano = null, int $qtd = 0, ?int $idAutor = null): bool
    {
        $sql = 'INSERT INTO livro (titulo, isbn, ano_publicacao, preco, quantidade, id_autor) 
                VALUES (:titulo, :isbn, :ano, :preco, :qtd, :autor)';

        $stmt = $this->pdo->prepare($sql);
        return $stmt->execute([
            ':titulo' => $titulo,
            ':isbn'   => $isbn,
            ':ano'    => $ano,
            ':preco'  => $preco,
            ':qtd'    => $qtd,
            ':autor'  => $idAutor
        ]);
    }
}