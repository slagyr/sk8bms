#ifndef SK8BMS_COMMON_H
#define SK8BMS_COMMON_H

#include "stdlib.h"

typedef unsigned char uint8_t;

#ifndef PROGMEM
#warning "PROGMEM undefined"
#define PROGMEM
#endif

inline int availableMemory() {
    int size = 2048; // Use 2048 with ATmega328
    uint8_t *buf;

    while ((buf = (uint8_t *) malloc(--size)) == NULL)
        ;

    free(buf);

    return size;
}

#endif //SK8BMS_COMMON_H
