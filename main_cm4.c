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


int main(void)
{
    __enable_irq(); /* Enable global interrupts. */
    
    xTaskCreate(vGreenTask, "led", 80, NULL, 3, NULL);
    vTaskStartScheduler();
    /* Place your initialization/startup code here (e.g. MyInst_Start()) */

    for(;;)
    {
        /* Place your application code here. */
    }
}

/* [] END OF FILE */
