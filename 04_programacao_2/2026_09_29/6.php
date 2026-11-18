<?php

class Config
{
    protected $parametros;

    public function __construct()
    {
        $this->parametros = array();
    }
}

class ConfigSistema extends Config
{
    public function adicionarParametro($nome, $valor)
    {
        $this->parametros[$nome] = $valor;
    }

    public function mostrarParametro($nome)
    {
        return $this->parametros[$nome];
    }
}

$config = new ConfigSistema();

$config->adicionarParametro("tema", "escuro");
$config->adicionarParametro("idioma", "portugues");

echo "Tema: " . $config->mostrarParametro("tema") . PHP_EOL;
echo "Idioma: " . $config->mostrarParametro("idioma");

?>