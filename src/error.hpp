#include "import_lib.hpp"


void error(int signum) {
    cursor_visibility(1);
    exit(signum);
}