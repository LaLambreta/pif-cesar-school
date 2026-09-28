# Lista de Exercícios – Capítulo 3 – Laço de Repetição

## PARTE I: QUESTÕES TEÓRICAS E ANALÍTICAS

##### 1. Diferenças Fundamentais e Tempo de Avaliação de Laços — A linguagem C disponibiliza três estruturas de controle para execução iterativa de código: for, while e do-while. Analise o funcionamento dessas estruturas e responda:

**a) Qual é a diferença essencial entre as estruturas while e do-while em relação ao número mínimo de execuções do bloco de código e ao momento em que a condição de teste é avaliada?**

O `while` testa a condição **antes** de executar o bloco, então pode executar **0 vezes**. O `do-while` testa a condição **depois** de executar o bloco, então executa **pelo menos 1 vez**.

**b) Em que situações de programação cada uma das três estruturas (for, while e do-while) se apresenta como a escolha mais elegante, legível e adequada?**

- `for`: quando se sabe quantas vezes vai repetir (contador, de 1 até N).
- `while`: quando não se sabe quantas vezes vai repetir (ex.: ler valores até o usuário digitar um número de parada).
- `do-while`: quando o bloco precisa rodar pelo menos uma vez (ex.: menus e validação de entrada).

**c) Análise de código: O trecho 'while (condicao);' (com ponto-e-vírgula ao final) é um erro de compilação ou um erro de lógica? Explique detalhadamente o que ocorre durante a execução se condicao for verdadeira.**

É um **erro de lógica**, pois o código compila normalmente. O `;` vira o corpo do laço, que fica vazio. Se `condicao` for verdadeira, nada dentro do laço muda essa condição, então o programa entra em **loop infinito** e trava. O bloco `{ }` escrito abaixo não faz parte do laço.

##### 2. Escopo e Tempo de Vida de Variáveis de Bloco — Um estudante escreveu o programa abaixo com o intuito de calcular a soma dos quadrados dos números inteiros de 1 a 9, mas encontrou falhas durante a compilação e execução:
```
#include <stdio.h>
#include <stdlib.h>
int main() {
    int i;
    for (i = 1; i < 10; i++) {
        int soma = 0;
        soma += i * i;
    }
    printf("Soma final = %d\n", soma);
    system("PAUSE");
    return 0;
}
```

**a) Por que o compilador emitirá um erro de sintaxe/declaração na instrução printf final?**

Porque `soma` foi declarada **dentro do bloco do `for`**. Ela só existe dentro dessas chaves. O `printf` está fora do bloco, então para o compilador `soma` não foi declarada.

**b) Mesmo que a instrução printf fosse movida para dentro do bloco do laço for, por que o valor impresso para soma estaria conceitualmente incorreto a cada iteração?**

Porque `int soma = 0;` é executado **a cada volta** do laço. A variável é recriada e zerada toda vez, então nunca acumula: imprimiria apenas o quadrado do `i` daquela volta (1, 4, 9, ...), e não a soma.

**c) Apresente o código corrigido e explique o conceito de visibilidade, escopo de bloco e tempo de vida de variáveis na linguagem C.**

- **Escopo/visibilidade:** uma variável só pode ser usada dentro do bloco `{ }` onde foi declarada.
- **Tempo de vida:** ela é criada quando o programa entra no bloco e destruída quando sai dele.
- Por isso `soma` deve ser declarada **antes do `for`**, no bloco do `main`: assim ela existe durante todo o `main`, é zerada uma única vez e acumula os valores.

Código corrigido:
```
#include <stdio.h>
#include <stdlib.h>

int main() {
    int i;
    int soma = 0;                    // declarada fora do for: vale no main inteiro

    for (i = 1; i < 10; i++) {
        soma += i * i;               // acumula o quadrado de i
    }

    printf("Soma final = %d\n", soma);   // 285
    system("PAUSE");
    return 0;
}
```

Saída: `Soma final = 285`

