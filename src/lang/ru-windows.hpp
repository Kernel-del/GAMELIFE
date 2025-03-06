#include "../import_lib.hpp"
#include <windows.h>

const char* LANG_SET_SIZE = "Введите, через пробел, размеры поля(x, y): ";
const char* LANG_CHOSEN_MAP = "Выберите карту:\n\t0. Системные карты\n\t1. Своя карта\n\t2. Рандом\nНапишите номер карты: ";
const char* LANG_RULES_CREATING_MAP = "Правила:\n\t0 - пустота\n\t1 - клетка\n\tn - переход на новую строчку\n\te - досрочное завершение\nВписывайте карту(удачи):\n";
const char* LANG_MOVE_COUNTER = "\nХод ";
const char* LANG_CHOSEN_SYSTEM_MAP = "Выберите карту:\n\t1. glider\n\t2. butterfly\n\t3. living forever\n\t4. gluider gun\nНапишите номер карты: ";

const char* LANG_STYLE_ACT = "#";
const char* LANG_STYLE_INACT = " ";



void SetLocale() {
    SetConsoleOutputCP(CP_UTF8);
    setvbuf(stdout, nullptr, _IOFBF, 1000);
    setlocale(LC_ALL, "ru_RU");
}

void term_clear() {
    system("cls");
}

void loin_home() {
    system("cls");
}