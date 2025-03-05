#include "import_lib.hpp"


class Line {
    private:
        int x = 0;
        std::vector<short> arr;
    public:
        Line(int x, short value): x(x), arr(x, value) {}
        short& operator[](int index) {
            int real_index = (index < 0) ? ((index % x + x) % x) : (index % x);
            return arr[real_index];
        }
        

        std::vector<short>::const_iterator begin() {return arr.begin(); }
        std::vector<short>::const_iterator end() {return arr.end(); }
};


class Field {
    private:
        int y = 0;
        int x = 0;
        std::vector<Line> arr;
    public:
        Field() {}
        Field(int x, int y, short value): x(x), y(y), arr(y, Line(x, value)) {}

        Line& operator [] (int index) {
            int real_index = (index < 0) ? ((index % y + y) % y) : (index % y);
            return arr[real_index];
        }

        std::vector<Line>::const_iterator begin() {return arr.begin(); }
        std::vector<Line>::const_iterator end() {return arr.end(); }

        Field& randow_fill(float act_perc) {
            for (int iy = 0; iy < y; ++iy) {
                for (int ix = 0; ix < x; ++ix) {
                    (*this)[iy][ix] = (std::rand()%static_cast<int>(1/act_perc*10000)/10000)<=act_perc;
                }
            }
        
            return *this;
        }

        Field& player_input() {
            char tmp;

            for (int iy = 0; iy < y; ++iy) {
                for (int ix = 0; ix < x; ++ix) {
                    std::cin >> tmp;
                    switch (tmp)
                    {
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
                    
                    default:
                        break;
                    }
                }
            }

            return *this;
        }

        Field& sys_input(char* str) {
            int i = 0;

            for (int iy = 0; iy < y; ++iy) {
                for (int ix = 0; ix < x; ++ix, ++i) {
                    switch (str[i])
                    {
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