#include <cstdio>
#include <cmath>
#include <cassert>

#include "Functions.h"

int Equal(double number1, double number2)
{
    return fabs(number1 - number2) < SMALLDIFFERENCE;
}

void SolveEquation(double a, double b, double c, double* Root1, double* Root2, int* ModeOfAnswer)
{
    if (Equal(a, 0))
    {
        *ModeOfAnswer = SolveLinear(b, c, Root1);
    }
    else
    {
        *ModeOfAnswer = SolveSquare(a, b, c, Root1, Root2);
    }
}

int SolveLinear(double b, double c, double* Root1)
{
    if(Equal(b, 0))
    {
        if(Equal(c, 0))
        {
            return 4;
        }
        *Root1 = -c;
        return 2;
    }
    else
    {
        *Root1 = -c / b;
        return 2;
    }
}

int SolveSquare(double a, double b, double c, double* Root1, double* Root2)
{
    assert(!isnan(a));
    assert(!isnan(b));
    assert(!isnan(c));

    double discriminant = b * b - 4 * a * c;

    if(discriminant > 0)
    {
        *Root1 = ( -b + sqrt( discriminant ) ) / ( 2 * a );
        *Root2 = ( -b - sqrt( discriminant ) ) / ( 2 * a );

        return 3;
    }
    if (Equal(discriminant, 0) == 1)
    {
        *Root1 = -b / ( 2 * a );

        return 2;
    }
    if (discriminant < 0)
    {
        return 1;
    }

    return 0;
}

int test(double a, double b, double c, double Root1, double Root2, int ModeOfAnswer)
{
    assert(!isnan(a));
    assert(!isnan(b));
    assert(!isnan(a));

    LevelData Levels[] = {
            {0, 0, 0, 0, 0},
            {0, 0, -3, 3, 0},
            {0, 5, 0, 0, 0},
            {0, 4, 2, -0.5, 0},
            {1, 2, 1, -1, 5},
            {1, 3, 1, -0.381966, -2.61803},
            {1, 4, 9, 'n', 0}
    };

    int CompletedTests = 0;

    for(int i = 0; i < 7; i++)
    {
        SolveEquation(Levels[i].a, Levels[i].b, Levels[i].c, &Root1, &Root2, &ModeOfAnswer);
        switch(ModeOfAnswer)
        {
            case NOROOTS:
                if(Levels[i].ExpRoot1 == 'n')
                {
                    CompletedTests++;
                    break;
                }
                else
                {
                    printf("ErrorTest No%d!\n", i+1);
                    printf("expected: x1 = %lg\nreceived: NoRoots\n \n", Levels[i].ExpRoot1);
                    break;
                }
            case ONEROOT:
                if(Equal(Levels[i].ExpRoot1, Root1))
                {
                    CompletedTests++;
                    break;
                }
                else
                {
                    printf("\nMain: Test: ErrorTest No%d!\n", i+1);
                    printf("expected: x1 = %lg\nreceived: x1 = %lg, x2 = %lg\n \n", Levels[i].ExpRoot1, Root1);
                    break;
                }
            case TWOROOTS:
                if(Equal(Levels[i].ExpRoot1 , Root1) == 1 && Equal(Levels[i].ExpRoot2, Root2) == 1)
                {
                    CompletedTests++;
                    break;
                }
                else
                {
                    printf("\nMain: Test: ErrorTest No%d\n", i+1);
                    printf("expected: x1 = %lg, x2 = %lg;\nreceived: x1 = %lg, x = %lg\n \n",
                           Levels[i].ExpRoot1, Levels[i].ExpRoot2, Root1, Root2);
                    break;
                }
            case ANYNUMBER:
                if(Equal(Levels[i].ExpRoot1, Root1))
                {
                    CompletedTests++;
                    break;
                }
                else
                {
                    printf("\nMain: Test: ErrorTest No%d!\n", i+1);
                    printf("expected: %lg\nreceived: %lg, %lg\n \n", Levels[i].ExpRoot1, Root1);
                    break;
                }
        }
    }
    if(CompletedTests == 7)
    {
        printf("AllTest Is Nice!\n");
    }
    else
    {
        printf("COMPLETE %d/7 TESTS\n", CompletedTests);
    }

    return 0;

}

void WritingAnswer(int ModeOfAnswer, double Root1, double Root2)
{
    switch(ModeOfAnswer)
    {
        case ERROR:
            printf("Main: Output: Incorrect Data//\n");
            break;
        case NOROOTS:
            printf("Main: Output: NoRoots\n");
            break;
        case ONEROOT:
            printf("Main: Output: Equation has one Root\n"
                   "x = %lg\n", Root1);
            break;
        case TWOROOTS:
            printf("Main: Output: Equation has two Roots\n"
                   "x1 = %lg, x2 = %lg\n", Root1, Root2);
            break;
        case ANYNUMBER:
            printf("Main: Output: Any Number\n");
            break;
    }
}
