//
//  errors.h
//  p2p_chat_c
//
//  Created by Gabriel Barbosa on 28/01/25.
//

#pragma once
#ifndef _ERRORS_H_
#define _ERRORS_H_

#include <stdlib.h>
#include <stdio.h>

// Print a message in stdout.
// The program will continue running.
void throwStandardError(const char *message);

// Print a critical error message and exit the program.
// The message will be printed in stderr.
// The program will exit with status -1.
void throwCriticalError(const char *message);

// Print a message in stderr and exit the program.
// The message will be printed in stderr.
// The program will exit with status -1.
void throwMemoryAllocationFailed(void);

#endif // _ERRORS_H_
