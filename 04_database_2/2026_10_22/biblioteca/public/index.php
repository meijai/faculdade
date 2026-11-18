<?php

require_once __DIR__ . '/../config/Database.php';
require_once __DIR__ . '/../src/Repository/LivroRepository.php';

try {
    $pdo = Database::conectar();
    $repository = new LivroRepository($pdo);

    echo "<h1>Biblioteca MySQL</h1>";

    // (Exercício 07)
    // $repository->cadastrar('Dominando MySQL', 95.00, '9788575220000', 2025, 10, 1);

    // (Exercício 08)
    $buscaInexistente = $repository->buscarPorId(999);
    if ($buscaInexistente === null) {
        echo "<p><em>Registo de ID 999 verificado com sucesso: Livro não encontrado.</em></p>";
    }

    // (Exercício 05)
    echo "<h2>Livros disponíveis:</h2><ul>";
    foreach ($repository->listar() as $livro) {
        $titulo = htmlspecialchars($livro->titulo, ENT_QUOTES, 'UTF-8');
        echo "<li><strong>{$titulo}</strong> - R$ {$livro->preco} (Qtd: {$livro->quantidade})</li>";
    }
    echo "</ul>";

} catch (PDOException $e) {
    error_log('Erro na base de dados: ' . $e->getMessage());
    echo '<p style="color: red;">Não foi possível carregar as informações no momento.</p>';
}