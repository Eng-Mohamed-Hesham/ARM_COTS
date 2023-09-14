#ifndef MSYSTICK_PRIVATE_H
#define MSYSTICK_PRIVATE_H

#define STK_BASE_ADDR               0xE000E010

#define STK_CTRLR_OFFSET            0x00
#define STK_LOADR_OFFSET            0x04
#define STK_VALR_OFFSET             0x08

#define STK_CTRLR                   *((u32 volatile *) (STK_BASE_ADDR + STK_CTRLR_OFFSET))
#define STK_LOADR                   *((u32 volatile *) (STK_BASE_ADDR + STK_LOADR_OFFSET))
#define STK_VALR                    *((u32 volatile *) (STK_BASE_ADDR + STK_VALR_OFFSET))

#endif
