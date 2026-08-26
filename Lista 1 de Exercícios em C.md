##### 1. Escreva um programa completo em C que declare uma variável do tipo inteiro, atribua um valor a ela (como o seu ano de nascimento ou o ano letivo corrente) e a imprima na tela junto com uma mensagem de texto explicativa utilizando a função printf() com o especificador de formato correspondente.
```
#include <stdio.h>
	int main() {
		int idade = 21;
		printf("Idade: %d\n", idade);
		return 0;
	}
```
##### 2. Faça um programa em C que declare uma variável de ponto flutuante de precisão simples (float), atribua a ela um valor constante real de sua preferência (como o valor do número de Euler 'e' = 2.71828) e exiba o resultado no console formatado com exatamente três casas decimais de precisão.
```
#include <stdio.h>
	int main() {
		float pi = 3.14159;
		printf("O valor de Pi: %.3f\n", pi);
		return 0;
	}
```
##### 3. O uso correto de comentários é fundamental para documentar e tornar o código compreensível. Com base nos tipos de comentários estudados (múltiplas linhas e linha única), escreva um programa simples em C e documente-o de forma clara. Siga o modelo de formatação de código ilustrado abaixo:
```
 /* Esse programa mostra o uso de comentários em várias linhas
*e mostra também o uso de comentários em uma única linha/*
*
*Primeiro programa
***************************************************************/
/* Prog1.C */

#include <stdio.h> /* Para printf() */
#include <stdlib.h>/* Para system() */
int main() /* Função main */
{ /* início do corpo da função main */
printf("Primeiro programa."); /* Chamada à função printf */
system("PAUSE"); /* Chamada à função system */
return 0;
}/* Fim do corpo da função main */
```
Meu programa:
```
/* Exemplo de programa em C */
#include <stdio.h> // Biblioteca que controla a entrada e saída de dados(como o printf e scanf).
#include <stdlib.h> // Biblioteca para gerenciar memória, números aleatórios e dados em C.
#include <locale.h> // Biblioteca para a utilização de diferentes configurações regionais, como idioma e formatação de números.
	int main() { // Função principal (main) do programa.
			setlocale(LC_ALL, "Portuguese"); // Configura a localidade para português, permitindo o uso de caracteres especiais e formatação adequada.
		printf("Este é o número %d\n \a", 5); // Imprime a mensagem "Este é o número 5" no console e emite um som de alerta (beep) devido ao caractere especial \a.
		system("PAUSE"); // Pausa a execução do programa até que o usuário pressione uma tecla, permitindo que ele veja a saída antes de o programa terminar.
		return 0; // Retorna 0 para indicar que o programa terminou com sucesso.
	} // Fim da função main e do programa.
```
##### 4. Um estudante iniciante de programação em C escreveu o programa abaixo e encontrou diversos erros que impedem a sua compilação. Analise o código atentamente, aponte cada um dos erros presentes e escreva a versão corrigida e funcional desse programa: 
```
 #include <stdio.h>
#include <stdlib.h>; // Esse ponto e virgula é desnecessário e pode causar erro de compilação.
	int Main{} // o main deve ser escrito com letra minúscula e com parênteses, como main().
	( // este parêntese de abertura não é necessário e deve ser removido.
		printf( Existem %d semanas no ano.,52); // A string deve estar entre aspas duplas.
		cout << endl; // cout não é definido em C, deve-se usar printf para imprimir no console.
		system("PAUSE");
		return 0;
	) // este parêntese de fechamento não é necessário e deve ser removido.
```
Código corrigido:
```#include <stdio.h>
`#include <stdlib.h>`
	`int main()` {`
		`printf("Existem %d semanas no ano.", 52);`
		`system("PAUSE");`
		`return 0;`
	}
```
##### 5. Analise o seguinte trecho de código em C. Sob a perspectiva do padrão ANSI C, o programa está correto para compilação e execução imediata? Caso negativo, descreva quais elementos cruciais e diretivas estão faltando no código abaixo:

```
main()
{
printf("Linguagem C");
system("pause");
}
```
Não está correto, pois não estão inclusos no código as bibliotecas que importam as funções de entrada e saída e as funções de gerenciamento de memória (`#include <stdio.h>` e `#include <stdlib.h>`). O main não possui tipo de retorno, e no padrão ANSI C a função principal deveria sempre ser declarada retornando um número inteiro `int main ()` e Como a função `main` deve ser do tipo `int`, é necessário incluir um `return 0;` no final do bloco de código para informar ao sistema operacional que o programa foi executado e encerrado com sucesso.

##### 6. Identifique e liste todos os erros de sintaxe (que violam as regras da linguagem C) e de lógica contidos no programa abaixo:
```
// Falta das bibliotecas #include <stdio.h> e <stdlib.h> para permitir o uso das funções printf e system.

main() // Falta do tipo de retorno da função main, que deve ser int.
{
int a=1; b=2; c=3: // Falta do ponto e vírgula (;) para separar as declarações das variáveis a, b e c, além de erro de sintaxe no uso dos dois pontos (:).
printf("0s números são: %d%d%d\n, a, b, c, d); // Falta do espacamento entre os números e a vírgula, além de erro na variável d que não foi declarada.
system("pause");
// Falta do return 0; para indicar que o programa terminou com sucesso.
// Falta do fechamento da chave } para encerrar a função main.
```
##### 7. Descreva a saída exata (incluindo quebras de linha e tabulações) que será impressa no console por cada uma das seguintes instruções independentes do printf():

a) printf("\n\tBom dia! Shirley.");
	```
	Bom dia! Shirley. 	```
