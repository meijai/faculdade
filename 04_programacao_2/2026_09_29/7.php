<?php

class Pedido
{
    private $itens;

    public function __construct()
    {
        $this->itens = array();
    }

    public function adicionarItem($item)
    {
        $this->itens[] = $item;
    }

    public function listarItens()
    {
        foreach ($this->itens as $item) {
            echo $item . PHP_EOL;
        }
    }
}

$pedido = new Pedido();

$pedido->adicionarItem("Mouse");
$pedido->adicionarItem("Teclado");
$pedido->adicionarItem("Monitor");

echo "Itens do pedido:" . PHP_EOL;

$pedido->listarItens();

?>