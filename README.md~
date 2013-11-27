Projeto 2
Sergio Rodrigues de Oliveira Filho
RA: 035949

A chamada de sistema implementada faz uso do espaço de kernel para armazenar e recuperar dados. A chamada é da seguinte forma:

asmlinkage long sys_kern_buf(int mode, void *p, int *b, size_t t);

O primeiro parametro mode define se a chamada será para armazenar dados (mode = 1), recuperar dados (mode = 2) ou liberar o espaço alocado (mode = 0).
O segundo parâmetro é um buffer no espaço do usuário. Para mode = 1 ele contém os dados a serem armazenaods, para mode = 2 ele indica a posição onde os dados devem ser salvos. Para mode = 0 este valor não é utilizado.
O terceiro parametro, para mode = 1, é um inteiro no espaço de usuário reservado para receber o endereço final dos dados armazenados, essa informação é devolvida como um inteiro, não como um ponteiro, para evitar problemas com endereços nas duas regiões. Para mode = 2, esse parametro indica a posição dos dados a serem recuperados na memória, esse valor é também um inteiro pelo mesmo motivo do caso anterior. Para mode = 0 é o endereço da memória a ser liberada.
O quarto parametro é o tamanho do dado a ser armazenado. Sua sintaxe é equivalente a do malloc.

Foi utilizado o espaço de kernel para que os dados fossem persistentes, mesmo depois do encerramento da aplicação. Assim é possível tranferir dados de uma aplicação a outra tendo o endereço de memória em mãos.

A chamada de sistema foi criada para utilizar o número 351.

Ela não utiliza outros arquivos como código fonte além do kern_buf.c, que foi adicionado a arch/x86/kernel

Foram criados 2 arquivos de teste. test.c armazena os seguintes dados na memória:
Um vetor de inteiros de 16 posições com o conteúdo 19, 65, 9, 17, 4, 1, 2, 6, 1, 9, 9, 2, 1, 1, 2, 4
Um vetor de 2 posições da estrutura cobaia descrita no código com os dados:
estrutura[0].key = 0;
estrutura[0].texto = "teste var 0";
estrutura[0].num = 27;

estrutura[1].key = 1;
estrutura[1].texto, "teste var 1";
estrutura[1].num = 27;

test2.c lê parametros da linha de comando. Se houver um só parametro ela libera a posição de memória indicada pelo parametro, se houver 2 parametros, se o primeiro for 1 ela recupera e imprime na tela os dados como se fosse um vetor de inteiros, se for 2 como um vetor da esrutura cobaia de 2 posições.

