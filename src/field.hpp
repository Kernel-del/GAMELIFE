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
                    case '0':
                        (*this)[iy][ix] = 0;
                        break;
                    case '1':
                        (*this)[iy][ix] = 1;
                        break;
                    case 'n':
                        ix=x;
                        break;
                    case 'r':
                        ix=-1;
                        break;
                    case 'e':
                        ix=x; iy=y;
                        break;
                    case 'w':
                        --iy; --ix;
                        break;
                    case 'a':
                        ----ix;
                        break;
                    case 's':
                        ++iy; --ix;
                        break;
                    case 'd':
                        break;
                    case '\0':
                        ix=x; iy=y;
                        break;
                    default:
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
                    case '0':
                        (*this)[iy][ix] = 0;
                        break;
                    case '1':
                        (*this)[iy][ix] = 1;
                        break;
                    case 'n':
                        ix=x;
                        break;
                    case 'r':
                        ix=-1;
                        break;
                    case 'e':
                        ix=x; iy=y;
                        break;
                    case 'w':
                        --iy; --ix;
                        break;
                    case 'a':
                        ----ix;
                        break;
                    case 's':
                        ++iy; --ix;
                        break;
                    case 'd':
                        break;
                    case '\0':
                        ix=x; iy=y;
                        break;
                    default:
                        break;
                    }
                }
            }

            return *this;
        }
};