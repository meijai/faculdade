# BibliotecaORM — Avaliação Prática de Programação II

**Acadêmico:** Bruno Furlan | **Matrícula:** 429274
**Disciplina:** Programação II | **Professor:** Leandro Otavio Cordova Vieira
**Instituição:** UNOESC — Ciência da Computação

Mini-ORM didático em PHP + MySQL para persistir as entidades de uma biblioteca (Livro, Autor, relação N:N).

## Estrutura da entrega

| Caminho | Conteúdo |
|---|---|
| `biblioteca_orm/` | Código-fonte do projeto (domínio, repositórios, SQL e testes) |
| `biblioteca_orm/sql/` | `schema.sql` (tabelas) e `seed.sql` (dados iniciais) |
| `biblioteca_orm/src/Domain/` | Entidades `Livro` e `Autor` |
| `biblioteca_orm/src/Infrastructure/` | `Conexao`, `RepositoryInterface`, `AbstractRepository`, `LivroRepository`, `AutorRepository` |
| `biblioteca_orm/tests/smoke.php` | Demonstração das 7 evidências exigidas |
| `diagramas/` | Diagramas de classes, entidade-relacionamento e sequência (PDF) |
| `RELATORIO_TECNICO.pdf` | Relatório técnico |
| `documentos_aula/` | Enunciado, artigo-tutorial e material de referência da aula |

## Como executar

Requisitos: PHP 8.2+ com `pdo_mysql` e MySQL/MariaDB (XAMPP).

```bash
cd biblioteca_orm
mysql -u root < sql/schema.sql
php tests/smoke.php
```

Mais detalhes em [biblioteca_orm/README.md](biblioteca_orm/README.md).

## Nota sobre o uso de IA

A formatação visual do PDF de entrega (`RELATORIO_TECNICO.pdf`) e deste README foi feita com auxílio de Inteligência Artificial.
