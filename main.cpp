#include <windows.h>
#include <conio.h>
#include <iostream>
#include <string>
#include <cmath>
#define UP 72
#define DOWN 80
#define ESC 27
#define ENTER 13
#define q 3.1415

using namespace std;

HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);


void gotoxy(int x, int y)
{
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
void cursoroff()
{
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO structCursorInfo;
    GetConsoleCursorInfo(handle, &structCursorInfo);
    structCursorInfo.bVisible = FALSE;
    SetConsoleCursorInfo(handle, &structCursorInfo);
}



void tabl()
{
SetConsoleOutputCP(CP_UTF8);
    system("cls");
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, 2);
    printf("|Таблица\n");

    int a = 0, i;
    float n = 18.0, dx, x[19], F1[19], F2[219], F1min, F1max, F2min, F2max;
    dx = fabs((5 - a) / (n - 1));
    x[0] = a;
    printf("______________________________________\n");
    printf("|_i_|___x____|____F1_____|____F2_____|\n");

    for (i = 0; i < n; i++)
    {
        F1[i] = pow(3,-x[i])/50;
        F2[i] =  x[i] * exp(-x[i]) + log(x[i]);
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
        if (sqrt(log(pow(c, 2) + 3)) + 2*c  - 3 <= 0) b = c;
        else a = c;

    } while (fabs(a - b) >= eps);
    printf("c=%lf\n", c);

    _getch();
    return 0;
}

void obomne()
{
    system("cls");
SetConsoleOutputCP(CP_UTF8);
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, 2);
    SetConsoleTextAttribute(hConsole, 2);
    printf("\t\t\t\x1b[32m------------------------------------------------\x1b[0m\n\n");
    printf("\t\t\t\x1b[32mРасчётно-графическая работа по программированию\x1b[0m\t\t\n\n");
    SetConsoleTextAttribute(hConsole, 2);
    printf("\t\t\tОмГТУ\t\t\n");
    printf("\t\t\tФакультет: ФИТиКС\t\t\n");
    printf("\t\t\tГруппа:ПИН-231 \n");
    printf("\t\t\tТищенко Тимофей Дмитриевич\n\n");
    printf("\t\t\t\x1b[32m------------------------------------------------\x1b[0m\n\n");
    SetConsoleTextAttribute(hConsole, 2);
    _getch();
}

void integral()
{
SetConsoleOutputCP(CP_UTF8);
    double a = 0, b = 2, h, s = 0, n, k, f, a2 = 0, b2 = 2, h2, x2, n2 = 1000, f2;
    cout<< "Введите количество прямоугольников";
    cin >> n;
    h = (b - a) / n;
    for (double x1 = 0, x = a;x <= b;x += h)
    {

        if (x < b)
        {
            x1 = x + h / 2;
            f = exp(x) + exp(-x);
            s += f;
        }
    }
    cout<< s * h<< " Методом прямоугольников\n";

    x2 = a2;
    h2 = (b2 - a2) / n2;

    f2 = (exp(a2) + exp(-a2) + exp(b2) + exp(-b2)) / 2.0;

    for (int i = 1; i < n2; i++) {
        x2 = a2 + i * h2;
        f2 += exp(x2) + exp(-x2);
    }
    cout<< f2 * h2 << " Методом трапеции\n";


    h2 = (b2 - a2) / n2;
    double f3 = (exp(a2) + exp(-a2) + exp(b2) + exp(-b2));
    for (int i = 1; i < n2; i++) {
        double x2 = a2 + i * h2;
        f3 += (i % 2 == 0) ? 2 * (exp(x2) + exp(-x2)) : 4 * (exp(x2) + exp(-x2));
    }
    cout<< f3 * h2 / 3.0 << " Методом Симпсона\n";

}