##### 3. Flexibilidade do Laço for e Omissão de Expressões — A sintaxe do laço for em C consiste em três expressões separadas por ponto-e-vírgulas: inicialização, teste e incremento. Analise os três trechos de código abaixo:
```
// Trecho A: Incremento por divisão
for (a = 36; a > 0; a /= 2)
    printf("%d\t", a);

// Trecho B: Omissão de inicialização e incremento
for (; (ch = getch()) != 'X' ;)
    printf("%c", ch + 1);

// Trecho C: Omissão completa de expressões
for (;;)
    printf("Laço Infinito\n");
```

**a) Qual é a sequência exata de valores impressos no console ao executar o Trecho A?**

```
36	18	9	4	2	1
```
O `a` é dividido por 2 a cada volta (divisão inteira): 36 → 18 → 9 → 4 → 2 → 1 → 0. Quando chega em 0, o teste `a > 0` é falso e o laço para.

**b) Explique o comportamento do Trecho B. O que faz a operação 'ch + 1' e por que os parênteses em '(ch = getch())' são estritamente necessários antes da comparação com 'X'?**

O laço lê uma tecla com `getch()` (da biblioteca `conio.h`), guarda em `ch` e compara com `'X'`. Enquanto a tecla não for `X` maiúsculo, ele repete.

`ch + 1` imprime o **próximo caractere da tabela ASCII**: se digitar `a`, aparece `b`.

Os parênteses são necessários porque o `!=` tem **prioridade maior** que o `=`. Sem eles, o C faria `ch = (getch() != 'X')`, e `ch` receberia 1 ou 0 (resultado da comparação) em vez da tecla digitada.

**c) Como o programa pode interromper a execução do laço infinito do Trecho C de forma programática sem forçar o encerramento do processo pelo sistema operacional?**

Usando um `break` dentro do laço, com uma condição de parada:
```
for (;;) {
    printf("Laço Infinito\n");
    if (condicao_de_parada)
        break;
}
```

##### 4. Comandos de Desvio de Fluxo: break vs. continue — Os comandos break e continue são instruções de controle de desvio que alteram a execução normal de laços de repetição:

**a) Descreva a ação exata executada pelo programa quando o comando break é acionado dentro de um laço for ou while.**

O `break` **encerra o laço imediatamente**. O programa continua na primeira instrução depois do laço.

**b) Descreva a ação exata executada pelo programa quando o comando continue é acionado dentro de um laço for. Qual das três expressões do cabeçalho do for é executada imediatamente após o continue?**

O `continue` **pula o resto do bloco** e vai para a próxima volta. No `for`, a expressão executada logo depois é o **incremento** (ex.: `i++`), e em seguida o teste.

**c) Em uma estrutura de laços aninhados (um laço for interno dentro de outro laço for externo), qual laço é interrompido quando a instrução break é executada dentro do laço interno?**

Apenas o **laço interno**. O laço externo continua normalmente.

##### 5. Operador Vírgula e Múltiplas Variáveis de Controle — O operador vírgula (,) permite agrupar múltiplas expressões em um único comando, garantindo a avaliação da esquerda para a direita. Observe o trecho abaixo:
```
int i, j;
for (i = 0, j = 10; i < j; i++, j--) {
    printf("i = %d, j = %d | soma = %d\n", i, j, i + j);
}
```

**a) Exatamente quantas iterações o laço acima executará antes de ser encerrado?**

**5 iterações.** Quando `i = 5` e `j = 5`, o teste `5 < 5` é falso e o laço para.

**b) Escreva a saída exata produzida pelo comando printf em cada uma das iterações executadas.**

```
i = 0, j = 10 | soma = 10
i = 1, j = 9 | soma = 10
i = 2, j = 8 | soma = 10
i = 3, j = 7 | soma = 10
i = 4, j = 6 | soma = 10
```

**c) Reescreva a lógica deste mesmo laço utilizando obrigatoriamente a estrutura while.**

