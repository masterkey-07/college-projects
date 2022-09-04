#include <stdio.h>

void verifyPoins(int *teamAPoints, int *teamBPoints, int teamAGoals, int teamBGoals)
{
    if (teamAGoals > teamBGoals)
        *teamAPoints += 3;
    else if (teamBGoals > teamAGoals)
        *teamBPoints += 3;
    else
    {
        (*teamAPoints)++;
        (*teamBPoints)++;
    }
}

int main()
{
    int teamAPoints, teamBPoints;

    int teamAGoals, teamBGoals;

    scanf("%d %d %d %d", &teamAPoints, &teamBPoints, &teamAGoals, &teamBGoals);

    verifyPoins(&teamAPoints, &teamBPoints, teamAGoals, teamBGoals);

    printf("%d %d", teamAPoints, teamBPoints);

    return 0;
}
