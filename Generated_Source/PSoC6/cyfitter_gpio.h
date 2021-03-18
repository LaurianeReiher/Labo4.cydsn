/*******************************************************************************
* File Name: cyfitter_gpio.h
* 
* PSoC Creator  4.4
*
* Description:
* 
* This file is automatically generated by PSoC Creator.
*
********************************************************************************
* Copyright (c) 2007-2020 Cypress Semiconductor.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
********************************************************************************/

#ifndef INCLUDED_CYFITTER_GPIO_H
#define INCLUDED_CYFITTER_GPIO_H
#include "cy_device_headers.h"

/* LED */
#define LED_0_DRIVEMODE CY_GPIO_DM_PULLUP
#define LED_0_INBUF_ENABLED 1u
#define LED_0_INIT_DRIVESTATE 1u
#define LED_0_INIT_MUXSEL 0u
#define LED_0_INPUT_SYNC 2u
#define LED_0_INTERRUPT_MODE CY_GPIO_INTR_DISABLE
#define LED_0_NUM 1u
#define LED_0_PORT GPIO_PRT1
#define LED_0_SLEWRATE CY_GPIO_SLEW_FAST
#define LED_0_THRESHOLD_LEVEL CY_GPIO_VTRIP_CMOS
#define LED_DRIVEMODE CY_GPIO_DM_PULLUP
#define LED_INBUF_ENABLED 1u
#define LED_INIT_DRIVESTATE 1u
#define LED_INIT_MUXSEL 0u
#define LED_INPUT_SYNC 2u
#define LED_INTERRUPT_MODE CY_GPIO_INTR_DISABLE
#define LED_NUM 1u
#define LED_PORT GPIO_PRT1
#define LED_SLEWRATE CY_GPIO_SLEW_FAST
#define LED_THRESHOLD_LEVEL CY_GPIO_VTRIP_CMOS

/* Bouton */
#define Bouton_0_DRIVEMODE CY_GPIO_DM_PULLUP
#define Bouton_0_INBUF_ENABLED 1u
#define Bouton_0_INIT_DRIVESTATE 1u
#define Bouton_0_INIT_MUXSEL 0u
#define Bouton_0_INPUT_SYNC 2u
#define Bouton_0_INTERRUPT_MODE CY_GPIO_INTR_BOTH
#define Bouton_0_NUM 4u
#define Bouton_0_PORT GPIO_PRT0
#define Bouton_0_SLEWRATE CY_GPIO_SLEW_FAST
#define Bouton_0_THRESHOLD_LEVEL CY_GPIO_VTRIP_CMOS
#define Bouton_DRIVEMODE CY_GPIO_DM_PULLUP
#define Bouton_INBUF_ENABLED 1u
#define Bouton_INIT_DRIVESTATE 1u
#define Bouton_INIT_MUXSEL 0u
#define Bouton_INPUT_SYNC 2u
#define Bouton_INTERRUPT_MODE CY_GPIO_INTR_BOTH
#define Bouton_NUM 4u
#define Bouton_PORT GPIO_PRT0
#define Bouton_SLEWRATE CY_GPIO_SLEW_FAST
#define Bouton_THRESHOLD_LEVEL CY_GPIO_VTRIP_CMOS

/* UART_rx */
#define UART_rx_0_DRIVEMODE CY_GPIO_DM_HIGHZ
#define UART_rx_0_INBUF_ENABLED 1u
#define UART_rx_0_INIT_DRIVESTATE 1u
#define UART_rx_0_INIT_MUXSEL 18u
#define UART_rx_0_INPUT_SYNC 2u
#define UART_rx_0_INTERRUPT_MODE CY_GPIO_INTR_DISABLE
#define UART_rx_0_NUM 0u
#define UART_rx_0_PORT GPIO_PRT5
#define UART_rx_0_SLEWRATE CY_GPIO_SLEW_FAST
#define UART_rx_0_THRESHOLD_LEVEL CY_GPIO_VTRIP_CMOS
#define UART_rx_DRIVEMODE CY_GPIO_DM_HIGHZ
#define UART_rx_INBUF_ENABLED 1u
#define UART_rx_INIT_DRIVESTATE 1u
#define UART_rx_INIT_MUXSEL 18u
#define UART_rx_INPUT_SYNC 2u
#define UART_rx_INTERRUPT_MODE CY_GPIO_INTR_DISABLE
#define UART_rx_NUM 0u
#define UART_rx_PORT GPIO_PRT5
#define UART_rx_SLEWRATE CY_GPIO_SLEW_FAST
#define UART_rx_THRESHOLD_LEVEL CY_GPIO_VTRIP_CMOS

/* UART_tx */
#define UART_tx_0_DRIVEMODE CY_GPIO_DM_STRONG_IN_OFF
#define UART_tx_0_INBUF_ENABLED 0u
#define UART_tx_0_INIT_DRIVESTATE 1u
#define UART_tx_0_INIT_MUXSEL 18u
#define UART_tx_0_INPUT_SYNC 2u
#define UART_tx_0_INTERRUPT_MODE CY_GPIO_INTR_DISABLE
#define UART_tx_0_NUM 1u
#define UART_tx_0_PORT GPIO_PRT5
#define UART_tx_0_SLEWRATE CY_GPIO_SLEW_FAST
#define UART_tx_0_THRESHOLD_LEVEL CY_GPIO_VTRIP_CMOS
#define UART_tx_DRIVEMODE CY_GPIO_DM_STRONG_IN_OFF
#define UART_tx_INBUF_ENABLED 0u
#define UART_tx_INIT_DRIVESTATE 1u
#define UART_tx_INIT_MUXSEL 18u
#define UART_tx_INPUT_SYNC 2u
#define UART_tx_INTERRUPT_MODE CY_GPIO_INTR_DISABLE
#define UART_tx_NUM 1u
#define UART_tx_PORT GPIO_PRT5
#define UART_tx_SLEWRATE CY_GPIO_SLEW_FAST
#define UART_tx_THRESHOLD_LEVEL CY_GPIO_VTRIP_CMOS

#endif /* INCLUDED_CYFITTER_GPIO_H */