b) printf("Você já tomou café? \n");
```Você já tomou café?```

c) printf("\n\nA solução não existe!\nNão insista.");


```A solução não existe!```
```Não insista. ```
d) printf("Duas\tlinhas\tde\tsaída\nou\tuma?");

```Duas linhas de saída```

```ou uma?```
e) printf("%s\n%s\n%s\n", "um", "dois", "três");
```um```
```dois```
```três```

##### 8. Explique detalhadamente o comportamento do programa abaixo quando executado no console. Apresente qual será a saída exata gerada pelas sequências de escape utilizadas no formato de controle: 
```
#include <stdio.h>
#include <stdlib.h>

int main()
{
	printf("\n\t\"Primeiro programa\"");
	system("PAUSE");
	return 0;
}
```

O programa imprime uma mensagem formatada no console e pausa a execução aguardando o usuário
- `\n` : Quebra de linha 
- `\t` : Tabulação 
- `\"` : Escapa as aspas duplas (permite imprimir as aspas na tela).


```

	"Primeiro programa"
Pressione qualquer tecla para continuar. . .
```

##### 9. Determine a saída exata do programa a seguir e explique como o compilador C interpreta os argumentos do tipo caractere simples ('\n', '\t', '\"') passados para o modificador %c:

O %c é usado para imprimir caracteres especiais, como nova linha (\n), tabulação (\t) e aspas (\\").

##### 10. A Linguagem C é conhecida por ser sensível a caixa alta e baixa (case sensitive). Explique o significado prático desse conceito. Identificadores como 'peso', 'Peso' e 'PESO' representam a mesma variável na memória? Assinale a alternativa correta e complemente com sua justificativa:

a) Depende exclusivamente da implementação do compilador utilizado no sistema.
**b) Verdadeiro (a linguagem C diferencia rigorosamente letras maiúsculas de minúsculas).**
c) Falso (letras maiúsculas e minúsculas são interpretadas como equivalentes pelo compilador).

##### 11. Para cada um dos valores constantes descritos na tabela abaixo, indique a classificação correta (por exemplo: constante inteira decimal, constante de ponto flutuante, constante de caractere,constante string ou sequência de escape) e o tipo de dado base correspondente em C (como char, int, float, double):

| Constante  | Classificação (Tipo de Constante)    | Tipo Base em C        |
| :--------- | :----------------------------------- | :-------------------- |
| `\r`       | Sequência de Escape (Caractere)      | `char`                |
| `2130`     | Inteiro (Decimal)                    | `int`                 |
| `-123`     | Inteiro (Decimal)                    | `int`                 |
| `33.28`    | Ponto Flutuante (Real)               | `double`              |
| `0XFA`     | Inteiro (Hexadecimal)                | `int`                 |
| `0101`     | Inteiro (Octal)                      | `int`                 |
| `2.0e30`   | Ponto Flutuante (Notação Científica) | `double`              |
| `\xDC`     | Sequência de Escape Hexadecimal      | `char`                |
| `'\"'`     | Caractere                            | `char`                |
| `'\\'`     | Caractere                            | `char`                |
| `'F'`      | Caractere                            | `char`                |
| `0`        | Inteiro (Decimal/Octal)              | `int`                 |
| `'\0'`     | Caractere (Nulo)                     | `char`                |
| `"F"`      | Cadeia de Caracteres (String)        | `char[]` (ou `char*`) |
| `-4567.89` | Ponto Flutuante (Real)               | `double`              |

