//
//  utils.h
//  p2p_chat_c
//
//  Created by Gabriel Barbosa on 28/01/25.
//

#ifndef _UTILS_H
#define _UTILS_H

// Print a message in stdout.
void standardError(const char *message);

// Print a critical error message and exit the program.
// The message will be printed in stderr.
// The program will exit with status 1.
void criticalError(const char *message);

// Print a message in stderr and exit the program.
// The message will be printed in stderr.
// The program will exit with status 1.
void memoryAllocationFailed(void);

#endif // _UTILS_H
