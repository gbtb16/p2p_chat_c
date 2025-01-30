//
//  menu.h
//  p2p_chat_c
//
//  Created by Gabriel Barbosa on 25/01/25.
//

#pragma once
#ifndef _MENU_H_
#define _MENU_H_

#include "../l10n/localization.h"
#include "../utils/utils.h"

#define TRUNCATE_IF_MENU_OPTION_LABEL_IS_TOO_LONG 1
#define MAX_MENU_OPTION_LABEL_LENGTH 32

// Enum for the different types of menu options.
typedef enum {
    LanguageMenuOptionType,
    StartChatMenuOptionType,
    ExitMenuOptionType,
    MenuOptionTypesLength
} MenuOptionType;

// Struct for a menu option.
// type: The type of the menu option.
// choiceNumber: The number of the choice in the menu.
// label: The label of the menu option.
typedef struct MenuOption {
    MenuOptionType type;
    int choiceNumber;
    char label[MAX_MENU_OPTION_LABEL_LENGTH];
} MenuOption;

// Show the entire menu.
void showMenu(void);

#endif // _MENU_H_