```
#include <stdio.h>

int main() {
    int i, j;

    i = 0;                           // inicializacao
    j = 10;
    while (i < j) {                  // teste
        printf("i = %d, j = %d | soma = %d\n", i, j, i + j);
        i++;                         // incremento
        j--;
    }
    return 0;
}
```

##### 6. Laço Sem Corpo e Incremento Pós-fixado — Analise o trecho de código abaixo que utiliza um laço de repetição com corpo vazio:
```
int x = 0;
while (x++ < 5);
printf("Valor final de x = %d\n", x);
```

**a) Qual é o valor final da variável x que será impresso pela instrução printf?**

`Valor final de x = 6`

**b) Explique passo a passo a sequência de incrementos e comparações lógicas que ocorrem durante a execução do teste 'x++ < 5'.**

No `x++` (pós-fixado), o C **primeiro compara** o valor atual e **depois soma 1**. Ele soma 1 até na comparação que dá falso.

| Compara | Resultado | x depois |
|---|---|---|
| 0 < 5 | verdadeiro | 1 |
| 1 < 5 | verdadeiro | 2 |
| 2 < 5 | verdadeiro | 3 |
| 3 < 5 | verdadeiro | 4 |
| 4 < 5 | verdadeiro | 5 |
| 5 < 5 | **falso** (sai do laço) | **6** |

**c) Reescreva esse código de forma explícita e clara (sem corpo vazio), mantendo exatamente o mesmo resultado final de x.**

```
#include <stdio.h>

int main() {
    int x = 0;

    while (x < 5) {
        x++;
    }
    x++;                             // o ultimo teste (5 < 5) tambem incrementava x

    printf("Valor final de x = %d\n", x);   // 6
    return 0;
}
```

## PARTE II: QUESTÕES PRÁTICAS DE IMPLEMENTAÇÃO

##### 7. Contagem Progressiva em Três Versões (for, while, do-while) — Desenvolva três programas independentes (ou três funções no mesmo arquivo) que mostrem na tela os números inteiros de 0 a 100 em ordem crescente. A primeira versão deve utilizar obrigatoriamente o laço for, a segunda versão a estrutura while, e a terceira versão a estrutura do-while. Em comentário ao final do código, responda: qual das três estruturas é a mais adequada para este caso e por quê?

Versão 1.0 (for):
```
#include <stdio.h>

int main() {
    int i;

    for (i = 0; i <= 100; i++) {
        printf("%d\n", i);
    }
    return 0;
}

// Resposta: o for e o mais adequado, porque ja sabemos onde comeca (0),
// onde termina (100) e o passo (1). Tudo fica em uma linha so.
```

Versão 2.0 (while):
```
#include <stdio.h>

int main() {
    int i = 0;

    while (i <= 100) {
        printf("%d\n", i);
        i++;
    }
    return 0;
}

// Resposta: o for e o mais adequado, porque ja sabemos onde comeca (0),
// onde termina (100) e o passo (1). Tudo fica em uma linha so.
```

Versão 3.0 (do-while):
```
#include <stdio.h>

int main() {
    int i = 0;

    do {
        printf("%d\n", i);
        i++;
    } while (i <= 100);
    return 0;
}

// Resposta: o for e o mais adequado, porque ja sabemos onde comeca (0),
// onde termina (100) e o passo (1). Tudo fica em uma linha so.
```

##### 8. Validação de Entrada de Dados com Laço Garantido (do-while) — Escreva um programa em C que solicite ao usuário que informe uma nota válida no intervalo fechado de 0.0 a 10.0. Caso o usuário digite um valor fora deste intervalo (por exemplo, -5.0 ou 12.5), o programa deve exibir uma mensagem de erro e repetir a solicitação usando a estrutura do-while. O programa só deve encerrar quando um valor válido for digitado, exibindo a mensagem 'Nota registrada com sucesso!'.

