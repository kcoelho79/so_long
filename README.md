# Projeto so_long

Desenvolvimento de um Jogo em 2d, utilizando a linguagem C, com o objetivo de estudar a biblioteca Minilibx (Interface para X-Windows) e a mecânica na criação de um jogo simples.
O resultado final é uma jogo em 2d, na qual o personagem tem que coletar todos os itens, e ir para saída.
o Personagem se movimenta com as teclas WSAD.

## Sobre a biblioteca Minilibx

Minilibx (MLX) é uma interface para X-Windows (servidor de janela) para , para criar aplicativos gráficos, 
com a MLX é oferece um caminho fácil para criar janelas, desenhar imagens, e gerenciar eventos do teclado e mouse,
keyrelease, etc.).

[Documento Manual](https://harm-smits.github.io/42docs/libs/minilibx/getting_started.html)

### Requerimentos no Linux
* gcc
* make
* X11 include files (package xorg)
* XShm extension must be present (package libxext-dev)
* Utility functions from BSD systems - development files (package libbsd-dev)

'sudo apt-get install gcc make xorg libxext-dev libbsd-dev (Debian/Ubuntu)'
[Download MiniLibx](https://github.com/42Paris/minilibx-linux)


## Como internamente a Minilibx (MLX) desenha na tela
Na Minilibx criamos uma janela de uma dimensão em Pixel informada, o Servidor X alocará um endereço de memória para cada pixel. Esse enderecamento receberá um valor em bits que representa a cor. O Servidor varrera essa tela, lendo as posições de memória dos pixel pegando as cores, e acendendo o pixel na tela, criando assim as imagens.

O que fazemos, e gravar no enderecámento de cada pixel a cor RGB que queremos desenhar, as funções da Minilibx ajuda nesse processo.

## Alguns Conceitos games 2D

### tiles
São pequenas imagens, geralmente no formato quadrado 40x40, 256x256, etc. ,a combinação dessas imagens compoe um cenário de jogo,
podemos entender de tiles, como se fosse tijolos e a sua combinação criar uma parede.

### tiles set
é um conjunto de tiles, um Tileset são todas imagens necessárias para criar o jogo.

### sprites
São imagens Bidimensionais, que se move interagindo com o cenário, por exemplo no Jogo Mario Bross a tartaruga,
o proprio Mario são sprites. 

### sprites sheets
É uma imagem que contem várias pequenos imagens (sprites), que se combinando em sequencia gera um sprite animado,
é como se o sprite fosse fotos e combinado essas fotos em sequencia terá um video (sprite sheets) como resultado final.

### pixels
É um ponto na tela, um conjunto de pixel gera uma imagem.

## Estrutura de pasta so_long
img > os sprites
map > mapa do jogo com a extensão ber
inc > header
mlx > biblioteca Minilibix
src > código do jogo
obj > objetos copilado do jogo
so_long > executável, gerado pelo make

## Funções 

* load_map  : lê o arquivo.ber e salva na var fber
* game_init : inicializa as variáveis com 0
*  map_init  : criar a matrix de 2 dimensão do game, salvando as coord. na var game->map, que servirá para a movimentação e a posição dos sprites, dos tiles, para depois ser renderizado
*  windows_init : inicializar a conexão X-Windows e cria a janela do game, carrega os sprites.
*  game_render	: desenha pixel por pixel de cada tile na tela.
* events	: recebe os eventos do teclado e do mouse.
 

## Como jogar

objetivo do jogar, é coletar todos os galões de combustivel, e depois pegar o helicoptero.
 
 `make`
 `./so_long maps/map.ber`

W = move o jogador para cima
S = move o jogador para baixo
A = move o jogador para esquerda
D = move o jogador para direita
ESC = sai do jogo

