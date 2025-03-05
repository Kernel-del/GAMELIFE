#include "src/import_lib.hpp"
#include "src/game.hpp"
#include "src/struct.hpp"


int main() {
    SetLocale();

    int x = 0, y = 0, chosen_map;

    std::cout << LANG_SET_SIZE; // Введите, через пробел, размеры поля(x, y): 
    std::cin >> x >> y;

    std::cout << LANG_CHOSEN_MAP; // \n\nВыберите карту:\n\t0. Стандартная карта\n\t1. Своя карта\n\t2. Рандом\nНапишите номер карты: 
    std::cin >> chosen_map;

    Game game(x, y);
    if (chosen_map==0) {
        game.getField().sys_input(STRUCT_glider);
    } else if(chosen_map==1) {
        std::cout << LANG_RULES_CREATING_MAP; // "\nПравила:\n\t0 - пустота\n\t1 - клетка\n\tn - переход на новую строчку\n\te - досрочное завершение\nВписывайте карту(удачи):\n"
        game.getField().player_input();
    } else {game.getField().randow_fill(0.5);}

    term_clear();

    for (int i = 1; 1; ++i) {
        game.step();

        loin_home();

        game.print();
        std::cout << LANG_MOVE_COUNTER << i << "     \n";
        std::this_thread::sleep_for(std::chrono::milliseconds(100));

        if (i%120==0) {term_clear();}
    }

    return 0;
}