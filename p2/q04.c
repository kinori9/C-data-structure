#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int     maxof(int human[], int people)
{
    int i;
    int max;

    max = human[0];
    for (i = 0; i < people; i++)
    {
        if (max < human[i])
            max = human[i];
    }
    return max;
}
int     main(void)
{
    int i;
    int n;
    int people;
    int *human;
    int result;

    srand(time(NULL));
    people = rand() % (20 + 1 - 5) + 5;
    human = calloc(people,sizeof(int));

    for(i = 0; i < people; i++)
    {
        int height;

        height = rand() % (190 + 1 - 160) + 160;
        human[i] = height;
    }
    result = maxof(human, people);
    printf("키 최댓값은 : %d",result);
    free(human);
    return 0;
}