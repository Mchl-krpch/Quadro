#include <cstdio>
#include <cmath>
#include <cassert>

#include "Functions.h"
/// \brief **test** тестирует программу
int Equal(double number1, double number2)
{
    return fabs(number1 - number2) < SMALLDIFFERENCE;
}

void SolveEquation(double a, double b, double c, double* Root1, double* Root2, int* ModeOfAnswer)
{
    assert(isfinite(a));
    assert(isfinite(b));
    assert(isfinite(c));
    assert(!isnan(a));
    assert(!isnan(b));
    assert(!isnan(c));

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
    assert(isfinite(b));
    assert(isfinite(c));
    assert(!isnan(b));
    assert(!isnan(c));

    if(Equal(b, 0))
    {
        if(Equal(c, 0))
        {
            *Root1 = 0;
            return ANYNUMBER;
        }
        *Root1 = -c;
        return ONEROOT;
    }
    else
    {
        *Root1 = -c / b;
        return ONEROOT;
    }
}

int SolveSquare(double a, double b, double c, double* Root1, double* Root2)
{
    assert(isfinite(a));
    assert(isfinite(b));
    assert(isfinite(c));
    assert(!isnan(a));
    assert(!isnan(b));
    assert(!isnan(c));

    double discriminant = b * b - 4 * a * c;

    if(discriminant > 0)
    {
        *Root1 = ( -b + sqrt( discriminant ) ) / ( 2 * a );
        *Root2 = ( -b - sqrt( discriminant ) ) / ( 2 * a );

        return TWOROOTS;
    }
    if (Equal(discriminant, 0) == 1)
    {
        *Root1 = -b / ( 2 * a );

        return ONEROOT;
    }
    if (discriminant < 0)
    {
        return NOROOTS;
    }

    return ERROR;
}

int test(int ModeOfAnswer)
{
    double Root1 = NAN, Root2 = NAN;
    LevelData Tests[] = {
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
        SolveEquation(Tests[i].a, Tests[i].b, Tests[i].c, &Root1, &Root2, &ModeOfAnswer);
        switch(ModeOfAnswer)
        {
            case NOROOTS:
                if(Tests[i].ExpRoot1 == 'n')
                {
                    CompletedTests++;
                    break;
                }
                else
                {
                    printf("ErrorTest No%d!\n", i+1);
                    printf("expected: x1 = %lg\nreceived: NoRoots\n \n", Tests[i].ExpRoot1);
                    break;
                }
            case ONEROOT:
                if(Equal(Tests[i].ExpRoot1, Root1))
                {
                    CompletedTests++;
                    break;
                }
                else
                {
                    printf("\nMain: Test: ErrorTest No%d!\n", i+1);
                    printf("expected: x1 = %lg\nreceived: x1 = %lg, x2 = %lg\n \n", Tests[i].ExpRoot1, Root1, Root2);
                    break;
                }
            case TWOROOTS:
                if(Equal(Tests[i].ExpRoot1 , Root1) == 1 && Equal(Tests[i].ExpRoot2, Root2) == 1)
                {
                    CompletedTests++;
                    break;
                }
                else
                {
                    printf("\nMain: Test: ErrorTest No%d\n", i+1);
                    printf("expected: x1 = %lg, x2 = %lg;\nreceived: x1 = %lg, x = %lg\n \n",
                           Tests[i].ExpRoot1, Tests[i].ExpRoot2, Root1, Root2);
                    break;
                }
            case ANYNUMBER:
                if(Equal(Tests[i].ExpRoot1, Root1))
                {
                    CompletedTests++;
                    break;
                }
                else
                {
                    printf("\nMain: Test: ErrorTest No%d!\n", i+1);
                    printf("expected: %lg\nreceived: %lg, %lg\n \n", Tests[i].ExpRoot1, Root1);
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
