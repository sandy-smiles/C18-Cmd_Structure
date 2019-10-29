/* 
 * File:   portSubsystem.c
 * Author: 470203101
 * Implementation file for port bit manipulation.
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

#include <stdio.h>
#include <stdlib.h>
#include "portSubsystem.h"

// Create a new port.
portSubsystem_t *newPort(portSubsystem_t *this, unsigned char *tris_port, unsigned char tris_val, unsigned char *port, unsigned char *lat, unsigned char lat_val) {
    
    // Initialise starting variables
    this->tris = tris_port;
    *(this->tris) = tris_val;
    this->port = port;
    this->lat = lat;
    *(this->tris) = lat_val;
    
    return this;
}

portSubsystem_t *setTris(portSubsystem_t *this, unsigned char data) {
    *(this->tris) = data;
    return this;
}
portSubsystem_t *setLat(portSubsystem_t *this, unsigned char value) {
    *(this->lat) = value;
    return this;
}
unsigned char getPort(portSubsystem_t *this) {
    return *(this->port);
}

unsigned char getLat(portSubsystem_t *this) {
    return *(this->lat);
}
