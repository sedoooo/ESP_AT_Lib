/**	
 * \file            esp_debug.h
 * \brief           Debugging inside ESP stack
 */
 
/*
 * Copyright (c) 2017 Tilen Majerle
 *  
 * Permission is hereby granted, free of charge, to any person
 * obtaining a copy of this software and associated documentation
 * files (the "Software"), to deal in the Software without restriction,
 * including without limitation the rights to use, copy, modify, merge,
 * publish, distribute, sublicense, and/or sell copies of the Software, 
 * and to permit persons to whom the Software is furnished to do so, 
 * subject to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be
 * included in all copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES
 * OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE
 * AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT
 * HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
 * WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING 
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
 * OTHER DEALINGS IN THE SOFTWARE.
 *
 * Author:          Tilen MAJERLE <tilen@majerle.eu>
 */
#ifndef __ESP_DEBUG_H
#define __ESP_DEBUG_H

/* C++ detection */
#ifdef __cplusplus
extern "C" {
#endif

#include "stdint.h"
#include "string.h"
    
#define ESP_DBG_ON                  0x80    /*!< Indicates debug is enabled */
#define ESP_DBG_OFF                 0       /*!< Indicates debug is disabled */
    
#define ESP_DBG_LVL_MASK            0x03    /*!< Mask for getting debug level */
#define ESP_DBG_LVL_ALL             0x00    /*!< Print all messages */
#define ESP_DBG_LVL_WARNING         0x01    /*!< Print warnings or more */
#define ESP_DBG_LVL_DANGER          0x02    /*!< Print danger errors */
#define ESP_DBG_LVL_SEVERE          0x03    /*!< Print severe problems affecting program flow */
    
#define ESP_DBG_LVL_MIN             ESP_DBG_LVL_ALL /*!< Minimal level to debug */

#define ESP_DBG                     ESP_DBG_ON    

#define ESP_DEBUG_INT(fmt, ...)     printf(fmt, ## __VA_ARGS__)
    
#if ESP_DBG || defined(__DOXYGEN__)
/**
 * \brief           Print message to the debug "window" if enabled
 * \param[in]       c: Condition if debug of specific type is enabled
 * \param[in]       fmt: Formatted string for debug
 * \param[in]       ...: Variable parameters for formatted string
 */
#define ESP_DEBUGF(c, fmt, ...)         do {\
    if (((c) & ESP_DBG_ON) && ((c) & ESP_DBG_LVL_MASK) >= ESP_DBG_LVL_MIN) {    \
        ESP_DEBUG_INT(fmt, ## __VA_ARGS__); \
    }                                       \
} while (0)

/**
 * \brief           Print message to the debug "window" if enabled when specific condition is met
 * \param[in]       c: Condition if debug of specific type is enabled
 * \param[in]       cond: Debug only if this condition is true
 * \param[in]       fmt: Formatted string for debug
 * \param[in]       ...: Variable parameters for formatted string
 */
#define ESP_DEBUGW(c, cond, fmt, ...)   do {\
    if (cond) {                             \
        ESP_DEBUGF(c, fmt, ## __VA_ARGS__); \
    }                                       \
} while (0)
#else
#define ESP_DEBUGF(c, fmt, ...)
#define ESP_DEBUGW(c, cond, fmt, ...)
#endif

/* C++ detection */
#ifdef __cplusplus
}
#endif

#endif /* __ESP_DEBUG_H */
