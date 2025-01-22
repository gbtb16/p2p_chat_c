//
//  localization.h
//  p2p_chat_c
//
//  Created by Gabriel Barbosa on 22/01/25.
//

#ifndef LOCALIZATION_H_
#define LOCALIZATION_H_

#include "localization_en.h"
#include "localization_pt.h"

// Enum for languages
typedef enum {
    LangTypeEn,
    LangTypePt,
    TotalNumberOfLanguages
} LanguageType;

// Localization structure
typedef struct {
    const char *languageSetMessage;
    const char *welcomeMessage;
    const char *selectOperationModeMessage;
    const char *typePeerIpMessage;
    const char *typePeerPortMessage;
    const char *goodbyeMessage;
} Localization;

// Array of localizations
static const Localization localizations[TotalNumberOfLanguages] = {
    [LangTypeEn] = {
        .languageSetMessage = LANG_EN_LANGUAGE_SET_MSG,
        .welcomeMessage = LANG_EN_WELCOME_MSG,
        .selectOperationModeMessage = LANG_EN_SELECT_OP_MODE_MSG,
        .typePeerIpMessage = LANG_EN_TYPE_PEER_IP_MSG,
        .typePeerPortMessage = LANG_EN_TYPE_PEER_PORT_MSG,
        .goodbyeMessage = LANG_EN_GOODBYE_MSG
    },
    [LangTypePt] = {
        .languageSetMessage = LANG_PT_LANGUAGE_SET_MSG,
        .welcomeMessage = LANG_PT_WELCOME_MSG,
        .selectOperationModeMessage = LANG_PT_SELECT_OP_MODE_MSG,
        .typePeerIpMessage = LANG_PT_TYPE_PEER_IP_MSG,
        .typePeerPortMessage = LANG_PT_TYPE_PEER_PORT_MSG,
        .goodbyeMessage = LANG_PT_GOODBYE_MSG
    }
};

// Current localization pointer
extern const Localization *currentLocalization;

// Function to ask user the language choice
// Returns the choice number
int askLanguageChoice();

// Function to select language
void setLanguage(LanguageType type);

#endif // LOCALIZATION_H_
