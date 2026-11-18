<?php

final class Database
{
    public static function conectar(): PDO
    {
        $dsn = 'mysql:host=127.0.0.1;port=3306;dbname=biblioteca;charset=utf8mb4';
        $user = 'root';
        $password = '123qwe';

        return new PDO($dsn, $user, $password, [
            PDO::ATTR_ERRMODE => PDO::ERRMODE_EXCEPTION,
            PDO::ATTR_DEFAULT_FETCH_MODE => PDO::FETCH_ASSOC,
            PDO::ATTR_EMULATE_PREPARES => false,
        ]);
    }
}