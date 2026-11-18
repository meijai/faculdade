<?php

class Contato
{
    public $nome;
    public $telefone;
    public $email;
}

$contato1 = new Contato();

$contato1->nome = "João";
$contato1->telefone = "99999-1111";
$contato1->email = "joao@email.com";


$contato2 = new Contato();

$contato2->nome = "Maria";
$contato2->telefone = "99999-2222";
$contato2->email = "maria@email.com";


$contato3 = new Contato();

$contato3->nome = "Pedro";
$contato3->telefone = "99999-3333";
$contato3->email = "pedro@email.com";


$contatos = [$contato1, $contato2, $contato3];

foreach ($contatos as $contato) {

    echo "Nome: " . $contato->nome . PHP_EOL;
    echo "Telefone: " . $contato->telefone . PHP_EOL;
    echo "Email: " . $contato->email . PHP_EOL;
    echo PHP_EOL;
}

?>