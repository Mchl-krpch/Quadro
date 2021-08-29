#include <iostream>
#include "Functions.h"

int main(int argc, char** argv)
{
    printf("\n# Main: Choose the Mode\n"
           "0.Solving\n"
           "1.Testing\n" );

    int Mode = -1;
    scanf("%d", &Mode);

    switch(Mode)
    {
        case SOLVING:
            printf("Main: solving\n");
            break;
        case TESTING:
            printf("Main: testing\n");
            break;
        default: // ОШИБКА
            printf("Main: Error. Incorrect Data//\n");
            return 0;
    }

    double
        a = 0,
        b = 0,
        c = 0,
        Root1 = 0,
        Root2 = 0;

    int ModeOfAnswer = -1;

    if (Mode == 0)
    {
        if (scanf("%lg %lg %lg", &a, &b, &c) == 3)
        {
            SolveEquation(a, b, c, &Root1, &Root2, &ModeOfAnswer);
        }
        else // Entered Letter (!)
        {
            ModeOfAnswer = 0;
            WritingAnswer(ModeOfAnswer, Root1, Root2);
            return 0;
        }
    }
    else
    {
        test(a, b, c, Root1, Root2, ModeOfAnswer);
    }

    WritingAnswer(ModeOfAnswer, Root1, Root2);

    return 0;
}
