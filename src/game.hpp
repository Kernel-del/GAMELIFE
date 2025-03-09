#include "import_lib.hpp"
#include "field.hpp"


// Основной движок игры
class Game{
    private:
        int y = 0;
        int x = 0;
        Field* base= new Field[2];
        bool selector = 0; // Выбор основной карты и tmp карты
    public:
        Game(int x = 10, int y = 10): x(x),  y(y){
            base[0] = Field(x, y, 0);
            base[1] = Field(x, y, 0);
        }

        // Вывод содержимого основной карты
        void print() {
            for (auto i: base[selector]) {
                for (auto j: i) {
                    std::cout << (j ? LANG_STYLE_ACT : LANG_STYLE_INACT);
                }
                std::cout << '\n';
            }
        }

        // Получение ссылки на основное поле
        Field& getField() {return base[selector];}

        // Обработка хода
        Game& step() {
            for (int iy = 0; iy < y; ++iy) {
                for (int ix = 0; ix < x; ++ix) {
                    int health = 0;

                    for (int jy = 0; jy < 3; ++jy) {  // Подсчёт соседий клетки
                        for (int jx = 0; jx < 3; ++jx) {
                            health+=base[selector][iy-1+jy][ix-1+jx];
                        }
                    }

                    if (base[selector][iy][ix]) { // Если клетка жива, обрабатываем её СмЕрТь 
                        if (health<3 or health>4) {
                            base[!selector][iy][ix] = 0;
                        } else {base[!selector][iy][ix] = 1;}
                    } else { // Иначе рождаем или воскрешаем её :)
                        if (health==3) {
                            base[!selector][iy][ix] = 1;
                        } else {
                            base[!selector][iy][ix] = 0;
                        }
                    }
                }
            }

            selector=!selector; // Переключение выбора основной карты
            return *this;
        }
};