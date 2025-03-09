#ifndef GAMELIFE_IMPORT
    #define GAMELIFE_IMPORT
    #include <iostream>
    #include <vector>
    #include <chrono>
    #include <thread>

    #ifdef DEBUG
        #ifdef LINUX // На всякий случай, при надобности
            std::cout << "Для linux\n";
        #else
            std::cout << "для windows\n";
        #endif
    #endif

    #ifdef LINUX
    #include "lang/ru-linux.hpp" // Языковой пакет линуксоидов
    #else
    #include "lang/ru-windows.hpp" // Языковой пакет фортачников
    #endif
#endif
