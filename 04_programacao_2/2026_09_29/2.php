<?php

class Produto2
{
    public $nome;
    private $preco;

    public function getPreco()
    {
        return $this->preco;
    }

    public function setPreco($preco)
    {
        $this->preco = $preco;
    }
}

$produto = new Produto2();

$produto->nome = "Mouse";
$produto->setPreco(80);

echo "Nome: " . $produto->nome . PHP_EOL;
echo "Preço: R$ " . $produto->getPreco();

?>