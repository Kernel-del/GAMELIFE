#include "import_lib.hpp"


class Line { // Класс обработки выхода за пределы массива
    private:
        int x = 0;
        std::vector<bool> arr;
    public:
        Line(int x, bool value): x(x), arr(x, value) {}
        std::vector<bool>::reference operator[](int index) {
            int real_index = (index < 0) ? ((index % x + x) % x) : (index % x);
            return arr[real_index];
        }
        std::vector<bool>::const_reference operator[](int index) const {
            int real_index = (index < 0) ? ((index % x + x) % x) : (index % x);
            return arr[real_index];
        }

        // Для удобной работы с циклом for(auto i: Line)
        std::vector<bool>::const_iterator begin() {return arr.begin(); }
        std::vector<bool>::const_iterator end() {return arr.end(); }
};


class Field { // Класс поля
    private:
        int y = 0;
        int x = 0;
        std::vector<Line> arr;

        int cy = -1; int cx = -1;
    public:
        Field() {}
        Field(int x, int y, bool value): x(x), y(y), arr(y, Line(x, value)) {}

        Line& operator [] (int index) {
            int real_index = (index < 0) ? ((index % y + y) % y) : (index % y);
            return arr[real_index];
        }

        // Для удобной работы с циклом for(auto i: Line)
        std::vector<Line>::const_iterator begin() {return arr.begin(); }
        std::vector<Line>::const_iterator end() {return arr.end(); }

        // рандомное заполнение поля
        Field& randow_fill(float act_perc) {
            for (int iy = 0; iy < y; ++iy) {
                for (int ix = 0; ix < x; ++ix) {
                    (*this)[iy][ix] = (std::rand()%static_cast<int>(1/act_perc*10000)/10000)<=act_perc;
                }
            }
        
            return *this;
        }

        // Обработка входящих клавиш
        Field& player_input() {
            char tmp;

            for (int iy = 0; iy < y; ++iy) {
                for (int ix = 0; ix < x; ++ix) {
                    std::cin >> tmp;
                    switch (tmp) {
                        case ' ': // Ставит пустоту
                            (*this)[iy][ix] = 0;
                            break;
                        case '0': // Ставит пустоту
                            (*this)[iy][ix] = 0;
                            break;
                        case '1': // Ставит клетку
                            (*this)[iy][ix] = 1;
                            break;
                        case 'n': // Перенос на новую строку
                            ix=x;
                            break;
                        case 'h': // Перенос на нулевые координаты
                            ix = -1; iy = 0;
                            break;
                        case 'r': // Перенос в начало строки
                            ix=-1;
                            break;
                        case 'e': // Досрочное завершение
                            ix=x; iy=y;
                            break;
                        case 'w': // Перемещение вверх
                            --iy; --ix;
                            break;
                        case 'a': // Перемещение вправо
                            ----ix;
                            break;
                        case 's': // Перемещение вниз
                            ++iy; --ix;
                            break;
                        case 'd': // Перемещение вправо
                            break;
                        case 'c': // Скопировать положение коретки
                            --ix;
                            cy = iy; cx = ix;
                            break;
                        case 'p': // переместить коретку в точку копирования
                            iy = cy; ix = cx;
                            break;
                        case '\0': // Досрочное завершение
                            ix=x; iy=y;
                            break;
                        default: // Перемещение вправо
                            break;
                    }
                }
            }

            return *this;
        }

        // Обработка входящей строки
        Field& sys_input(char* str) {
            int i = 0;

            for (int iy = 0; iy < y; ++iy) {
                for (int ix = 0; ix < x; ++ix, ++i) {
                    switch (str[i]) {
                        case ' ': // Ставит пустоту
                            (*this)[iy][ix] = 0;
                            break;
                        case '0': // Ставит пустоту
                            (*this)[iy][ix] = 0;
                            break;
                        case '1': // Ставит клетку
                            (*this)[iy][ix] = 1;
                            break;
                        case 'n': // Перенос на новую строку
                            ix=x;
                            break;
                        case 'h': // Перенос на нулевые координаты
                            ix = -1; iy = 0;
                            break;
                        case 'r': // Перенос в начало строки
                            ix=-1;
                            break;
                        case 'e': // Досрочное завершение
                            ix=x; iy=y;
                            break;
                        case 'w': // Перемещение вверх
                            --iy; --ix;
                            break;
                        case 'a': // Перемещение вправо
                            ----ix;
                            break;
                        case 's': // Перемещение вниз
                            ++iy; --ix;
                            break;
                        case 'd': // Перемещение вправо
                            break;
                        case 'c': // Скопировать положение коретки
                            --ix;
                            cy = iy; cx = ix;
                            break;
                        case 'p': // переместить коретку в точку копирования
                            iy = cy; ix = cx;
                            break;
                        case '\0': // Досрочное завершение
                            ix=x; iy=y;
                            break;
                        default: // Перемещение вправо
                            break;
                    }
                }
            }

            return *this;
        }
        Field& sys_input(std::string str) {
            int i = 0;

            for (int iy = 0; iy < y; ++iy) {
                for (int ix = 0; ix < x; ++ix, ++i) {
                    switch (str[i]) {
                        case ' ': // Ставит пустоту
                            (*this)[iy][ix] = 0;
                            break;
                        case '0': // Ставит пустоту
                            (*this)[iy][ix] = 0;
                            break;
                        case '1': // Ставит клетку
                            (*this)[iy][ix] = 1;
                            break;
                        case 'n': // Перенос на новую строку
                            ix=x;
                            break;
                        case 'h': // Перенос на нулевые координаты
                            ix = -1; iy = 0;
                            break;
                        case 'r': // Перенос в начало строки
                            ix=-1;
                            break;
                        case 'e': // Досрочное завершение
                            ix=x; iy=y;
                            break;
                        case 'w': // Перемещение вверх
                            --iy; --ix;
                            break;
                        case 'a': // Перемещение вправо
                            ----ix;
                            break;
                        case 's': // Перемещение вниз
                            ++iy; --ix;
                            break;
                        case 'd': // Перемещение вправо
                            break;
                        case 'c': // Скопировать положение коретки
                            --ix;
                            cy = iy; cx = ix;
                            break;
                        case 'p': // переместить коретку в точку копирования
                            iy = cy; ix = cx;
                            break;
                        case '\0': // Досрочное завершение
                            ix=x; iy=y;
                            break;
                        default: // Перемещение вправо
                            break;
                    }
                }
            }

            return *this;
        }
};