<?php

class Funcionario
{
    protected $salario;

    public function __construct($salario)
    {
        $this->salario = $salario;
    }
}

class Gerente extends Funcionario
{
    public function aumentarSalario($valor)
    {
        $this->salario = $this->salario + $valor;
    }

    public function getSalario()
    {
        return $this->salario;
    }
}

$gerente = new Gerente(3000);

$gerente->aumentarSalario(1000);

echo "Salário do gerente: R$ " . $gerente->getSalario();

?>