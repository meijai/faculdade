PDO: É uma extensão de baixo nível que fornece uma API comum para abrir ligações e executar comandos SQL, retornando apenas matrizes (arrays) ou objetos simples. Não conhece regras da aplicação nem mapeia relações de forma automatizada.

Repository: É um padrão arquitetural que apenas encapsula e organiza os comandos SQL em métodos específicos, convertendo manualmente os registos devolvidos em objetos

ORM: Uma biblioteca ORM completa automatiza o mapeamento direto entre classes e tabelas. Ela gera os comandos SQL de forma transparente, controla o ciclo de vida dos objetos em memória e gere associações complexas entre tabelas sem a necessidade de o programador escrever SQL manual para cada operação.