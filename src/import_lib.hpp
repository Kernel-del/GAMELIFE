#ifndef GAMELIFE_IMPORT
    #define GAMELIFE_IMPORT
    #include <iostream>
    #include <vector>
    #include <chrono>
    #include <thread>
    #include <string>
    #include <csignal>
    #include <cstdlib>

    #ifdef DEBUG
        #ifdef LINUX // На всякий случай, при надобности
            std::cout << "Для linux\n";
        #else
            std::cout << "для windows\n";
        #endif
    #endif

    #ifdef LINUX
    #include "lang/linux.hpp" // Языковой пакет линуксоидов
    #else
    #include "lang/windows.hpp" // Языковой пакет фортачников
    #endif

    #include "lang/Ru_ru.hpp"
#endif
