#ifndef GAMELIFE_IMPORT
    #define GAMELIFE_IMPORT
    #include <iostream>
    #include <vector>
    #include <chrono>
    #include <thread>

    #ifdef DEBUG
        #ifdef LINUX //Очистка экрана
            std::cout << "Для linux\n";
        #else
            std::cout << "для windows\n";
        #endif
    #endif

    #ifdef LINUX
    #include "lang/ru-linux.hpp"
    #else
    #include "lang/ru-windows.hpp"
    #endif
#endif
