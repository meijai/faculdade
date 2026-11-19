> Nota: a formatacao visual deste README foi feita usando IA.

# Aula 10 – Views, Triggers e Procedures (MySQL 8.x)

Trabalho feito na cópia da base: `biblioteca_copia` (arquivo `biblioteca_copia.sql`).

## Exercício 3 – por que `vw_estoque_autor` não é atualizável?
Ela usa `GROUP BY` e agregações (`COUNT`, `SUM`). Cada linha da view resume várias linhas de `livro`, então não existe uma linha única para o MySQL alterar.

## Resultados esperados dos testes
| Teste | Resultado |
|---|---|
| UPDATE de preço do livro 1 | Linha nova em `auditoria_preco` (80 → 85) |
| INSERT com preço negativo | Erro: `Preco/quantidade invalidos` |
| `sp_retirar_estoque(1, 2)` | Estoque do livro 1 passa de 5 para 3 |
| `sp_retirar_estoque(1, 100)` | Erro: `Livro inexistente ou estoque insuficiente` |
| `sp_retirar_estoque(999, 1)` | Erro: `Livro inexistente ou estoque insuficiente` |
| `sp_retirar_estoque(1, 0)` | Erro: `Quantidade deve ser positiva` |

## Exercício 10 – Comparação

| | View | Trigger | Procedure |
|---|---|---|---|
| Finalidade | Expor uma consulta com nome | Reagir a um evento de linha | Executar uma rotina com parâmetros |
| Execução | Consultada como tabela | Automática (INSERT/UPDATE/DELETE) | Chamada com `CALL` |
| Vantagens | Reutiliza consultas, evita repetir JOIN | Auditoria e validação automáticas | Centraliza regras, aceita parâmetros |
| Limitações | Nem sempre é atualizável | Efeitos escondidos, difícil depurar, não faz COMMIT/ROLLBACK | Precisa ser chamada explicitamente |
| Impacto na arquitetura | Padroniza o acesso aos dados | Regras ficam no banco, fora do código PHP | Reduz SQL duplicado nas aplicações |

Exemplos neste trabalho: catálogo reutilizável → view; histórico de preço → trigger; retirada de estoque → procedure.