```
#include <stdio.h>

int main() {
    float nota;

    do {
        printf("Digite a nota (0.0 a 10.0): ");
        scanf("%f", &nota);
        if (nota < 0 || nota > 10)
            printf("Nota invalida!\n");
    } while (nota < 0 || nota > 10);     // repete enquanto for invalida

    printf("Nota registrada com sucesso!\n");
    return 0;
}
```

##### 9. Acumulador de Valores Reais com Sentinela de Parada Negativa — Faça um programa que permita ao usuário fornecer uma sequência indeterminada de valores reais positivos. O programa deve parar de solicitar valores no momento em que o usuário fornecer um valor negativo (que funcionará como sentinela de parada). Ao final, o programa deve exibir a quantidade de valores válidos digitados, a soma total e a média aritmética (garantindo que o valor negativo de parada não entre nos cálculos).

```
#include <stdio.h>

int main() {
    float valor, soma = 0;
    int qtd = 0;

    printf("Digite um valor (negativo para parar): ");
    scanf("%f", &valor);

    while (valor >= 0) {                 // o negativo para o laco e nao entra na conta
        soma += valor;
        qtd++;
        printf("Digite um valor (negativo para parar): ");
        scanf("%f", &valor);
    }

    printf("Quantidade: %d\n", qtd);
    printf("Soma: %.2f\n", soma);
    if (qtd > 0)                         // evita divisao por zero
        printf("Media: %.2f\n", soma / qtd);
    return 0;
}
```

##### 10. Geração de Múltiplos com Formatação em Colunas — Desenvolva um programa que determine e exiba no console os 100 primeiros múltiplos inteiros e positivos de 3 (isto é: 3, 6, 9, 12, ...). A saída deve ser formatada organizadamente em colunas contendo 10 números por linha separados por tabulação (\t).

```
#include <stdio.h>

int main() {
    int i;

    for (i = 1; i <= 100; i++) {
        printf("%d\t", i * 3);           // multiplo de 3
        if (i % 10 == 0)                 // a cada 10 numeros, pula a linha
            printf("\n");
    }
    return 0;
}
```

##### 11. Intervalo Numérico Dinâmico (Crescente e Decrescente) — Escreva um programa que leia dois números inteiros quaisquer, A e B, fornecidos pelo usuário. O programa deve imprimir todos os números inteiros situados no intervalo fechado entre A e B. Se A for menor ou igual a B, a impressão deve ser em ordem crescente; caso A seja maior que B, a impressão deve ser em ordem decrescente.

```
#include <stdio.h>

int main() {
    int a, b, i;

    printf("Digite A e B: ");
    scanf("%d %d", &a, &b);

    if (a <= b) {
        for (i = a; i <= b; i++)         // crescente
            printf("%d ", i);
    } else {
        for (i = a; i >= b; i--)         // decrescente
            printf("%d ", i);
    }
    printf("\n");
    return 0;
}
```

##### 12. Tabela de Conversão de Temperaturas (Celsius, Fahrenheit e Kelvin) — Crie um programa que imprima uma tabela de conversão de temperaturas de 0°C a 100°C, com variação de 5 em 5 graus Celsius. Para cada valor em Celsius, o programa deve calcular e exibir os valores equivalentes em Fahrenheit (F = (9*C)/5 + 32) e Kelvin (K = C + 273.15), utilizando formatação alinhada com duas casas decimais.

```
#include <stdio.h>

int main() {
    float c, f, k;

    printf("Celsius\t\tFahrenheit\tKelvin\n");
    for (c = 0; c <= 100; c += 5) {      // de 5 em 5 graus
        f = (9 * c) / 5 + 32;
        k = c + 273.15;
        printf("%7.2f\t\t%7.2f\t\t%7.2f\n", c, f, k);
    }
    return 0;
}
```

##### 13. Cálculo de Fatorial com Tratamento de Casos Especiais — Escreva um programa que leia um número inteiro N e calcule o seu fatorial (N!). Lembre-se de que 0! = 1 e 1! = 1. O programa deve utilizar o tipo de dado 'long long int' para evitar estouro de memória prematuro e deve exibir uma mensagem de erro caso o usuário forneça um número negativo.

