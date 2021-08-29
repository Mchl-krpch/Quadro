#ifndef KVADRATKA3_FUNCTIONS_H
#define KVADRATKA3_FUNCTIONS_H

/// \breaf **SMALLDIFFERENCE** это очень маленькое число
double const SMALLDIFFERENCE = 1e-3;

/// \breaf **LevelData** структура для тестов, которая описывает вводные данные: коэфиценты a, b, c и два ожидаемых (правильных) корня
struct LevelData{
    double a, b, c, ExpRoot1, ExpRoot2;
};

/// \breaf **Mode** обозначение режимов работы программы
enum Mode{
    SOLVING = 0,
    TESTING = 1,
};

/// \breaf **TypeOfOtvet** Обозначения типов возможных режимов вывода ответа
enum TypeOfOtvet{
    ERROR = 0,
    NOROOTS = 1,
    ONEROOT = 2,
    TWOROOTS = 3,
    ANYNUMBER = 4,

};

/// \breaf **Equal()** Сравнивает числа: если равны - значение 1; если не равны - значение 0;
/// \param number1 Число сравнения 1
/// \param number2 Число сравнения 2
/// **Example of code**
/// \code
///int Equal(double number1, double number2)
///{
///    return fabs(number1 - number2) < SMALLDIFFERENCE;
///}
///\endcode
int Equal(double number1, double number2);

/// \breaf **SolveEquation** решает, какое уравнение решать, Линейное или Квадратное
/// \param a Коэфицент в уравнении при X^2
/// \param b Коэфицент в уравнении при X
/// \param c свободный член в уравнении
/// \param Root1 Найденный первый (единсвтенный корень, если уравнение линейное или дискриминант = 0) корень уравнения
/// \param Root2 Найденный второй корень уравнения
/// \param ModeOfAnswer Функция сохраняет корни и этой константой сохраняет режим ответа (выводить один или два корня или другие случаи в ответе)
/// **Example of code**
/// \code
///void SolveEquation(double a, double b, double c, double* Root1, double* Root2, int* ModeOfAnswer)
///{
///    if (Equal(a, 0))
///    {
///        *ModeOfAnswer = SolveLiniar(b, c, Root1);
///    }
///    else
///    {
///        *ModeOfAnswer = SolveSquare(a, b, c, Root1, Root2);
///    }
///}
///\endcode
void SolveEquation( double a, double b, double c, double * Root1, double * Root2, int * ModeOfAnswer );

/// \breaf **SolveLiniar** решает линейное уравнение, возвращая лишь корень Root1
/// \param a Коэфицент в уравнении при X^2
/// \param b Коэфицент в уравнении при X
/// \param c свободный член в уравнении
/// \param Root1 Найденный первый (единсвтенный корень, если уравнение линейное или дискриминант = 0) корень уравнения
/// **Example of code**
/// \code
///int SolveLiniar(double b, double c, double* Root1)
///{
///    if(Equal(b, 0))
///    {
///        if(Equal(c, 0))
///        {
///            return 4;
///        }
///        *Root1 = -c;
///        return 2;
///    }
///    else
///    {
///        *Root1 = -c / b;
///        return 2;
///    }
///}
///\endcode
int SolveLinear( double b, double c, double * Root1 );

/// \breaf **SolveSquare** решает квадратное уравнение и возвращает корни: Root1 и Root2
/// \param a Коэфицент в уравнении при X^2
/// \param b Коэфицент в уравнении при X
/// \param c свободный член в уравнении
/// \param Root1 Найденный первый (единсвтенный корень, если уравнение линейное или дискриминант = 0) корень уравнения
/// \param Root2 Найденный второй корень уравнения
/// \param Discriminant Найденный дискриминант уравнения
/// **Example of code**
/// \code
///int SolveSquare(double a, double b, double c, double* Root1, double* Root2)
///{
///    assert(!isnan(a));
///    assert(!isnan(b));
///    assert(!isnan(c));
///
///    double discriminant = b * b - 4 * a * c;
///
///    if(discriminant > 0)
///    {
///        *Root1 = ( -b + sqrt( discriminant ) ) / ( 2 * a );
///        *Root2 = ( -b - sqrt( discriminant ) ) / ( 2 * a );
///
///        return 3;
///    }
///    if (Equal(discriminant, 0) == 1)
///    {
///        *Root1 = -b / ( 2 * a );
///
///        return 2;
///    }
///    if (discriminant < 0)
///    {
///        return 1;
///    }
///
///    return 0;
///}
///\endcode
int SolveSquare( double a, double b, double c, double * Root1, double * Root2 );

