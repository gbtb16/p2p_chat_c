//
//  main.c
//  p2p_chat_c
//
//  Created by Gabriel Barbosa on 22/01/25.
//

#include <stdlib.h>

#include "../include/menu/menu.h"

int main(int argc, char *argv[]) {
    #ifdef _WIN32
            system("cls");
        #else
            system("clear");
        #endif

    showMenu();
    return 0;
}
