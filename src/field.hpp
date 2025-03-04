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
};