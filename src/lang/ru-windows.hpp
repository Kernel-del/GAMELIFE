#include "../import_lib.hpp"
#include <windows.h>

const char* LANG_SET_SIZE = "Введите, через пробел, размеры поля(x, y): "; // Выбор размера игрового поля

const char* LANG_CHOSEN_MAP = // Выбор режима
    "Выберите карту:"
        "\n\t0. Системные карты"
        "\n\t1. Своя карта"
        "\n\t2. Рандом"
        "\nНапишите номер карты: ";

const char* LANG_RULES_CREATING_MAP =  // Правила создание своей карты
    "Правила:"
        "\n\tПоставь блок:"
            "\n\t\t0 - пустота"
            "\n\t\t1 - клетка"
        "\n\tПеренос коретки:"
            "\n\t\tn - переход на новую строчку c переносом коретки в начало строки"
            "\n\t\tr - перенос коретки в начало строки"
            "\n\t\tw - перенос коретки на одну строчку вверх"
            "\n\t\ta - перенос коретки на одну клетку вправо"
            "\n\t\ts - перенос коретки на одну строчку вниз"
            "\n\t\td - перенос коретки на одну клетку влево"
        "\n\tСпец символы:"
            "\n\t\te - досрочное завершение"
    "\nВписывайте карту(удачи):\n";

const char* LANG_MOVE_COUNTER = "\nХод "; // Вывод хода

const char* LANG_CHOSEN_SYSTEM_MAP =  // Выбор каарты по умолчанию
    "Выберите карту:"
        "\n\t1. glider"
        "\n\t2. butterfly"
        "\n\t3. living forever"
        "\n\t4. gluider gun"
    "\nНапишите номер карты: ";

const char* LANG_STYLE_ACT = "##"; // Активированная ячейка
const char* LANG_STYLE_INACT = "  "; // Не активированная ячейка



void SetLocale() { // Установка языка (на всякий пожарный)
    SetConsoleOutputCP(CP_UTF8);
    setvbuf(stdout, nullptr, _IOFBF, 1000);
    setlocale(LC_ALL, "ru_RU");
}

void term_clear() { // Полная очистка терминала
    system("cls");
}

void loin_home() { // Перенос коретки в начало строки (я не знаю как это сделать на окне)
    system("cls");
}