```
#include <stdio.h>

int main() {
    int n, i;
    long long int fat = 1;               // comeca em 1 (0! = 1)

    printf("Digite N: ");
    scanf("%d", &n);

    if (n < 0) {
        printf("Erro: numero negativo!\n");
    } else {
        for (i = 1; i <= n; i++)
            fat = fat * i;
        printf("%d! = %lld\n", n, fat);  // %lld para long long int
    }
    return 0;
}
```

##### 14. Sequência de Quadrados e Acumulador Global — Desenvolva um programa que imprima todos os números inteiros de 1 a 100, acompanhados de seus respectivos quadrados (1 -> 1, 2 -> 4, 3 -> 9, ..., 100 -> 10000). Ao final da listagem, o programa deve calcular e exibir a soma total dos quadrados de todos esses 100 números.

```
#include <stdio.h>

int main() {
    int i, soma = 0;

    for (i = 1; i <= 100; i++) {
        printf("%d -> %d\n", i, i * i);
        soma += i * i;                   // acumula os quadrados
    }

    printf("Soma dos quadrados: %d\n", soma);
    return 0;
}
```

##### 15. Filtragem Numérica Simultânea com Operadores Lógicos — Criar um programa em C que solicite ao usuário um número limite inteiro positivo NUM. Em seguida, o programa deve imprimir todos os números no intervalo fechado de 1 até NUM que sejam múltiplos de 3 e de 5 ao mesmo tempo (por exemplo: 15, 30, 45, ...). Caso nenhum número satisfaça a condição, informe o usuário.

```
#include <stdio.h>

int main() {
    int num, i, qtd = 0;

    printf("Digite NUM: ");
    scanf("%d", &num);

    for (i = 1; i <= num; i++) {
        if (i % 3 == 0 && i % 5 == 0) {  // multiplo de 3 E de 5
            printf("%d ", i);
            qtd++;
        }
    }

    if (qtd == 0)
        printf("Nenhum numero encontrado.");
    printf("\n");
    return 0;
}
```

##### 16. Autenticação de Senha com Limite Finito de Tentativas — Desenvolva um sistema de autenticação que defina uma senha numérica secreta (ex: 2026). O programa deve permitir que o usuário tente digitar a senha no máximo 3 vezes. Se o usuário acertar a senha, o programa deve imprimir 'Acesso Concedido!' e o número de tentativas utilizadas, encerrando a execução. Se errar as 3 tentativas, o programa deve exibir 'Conta Bloqueada por Segurança!'.

```
#include <stdio.h>

int main() {
    int senha, i;

    for (i = 1; i <= 3; i++) {           // no maximo 3 tentativas
        printf("Digite a senha: ");
        scanf("%d", &senha);

        if (senha == 2026) {
            printf("Acesso Concedido! Tentativas: %d\n", i);
            return 0;                    // acertou: encerra
        }
    }

    printf("Conta Bloqueada por Seguranca!\n");
    return 0;
}
```

##### 17. Estatísticas de Turma (Menor, Maior, Média e Contagem) — Faça um programa para ler uma sequência de notas de alunos (valores reais de 0.0 a 10.0). A entrada de dados deve ser encerrada quando o usuário digitar a nota '-1.0'. Ao final, o programa deve exibir: a) Total de alunos avaliados; b) A maior nota da turma; c) A menor nota da turma; d) A média geral da turma.

```
#include <stdio.h>

int main() {
    float nota, soma = 0;
    float maior = 0, menor = 10;         // comecam nos extremos do intervalo
    int total = 0;

    printf("Digite a nota (-1 para sair): ");
    scanf("%f", &nota);

    while (nota != -1) {
        if (nota > maior) maior = nota;
        if (nota < menor) menor = nota;
        soma += nota;
        total++;
        printf("Digite a nota (-1 para sair): ");
        scanf("%f", &nota);
    }

    printf("Total de alunos: %d\n", total);
    if (total > 0) {
        printf("Maior nota: %.1f\n", maior);
        printf("Menor nota: %.1f\n", menor);
        printf("Media: %.2f\n", soma / total);
    }
    return 0;
}
```

