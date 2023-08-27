# Top-K-Elementos

# Descrição

Nesta primeira atividade de Algoritmos e Estrutura de Dados II, foi feito um programa usando a linguagem C++, que recebe um arquivo de texto contendo uma grande quantidade de palavras.

Esse programa vai armazenar cada palavra do arquivo.txt como chave de uma hash, que inclui um valor inteiro que indica a quantidade de vezes que essa palavra apareceu no arquivo, e ao final do programa serão mostradas as K palavras que mais tiveram ocorrência (no caso deste código, está pré-definido com 20 palavras).

## Objetivo

O mapeamento de todas as palavras de um texto e posteriormente a filtragem das palavras que mais aparecem, tem o objetivo de mostrar ao usuário o que tem de mais relevante com a lista dos principais termos, ajudando a criar uma ideia do que se trata o texto antes mesmo dele ser lido, além de também auxiliar no gerenciamento de informações.

## Implementação

- Primeiramente, o programa vai abrir o arquivo "stopwords.txt", e armazená-los em um vector de stop words, para ao longo da execução do código, o programa desconsiderar as stopwords para elementar as palavras mais frequentes, já que elas somente ajudam a formar os enunciados e não são as ideias principais.
- Após isso é aberto o arquivo "DomCasmurro.txt" (como pré-definido no código, mas pode ser qualquer outro texto), e no loop de leitura das palavras, elas vão sendo armazenadas como chaves (arrays) de uma hash (no caso, unordered_map), e a cada vez que essa palavra aparecer, o int do contador de palavras incrementa. Como o critério de ordenação são os valores a serem modificados e não as chaves de strings, é melhor para esse programa usar uma map não ordenada do que a map normal.
- E por último, é criado um heap (priority_queue) contendo string e int assim como a hash, que inicialmente pega os 20 primeiros itens encontrados na hash. Depois, um loop vai percorrer toda a hash, e o contador da palavra de cada iteração vai ser comparado com o contador da palavra com menos frequência do heap para atualizar os valores do resultado final.
- A inserção de itens na map e o método de verificação dos itens da heap possuem custo constante, porque quando o texto é mapeado para o armazenamento de palavras na hash e o incremento de seu int de frequência, somente possui o custo de acessar cada palavra, e não há mais custo para ordenar as palavras pelo valor da chave (string) que teria com o uso de uma map normal com ordenação. O método de classificar a heap também tem custo constante e menor do que o método anterior, já que agora não é mais necessário contar novamente as palavras que se repetiram, e apenas acessar o inteiro de frequência de cada uma.

```Observação```

Foram utilizadas duas structs (Item) para inicializar e orientar a ordenação das atribuições heap (priority_queue), uma onde compara os valores de contagem pegando a menor, e outra pegando a de maior valor.
## Arquivos

* ```main.cpp```: Arquivo e função principal do código;
* ```read.hpp```: Declaração das funções utilizadas;
* ```read.cpp```: Implementação das funções descritas no arquivo hpp;
* ```DomCasmurro.txt```: Arquivo com o texto a ser mapeado;
* ```stopwords.txt```: Arquivo com as stopwords a serem desconsideradas do mapeamento de palavras;
* ```Makefile```: Automatiza o processo de compilação;

## Funções

* ```void stopwords()```: A primeira função que executada na main, ela abre o arquivo das stopwords, e armazena todas em um vector de string (vector<string> stopword);
* ```bool ehstopword(string word)```: Função booleana que recebe uma palavra que está sendo verificada na função de mapeamento e retorna se ela é ou não uma stop word;
* ```void mapeamento()```: É a função responsável por colocar todas as palavras na hash. Inicialmente é aberto o arquivo de texto e depois começa um loop do tipo while para fazer a leitura, e essa função deixa todas as palavras em letra mínuscula e são retiradas pontuações como "(", ")", ".", "-". A palavra em questão vai ser testada, se não for vazia e nem stopword, é colocada como array do heap e o int de contagem é incrementado.
* ```void topKitens()```: Após o mapeamento e contagem de todas as palavras, um loop até 20 é iniciado para colocar os primeiros itens que estão na hash, sejam eles os maiores ou não, e então um novo loop é iniciado, e este vai percorrer palavra por palavra e comparar o contador de cada uma com a palavra da heap que apareceu menos. Se a palavra do loop tiver maior contador, a palavra com menos contagem é removida do heap e é substituída.
* ```void heapfinal()```: A função anterior usava um heap que ordenava os elementos crescentemente para facilitar as operações, essa função de heapfinal transfere os elementos da heap crescente e coloca em uma heap em ordem decrescente, e após isso é mostrado no terminal o resultado final de todas as operações do programa.

## Exemplos da execução

![Captura de tela 2023-08-24 201747](https://github.com/vramoscabral/Top-K-Elementos/assets/127407951/704612ab-261d-46a6-894f-c2c370782ce5)

![Captura de tela 2023-08-24 201831](https://github.com/vramoscabral/Top-K-Elementos/assets/127407951/024fd295-5833-4ad9-a089-bc4f38e0cd75)

Dois prints do terminal que mostram um exemplo de como estavam distribuídas as palavras dentro da hash.

![Captura de tela 2023-08-24 202704](https://github.com/vramoscabral/Top-K-Elementos/assets/127407951/e690ff59-89e5-4030-a94e-953abb6639ef)

Um print do resultado final com os Top K elementos (20, nesse caso) da heap. É o que aparece no terminal quando esse código é executado.


## Conclusão

O foco desse programa ao utilizar uma hash e posteriormente o heap, foi considerar as palavras (elementos) mais presentes no texto, logo o critério de comparação das operações foi o valor da contagem de vezes em que as palavras apareciam.

Esse programa permite que o usuário possa ter uma noção do que é mais relevante e crucial a fim de orientar no entendimento do texto todo e sobre o que ele trata.

## Compilação e Execução

Esse código possui um arquivo Makefile que realiza todo o procedimento de compilação e execução. Para tanto, temos as seguintes diretrizes de execução:


| Comando                |  Função                                                                                           |                     
| -----------------------| ------------------------------------------------------------------------------------------------- |
|  `make clean`          | Apaga a última compilação realizada contida na pasta build                                        |
|  `make`                | Executa a compilação do programa utilizando o gcc, e o resultado vai para a pasta build           |
|  `make run`            | Executa o programa da pasta build após a realização da compilação                                 |


# Contato

✉️ <i>vramoscabral2020@gmail.com</i>