void graphs()
{
    system("cls");
    int pravka;
    HDC screen = GetDC(GetConsoleWindow());
    HPEN pen_white = CreatePen(PS_DASH, 2, RGB(255, 255, 255));
    HPEN pen = CreatePen(PS_DASH, 2, RGB(80, 170, 220));
    HPEN pen2 = CreatePen(PS_DASH, 2, RGB(200,120, 0));
    SelectObject(screen, pen_white);
    const int zero_x = 530;
    const int zero_y = 280;
// ОХ
    MoveToEx(screen, zero_x - 400, zero_y, NULL);
    LineTo(screen, zero_x + 400, zero_y);
// ОУ
    MoveToEx(screen, zero_x, zero_y - 250, NULL);
    LineTo(screen, zero_x, zero_y + 250);
// Стрелочка у оси Х
    MoveToEx(screen, zero_x + 400 - 25, zero_y + 10, NULL);
    LineTo(screen, zero_x + 400, zero_y);
    LineTo(screen, zero_x + 400 - 25, zero_y - 10);
//..
    MoveToEx(screen, zero_x + 10, zero_y - 250 + 25, NULL);
    LineTo(screen, zero_x, zero_y - 250);
    LineTo(screen, zero_x - 10, zero_y - 250 + 25);
// Единичные отрезки
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
// Оси
    SetBkMode(screen, TRANSPARENT);
    SetTextColor(screen, RGB(255, 255, 255));
    TextOut(screen, zero_x + 15, zero_y - 240, reinterpret_cast<LPCSTR>(L"Y"), 1);
    TextOut(screen, zero_x + 380, zero_y + 15, reinterpret_cast<LPCSTR>(L"X"), 1);
    TextOut(screen, zero_x - 12, zero_y + 2, reinterpret_cast<LPCSTR>(L"0"), 1);
    TextOut(screen, zero_x + 15, zero_y + 10, reinterpret_cast<LPCSTR>(L"1"), 1);
    TextOut(screen, zero_x - 15, zero_y - 27, reinterpret_cast<LPCSTR>(L"1"), 1);
// Названия графиков функции
    SetTextColor(screen, RGB(80, 170, 220));
    TextOut(screen, zero_x - 300, zero_y - 150, reinterpret_cast<LPCSTR>(L"y = (3^-x)/50"), 30);
    SetTextColor(screen, RGB(200,120, 0));
    TextOut(screen, zero_x - 300, zero_y - 200, reinterpret_cast<LPCSTR>(L"y = x * e^-x + ln(x)"), 40);
// функция 1
    SelectObject(screen, pen);
    int i = 1;
    for (double x = 0.01; x <= 8.50; x += 0.01)
    {
        MoveToEx(screen, 12 * x + zero_x, -12 * (pow(3,-x)/50) + zero_y, NULL);
        LineTo(screen, 12 * (x + 0.1) + zero_x, -12 *(pow(3,-x + 0.1)/50) + zero_y);
        i++;
        if (i % 12 == 0)
            Sleep(1);
    }
    i = 1;
    //функция 2
    SelectObject(screen, pen2);
    for (double x = 0.01; x <= 8.50; x += 0.01)
    {
        MoveToEx(screen, 12 * x + zero_x, -12 * ( x * exp(-x) + log(x)) + zero_y, NULL);
        LineTo(screen, 12 * (x + 0.1) + zero_x, -12 * ( (x + 0.1) * exp(-x + 0.1) + log(x + 0.1))  + zero_y);
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
    cursoroff();
        HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
    //смешиваем цвета RGB для получения бего цвета
    SetConsoleTextAttribute(hStdout,FOREGROUND_INTENSITY +FOREGROUND_RED + FOREGROUND_GREEN);
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(hStdout, &csbi);

    const int M = csbi.srWindow.Right - csbi.srWindow.Left ;
    const int N = csbi.srWindow.Bottom - csbi.srWindow.Top ;
    const int n = 80;

    int y[n], x[n], sy[M];
    bool poi = 0, stopFlag = true;
    for (int s = 0; s < n; s++) {
        y[s] = rand() % N;
        x[s] = rand() % M;
    }
    sy[0] = N-3;
    for (int s = 1; s < M; s++) {
        sy[s] = N;
    }

    while(stopFlag)
    {
        //отчистка
        gotoxy(0,0);

        //отрисовка
        for (int i = 0; i < N; i++, printf("\n"))
            for (int j = 0; j < M; j++) {
                poi = false;
                for (int s = 0; s < n; s++)
                    if ((i == y[s] && j == x[s]) || (i >= sy[j]))
                        poi = true;
                if (poi)
                    printf("*");
                else
                    printf(" ");

            }
        if (_kbhit())
        {
            char key = _getch();
            if (key == ESC)
            {
                stopFlag = false;
            }
        }

        for (int s = 0; s < n; s++) {
            for (int j = 0; j < M; j++)
                if (y[s] == N && x[s] == j) {
                    if (sy[j - 1] > sy[j])
                        sy[j - 1]--;
                    else
                    if (sy[j + 1] > sy[j])
                        sy[j+1]--;
                    else
                        sy[j]--;
                }
            if (y[s] == N)
                y[s] = 0;
            else
                y[s] += 1;
            x[s] += rand() % 3 - 1;
        }

        Sleep(20);
    }

    return 0;
}



int rgr()
{
    SetConsoleTitle(reinterpret_cast<LPCSTR>(L"ХАИ"));
    system("CLS");
SetConsoleOutputCP(CP_UTF8);
    cursoroff(); 
    string Menu[] = { "Сведения об авторе","Графическая заствка", "Расчёт таблиц", "Построение графиков", "Решение уравнения", "Вычисление интеграла", "Выйти" };
    int active_menu = 0;

    char ch;
    while (true)
    {
        int x = 40, y = 12;
        gotoxy(x, y);
        for (int i = 0; i < size(Menu); i++)
        {
            if (i == active_menu % size(Menu))
                SetConsoleTextAttribute(hStdOut, FOREGROUND_GREEN | FOREGROUND_INTENSITY);

            else SetConsoleTextAttribute(hStdOut, FOREGROUND_GREEN);
            gotoxy(x, y++);
            cout<< Menu[i]<< endl;
        }
        ch = _getch();
        if (ch == -32) ch = _getch(); // Отлавливаем стрелочки
        switch (ch)
        {
            case ESC:
                exit(0);


            case UP:
                --active_menu;
                break;
            case DOWN:
                    ++active_menu;
                break;

            case ENTER:
                switch (active_menu % size(Menu))
                {
                    case 0: obomne();gotoxy(x, y);
                        SetConsoleTextAttribute(hStdOut, FOREGROUND_RED | FOREGROUND_GREEN |

                                                         FOREGROUND_INTENSITY);
                        _getch();
                        system("CLS");
                        break;

                    case 1: animation();
                        system("CLS");
                        break;

                    case 2:tabl(); gotoxy(x, y);
                        SetConsoleTextAttribute(hStdOut, FOREGROUND_RED | FOREGROUND_GREEN |

                                                         FOREGROUND_INTENSITY);

                        _getch();
                        system("CLS");
                        break;

                    case 3: graphs();
                        gotoxy(x, y);
                        SetConsoleTextAttribute(hStdOut, FOREGROUND_RED | FOREGROUND_GREEN |

                                                         FOREGROUND_INTENSITY);

                        _getch();
                        system("CLS");
                        break;

                    case 4:uravn(); gotoxy(x, y);
                        SetConsoleTextAttribute(hStdOut, FOREGROUND_RED | FOREGROUND_GREEN |

                                                         FOREGROUND_INTENSITY);

                        _getch();
                        system("CLS");
                        break;

                    case 5: integral();

                        gotoxy(x, y);
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
    SetConsoleOutputCP(CP_UTF8);
    rgr();

}