##### 18. Inversão de Dígitos de um Número Inteiro (Algoritmo Numérico) — Elabore um programa que solicite ao usuário um número inteiro positivo (ex: 12345) e construa um novo número inteiro com os dígitos em ordem inversa (ex: 54321). Dica: utilize um laço enquanto o número for maior que zero, extraindo o último dígito com o operador resto (%) e reduzindo o número com a divisão inteira (/).

```
#include <stdio.h>

int main() {
    int n, invertido = 0;

    printf("Digite um numero positivo: ");
    scanf("%d", &n);

    while (n > 0) {
        invertido = invertido * 10 + n % 10;   // n % 10 pega o ultimo digito
        n = n / 10;                            // n / 10 remove o ultimo digito
    }

    printf("Invertido: %d\n", invertido);
    return 0;
}
```

##### 19. Cálculo do N-ésimo Termo da Sequência de Fibonacci — A sequência de Fibonacci é dada por: 1, 1, 2, 3, 5, 8, 13, 21, 34, ... onde cada termo a partir do terceiro é a soma dos dois anteriores. Escreva um programa que solicite ao usuário o número do termo desejado (N) e calcule e imprima o valor correspondente desse termo, além de listar todos os termos até N.

```
#include <stdio.h>

int main() {
    int n, i;
    int a = 1, b = 1, prox, termo = 1;

    printf("Digite N: ");
    scanf("%d", &n);

    printf("Termos: ");
    for (i = 1; i <= n; i++) {
        termo = a;
        printf("%d ", a);
        prox = a + b;                    // proximo = soma dos dois anteriores
        a = b;
        b = prox;
    }

    printf("\nO termo %d e: %d\n", n, termo);
    return 0;
}
```

##### 20. Tabela de Caracteres ASCII e Códigos Hexadecimais — Escreva um programa que utilize um laço for para imprimir a tabela de caracteres da tabela ASCII para os códigos decimais compreendidos entre 32 e 126 (caracteres imprimíveis). Para cada código, imprima o valor em decimal, o valor equivalente em hexadecimal (usando o formatador %X) e o próprio caractere visível.

```
#include <stdio.h>

int main() {
    int i;

    printf("Dec\tHex\tChar\n");
    for (i = 32; i <= 126; i++) {
        printf("%d\t%X\t%c\n", i, i, i); // %X = hexadecimal, %c = caractere
    }
    return 0;
}
```

##### 21. Jogo de Adivinhação com Letras Aleatórias e Dicas (rand()) — Desenvolva um jogo interativo em C que sorteie uma letra minúscula aleatória entre 'a' e 'z' usando a função rand() % 26 + 'a' da biblioteca <stdlib.h>. O programa deve pedir para o usuário adivinhar a letra. A cada tentativa errada, o programa deve informar se a letra secreta vem antes ou depois da letra digitada no alfabeto. Quando o usuário acertar, exiba uma mensagem de parabéns e o total de tentativas.

```
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    char secreta, palpite;
    int tentativas = 0;

    srand(time(NULL));                   // sem isso a letra sorteada seria sempre a mesma
    secreta = rand() % 26 + 'a';

    do {
        printf("Adivinhe a letra (a-z): ");
        scanf(" %c", &palpite);          // o espaco antes do %c ignora o ENTER
        tentativas++;

        if (palpite < secreta)
            printf("A letra secreta vem DEPOIS de %c\n", palpite);
        else if (palpite > secreta)
            printf("A letra secreta vem ANTES de %c\n", palpite);
    } while (palpite != secreta);

    printf("Parabens! Voce acertou em %d tentativa(s).\n", tentativas);
    return 0;
}
```

