#include <windows.h>
#include <conio.h>
#include <iostream>
#include <string>
#include <cmath>
#include <locale>

#define UP 72
#define DOWN 80
#define ESC 27
#define ENTER 13
#define q 3.1415
using namespace std;

void tabl()
{
 setlocale(LC_ALL, "RUS");
    system("cls");
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, 2);
    printf("|Таблица\n");

    int n = 20, a = -q;
    float dx, x[21], F1[20], F2[20], F1min, F1max, F2min, F2max;
    int i;
    dx = fabs((q - a) / (n - 1));
    x[0] = a;
    printf("______________________________________\n");
    printf("|_i_|___x____|____F1_____|____F2_____|\n");

    for (i = 0; i < n; i++)
    {
        F2[i] = fabs(sin(x[i])) + fabs(cos(x[i]));
        F1[i] = fabs(sin(x[i])) - fabs(cos(x[i]));
        x[i + 1] = x[i] + dx;
    }

    F1min = F1[0];
    F2min = F2[0];
    F1max = F1[0];
    F2max = F2[0];

    for (i = 0; i < n; i++)
    {
        if (F1[i] < F1min) F1min = F1[i];
        if (F1[i] > F1max) F1max = F1[i];
        if (F2[i] < F2min) F2min = F2[i];
        if (F2[i] > F2max) F2max = F2[i];
    }

    for (i = 0; i < n; i++)
    {
        printf("|%3d|%8.3f|", i + 1, x[i]);
        if (F1[i] == F1min)
        {
            SetConsoleTextAttribute(hConsole, 1);
            printf_s("%11.4f", F1min);
            SetConsoleTextAttribute(hConsole, 2);
            printf_s("|");
        }
        else
        if (F1[i] == F1max)
        {
            SetConsoleTextAttribute(hConsole, 4);
            printf("%11.4f", F1max);
            SetConsoleTextAttribute(hConsole, 2);
            printf("|");
        }
        else
            printf("%11.4f|", F1[i]);
        if (F2[i] == F2min)
        {
            SetConsoleTextAttribute(hConsole, 1);
            printf("%11.4f", F2min);
            SetConsoleTextAttribute(hConsole, 2);
            printf("|\n");
        }
        else
        if (F2[i] == F2max)
        {
            SetConsoleTextAttribute(hConsole, 4);
            printf("%11.4f", F2max);
            SetConsoleTextAttribute(hConsole, 2);
            printf("|\n");
        }
        else
            printf("%11.4f|\n", F2[i]);
    }
    printf("|___|________|___________|___________|\n\n");

    SetConsoleTextAttribute(hConsole, 2 | 2);
    printf_s("Максимальное значение функций \x1b[31mкрасным цветом\x1b[0m\n");
    SetConsoleTextAttribute(hConsole, 2 | 2);
    printf_s("Минимальное значение функций \x1b[34mсиним цветом\x1b[0m\n");
    SetConsoleTextAttribute(hConsole, 2 | 4);
    _getch();
}

int uravn() {
    int n = 0;
    double a = 4, b = 14, c, eps = 0.001;

    do {
        c = (a + b) / 2;
        if ((2 * log(c + 1) + atan(c) - 3) * (2 * log(a + 1) + atan(a) - 3 <= 0)) b = c;
        else a = c;

    } while (fabs(a - b) >= eps);
    printf("c=%lf\n", c);

    _getch();
    return 0;
}

void obomne()
{
    system("cls");
 setlocale(LC_ALL, "RUS");
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, 2);
    SetConsoleTextAttribute(hConsole, 2);
    printf("\t\t\t\x1b[32m------------------------------------------------\x1b[0m\n\n");
    printf("\t\t\t\x1b[32mРасчётно-графическая работа по программированию\x1b[0m\t\t\n\n");
    SetConsoleTextAttribute(hConsole, 2);
    printf("\t\t\tОмГТУ\t\t\n");
    printf("\t\t\tФакультет: ФИТиКС\t\t\n");
    printf("\t\t\tГруппа:ИВТ-234 \n");
    printf("\t\t\tНаумкин Владислав Сергеевич\n\n");
    printf("\t\t\t\x1b[32m------------------------------------------------\x1b[0m\n\n");
    SetConsoleTextAttribute(hConsole, 2);
    _getch();
}

void integral()
{
 setlocale(LC_ALL, "RUS");
    double a = 0, b = 2, h, s = 0, n, k, f, a2 = 0, b2 = 2, h2, x2, n2 = 1000, f2;
    std::cout<< "Введите количество прямоугольников";
    std::cin >> n;
    h = (b - a) / n;
    for (double x1 = 0, x = a;x <= b;x += h)
    {

        if (x < b)
        {
            x1 = x + h / 2;
            f = (sqrt(x)) * sin(x);
            s += f;
        }
    }
    std::cout<< s * h<< " Методом прямоугольников\n";

    x2 = a2;
    h2 = (b2 - a2) / n2;

    f2 = h2 * ((sqrt(a2)) * sin(a2)) * ((sqrt(b2)) * sin(b2)) / 2;
    for (int i = 1; i < n; i++)
    {
        x2 = a2 + i * h2;
        f2 += h2 * ((sqrt(x2)) * sin(x2)) * ((sqrt(x2)) * sin(x2));
    }
    std::cout<< f2<< " Методом трапеции";

}

