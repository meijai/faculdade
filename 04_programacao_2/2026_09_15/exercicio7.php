<?php

class Funcionario
{
    public $nome;
    public $salario;

    public function reajustarSalario($porcentagem)
    {
        $aumento = $this->salario * $porcentagem / 100;

        $this->salario = $this->salario + $aumento;
    }
}

$funcionario = new Funcionario();

$funcionario->nome = "João";
$funcionario->salario = 2000;

$funcionario->reajustarSalario(10);

echo "Nome: " . $funcionario->nome . PHP_EOL;
echo "Novo salário: R$ " . $funcionario->salario;

?>