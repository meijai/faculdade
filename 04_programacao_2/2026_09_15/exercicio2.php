<?php

class Aluno
{
    public $nome;
    public $media;

    public function verificarAprovacao()
    {
        if ($this->media >= 7) {
            return "Aprovado";
        } else {
            return "Reprovado";
        }
    }
}

$aluno = new Aluno();

$aluno->nome = "João";
$aluno->media = 8;

echo "Nome: " . $aluno->nome . PHP_EOL;
echo "Média: " . $aluno->media . PHP_EOL;
echo "Situação: " . $aluno->verificarAprovacao();

?>