##### 22. Geração do Triângulo de Floyd com Laços Aninhados — Escreva um programa em C que leia um número inteiro positivo N e imprima N linhas do Triângulo de Floyd. Por exemplo, se N = 5, a saída na tela deve ser exatamente:
```
1
2 3
4 5 6
7 8 9 10
11 12 13 14 15
```

```
#include <stdio.h>

int main() {
    int n, i, j;
    int num = 1;                         // fora dos lacos: nao reinicia

    printf("Digite N: ");
    scanf("%d", &n);

    for (i = 1; i <= n; i++) {           // linhas
        for (j = 1; j <= i; j++) {       // a linha i tem i numeros
            printf("%d ", num);
            num++;
        }
        printf("\n");
    }
    return 0;
}
```

##### 23. Desenho de Moldura e Quadrado Vazado com Caracteres — Desenvolva um programa que solicite ao usuário a dimensão do lado de um quadrado L (com L entre 3 e 20). O programa deve utilizar laços aninhados para desenhar no console um quadrado vazado composto pelo caractere 'X'. Por exemplo, para L = 5, a saída deve ser:
```
XXXXX
X   X
X   X
X   X
XXXXX
```

```
#include <stdio.h>

int main() {
    int l, i, j;

    do {
        printf("Digite o lado (3 a 20): ");
        scanf("%d", &l);
    } while (l < 3 || l > 20);

    for (i = 1; i <= l; i++) {
        for (j = 1; j <= l; j++) {
            if (i == 1 || i == l || j == 1 || j == l)   // borda
                printf("X");
            else                                        // miolo
                printf(" ");
        }
        printf("\n");
    }
    return 0;
}
```

##### 24. Padrão Visual em X (Diagonais Cruzadas) — Crie um programa em C que solicite uma dimensão ímpar N (entre 3 e 19). O programa deve utilizar laços aninhados e condicionais lógicas para desenhar um padrão visual de duas diagonais que se cruzam no centro formando um 'X' com o caractere '*'. Por exemplo, para N = 5:
```
*   *
 * * 
  *  
 * * 
*   *
```

```
#include <stdio.h>

int main() {
    int n, i, j;

    do {
        printf("Digite um numero impar (3 a 19): ");
        scanf("%d", &n);
    } while (n < 3 || n > 19 || n % 2 == 0);

    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            if (j == i || j == n - i + 1)   // diagonal principal ou secundaria
                printf("*");
            else
                printf(" ");
        }
        printf("\n");
    }
    return 0;
}
```

##### 25. Análise e Teste de Primalidade de um Número Inteiro — Escreva um programa em C que receba um número inteiro positivo N e determine se N é um número primo. Um número é primo se for maior que 1 e divisível apenas por 1 e por ele mesmo. O programa deve contar a quantidade de divisores encontrados no laço e exibir uma mensagem conclusiva.

```
#include <stdio.h>

int main() {
    int n, i, divisores = 0;

    printf("Digite N: ");
    scanf("%d", &n);

    for (i = 1; i <= n; i++) {
        if (n % i == 0)                  // i divide n
            divisores++;
    }

    printf("Divisores encontrados: %d\n", divisores);
    if (divisores == 2)                  // primo: so 1 e ele mesmo
        printf("%d e primo.\n", n);
    else
        printf("%d nao e primo.\n", n);
    return 0;
}
```

##### 26. Mapeamento e Soma de Primos em um Intervalo Fechado [A, B] — Desenvolva um programa que solicite ao usuário dois números inteiros positivos A e B (garantindo A < B). O programa deve encontrar e listar todos os números primos situados no intervalo fechado [A, B], e ao final exibir a soma total de todos os primos encontrados nesse intervalo.

