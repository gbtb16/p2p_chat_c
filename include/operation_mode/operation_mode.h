//
//  operation_mode.h
//  p2p_chat_c
//
//  Created by Gabriel Barbosa on 25/01/25.
//

#pragma once
#ifndef _OPERATION_MODE_H_
#define _OPERATION_MODE_H_

// Enum for operation modes.
typedef enum {
    ServerOperationModeType,
    ClientOperationModeType,
    OperationModeTypesLength
} OperationModeType;

// Ask the user to choose the operation mode.
// Returns the user's choice.
int showOperationModeSetup(void);

#endif // _OPERATION_MODE_H_
