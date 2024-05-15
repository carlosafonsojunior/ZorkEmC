#include <stdio.h>
#include <string.h>
#include <locale.h>

struct Room {
	/*
	Um struct na linguagem de programação C é uma declaração de tipo de dado composto 
	que define uma lista de variáveis 
	fisicamente agrupadas sob um nome em um bloco	
	*/
    const char *description;  // ponteiro para armazenar a descrição da sala
    struct Room *north; //ponteiro da variavel Roon indicando o lado norte do Roon
    struct Room *south;
    struct Room *east;
    struct Room *west;
};

int main() {
	setlocale(LC_ALL, "Protuguese");
    // Definindo as salas
    struct Room room1 = {"Você está em uma sala escura.", NULL, NULL, NULL, NULL}; // os NULL representam as direções e estao nulas pra n afetar o direcionamento 
    struct Room room2 = {"Você está em uma sala iluminada.", NULL, NULL, NULL, NULL};
    struct Room room3 = {"Você está em uma sala misteriosa.", NULL, NULL, NULL, NULL};
    struct Room room4 = {"Você está em uma sala assustadora.", NULL, NULL, NULL, NULL};
    struct Room room5 = {"Você encontrou o tesouro! Parabéns!", NULL, NULL, NULL, NULL};

    // Conectando as salas
    room1.north = &room2;
    room2.south = &room1;

    room2.north = &room3;
    room2.east = &room4;
    room2.west = &room1;

    room3.south = &room2;

    room4.north = &room5;
    room4.west = &room2;

    struct Room *currentRoom = &room1;

    // Loop do jogo
    printf("Bem-vindo ao jogo! Você está na sala inicial.\n");
    char input[10];
    while (currentRoom != &room5) {
        printf("%s\n", currentRoom->description);
        printf("Para onde você quer ir? (norte, sul, leste, oeste)\n");

        scanf("%s", input);

        if (strcmp(input, "norte") == 0 && currentRoom->north != NULL) { // strcmp = string compare  compara a direção com o digitado pelo usiario n podendo apontar pra NULL
            currentRoom = currentRoom->north;
        } else if (strcmp(input, "sul") == 0 && currentRoom->south != NULL) {
            currentRoom = currentRoom->south;
        } else if (strcmp(input, "leste") == 0 && currentRoom->east != NULL) {
            currentRoom = currentRoom->east;
        } else if (strcmp(input, "oeste") == 0 && currentRoom->west != NULL) {
            currentRoom = currentRoom->west;
        } else {
            printf("Direção inválida! Tente novamente.\n");
        }
    }

    printf("%s\n", currentRoom->description);
    printf("Parabéns! Você encontrou o tesouro e venceu o jogo!\n");

    return 0;
}