##### 12. A declaração de variáveis define o tipo e o identificador de cada espaço reservado na memória. Analise cada uma das declarações na tabela a seguir, preencha o seu status (Correto ou Incorreto) e, caso seja incorreto, justifique detalhadamente o erro sintático:
| **Instrução**         | **Status (C/I)** | **Justificativa Teórica**                                                                                                                                            |
| --------------------- | ---------------- | -------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| `a) int a;`           | **Correto**      | Declaração padrão e válida de uma variável do tipo inteiro.                                                                                                          |
| `b) float b;`         | **Correto**      | Declaração padrão e válida de uma variável de ponto flutuante (precisão simples).                                                                                    |
| `c) double float c;`  | **Incorreto**    | Sintaxe inválida. Em C, usa-se `float` (precisão simples) ou `double` (precisão dupla). A combinação `double float` não existe.                                      |
| `d) unsigned char d;` | **Correto**      | Válido. O modificador `unsigned` indica que o `char` armazenará apenas valores positivos (geralmente de 0 a 255), muito usado para manipular bytes puros.            |
| `e) unsigned e;`      | **Correto**      | Válido. Quando o tipo base é omitido após um modificador como `unsigned`, o compilador do C assume implicitamente que se trata de um `unsigned int`.                 |
| `f) long float f;`    | **Incorreto**    | Sintaxe inválida no padrão C moderno. O tipo `long float` existia nas primeiras versões da linguagem, mas foi removido no padrão ANSI C (substituído pelo `double`). |
| `g) long g;`          | **Correto**      | Válido. Assim como no item "e", ao utilizar apenas o modificador `long`, o compilador entende implicitamente que é um `long int`.                                    |
| `h) long double h;`   | **Correto**      | Válido. O C suporta o tipo `long double` nativamente para representar números de ponto flutuante com precisão estendida (maior do que a do `double` padrão).         |

##### 13. No desenvolvimento de programas em C, o que são conceitualmente os arquivos de inclusão (headers com extensão .h)?

a) São bibliotecas pré-compiladas em formato binário contendo funções estruturadas.
b) São utilitários do sistema que realizam a linkedição dos programas.
**c) São arquivos de texto ASCII padrão contendo protótipos de funções, definições de constantes, macros etipos.**
d) São módulos de controle executados diretamente pelo microprocessador em tempo de execução.

##### 14. Qual é o papel e o objetivo principal do programador ao incluir arquivos de cabeçalho (como <stdio.h>)?

**a) Instruir o compilador a carregar as definições das funções da biblioteca padrão antes de compilar o código-fonte.**
b) Linkeditar os arquivos binários do projeto automaticamente.
c) Executar e testar as saídas de vídeo diretamente no console de depuração.
d) Converter automaticamente o código-fonte C em arquivos executáveis (.EXE).

##### 15. A diretiva `#include`, amplamente utilizada no topo dos arquivos C, é classificada como:

a) Uma instrução C nativa (compilada diretamente em linguagem de máquina).
b) Uma instrução específica de linguagens de programação orientadas a objetos.
**c) Uma diretiva especial para o pré-processador C, executada antes da compilação.**
d) Um objeto de classe de armazenamento dinâmico na memória heap.

##### 16. As diretivas de pré-processador em C (todas iniciadas com o caractere #) são lidas e interpretadas pelo:
a) Linkeditor do sistema no momento de montagem do arquivo executável final.
b) Microprocessador diretamente em tempo de execução.
**c) Pré-processador (fase do compilador que altera o programa-fonte antes da compilação propriamente dita).**
d) Depurador integrado da IDE durante os testes de execução.

##### 17.Dentre as instruções de escrita abaixo, quais estão sintaticamente corretas? O que essas variações demonstram sobre a flexibilidade de espaçamento e formatação do compilador C?