void graphs()
{
    system("cls");
    int pravka;
    HDC screen = GetDC(GetConsoleWindow());
    HPEN pen_white = CreatePen(PS_DASH, 2, RGB(255, 255, 255));
    HPEN pen = CreatePen(PS_DASH, 2, RGB(80, 170, 220));
    HPEN pen2 = CreatePen(PS_DASH, 2, RGB(255, 0, 0));
    SelectObject(screen, pen_white);
    const int zero_x = 550;
    const int zero_y = 300;
// Ось Х
    MoveToEx(screen, zero_x - 400, zero_y, NULL);
    LineTo(screen, zero_x + 400, zero_y);
// Ось У
    MoveToEx(screen, zero_x, zero_y - 250, NULL);
    LineTo(screen, zero_x, zero_y + 250);
// Стрелочка у оси Х
    MoveToEx(screen, zero_x + 400 - 25, zero_y + 10, NULL);
    LineTo(screen, zero_x + 400, zero_y);
    LineTo(screen, zero_x + 400 - 25, zero_y - 10);
// Стрелочка у оси У
    MoveToEx(screen, zero_x + 10, zero_y - 250 + 25, NULL);
    LineTo(screen, zero_x, zero_y - 250);
    LineTo(screen, zero_x - 10, zero_y - 250 + 25);
// Палочки
    for (int i = -380; i <= 360; i += 20)
    {
        MoveToEx(screen, zero_x + i, zero_y - 5, NULL);
        LineTo(screen, zero_x + i, zero_y + 5);
    }
    for (int i = -220; i <= 240; i += 20)
    {
        MoveToEx(screen, zero_x - 5, zero_y + i, NULL);
        LineTo(screen, zero_x + 5, zero_y + i);
    }
// Подпись осей и начала координат
    SetBkMode(screen, TRANSPARENT);
    SetTextColor(screen, RGB(255, 255, 255));
    TextOut(screen, zero_x + 15, zero_y - 240, reinterpret_cast<LPCSTR>(L"Y"), 1);
    TextOut(screen, zero_x + 380, zero_y + 15, reinterpret_cast<LPCSTR>(L"X"), 1);
    TextOut(screen, zero_x - 12, zero_y + 2, reinterpret_cast<LPCSTR>(L"0"), 1);
    TextOut(screen, zero_x + 15, zero_y + 10, reinterpret_cast<LPCSTR>(L"1"), 1);
    TextOut(screen, zero_x - 15, zero_y - 27, reinterpret_cast<LPCSTR>(L"1"), 1);
// Подпись кривой функции
    SetTextColor(screen, RGB(80, 170, 220));
    TextOut(screen, zero_x - 300, zero_y - 150, reinterpret_cast<LPCSTR>(L"y = (|sinx| + |cosx|)"), 25);
    SetTextColor(screen, RGB(255, 0, 0));
    TextOut(screen, zero_x - 300, zero_y - 200, reinterpret_cast<LPCSTR>(L"y = (|sin x| - |cos x|)"), 25);
// Cам график
    SelectObject(screen, pen);
    int i = 1;
    for (double x = 0.01; x <= 10.0; x += 0.01)
    {
        MoveToEx(screen, 12 * x + zero_x, -12 * (fabs(sin(x)) + fabs(cos(x))) + zero_y, NULL);
        LineTo(screen, 12 * (x + 0.1) + zero_x, -12 *(fabs(sin(x+0.1)) + fabs(cos(x+0.1))) +
                                                zero_y);
        i++;
        if (i % 12 == 0)
            Sleep(1);
    }
    i = 1;
    SelectObject(screen, pen2);
    for (double x = 0.01; x <= 10.0; x += 0.01)
    {
        MoveToEx(screen, 12 * x + zero_x, -12 * ( fabs(sin(x)) - fabs(cos(x)) ) + zero_y,
                 NULL);
        LineTo(screen, 12 * (x + 0.1) + zero_x, -12 * (fabs(sin(x+0.1)) - fabs(cos(x+0.1))) + zero_y);
        i++;
        if (i % 12 == 0)
            Sleep(1);
    }
    for (bool j = true; j == true;)
    {
        pravka = _getch();
        if (pravka == 224)
            pravka = _getch();
        switch (pravka)
        {
            case 27:
            case 32:
            case 13:
                system("cls");
                return;
        }
    }

    _getch();

}

