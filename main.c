#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Participant
{
    char *lastName;
    char *firstName;
    int repas;    // 0 : DEJEUNER | 1 : REPAS | 2 : DEJEUNER & REPAS
    int hotel;    // 0 : PAS D'HOTEL | 1 : 2 ETOILES | 2: 3 ETOILES
    int conjoint; // 0 : NON | 1: OUI - COMPTER DEUX REPAS
};
typedef struct Participant Participant;

char *duplicateString(char *str);
Participant *newParticipant(char *lastName, char *firstName, int repas, int hotel, int conjoint);
unsigned int factureParticipant(Participant *participant);
void printParticipant(Participant *participant);
void freeParticipant(Participant *participant);

int main(int argc, char *argv[])
{
    Participant *p1 = newParticipant("SAMA", "Theo", 1, 1, 1);
    Participant *p2 = newParticipant("SAMA", "Oce", 0, 2, 1);
    Participant *p3 = newParticipant("SAMA", "Dinush", 2, 0, 0);
    printParticipant(p1);
    printParticipant(p2);
    printParticipant(p3);
    freeParticipant(p1);
    freeParticipant(p2);
    freeParticipant(p3);
}

Participant *newParticipant(char *lastName, char *firstName, int repas, int hotel, int conjoint)
{
    Participant *participant = malloc(sizeof(Participant));
    participant->lastName = duplicateString(lastName);
    participant->firstName = duplicateString(firstName);
    participant->repas = repas;
    participant->hotel = hotel;
    participant->conjoint = conjoint;
    return participant;
}

unsigned int factureParticipant(Participant *participant)
{
    unsigned int total = 0;
    if (participant->repas == 0)
        if (participant->conjoint)
            total += 30;
        else
            total += 15;

    else if (participant->repas == 1)
        if (participant->conjoint)
            total += 70;
        else
            total += 35;

    else if (participant->repas == 2)
        if (participant->conjoint)
            total += 100;
        else
            total += 50;

    if (participant->hotel == 0)
        printf("HOTEL : NON\n");
    else if (participant->hotel == 1)
        printf("HOTEL : 2 ETOILE\n");
    else if (participant->hotel == 2)
        printf("HOTEL : 3 ETOILE\n");
}

char *duplicateString(char *str)
{
    if (str == NULL)
        return NULL;
    int size = strlen(str);
    char *newStr = malloc(sizeof(char) * (size + 1));
    return strcpy(newStr, str);
}