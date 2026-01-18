//
// Created by 29113 on 2025/11/21.
//

#ifndef CHUANCHUANKOU_ASCIIDISPLAY_H
#define CHUANCHUANKOU_ASCIIDISPLAY_H
#include <stdint.h>
#include "stdio.h"

extern const unsigned char Basstt[53];
extern const unsigned char scp[1378];
extern  const unsigned char scp_ver2[53 * 26];
extern const unsigned char scp_ver3[53 * 26];
extern const unsigned char scp_ver4[53 * 26];
extern const unsigned char scp_ver5[53 * 26];
extern const unsigned char scp_ver6[53 * 26];
extern const unsigned char scp_ver7[53 * 26];
extern const unsigned char scp_ver8[53 * 26];
extern const unsigned char scp_ver9[53 * 26];
extern const unsigned char scp_ver10[53 * 26];
extern const unsigned char scp_ver11[53 * 26];
extern const unsigned char scp_ver12[53 * 26];
extern const unsigned char scp_ver13[53 * 26];
extern const unsigned char THANKU[46 * 6];


void display(uint16_t x_init, uint16_t y_init, uint16_t heng, uint16_t lie, const unsigned char *paint);

void display_in_RED(uint16_t x_init, uint16_t y_init, uint16_t heng, uint16_t lie,const unsigned char *paint);

void display_quick(uint16_t x_init, uint16_t y_init, uint16_t heng, uint16_t lie,const unsigned char *paint);

#endif //CHUANCHUANKOU_ASCIIDISPLAY_H