/// \breaf **test** тестирует программу
/// \param a Коэфицент в уравнении при X^2
/// \param b Коэфицент в уравнении при X
/// \param c свободный член в уравнении
/// \param Root1 Найденный первый (единсвтенный корень, если уравнение линейное или дискриминант = 0) корень уравнения
/// \param Root2 Найденный второй корень уравнения
/// \param LevelData - это массив из структур, данные которых являются a, b, c, Ожидаемый корень1 и ожидаемый корень2
/// \param CompletedTests Отвечает за количество успешных тестов
/// \param ModeOfAnswer Функция сохраняет корни и этой константой сохраняет режим ответа (выводить один или два корня или другие случаи в ответе)
/// **Example of code**
/// \code
///int test(double a, double b, double c, double Root1, double Root2, int ModeOfAnswer)
///{
///    assert(!isnan(a));
///    assert(!isnan(b));
///    assert(!isnan(a));
///
///    LevelData Levels[] = {
///            {0, 0, 0, 0, 0},
///            {0, 0, -3, 3, 0},
///           {0, 5, 0, 0, 0},
///           {0, 4, 2, -0.5, 0},
///            {1, 2, 1, -1, 5},
///            {1, 3, 1, -0.381966, -2.61803},
///            {1, 4, 9, 'n', 0}
///    };
///
///    int CompletedTests = 0;
///
///    for(int i = 0; i < 7; i++)
///    {
///        SolveEquation(Levels[i].a, Levels[i].b, Levels[i].c, &Root1, &Root2, &ModeOfAnswer);
///        switch(ModeOfAnswer)
///        {
///            case NOROOTS:
///                if(Levels[i].ExpRoot1 == 'n')
///                {
///                    CompletedTests++;
///                    break;
///                }
///                else
///                {
///                    printf("ErrorTest No%d!\n", i+1);
///                    printf("expected: x1 = %lg\nreceived: NoRoots\n \n", Levels[i].ExpRoot1);
///                    break;
///                }
///            case ONEROOT:
///                if(Equal(Levels[i].ExpRoot1, Root1))
///                {
///                    CompletedTests++;
///                    break;
///                }
///                else
///                {
///                    printf("\nMain: Test: ErrorTest No%d!\n", i+1);
///                    printf("expected: x1 = %lg\nreceived: x1 = %lg, x2 = %lg\n \n", Levels[i].ExpRoot1, Root1);
///                    break;
///                }
///            case TWOROOTS:
///                if(Equal(Levels[i].ExpRoot1 , Root1) == 1 && Equal(Levels[i].ExpRoot2, Root2) == 1)
///                {
///                    CompletedTests++;
///                    break;
///                }
///                else
///                {
///                    printf("\nMain: Test: ErrorTest No%d\n", i+1);
///                    printf("expected: x1 = %lg, x2 = %lg;\nreceived: x1 = %lg, x = %lg\n \n",
///                          Levels[i].ExpRoot1, Levels[i].ExpRoot2, Root1, Root2);
///                    break;
///                }
///            case ANYNUMBER:
///                if(Equal(Levels[i].ExpRoot1, Root1))
///                {
///                    CompletedTests++;
///                    break;
///                }
///                else
///                {
///                    printf("\nMain: Test: ErrorTest No%d!\n", i+1);
///                    printf("expected: %lg\nreceived: %lg, %lg\n \n", Levels[i].ExpRoot1, Root1);
///                    break;
///                }
///        }
///    }
///    if(CompletedTests == 7)
///    {
///        printf("AllTest Is Nice!\n");
///    }
///    else
///    {
///        printf("COMPLETE %d/7 TESTS\n", CompletedTests);
///    }
///
///    return 0;
///
///}
///\endcode
int test( double a, double b, double c, double Root1, double Root2, int ModeOfAnswer );

/// \breaf **WritiongAnswer** выводит полученный ответ с учетом выбранного режима
/// \param Root1 Найденный первый (единсвтенный корень, если уравнение линейное или дискриминант = 0) корень уравнения
/// \param Root2 Найденный второй корень уравнения
/// **Example of code**
/// \code
///void WritingAnswer(int ModeOfAnswer, double Root1, double Root2)
///{
///    switch(ModeOfAnswer)
///    {
///        case ERROR:
///            printf("Main: Output: Incorrect Data//\n");
///            break;
///        case NOROOTS:
///            printf("Main: Output: NoRoots\n");
///            break;
///        case ONEROOT:
///            printf("Main: Output: Equation has one Root\n"
///                   "x = %lg\n", Root1);
///            break;
///        case TWOROOTS:
///            printf("Main: Output: Equation has two Roots\n"
///                   "x1 = %lg, x2 = %lg\n", Root1, Root2);
///            break;
///        case ANYNUMBER:
///            printf("Main: Output: Any Number\n");
///            break;
///    }
///}
///\endcode
void WritingAnswer( int ModeOfAnswer, double Root1, double Root2 );

#endif //KVADRATKA3_FUNCTIONS_H