a) printf ( "Primeiro programa" );
b) printf( "Primeiro programa" );
**c) printf("Primeiro programa");**
d) printf "Primeiro programa" ;

##### 18. Desenvolva um programa completo em C que declare variáveis de ponto flutuante para os seguintes itens e seus preços unitários: Lápis (4.88), Borrachas (234.54), Canetas (42.04), Cadernos (8.00) e Fitas (13.05). Utilize a função printf() para exibir esses dados no console em formato de tabela, alinhados à direita, com largura mínima de campo de 12 caracteres e precisão de duas casas decimais, conforme a saída abaixo:
```
Lapis 4.88
Borrachas 234.54
Canetas 42.04
Cadernos 8.00
Fitas 13.05
```

```
#include<stdio.h>
#include<stdlib.h>
	int main(){

		float lapis = 4.88, borrachas = 234.54, canetas = 42.04, cadernos = 8.00, fitas = 13.05;

		printf("\nLapis %12.2f", lapis);
		printf("\nBorrachas %12.2f", borrachas);
		printf("\nCanetas %12.2f", canetas);
		printf("\nCadernos %12.2f", cadernos);
		printf("\nFitas %12.2f", fitas);
		system("PAUSE");
	return 0;
	}
```

##### 19. Questão 19. Escreva um programa em C que contenha uma única chamada de função para impressão(um único printf()) e produza exatamente a saída formatada abaixo com tabulação em cascata:
```
um
	dois
		três
```

Código: 
```
#include<stdio.h>
#include<stdlib.h>
	int main() {
		printf("\num\n\tdois\n\t\ttres");
		system("pause");
		return 0;
	}
```

##### 20. Caracteres gráficos baseados na tabela ASCII estendida (Codepage 437) podem ser usados para desenhar molduras e caixas de diálogo na tela de modo console. Desenvolva um programa em C que produza uma moldura simples com exatamente 4 caracteres de largura por 4 de altura. Dica: utilize constantes de caracteres em hexadecimal para representar os cantos e as retas horizontais/verticais:
```

Cantos Superiores: Esquerdo = \xC9, Direito = \xBB
Cantos Inferiores: Esquerdo = \xC8, Direito = \xBC
Linha Horizontal: \xCD, Linha Vertical: \xBA
```

```
#include <stdio.h>

int main() {
    printf("\xC9\xCD\xCD\xBB\n");
    printf("\xBA  \xBA\n");
    printf("\xBA  \xBA\n");
    printf("\xC8\xCD\xCD\xBC\n");
return 0;
}
```

##### 21. Questão 21. Desenvolva três versões independentes de programas em C para produzir no console a saída de texto abaixo. A primeira versão deve usar uma única chamada de printf(); a segunda deve usar exatamente duas instruções de impressão independentes; e a terceira deve desenhar as frases emolduradas utilizando caracteres gráficos de caixa:
```

Treinamento em programação.
Linguagem C.
```

Versão 1.0:
```
#include <stdio.h>

int main() {
    printf("Treinamento em programação.\nLinguagem C.\n");
    return 0;
}
```

Versão 2.0:
```
#include <stdio.h>

int main() {
    printf("Treinamento em programação.\n");
    printf("Linguagem C.\n");
    return 0;
}
```

Versão 3.0:
```
#include <stdio.h>

int main() {
    printf("┌─────────────────────────────┐\n");
    printf("│ Treinamento em programação. │\n");
    printf("│ Linguagem C.                │\n");
    printf("└─────────────────────────────┘\n");
    return 0;
}
```

##### 22.Desenhe no console um carro e uma caminhonete utilizando caracteres de bloco e de controle estudados no capítulo. Utilize sequências de escape em hexadecimal (como \xDC e \xDF) para
renderizar a seguinte arte gráfica:
```
▄▄████▄▄
  ▀O▀▀▀▀▀O▀
▄▄█ ██████
▀O▀▀▀▀▀OO▀
```

Código:
```
#include <stdio.h>

int main() {
    printf("\xDC\xDC\xDB\xDB\xDB\xDB\xDC\xDC\n");
    printf("\xDFO\xDF\xDF\xDF\xDF\xDFO\xDF\n");
    
    printf("\xDC\xDC\xDB \xDB\xDB\xDB\xDB\xDB\xDB\n");
    printf("\xDFO\xDF\xDF\xDF\xDF\xDFOO\xDF\n");
    
    return 0;
}
```

