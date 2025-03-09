#include "src/import_lib.hpp"
#include "src/game.hpp"
#include "src/struct.hpp"


int main() {
    // Запуск
    int x = 0, y = 0, chosen_map;
    SetLocale(); // Устанавливаем кодировку из lang
    term_clear();

    // Комната №1
    std::cout << LANG_SET_SIZE; // Введите, через пробел, размеры поля(x, y): 
    std::cin >> x >> y;
    term_clear();

    // Комната №2
    std::cout << LANG_CHOSEN_MAP; // \n\nВыберите режим
    std::cin >> chosen_map;
    term_clear();

    
    Game game(x, y); // Создание поля

    // Комната №4 - подготовка поля перед основным циклом
    if (chosen_map==0) { // Комната №4.0 - выбор стандартных карт
        std::cout<<LANG_CHOSEN_SYSTEM_MAP; // Выберите карту
        std::cin >> chosen_map;

        switch (chosen_map)
        {
        case 1:
            game.getField().sys_input(STRUCT_glider);
            break;
        case 2:
            game.getField().sys_input(STRUCT_butterfly);
            break;
        case 3:
            game.getField().sys_input(STRUCT_living_forever);
            break;
        case 4:
            game.getField().sys_input(STRUCT_glider_gub);
            break;
        default:
            break;
        }
    } else if(chosen_map==1) { // Комната №4.1 - создание своей карты
        std::cout << LANG_RULES_CREATING_MAP; // Правила
        game.getField().player_input();

    } else {game.getField().randow_fill(0.5);} // // Комната №4.2 - рандомная карта

    // Комната №5 - основной цикл
    term_clear();
    for (int i = 1; true; ++i) {
        game.step(); // Обработка поля

        loin_home(); // Перемотка каретки в начало страницы

        game.print(); // Вывод поля
        std::cout << LANG_MOVE_COUNTER << i << "     \n"; // Счётчик ходов
        std::this_thread::sleep_for(std::chrono::milliseconds(150));

        if (i%30==0) {term_clear();} // Во избежание артифактов, вызванных изменением размера терминала
    }

    return 0;
}