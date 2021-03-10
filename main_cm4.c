/* ========================================
 * Laboratoire 4 
 * Par Lauriane Grondin-Reiher (2011285) et Andréa Skaf (2011061)
 *
 * Lien github : https://github.com/LaurianeReiher/Labo4.cydsn.git
 *
 *
 *
 * Copyright YOUR COMPANY, THE YEAR
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF your company.
 *
 * ========================================
*/
#include "project.h"
#include "FreeRTOS.h"
#include "task.h"
#include "semphr.h"
#include "params.h"
#include "queue.h"

SemaphoreHandle_t semaphore;

// Partie 1 

void vGreenTask ()
{
    for(;;)
    {
        vTaskDelay(pdMS_TO_TICKS(500));
        Cy_GPIO_Write(LED_0_PORT, LED_0_NUM, 0);
        vTaskDelay(pdMS_TO_TICKS(500));
        Cy_GPIO_Write(LED_0_PORT, LED_0_NUM, 1);
    }
}

// Partie 2 

void isr_bouton(void)
{
    xSemaphoreGiveFromISR(semaphore, NULL);
    Cy_GPIO_ClearInterrupt(Bouton_0_PORT, Bouton_0_NUM);
    NVIC_ClearPendingIRQ(Bouton_ISR_cfg.intrSrc);
}

void bouton_Task()
{
    //xSemaphoreTakeFromISR(semaphore, NULL);
    vTaskDelay(pdMS_TO_TICKS(20));
    if (xSemaphoreTakeFromISR(semaphore, NULL)==pdTRUE)
    {
        UART_PutString("Bouton appuye");
    }
    else 
        UART_PutString("Bouton relache");
    
    
}

int main(void)
{
    __enable_irq(); /* Enable global interrupts. */
    
    semaphore = xSemaphoreCreateBinary();
    // Partie 1
    xTaskCreate(vGreenTask, "led", 80, NULL, 3, NULL);
    vTaskStartScheduler();
    
    // Partie 2
    UART_Start();
    Cy_GPIO_ClearInterrupt(Bouton_0_PORT, Bouton_0_NUM);
    NVIC_ClearPendingIRQ(Bouton_ISR_cfg.intrSrc);
    
    /* Place your initialization/startup code here (e.g. MyInst_Start()) */

    for(;;)
    {
        /* Place your application code here. */
    }
}

/* [] END OF FILE */
