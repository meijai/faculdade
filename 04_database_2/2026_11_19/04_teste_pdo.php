    <?php
// Exercicio 9: chamando a sp_retirar_estoque pelo PHP/PDO
$pdo = new PDO(
    'mysql:host=127.0.0.1;dbname=biblioteca_copia;charset=utf8mb4',
    'root', '123qwe',
    [PDO::ATTR_ERRMODE => PDO::ERRMODE_EXCEPTION]
);

function retirar(PDO $pdo, int $id, int $qtd): void
{
    try {
        $stmt = $pdo->prepare('CALL sp_retirar_estoque(:id, :qtd)');
        $stmt->execute(['id' => $id, 'qtd' => $qtd]);
        $stmt->closeCursor();
        echo "OK: retirada de $qtd unidade(s) do livro $id\n";
    } catch (PDOException $e) {
        echo "ERRO (livro $id, qtd $qtd): " . $e->getMessage() . "\n";
    }
}

retirar($pdo, 1, 1);    // valida
retirar($pdo, 1, 100);  // estoque insuficiente
retirar($pdo, 999, 1);  // livro nao existe
retirar($pdo, 1, 0);    // quantidade invalida
