#ifndef SK8BMS_COMMON_H
#define SK8BMS_COMMON_H

#include "stdlib.h"

typedef unsigned char byte;

#ifndef PROGMEM
//#warning "PROGMEM undefined"
//#define PROGMEM
//#include <avr/pgmspace.h>
#define __ATTR_PROGMEM__ __attribute__((__progmem__))
#define PROGMEM __ATTR_PROGMEM__
#endif

inline int availableMemory() {
    int size = 2048; // Use 2048 with ATmega328
    byte *buf;

    while ((buf = (byte *) malloc(--size)) == NULL)
        ;

    free(buf);

    return size;
}

#endif
