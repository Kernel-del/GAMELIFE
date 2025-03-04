#include "src/import_lib.hpp"
#include "src/game.hpp"



int main() {
    SetLocale();

    int x = 0, y = 0, chosen_map; char tmp;

    std::cout << LANG_SET_SIZE; // Введите, через пробел, размеры поля(x, y): 
    std::cin >> x >> y;

    std::cout << LANG_CHOSEN_MAP; // \n\nВыберите карту:\n\t0. Стандартная карта\n\t1. Своя карта\n\t2. Рандом\nНапишите номер карты: 
    std::cin >> chosen_map;

    Game game(x, y);
    if (chosen_map==0) {
        game.getField()[0][2]=1;
        game.getField()[1][3]=1;
        game.getField()[2][1]=1; game.getField()[2][2]=1; game.getField()[2][3]=1;
    } else if(chosen_map==1) {
        std::cout << LANG_RULES_CREATING_MAP; // "\nПравила:\n\t0 - пустота\n\t1 - клетка\n\tn - переход на новую строчку\n\te - досрочное завершение\nВписывайте карту(удачи):\n"
        for (int iy = 0; iy < y; ++iy) {
            for (int ix = 0; ix < x; ++ix) {
                std::cin >> tmp;
                switch (tmp)
                {
                case '0':
                    game.getField()[iy][ix] = 0;
                    break;
                case '1':
                    game.getField()[iy][ix] = 1;
                    break;
                case 'n':
                    ix=x;
                    break;
                case 'e':
                    ix=x; iy=y;
                    break;
                
                default:
                    break;
                }
            }
        }
    } else {
        for (int iy = 0; iy < y; ++iy) {
            for (int ix = 0; ix < x; ++ix) {
                game.getField()[iy][ix] = std::rand()%2;
            }
        }
    }

    term_clear();

    for (int i = 1; i < 100000; ++i) {
        game.step();

        loin_home();

        game.print();
        std::cout << LANG_MOVE_COUNTER << i << "     \n";
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }

    return 0;
}