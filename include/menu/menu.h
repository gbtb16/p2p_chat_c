//
//  menu.h
//  p2p_chat_c
//
//  Created by Gabriel Barbosa on 25/01/25.
//

#ifndef _MENU_H_
#define _MENU_H_

typedef enum {
    LanguageMenuOptionType,
    StartChatMenuOptionType,
    ExitMenuOptionType,
    MenuOptionTypesLength
} MenuOptionType;

// Show the entire menu.
void showMenu(void);

#endif // _MENU_H_
