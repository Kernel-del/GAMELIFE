#include "../import_lib.hpp"


const char* LANG_SET_SIZE = "Введите, через пробел, размеры поля(x, y): ";
const char* LANG_CHOSEN_MAP = "\n\nВыберите карту:\n\t0. Стандартная карта\n\t1. Своя карта\n\t2. Рандом\nНапишите номер карты: ";
const char* LANG_RULES_CREATING_MAP = "\nПравила:\n\t0 - пустота\n\t1 - клетка\n\tn - переход на новую строчку\n\te - досрочное завершение\nВписывайте карту(удачи):\n";
const char* LANG_MOVE_COUNTER = "\nХод ";

const char* LANG_STYLE_ACT = "█";
const char* LANG_STYLE_INACT = "░";

void SetLocale() {
    setlocale(LC_ALL, "ru_RU");
}

void term_clear() {
    std::cout << "\x1B[2J\x1B[H";
}

void loin_home() {
    std::cout << "\x1B[H";
}