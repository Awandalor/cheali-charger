/*
    cheali-charger - open source firmware for a variety of LiPo chargers
    Copyright (C) 2014 Paweł Stawicki. All right reserved.

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/
#ifndef CPU_H_
#define CPU_H_

extern "C" {
#include "DrvSYS.h"
}



//TODO: implement
namespace cpu {
    inline void init() {
        UNLOCKREG();
        SYSCLK->PWRCON.XTL12M_EN = 1;
        /* Waiting for 12M Xtal stable */
        while (DrvSYS_GetChipClockSourceStatus(E_SYS_XTL12M) != 1);

        DrvSYS_SelectHCLKSource(0);
        /* HCLK clock frequency = HCLK clock source / (HCLK_N + 1) */
        DrvSYS_SetClockDivider(E_SYS_HCLK_DIV, 0);
    }
}

#endif /* CPU_H_ */
