<?php

class ContaBancaria
{
    public $titular;
    public $saldo;

    public function depositar($valor)
    {
        $this->saldo = $this->saldo + $valor;
    }

    public function sacar($valor)
    {
        if ($valor <= $this->saldo) {
            $this->saldo = $this->saldo - $valor;
        } else {
            echo "Saldo insuficiente!";
        }
    }
}

$conta = new ContaBancaria();

$conta->titular = "João";
$conta->saldo = 1000;

$conta->depositar(500);
$conta->sacar(200);

echo "Titular: " . $conta->titular . PHP_EOL;
echo "Saldo final: R$ " . $conta->saldo;

?>