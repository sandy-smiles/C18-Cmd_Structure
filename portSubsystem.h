/* 
 * File:   portSubsystem.h
 * Author: 470203101
 * Header file for port bit manipulation.
 * 
 * Created: 20191002
 * 
 */

/*
 * When programming with a port, you:
 * - Initialise I/O with TRIS
 * - Read from the PORT
 * - Write to the LAT
 */


#ifndef PORTSUBSYSTEM_H
#define	PORTSUBSYSTEM_H

typedef struct portSubsystem {
    unsigned char *tris;
    unsigned char *port;
    unsigned char *lat;
} portSubsystem_t;

portSubsystem_t *newPort(portSubsystem_t *this, unsigned char *tris_port, unsigned char tris_val, unsigned char *port, unsigned char *lat, unsigned char lat_val);
portSubsystem_t *setTris(portSubsystem_t *this, unsigned char data);
portSubsystem_t *setLat(portSubsystem_t *this, unsigned char value);
unsigned char getPort(portSubsystem_t *this);
unsigned char getLat(portSubsystem_t *this);

#endif	/* PORTSUBSYSTEM_H */

