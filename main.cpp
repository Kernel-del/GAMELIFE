#include "src/import_lib.hpp"
#include "src/game.hpp"
#include "src/struct.hpp"


int main() {
    SetLocale();
    int x = 0, y = 0, chosen_map;
    term_clear();

    std::cout << LANG_SET_SIZE; // Введите, через пробел, размеры поля(x, y): 
    std::cin >> x >> y;
    term_clear();

    std::cout << LANG_CHOSEN_MAP; // \n\nВыберите карту:\n\t0. Системные карты\n\t1. Своя карта\n\t2. Рандом\nНапишите номер карты: 
    std::cin >> chosen_map;
    term_clear();

    Game game(x, y);
    if (chosen_map==0) {
        std::cout<<LANG_CHOSEN_SYSTEM_MAP; // Выберите карту:\n\t1. glider\n\t2. butterfly\n\t3. living forever\n\t4. gluider gun\nНапишите номер карты: 
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
    } else if(chosen_map==1) {
        std::cout << LANG_RULES_CREATING_MAP; // "\nПравила:\n\t0 - пустота\n\t1 - клетка\n\tn - переход на новую строчку\n\te - досрочное завершение\nВписывайте карту(удачи):\n"
        game.getField().player_input();

    } else {game.getField().randow_fill(0.5);}

    term_clear();

    for (int i = 1; true; ++i) {
        game.step();

        loin_home();

        game.print();
        std::cout << LANG_MOVE_COUNTER << i << "     \n";
        std::this_thread::sleep_for(std::chrono::milliseconds(150));

        if (i%30==0) {term_clear();}
    }

    return 0;
}