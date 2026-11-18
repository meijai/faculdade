<?php

class Carro
{
    public $marca;
    public $modelo;
    public $ano;

    public function exibirInfo()
    {
        echo "Marca: " . $this->marca . PHP_EOL;
        echo "Modelo: " . $this->modelo . PHP_EOL;
        echo "Ano: " . $this->ano . PHP_EOL;
    }
}

$carro = new Carro();

$carro->marca = "Toyota";
$carro->modelo = "Corolla";
$carro->ano = 2020;

$carro->exibirInfo();

?>