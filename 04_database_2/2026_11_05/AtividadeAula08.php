<?php
final class LivroRepository {
    public function __construct(private PDO $pdo) {}

    //Ex. 06 - Buscar por ID
    public function buscarPorId(int $id): ?array {
        $stmt = $this->pdo->prepare('SELECT * FROM livro WHERE id = :id');
        $stmt->execute(['id' => $id]);
        
        $linha = $stmt->fetch(PDO::FETCH_ASSOC);
        return $linha === false ? null : $linha;
    }

    //Ex. 10 - Atualizar preço
    public function atualizarPreco(int $id, int $preco): bool {
        $stmt = $this->pdo->prepare('UPDATE livro SET preco = :preco WHERE id = :id');
        $stmt->execute(['preco' => $preco, 'id' => $id]);
        return $stmt->rowCount() > 0;
    }
    
    //Ex. 07 - Cadastrar com parâmetros nomeados
    public function cadastrar(string $titulo, string $isbn, int $id_autor, string $ano_publicacao, int $preco, int $quantidade): void {
        $sql = 'INSERT INTO livro (titulo, isbn, id_autor, ano_publicacao, preco, quantidade) 
                VALUES (:titulo, :isbn, :id_autor, :ano_publicacao, :preco, :quantidade)';
        $stmt = $this->pdo->prepare($sql);
        $stmt->execute([
            'titulo' => $titulo, 
            'isbn' => $isbn, 
            'id_autor' => $id_autor, 
            'ano_publicacao' => $ano_publicacao, 
            'preco' => $preco, 
            'quantidade' => $quantidade
        ]);
    }

    //Ex. 10 - Excluir registro
    public function excluir(int $id): bool {
        $stmt = $this->pdo->prepare('DELETE FROM livro WHERE id = :id');
        $stmt->execute(['id' => $id]);
        return $stmt->rowCount() > 0;
    }
}
?>
