<?php

class Calculadora
{
    public function somar($numero1, $numero2)
    {
        return $numero1 + $numero2;
    }

    public function subtrair($numero1, $numero2)
    {
        return $numero1 - $numero2;
    }

    public function multiplicar($numero1, $numero2)
    {
        return $numero1 * $numero2;
    }

    public function dividir($numero1, $numero2)
    {
        return $numero1 / $numero2;
    }
}

$calculadora = new Calculadora();

echo "Soma: " . $calculadora->somar(10, 5) . PHP_EOL;
echo "Subtração: " . $calculadora->subtrair(10, 5) . PHP_EOL;
echo "Multiplicação: " . $calculadora->multiplicar(10, 5) . PHP_EOL;
echo "Divisão: " . $calculadora->dividir(10, 5);

?>