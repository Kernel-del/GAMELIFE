#include "import_lib.hpp"
#include "field.hpp"

// Обработка линии
void step_line(Field& base, Field& tmp, int iy, int x, int y) {
    for (int ix = 0; ix < x; ++ix) {
        int health = 0;

        for (int jy = 0; jy < 3; ++jy) {  // Подсчёт соседий клетки
            for (int jx = 0; jx < 3; ++jx) {
                health+=base[iy-1+jy][ix-1+jx];
            }
        }

        if (base[iy][ix]) { // Если клетка жива, обрабатываем её СмЕрТь 
            if (health<3 or health>4) {
                tmp[iy][ix] = 0;
            } else {tmp[iy][ix] = 1;}
        } else { // Иначе рождаем или воскрешаем её :)
            if (health==3) {
                tmp[iy][ix] = 1;
            } else {
                tmp[iy][ix] = 0;
            }
        }
    }
}

// Основной движок игры
class Game{
    private:
        int y = 0;
        int x = 0;
        Field* base= new Field[2];
        bool selector = 0; // Выбор основной карты и tmp карты

        std::vector<std::thread> threads;
    public:
        Game(int x = 10, int y = 10): x(x),  y(y){
            base[0] = Field(x, y, 0);
            base[1] = Field(x, y, 0);

            std::vector<std::thread> threads(y);
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
                threads.emplace_back(step_line, std::ref(base[selector]), std::ref(base[!selector]), iy, x, y);
            }

            for (int iy = 0; iy < y; ++iy) {
                threads[iy].join();
            }
            threads.clear();

            selector=!selector; // Переключение выбора основной карты
            return *this;
        }
        

        ~Game() {
            threads.clear();
        }
};