//
//  main.c
//  p2p_chat_c
//
//  Created by Gabriel Barbosa on 22/01/25.
//

#include "menu/menu.c"

int main(int argc, char *argv[]) {
    (void)argc;
    (void)argv;

    #ifdef _WIN32
        system("cls");
    #elif _WIN64
        system("cls");
    #else
        system("clear");
    #endif

    showMenu();
    return 0;
}
