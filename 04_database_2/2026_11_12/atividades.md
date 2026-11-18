# Respostas - Questões para Estudo e Discussão (ORM e MySQL)
**Disciplina:** Banco de Dados II  
**Tema:** Mapeamento Objeto-Relacional (ORM) e Modelagem

---

### 1. Por que a tabela `livros_autores` é necessária para representar a relação N:N entre livros e autores?
Pq o banco relacional n permite guardar uma lista de valores em uma unica colna. Como um livro pode ter varios autores e um autor varios livros, a tabela associativa quebra o relacionamento N:N em dois relacionamentos 1:N, guardando os pares `livro_id` e `autor_id`.

### 2. Como distinguir, em um resultado de JOIN, a repetição de uma entidade da existência de entidades distintas?
Pela chave primaria (ID). Se o `livro_id` for o mesmo em varias linhas, significa que eh o mesmo livro se repetindo para associar autores diferentes. Se o ID mudar, sao livros diferentes.

### 3. O que ocorre quando uma consulta LEFT JOIN não encontra exemplares para determinado livro?
O livro continua aparecendo no resultado, mas todas as colunas da tabela de exemplares vem com valor `NULL`. No codigo, isso deve virar uma colecao vazia, e n um exemplar com campos nulos.

### 4. Quais restrições de integridade devem permanecer no MySQL mesmo quando a aplicação utiliza ORM?
Todas as principais: `PRIMARY KEY`, `FOREIGN KEY`, `UNIQUE` e `NOT NULL`. O ORM valida no codigo, mas o banco de dados eh a ultima garantia de que os dados n ficarao corrompidos ou inconsistentes.

### 5. Qual é a diferença entre hidratar entidades completas e retornar resultados agregados?
* **Hidratar entidades:** Converter os registros do banco em instancias completas de objetos da classe (ex.: instanciar a classe `Livro` com todas as propriedades).
* **Resultados agregados:** Retornar dados calculados ou agrupados (ex.: `COUNT()`, `AVG()`), que servem para relatorios ou contadores e nao viram entidades de dominio.

### 6. Como o problema N+1 pode afetar uma listagem de livros e autores?
Ocorre quando o sistema faz 1 consulta para listar os livros e depois faz +1 consulta no banco para cada livro so para buscar seus autores. Para 100 livros, seraoo disparadas 101 consultas ($1 + 100$), sobrecarregando o banco e deixando o sistema lento.

### 7. De que maneira o EXPLAIN contribui para avaliar consultas executadas por um ORM?
Como o ORM esconde o SQL gerado, o comando `EXPLAIN` permite ver o plano de execucao real do MySQL, mostrando se a consulta esta usando indices ou fazendo varredura lenta na tabela inteira (*table scan*).

### 8. Qual a diferença de responsabilidade entre uma entidade de domínio e um repositório de persistência?
* **Entidade de domínio (`Livro`):** Cuida dos dados e das regras de negocio do objeto. N sabe nada sobre SQL ou banco de dados.
* **Repositório (`LivroRepository`):** Cuida exclusivamente do acesso ao banco (executar `SELECT`, `INSERT`, `UPDATE`, gerenciar conexoes e converter linhas em objetos).
