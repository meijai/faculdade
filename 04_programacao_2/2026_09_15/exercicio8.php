<?php

class Item
{
    public $nome;
    public $preco;
    public $quantidade;
}

class Carrinho
{
    public $itens = [];

    public function adicionarItem($item)
    {
        $this->itens[] = $item;
    }

    public function calcularTotal()
    {
        $total = 0;

        foreach ($this->itens as $item) {
            $total = $total + ($item->preco * $item->quantidade);
        }

        return $total;
    }
}


$item1 = new Item();

$item1->nome = "Arroz";
$item1->preco = 25;
$item1->quantidade = 2;


$item2 = new Item();

$item2->nome = "Feijão";
$item2->preco = 8;
$item2->quantidade = 3;


$carrinho = new Carrinho();

$carrinho->adicionarItem($item1);
$carrinho->adicionarItem($item2);


echo "Total da compra: R$ " . $carrinho->calcularTotal();

?>