```
#include <stdio.h>

int main() {
    int a, b, n, i, divisores, soma = 0;

    do {
        printf("Digite A e B (A < B): ");
        scanf("%d %d", &a, &b);
    } while (a >= b);

    printf("Primos: ");
    for (n = a; n <= b; n++) {           // cada numero do intervalo
        divisores = 0;
        for (i = 1; i <= n; i++) {       // conta os divisores de n
            if (n % i == 0)
                divisores++;
        }
        if (divisores == 2) {
            printf("%d ", n);
            soma += n;
        }
    }

    printf("\nSoma dos primos: %d\n", soma);
    return 0;
}
```

##### 27. Simulador de Caixa Eletrônico (Decomposição de Cédulas) — Escreva um programa que simule o saque de um caixa eletrônico. O usuário informa o valor do saque em reais (número inteiro positivo). O programa deve calcular e exibir a menor quantidade de cédulas de R$ 100, R$ 50, R$ 20, R$ 10, R$ 5 e R$ 2 necessárias para compor o valor. Utilize laços de repetição para efetuar as subtrações sucessivas.

```
#include <stdio.h>

int main() {
    int valor;
    int c100 = 0, c50 = 0, c20 = 0, c10 = 0, c5 = 0, c2 = 0;

    printf("Valor do saque: R$ ");
    scanf("%d", &valor);

    // Se o valor for impar, usa UMA nota de 5 primeiro para ele ficar par.
    // Assim as notas de 2 sempre conseguem fechar a conta no final.
    if (valor % 2 == 1 && valor >= 5) {
        valor -= 5;
        c5++;
    }

    while (valor >= 100) { valor -= 100; c100++; }   // subtracoes sucessivas
    while (valor >= 50)  { valor -= 50;  c50++;  }
    while (valor >= 20)  { valor -= 20;  c20++;  }
    while (valor >= 10)  { valor -= 10;  c10++;  }
    while (valor >= 2)   { valor -= 2;   c2++;   }

    printf("R$ 100: %d\n", c100);
    printf("R$ 50: %d\n", c50);
    printf("R$ 20: %d\n", c20);
    printf("R$ 10: %d\n", c10);
    printf("R$ 5: %d\n", c5);
    printf("R$ 2: %d\n", c2);
    if (valor > 0)
        printf("Sobrou R$ %d que nao pode ser sacado.\n", valor);
    return 0;
}
```

##### 28. Sistema de Folha de Pagamento com Menu Contínuo (do-while & switch) — Desenvolva um programa completo para gerenciamento de folha de pagamento de uma empresa. O programa deve exibir um menu de opções em um laço do-while contínuo: 1. Reajuste Salarial (Calcula e exibe novo salário: 15% de aumento para salários até R$ 2.000,00 e 10% para salários superiores). 2. Retenção de Imposto de Renda (Calcula desconto: 8% para salários até R$ 3.000,00 e 15% para salários superiores). 3. Encerrar Programa. O programa deve validar as opções do menu e só finalizar a execução quando a opção 3 for expressamente selecionada.

```
#include <stdio.h>

int main() {
    int opcao;
    float salario;

    do {
        printf("\n1 - Reajuste Salarial\n");
        printf("2 - Imposto de Renda\n");
        printf("3 - Encerrar\n");
        printf("Opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Salario: ");
                scanf("%f", &salario);
                if (salario <= 2000)
                    printf("Novo salario: R$ %.2f\n", salario * 1.15);   // +15%
                else
                    printf("Novo salario: R$ %.2f\n", salario * 1.10);   // +10%
                break;
            case 2:
                printf("Salario: ");
                scanf("%f", &salario);
                if (salario <= 3000)
                    printf("Desconto de IR: R$ %.2f\n", salario * 0.08); // 8%
                else
                    printf("Desconto de IR: R$ %.2f\n", salario * 0.15); // 15%
                break;
            case 3:
                printf("Encerrando...\n");
                break;
            default:
                printf("Opcao invalida!\n");
        }
    } while (opcao != 3);                // so sai com a opcao 3

    return 0;
}
```
