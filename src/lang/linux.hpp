#include "../import_lib.hpp"


const char* LANG_STYLE_ACT = "██"; // Активированная ячейка
const char* LANG_STYLE_INACT = "░░"; // Не активированная ячейка

void SetLocale() { // Установка языка (на всякий пожарный)
    setlocale(LC_ALL, "ru_RU");
}

void term_clear() { // Полная очистка терминала
    std::cout << "\x1B[2J\x1B[H";
}

void loin_home() { // Перенос коретки в начало строки
    std::cout << "\x1B[H";
}