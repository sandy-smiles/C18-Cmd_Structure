/* 
 * File:   cmd.h
 * Author: 470203101
 * Header file for command structure.
 * 
 * Created: 20191003
 * 
 */

#ifndef CMD_H
#define	CMD_H

typedef struct cmd {
    void (*run)(void *);    // Pointer to the run function
    int  (*isFinished)(void *);    // Pointer to the isFinished function
    void (*end)(void *);    // Pointer to the end function
    void (*interrupted)(void *);    // Pointer to the interrupted function
    void *private;    // Pointer to command's private data
} cmd_t;

#endif	/* CMD_H */

