# Lista de Exercícios – Simulado – Capítulos 1, 2 e 3

## PARTE I: QUESTÕES TEÓRICAS E ANALÍTICAS

##### 1. Sensibilidade a Caixa (Case Sensitivity) e Identificadores em C (Cap. 1) — A linguagem C diferencia rigorosamente letras maiúsculas e minúsculas na formação de nomes de identificadores e palavras-chave. Com base nessa premissa, analise os pares de identificadores abaixo e assinale a alternativa correta:

a) Os nomes de variáveis 'numero' e 'Numero' referenciam o mesmo endereço de memória.
b) A palavra-chave 'Main' com 'M' maiúsculo é reconhecida pelo compilador como ponto de entrada válido.
**c) Todos os pares de nomes ('valor'/'VALOR', 'peso'/'Peso', 'taxa'/'TAXA') representam identificadores totalmente distintos para o compilador.**
d) A sensibilidade a caixa baixa/alta depende exclusivamente do sistema operacional utilizado na compilação.

Como o C diferencia maiúsculas de minúsculas, qualquer diferença de caixa gera um identificador diferente. A alternativa a) está errada porque `numero` e `Numero` são variáveis diferentes. A b) está errada porque o ponto de entrada é `main`, minúsculo. A d) está errada porque essa é uma regra da linguagem, não do sistema operacional.

##### 2. Especificadores de Formato, Sequências de Escape e Erros de Compilação (Cap. 1) — Um estudante iniciante escreveu o código C abaixo tentando imprimir mensagens formatadas com quebras de linha e tabulações, mas enfrentou erros de compilação. Identifique os três erros sintáticos/estruturais presentes no código:
```
#include <stdio.h>
#include <stdlib.h>;

int Main()
{
    int idade = 20;
    printf( A idade do aluno eh: %d anos.. , idade);
    cout << endl;
    system("PAUSE");
    return 0;
}
```

1. `printf( A idade do aluno eh: %d anos.. , idade);`: o texto deve estar entre aspas duplas.
2. `cout << endl;`: `cout` e `endl` são de C++ e não existem em C. Deve-se usar `printf("\n");`.
3. `int Main()`: o `main` deve ser escrito com letra minúscula.
4. Além desses, `#include <stdlib.h>;` tem um ponto e vírgula que não deve existir depois do include.

Código corrigido:
```
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int idade = 20;
    printf("A idade do aluno eh: %d anos.\n", idade);
    printf("\n");
    system("PAUSE");
    return 0;
}
```

##### 3. Operadores de Atribuição Composta e Avaliação Sequencial (Cap. 2) — Os operadores de atribuição em C executam suas ações da direita para a esquerda e podem ser combinados com operadores aritméticos. Determine os valores finais de a, b, c e d após a execução da sequência abaixo:
```
int a = 2, b = 4, c = 5, d = 10;
a += b + c;
b *= c = d - 2;
d %= a + 3;
a += b += c += 5;
```

| Instrução | Conta | Resultado |
| --- | --- | --- |
| `a += b + c;` | a = 2 + (4 + 5) | a = 11 |
| `b *= c = d - 2;` | c = 10 - 2 = 8; b = 4 * 8 | c = 8, b = 32 |
| `d %= a + 3;` | d = 10 % (11 + 3) = 10 % 14 | d = 10 |
| `a += b += c += 5;` | c = 8 + 5; b = 32 + 13; a = 11 + 45 | c = 13, b = 45, a = 56 |

Valores finais: **a = 56, b = 45, c = 13, d = 10**

##### 4. Avaliação de Expressões Lógicas, Relacionais e Precedência (Cap. 2) — Considere as variáveis inteiras i = 2, j = 3, k = 0 e as variáveis de ponto flutuante x = 2.5, y = 5.0. Avalie cada expressão abaixo e determine seu resultado lógico em C (1 para Verdadeiro, 0 para Falso):

| Expressão | Conta | Resultado |
| --- | --- | --- |
| a) `i < j + 2` | 2 < 5 | **1** |
| b) `2 * i - 5 <= j - 4` | -1 <= -1 | **1** |
| c) `!k && (x + y >= 7.5)` | 1 && 1 | **1** |
| d) `!(i == j) \|\| (y / x == 2.0)` | 1 \|\| 1 | **1** |
| e) `i == 2 && j == 4 \|\| k == 0` | (1 && 0) \|\| 1 = 0 \|\| 1 | **1** |

A ordem de avaliação é: primeiro a conta, depois a comparação, depois o `&&` e por último o `||`.

##### 5. Estruturas de Repetição: Comparação entre for, while e do-while (Cap. 3) — As estruturas de repetição permitem a execução iterativa de instruções em C. Analise as características de for, while e do-while e responda fundamentadamente:

**a) Qual é a diferença essencial entre while e do-while em relação ao número mínimo de execuções do bloco de código e ao momento do teste condicional?**

O `while` testa **antes** de executar, então pode executar **0 vezes**. O `do-while` testa **depois**, então executa **pelo menos 1 vez**.

**b) Em que cenários o laço for se apresenta como a escolha mais elegante e legível frente ao laço while?**

Quando se sabe quantas vezes vai repetir, como em um contador de 1 até N. O `for` junta inicialização, teste e incremento em uma linha só.

**c) O trecho de código 'while (condicao);' (com ponto-e-vírgula ao final do cabeçalho) constitui um erro de compilação ou de lógica? O que acontece se condicao for verdadeira?**

É um **erro de lógica**, pois o código compila. O `;` vira o corpo do laço, que fica vazio. Se `condicao` for verdadeira, acontece um **loop infinito** e o programa trava.

##### 6. Escopo de Bloco e Comandos de Desvio (break e continue) (Cap. 3) — Analise o programa abaixo que calcula a soma acumulada de quadrados dentro de um laço for contendo um comando de desvio e controle de escopo interno:
```
#include <stdio.h>
#include <stdlib.h>
int main() {
    int i;
    for (i = 1; i <= 10; i++) {
        if (i == 5) continue;
        if (i == 8) break;
        int soma = 0;
        soma += i * i;
    }
    printf("Soma final = %d\n", soma);
    system("PAUSE");
    return 0;
}
```

**a) Por que o compilador emitirá um erro de compilação na instrução printf final?**

Porque `soma` foi declarada **dentro do bloco do `for`** e só existe dentro dele. No `printf`, que está fora do bloco, ela não existe mais.

**b) Quais iterações do laço serão efetivamente executadas e qual o impacto dos comandos continue e break no fluxo?**

As iterações executadas são i = 1, 2, 3, 4, 6 e 7. Em i = 5, o `continue` pula o resto dessa volta. Em i = 8, o `break` encerra o laço, e por isso 9 e 10 nunca acontecem.

**c) Reescreva o código corrigindo o escopo de 'soma' e apresente o resultado que será impresso no console.**

```
#include <stdio.h>
#include <stdlib.h>

int main() {
    int i;
    int soma = 0;

    for (i = 1; i <= 10; i++) {
        if (i == 5) continue;
        if (i == 8) break;
        soma += i * i;
    }

    printf("Soma final = %d\n", soma);
    system("PAUSE");
    return 0;
}
```

Saída: `Soma final = 115` (1 + 4 + 9 + 16 + 36 + 49)