int animation()
{
    HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);

    SetConsoleTextAttribute(hStdout, BACKGROUND_RED + //голубой цвет фона
                                     BACKGROUND_INTENSITY + //увеличиваем яркость фона
                                     //смешиваем цвета RGB для получения бего цвета
                                     FOREGROUND_INTENSITY + //увеличение яркости цвета
                                     FOREGROUND_RED + //смешиваем цвета RGB для получения бего цвета
                                     FOREGROUND_GREEN); //смешиваем цвета RGB для получения бего цвета

    const char heart = 3;

    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(hStdout, &csbi);

    const int WindowWidth = csbi.srWindow.Right - csbi.srWindow.Left + 1;
    const int WindowHeight = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;

    for (int i = 0; i < WindowWidth * WindowHeight; i++)
        cout<< " ";

    COORD orig = { 0, 0 };

    SetConsoleCursorPosition(hStdout, orig);
    COORD snowflake[1000];

    for (int i = 0; i < WindowWidth; i++)
    {
        snowflake[i].X = i;
        snowflake[i].Y = rand() % WindowHeight;
    }

    while (true)
    {
        for (int i = 0; i < WindowWidth; i++)
        {
            SetConsoleCursorPosition(hStdout, snowflake[i]);
            cout<< ' ';

            snowflake[i].Y++;

            if (snowflake[i].Y == WindowHeight)
                snowflake[i].Y = 0;

            SetConsoleCursorPosition(hStdout, snowflake[i]);
            cout<< heart;
        }

        SetConsoleCursorPosition(hStdout, orig);
        Sleep(200);

    }

    return 0;
}

HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);

// Текстовый курсор в точку x,y
void GoToXY(short x, short y)
{
    SetConsoleCursorPosition(hStdOut, { x, y });
}

void ConsoleCursorVisible(bool show, short size)
{
    CONSOLE_CURSOR_INFO structCursorInfo;
    GetConsoleCursorInfo(hStdOut, &structCursorInfo);
    structCursorInfo.bVisible = show;
    structCursorInfo.dwSize = size;
    SetConsoleCursorInfo(hStdOut, &structCursorInfo);
}

int rgr()
{
    SetConsoleTitle(reinterpret_cast<LPCSTR>(L"ХАИ"));
    system("CLS");
 setlocale(LC_ALL, "RUS");
    ConsoleCursorVisible(false, 100);
    string Menu[] = { "Сведения об авторе","Графическая заствка", "Расчёт таблиц", "Построение графиков", "Решение уравнения", "Вычисление интеграла" };
    int active_menu = 0;

    char ch;
    while (true)
    {
        int x = 40, y = 12;
        GoToXY(x, y);
        for (int i = 0; i < size(Menu); i++)
        {
            if (i == active_menu)
                SetConsoleTextAttribute(hStdOut, FOREGROUND_RED | FOREGROUND_INTENSITY);

            else SetConsoleTextAttribute(hStdOut, FOREGROUND_RED);
            GoToXY(x, y++);
            cout<< Menu[i]<< endl;
        }
        ch = _getch();
        if (ch == -32) ch = _getch(); // Отлавливаем стрелочки
        switch (ch)
        {
            case ESC:
                exit(0);
            case UP:
                if (active_menu > 0)
                -active_menu;
                break;
            case DOWN:
                if (active_menu < size(Menu) - 1)
                    ++active_menu;
                break;

            case ENTER:
                switch (active_menu)
                {
                    case 0: obomne();GoToXY(x, y);
                        SetConsoleTextAttribute(hStdOut, FOREGROUND_RED | FOREGROUND_GREEN |

                                                         FOREGROUND_INTENSITY);
                        _getch();
                        system("CLS");
                        break;

                    case 1: animation();
                        system("CLS");
                        break;

                    case 2:tabl(); GoToXY(x, y);
                        SetConsoleTextAttribute(hStdOut, FOREGROUND_RED | FOREGROUND_GREEN |

                                                         FOREGROUND_INTENSITY);

                        _getch();
                        system("CLS");
                        break;

                    case 3: graphs();
                        GoToXY(x, y);
                        SetConsoleTextAttribute(hStdOut, FOREGROUND_RED | FOREGROUND_GREEN |

                                                         FOREGROUND_INTENSITY);

                        _getch();
                        system("CLS");
                        break;

                    case 4:uravn(); GoToXY(x, y);
                        SetConsoleTextAttribute(hStdOut, FOREGROUND_RED | FOREGROUND_GREEN |

                                                         FOREGROUND_INTENSITY);

                        _getch();
                        system("CLS");
                        break;

                    case 5: integral();

                        GoToXY(x, y);
                        SetConsoleTextAttribute(hStdOut, FOREGROUND_RED | FOREGROUND_GREEN |

                                                         FOREGROUND_INTENSITY);

                        _getch();
                        system("CLS");
                        break;

                    case 6: exit(0);

                }

                break;
            default:
                cout<< "Код"<< (int)ch<< endl;

        }
    }
//_getch();
}

int main()
{
 setlocale(LC_ALL, "RUS");
    rgr();
}