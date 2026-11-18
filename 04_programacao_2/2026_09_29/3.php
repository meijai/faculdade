<?php

class ContaBancaria
{
    private $saldo;

    public function depositar($valor)
    {
        $this->saldo = $this->saldo + $valor;
    }

    public function sacar($valor)
    {
        $this->saldo = $this->saldo - $valor;
    }

    public function getSaldo()
    {
        return $this->saldo;
    }
}

$conta = new ContaBancaria();

$conta->depositar(1000);
$conta->sacar(300);

echo "Saldo: R$ " . $conta->getSaldo();

?>