<?php

class ConexaoBD
{
    private function conectar()
    {
        return "Conexão realizada com o banco de dados";
    }

    public function getConexao()
    {
        return $this->conectar();
    }
}

$conexao = new ConexaoBD();

echo $conexao->getConexao();

?>