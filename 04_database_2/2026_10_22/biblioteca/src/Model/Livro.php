<?php

final class Livro
{
    public function __construct(
        public readonly int $id,
        public string $titulo,
        public float $preco,
        public ?string $isbn = null,
        public ?int $anoPublicacao = null,
        public int $quantidade = 0,
        public ?int $idAutor = null
    ) {}
}