<?php

class Produto1
{
    public $nome;
    public $preco;
}

$produto = new Produto1();

$produto->nome = "Teclado";
$produto->preco = 100;

echo "Nome: " . $produto->nome . PHP_EOL;
echo "Preço: R$ " . $produto->preco;

?>