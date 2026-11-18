<?php

class ContaBancaria
{
    private $saldo;

    public function __construct()
    {
        $this->saldo = 0;
    }

    public function depositar($valor)
    {
        $this->saldo = $this->saldo + $valor;
    }

    public function sacar($valor)
    {
        if ($valor <= $this->saldo) {
            $this->saldo = $this->saldo - $valor;
            echo "Saque realizado com sucesso!" . PHP_EOL;
        } else {
            echo "Saldo insuficiente!" . PHP_EOL;
        }
    }

    public function getSaldo()
    {
        return $this->saldo;
    }
}

$conta = new ContaBancaria();

$conta->depositar(500);

$conta->sacar(200);

echo "Saldo atual: R$ " . $conta->getSaldo();

?>