/*
Nome: Federico
Cognome: Russo
Data e ora: 07-03/2024 9:30
Obiettivo:q
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DOMANDE 10

typedef struct {
    char domanda[256];
    char opzioni[4][100];
    int rispostaCorretta;
} Domanda;

void stampaMenu() {
    printf("1. Inizia una nuova partita\n");
    printf("2. Esci\n");
}

void stampaCongratulazioni() {
    printf("\n");
    printf("  ____                            _         _       _   _             \n");
    printf(" / ___|___  _ __  _ __   ___  ___(_) __ _  | |     | |_| |__   ___   \n");
    printf("| |   / _ \\| '_ \\| '_ \\ / _ \\/ __| |/ _` | | |     | __| '_ \\ / _ \\  \n");
    printf("| |__| (_) | | | | | | |  __/ (__| | (_| | | |___  | |_| | | |  __/  \n");
    printf(" \\____\\___/|_| |_|_| |_|\\___|\\___|_|\\__,_| |_____|  \\__|_| |_|\\___| \n");
    printf("\n");
}


void gioca(Domanda domande[], int totaleDomande) {
    char nickname[50];
    int punteggio = 0;
    int scelta;
    
    printf("Inserisci il tuo nickname: ");
    scanf("%s", nickname);
    getchar(); // Pulisce il buffer di input dopo la lettura del nickname

    for (int i = 0; i < totaleDomande; i++) {
        printf("\n%s\n", domande[i].domanda);
        for (int j = 0; j < 4; j++) {
            printf("%d. %s\n", j+1, domande[i].opzioni[j]);
        }
        printf("Inserisci la tua risposta (1-4, dove 4 per uscire): ");
        scanf("%d", &scelta);

        if (scelta == 4) {
            printf("\nHai deciso di uscire. Il tuo punteggio è: %d\n", punteggio);
            return;
        } else if (scelta == domande[i].rispostaCorretta) {
            punteggio++;
            printf("\nCorretto! Punteggio: %d\n", punteggio);
        } else {
            printf("\nSbagliato! Punteggio: %d\n", punteggio);
        }
    }

    printf("\nIl gioco è finito. Il tuo punteggio è: %d\n", punteggio);
    if (punteggio > totaleDomande / 2) {
        stampaCongratulazioni();
    }
}

int main() {
    Domanda domande[MAX_DOMANDE] = {
        {"Quale keyword si usa per dichiarare una variabile 'intera'?", {"int", "float", "string", "char"}, 1},
        {"Come si commenta una linea in C?", {"// commento", "/* commento */", "# commento", "-- commento"}, 1},
        {"Quale funzione si usa per allocare memoria dinamicamente?", {"malloc", "alloc", "new", "memory"}, 1},
        {"Come si dichiara una funzione che non ritorna nulla?", {"void", "null", "empty", "none"}, 1},
        {"Qual è l'operatore di indirizzo in C?", {"&", "*", "@", "^"}, 1},
        {"Come si dichiara un puntatore a char?", {"char*", "char[]", "*char", "&char"}, 1},
        {"Quale di questi è un ciclo in C?", {"for", "loop", "repeat", "do-while"}, 4},
        {"Quale header file è necessario per usare la funzione printf?", {"<stdio.h>", "<stdlib.h>", "<string.h>", "<math.h>"}, 1},
        {"Come inizializzi un array di 10 interi a zero?", {"int arr[10] = {0};", "int arr[] = {0,0,0,0,0,0,0,0,0,0};", "int arr[10] = {};","Tutte le precedenti"}, 4},
        {"Qual è il prototipo della funzione 'main' in C?", {"int main(void)", "void main()", "public static void main(String[] args)", "int main(int argc, char **argv)"}, 4}
    };

    int sceltaMenu;

    do {
        stampaMenu();
        printf("Scegli un'opzione: ");
        scanf("%d", &sceltaMenu);
        switch (sceltaMenu) {
            case 1:
                gioca(domande, MAX_DOMANDE);
                break;
            case 2:
                printf("Grazie per aver giocato!\n");
                break;
            default:
                printf("Opzione non valida.\n");
        }
    } while (sceltaMenu != 2);

    return 0;
}
