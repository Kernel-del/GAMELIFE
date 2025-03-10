#include "src/import_lib.hpp"
#include "src/game.hpp"
#include "src/struct.hpp"


int main() {
    // Запуск
    int x = 0, y = 0, chosen_map;
    SetLocale(); // Устанавливаем кодировку из lang

    while (true) {
        // Комната №1
        term_clear();
        std::cout << lang::SET_SIZE; // Введите, через пробел, размеры поля(x, y): 
        std::cin >> x >> y;

        while (true) {
            // Комната №2
            term_clear();
            std::cout << lang::CHOSEN_MAP; // \n\nВыберите режим
            std::cin >> chosen_map;
            term_clear();

            
            Game game(x, y); // Создание поля

            // Комната №4 - подготовка поля перед основным циклом
            if (chosen_map==0) {break;
            } if (chosen_map==1) { // Комната №4.0 - выбор стандартных карт
                std::cout<<lang::CHOSEN_SYSTEM_MAP; // Выберите карту
                std::cin >> chosen_map;
                
                if (chosen_map==0) {continue; }

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
            } else if(chosen_map==2) { // Комната №4.1 - создание своей карты
                std::cout << lang::RULES_CREATING_MAP; // Правила
                game.getField().player_input();
            } else if(chosen_map==3) {game.getField().randow_fill(0.5); // // Комната №4.2 - рандомная карта
            } else {break; }

            // Комната №5 - основной цикл
            term_clear();
            for (int i = 1; true; ++i) {
                game.step(); // Обработка поля

                loin_home(); // Перемотка каретки в начало страницы

                game.print(); // Вывод поля
                std::cout << lang::MOVE_COUNTER << i << "     \n"; // Счётчик ходов
                std::this_thread::sleep_for(std::chrono::milliseconds(100));

                if (i%30==0) {term_clear();} // Во избежание артифактов, вызванных изменением размера терминала
            }
        }
    }


    return 0;
}