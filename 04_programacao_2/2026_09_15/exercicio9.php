<?php

class Livro
{
    public $titulo;
    public $autor;
    public $ano;
}

$livro1 = new Livro();

$livro1->titulo = "Livro 1";
$livro1->autor = "Autor 1";
$livro1->ano = 2010;


$livro2 = new Livro();

$livro2->titulo = "Livro 2";
$livro2->autor = "Autor 2";
$livro2->ano = 2018;


$livro3 = new Livro();

$livro3->titulo = "Livro 3";
$livro3->autor = "Autor 3";
$livro3->ano = 2020;


$livros = [$livro1, $livro2, $livro3];


foreach ($livros as $livro) {

    if ($livro->ano > 2015) {

        echo "Título: " . $livro->titulo . PHP_EOL;
        echo "Autor: " . $livro->autor . PHP_EOL;
        echo "Ano: " . $livro->ano . PHP_EOL;
        echo PHP_EOL;
    }
}

?>