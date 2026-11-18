<?php

class ConversorTemperatura
{
    public function celsiusParaFahrenheit($celsius)
    {
        return ($celsius * 9 / 5) + 32;
    }

    public function fahrenheitParaCelsius($fahrenheit)
    {
        return ($fahrenheit - 32) * 5 / 9;
    }
}

$conversor = new ConversorTemperatura();


$celsius = 25;

$fahrenheit = $conversor->celsiusParaFahrenheit($celsius);

echo "25 graus Celsius = " . $fahrenheit . " graus Fahrenheit" . PHP_EOL;


$fahrenheit = 77;

$celsius = $conversor->fahrenheitParaCelsius($fahrenheit);

echo "77 graus Fahrenheit = " . $celsius . " graus Celsius";

?>