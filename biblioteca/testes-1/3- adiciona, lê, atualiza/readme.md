# adiciona, lê, atualiza.
agora é possível ler todos os livros, assim como criar, atualizar ou deletar um livro específico. utilizando apenas a classe livro. basta criar a classe e os dados para leitores e administradores para que o programa seja, de fato, funcional.

### to-do obrigatórios:
- sobrecarga de operadores na hora de ler os livros e gravar para o .txt
- criacao das classes leitor (implementando a funcao de retirada de livro) e da classe administrador (com sistema de niveis de permissao, que permite o sistema de retirada e modificacao de livros)
- setters individuais ao inves de um metodo para atualizar o livro inteiro (ou usuario, no futuro)

#### to-do opcionais:
- mudança de logica 1: quando as funcoes de administração dos livros forem migradas para métodos do administrador, a lógica pode ser alterada para serem utilizadas apenas as sobrecargas de operador de leitura e escrita;
- mudança de logica 2: ao atualizar os livros, por exemplo, basta atualizar um objeto livro, e depois, colar os dados de todos os objetos para o arquivo de saída, ao invés de copiar de um arquivo para o outro.
