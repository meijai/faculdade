<?php

class Cliente
{
    public $nome;
    protected $cpf;
    private $telefone;

    public function __construct($nome, $cpf, $telefone)
    {
        $this->nome = $nome;
        $this->cpf = $cpf;
        $this->telefone = $telefone;
    }

    public function mostrarDados()
    {
        echo "Nome: " . $this->nome . PHP_EOL;
        echo "CPF: " . $this->cpf . PHP_EOL;
        echo "Telefone: " . $this->telefone . PHP_EOL;
    }
}

$cliente = new Cliente(
    "Bruno",
    "123.456.789-00",
    "(49) 99999-9999"
);

echo "Nome: " . $cliente->nome . PHP_EOL;

echo PHP_EOL . "Dados do cliente:" . PHP_EOL;

$cliente->mostrarDados();

?>