##### 23. Escreva um programa em C que exiba no console uma figura simples (como uma caixa retangular vazia de 5x5) formada inteiramente por uma letra de sua escolha (como 'X'), similar ao modelo a seguir:
```
XXXXX
X   X
X   X
X   X
XXXXX
```

Código:
```
#include <stdio.h>

int main() {
printf("XXXXX\nX\tX\nX\tX\nXXXXX\n");
return 0;
}
```

##### 24. Desenvolva um programa em C que organize dados de notas escolares em uma tabela no console. Seu programa deve usar especificadores de formato e largura de campos para que as colunas fiquem perfeitamente alinhadas, gerando a saída mostrada abaixo:
```
ALUNO(A) NOTA
========= =====
ALINE 9.0

MÁRIO DEZ
SÉRGIO 4.5
SHIRLEY 7.0
```
Código:
```
#include <stdio.h>

int main() {
    printf("%-9s %s\n", "ALUNO(A)", "NOTA");
    printf("%-9s %s\n", "=========", "=====");
    printf("%-9s %.1f\n", "ALINE", 9.0);
    printf("\n");
    printf("%-9s %s\n", "MÁRIO", "DEZ");
    printf("%-9s %.1f\n", "SÉRGIO", 4.5);
    printf("%-9s %.1f\n", "SHIRLEY", 7.0);

    return 0;
}
```

##### 25. Escreva um programa em C contendo uma única instrução printf() que desenhe a letra C em formato ampliado, utilizando a própria letra para a sua composição, conforme o modelo abaixo:
```
CCCCC
C
C
CCCCC
```

Código:
```
#include <stdio.h>

int main() {
    printf("CCCCC\nC\nC\nCCCCC\n");
    return 0;
}
```

##### 26. Elabore um programa em C que utilize caracteres para desenhar um 'pinheiro de Natal' estilizado no console. Enriqueça o desenho adicionando outros caracteres (como *, o, +) simulando enfeites espalhados pela árvore:
```
	X
   X*X
  X+XoX
 X*X+X*X
XXXXXXXXX
   XX
   XX
  XXXX
```

Código:
```
#include <stdio.h>
int main() {
    printf("    X\n");
    printf("   X*X\n");
    printf("  X+XoX\n");
    printf(" X*X+X*X\n");
    printf("XXXXXXXXX\n");
    printf("   XX\n");
    printf("   XX\n");
    printf("  XXXX\n");
return 0;
}
```

##### 27. Escreva um programa em C que solicite ao usuário (usando a função scanf()) um valor inteiro correspondente a um intervalo de tempo em segundos. O programa deve processar esse dado, calcular e exibir o equivalente formatado em Horas, Minutos e Segundos restantes (Exemplo: 3665 segundos correspondem a 1 hora, 1 minuto e 5 segundos).
Código:
```
#include <stdio.h>

int main() {
    int total_segundos, horas, minutos, segundos;

    printf("Digite o tempo em segundos: ");
    scanf("%d", &total_segundos);

    horas = total_segundos / 3600;
    minutos = (total_segundos % 3600) / 60;
    segundos = (total_segundos % 3600) % 60;

    printf("%d hora(s), %d minuto(s) e %d segundo(s)\n", horas, minutos, segundos);

    return 0;
}
```

##### 28. Desenvolva um programa em C que leia três valores numéricos inteiros fornecidos pelo usuário através do teclado, calcule a média aritmética simples desses valores como um número real de dupla precisão (double) e exiba o resultado final na tela formatado com exatamente duas casas decimais.
```
#include <stdio.h>

int main() {
    int num1, num2, num3;
    double media;

    printf("Digite o primeiro valor inteiro: ");
    scanf("%d", &num1);
    
    printf("Digite o segundo valor inteiro: ");
    scanf("%d", &num2);
    
    printf("Digite o terceiro valor inteiro: ");
    scanf("%d", &num3);

    // A divisão por 3.0 garante que o resultado seja tratado como ponto flutuante (double)
    media = (num1 + num2 + num3) / 3.0;

    printf("A media aritmetica: %.2lf\n", media);

    return 0;
}
```
