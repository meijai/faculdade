# Cola da Apresentação — BibliotecaORM

**Acadêmico:** Bruno Furlan | **Matrícula:** 429274  
**Disciplina:** Programação II | **Professor:** Leandro Otavio Cordova Vieira  
**Instituição:** UNOESC — Ciência da Computação  

---

### [Slide 1] Capa
- **O que falar:** Apresentação do projeto BibliotecaORM, desenvolvido para persistência de livros e autores aplicando os conceitos de POO em PHP puro com MySQL.

---

### [Slide 2] 1. O que é o projeto?
- Um mini-ORM criado do zero em PHP 8 com PDO e MySQL, sem uso de frameworks externos.
- Focado na aplicação prática de Orientação a Objetos e persistência relacional.

---

### [Slide 3] 2. Separação de Camadas (Data Mapper)
- **Domínio (`src/Domain/`):** entidades `Livro` e `Autor`. Cuidam apenas dos dados, regras e validações. Não têm conhecimento de SQL nem de tabelas.
- **Infraestrutura (`src/Infrastructure/`):** conexão PDO (`Conexao`) e repositórios (`AbstractRepository`, `LivroRepository`, `AutorRepository`). São os únicos que lidam diretamente com o banco de dados.

---

### [Slide 4] 3. Conceitos de POO Aplicados
- **Encapsulamento:** propriedades privadas nas entidades. O `id` só pode ser atribuído uma única vez (`atribuirId()`), protegendo a identidade do objeto contra alterações indevidas.
- **Abstração e Herança:** `AbstractRepository` contém o CRUD básico reaproveitável (`buscar`, `listar`, `salvar`, `excluir`). As classes filhas só precisam definir o nome da tabela, as colunas e como converter linha do banco em objeto.
- **Polimorfismo:** `RepositoryInterface` define os métodos comuns. Podemos manipular qualquer repositório pelo mesmo contrato.
- **Relacionamento N:N:** livros e autores são vinculados pela tabela `livros_autores`, e a classe `Livro` guarda a lista de autores sem permitir duplicatas.

---

### [Slide 5] 4. Como o ORM salva os dados
- O método `salvar($entidade)` verifica se o objeto já tem `id`:
  - Se **não tem ID**: executa um `INSERT` parametrizado e atualiza o objeto com `lastInsertId()`.
  - Se **já tem ID**: executa automaticamente um `UPDATE`.
- Todas as consultas usam **Prepared Statements** para evitar SQL Injection.
- Operações de múltiplos passos usam **transações com rollback**, garantindo integridade referencial.

---

### [Slide 6] 5. Demonstração Prática (As 7 Evidências)
*(No terminal, rodar o comando: `php tests/smoke.php`)*
1. **Cadastro:** insere Livro e Autor com IDs gerados pelo MySQL.
2. **Busca por ID:** recupera o livro e recria o objeto com os tipos corretos.
3. **Atualização:** altera o título do livro e confirma o UPDATE no banco.
4. **Relação N:N:** vincula 2 autores ao livro e recupera a coleção sem duplicações.
5. **Polimorfismo:** usa uma mesma função para buscar registros em repositórios diferentes.
6. **Rollback:** simula um erro com autor inexistente e desfaz a gravação do livro.
7. **Restrição de FK:** mostra o banco bloqueando a exclusão de autor com vínculo ativo, seguida da exclusão controlada.

---

### [Slide 7] 6. Dificuldades Encontradas
- **Relação N:N:** Gerenciar a tabela `livros_autores` e carregar a coleção de autores no objeto `Livro` sem criar instâncias duplicadas na memória.
- **Transações e Integridade:** Tratar exceções de chave estrangeira com `rollBack()` para não deixar dados órfãos se a operação falhar no meio.
- **CRUD Genérico:** Fazer o método `salvar()` do `AbstractRepository` decidir sozinho entre `INSERT` e `UPDATE` pelo ID, mantendo o SQL 100% parametrizado.

---

## ❓ Cola de Respostas (Se o professor perguntar):
- **"Por que a classe Livro não tem SQL?"**  
  👉 *Resposta:* Para manter a camada de Domínio desacoplada da tecnologia de banco (padrão Data Mapper).
- **"Como o método `salvar()` decide entre INSERT e UPDATE?"**  
  👉 *Resposta:* Olhando se a propriedade `id` é nula (novo registro) ou se já possui um valor (registro existente).
- **"O que é hidratação?"**  
  👉 *Resposta:* É transformar o array associativo retornado pelo PDO em uma instância de objeto real da classe.
- **"O que acontece se tentar deletar um autor que tem livro vinculado?"**  
  👉 *Resposta:* O MySQL bloqueia a exclusão por causa da Foreign Key em `livros_autores` (código de erro 23000).
