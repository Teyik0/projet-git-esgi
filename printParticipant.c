void printParticipant(Participant *participant)
{
    printf("NOM : %s\n", participant->lastName);
    printf("PRENOM : %s\n", participant->firstName);
    if (participant->repas == 0)
        participant->conjoint ? printf("REPAS : DEJEUNER x2 - 30$\n") : printf("REPAS : DEJEUNER x1 - 15$\n");
    else if (participant->repas == 1)
        participant->conjoint ? printf("REPAS : DINER x2 - 70$\n") : printf("REPAS : DINER x1 - 35$\n");
    else if (participant->repas == 2)
        participant->conjoint ? printf("REPAS : DEJEUNER&DINER x2 - 100$\n") : printf("REPAS : DEJEUNER&DINER x1 - 50$\n");
    if (participant->hotel == 0)
        printf("HOTEL : NON\n");
    else if (participant->hotel == 1)
        printf("HOTEL : 2 ETOILE\n");
    else if (participant->hotel == 2)
        printf("HOTEL : 3 ETOILE\n");
}