#include "../import_lib.hpp"
#include <windows.h>


const char* LANG_STYLE_ACT = "██"; // Активированная ячейка
const char* LANG_STYLE_INACT = "░░"; // Не активированная ячейка

void SetLocale() { // Установка языка (на всякий пожарный)
    SetConsoleOutputCP(CP_UTF8);
    setvbuf(stdout, nullptr, _IOFBF, 1000);
    setlocale(LC_ALL, "ru_RU.UTF-8");
}

void cursor_visibility(bool vision) {
    static const HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cci;
    GetConsoleCursorInfo(handle, &cci);
    cci.bVisible = vision; // show/hide cursor
    SetConsoleCursorInfo(handle, &cci);
}

void term_clear() { // Полная очистка терминала
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    if (hConsole == INVALID_HANDLE_VALUE) return;

    CONSOLE_SCREEN_BUFFER_INFO csbi;
    if (!GetConsoleScreenBufferInfo(hConsole, &csbi)) return;

    DWORD cellCount = csbi.dwSize.X * csbi.dwSize.Y;
    DWORD count;
    COORD homeCoords = { 0, 0 };
    FillConsoleOutputCharacter(hConsole, ' ', cellCount, homeCoords, &count);
    FillConsoleOutputAttribute(hConsole, csbi.wAttributes, cellCount, homeCoords, &count);
    SetConsoleCursorPosition(hConsole, homeCoords);
}

void loin_home() { // Перемещает курсор в начало текущей строки без очистки экрана
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    if (hConsole == INVALID_HANDLE_VALUE) return;
    COORD homeCoords = { 0, 0 };
    SetConsoleCursorPosition(hConsole, homeCoords);
}