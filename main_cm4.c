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

volatile SemaphoreHandle_t bouton_semph; // Déclaration du sémaphore globalement (Partie 2)

task_params_t task_A = {                 // Structures globales (Partie 3)
    .delay = 1000,
    .message = "Tache A en cours\n\r"
};

task_params_t task_B = {
    .delay = 999,
    .message = "Tache B en cours\n\r"
};

// Partie 1 

void vGreenTask ()
{
    for(;;)
    {
        vTaskDelay(pdMS_TO_TICKS(500));
        Cy_GPIO_Write(LED_0_PORT, LED_0_NUM,!(Cy_GPIO_Read(LED_0_PORT, LED_0_NUM)));
        
        //Cy_GPIO_Write(LED_0_PORT, LED_0_NUM, 0);
        //vTaskDelay(pdMS_TO_TICKS(500));
        //Cy_GPIO_Write(LED_0_PORT, LED_0_NUM, 1);
    }
}

// Partie 2 

void isr_bouton(void)
{
    Cy_SysPm_PmicUnlock();
    xSemaphoreGiveFromISR(bouton_semph, NULL);
    Cy_GPIO_ClearInterrupt(Bouton_0_PORT, Bouton_0_NUM);
    NVIC_ClearPendingIRQ(Bouton_ISR_cfg.intrSrc);
}

void bouton_Task()
{
    
    for (;;)
    {
        xSemaphoreTake(bouton_semph, portMAX_DELAY); // Attente du sémaphore
        vTaskDelay(pdMS_TO_TICKS(20)); // Délai de 20 ms à des fins de debouncing
        
        {
        
            if(Cy_GPIO_Read(Bouton_0_PORT, Bouton_0_NUM)==0)  // Quand le bouton est appuyé, l'état du port est de 0
            {
            UART_PutString("Bouton appuye\n\r");
            
            }
            else
            {
            UART_PutString("Bouton relache\n\r");  
            }
        }
        bouton_semph = xSemaphoreCreateBinary();  // Création d'un nouveau sémaphore car simplement redonner le premier pose problème
    }
    
    
    
    
}

// Partie 3 
task_params_t *pointeurA = &task_A;
task_params_t *pointeurB = &task_B;

 void print_loop(void *params)  // affiche périodiquement un message via le UART. 
{
    for (;;)
    {
        if (params == &task_A)
        {
            vTaskDelay(pdMS_TO_TICKS(task_A.delay));
            UART_PutString(task_A.message);
        }
        else if (params == &task_B)
        {
            vTaskDelay(pdMS_TO_TICKS(task_B.delay));
            UART_PutString(task_B.message);
        }
    }
} 

int main(void)
{
    
    bouton_semph = xSemaphoreCreateBinary();
    
    __enable_irq(); /* Enable global interrupts. */
    
    Cy_SysInt_Init(&Bouton_ISR_cfg, isr_bouton);
    Cy_GPIO_ClearInterrupt(Bouton_0_PORT, Bouton_0_NUM);
    NVIC_ClearPendingIRQ(Bouton_ISR_cfg.intrSrc);
    NVIC_EnableIRQ(Bouton_ISR_cfg.intrSrc);
    
    
    xTaskCreate(vGreenTask, "led", 80, NULL, 3, NULL);
    
    UART_Start();
    xTaskCreate(bouton_Task, "Bouton", 80, NULL, 3, NULL);
    
    xTaskCreate(print_loop, "task A", configMINIMAL_STACK_SIZE, (void *) &task_A, 1, NULL);
    xTaskCreate(print_loop, "task B", configMINIMAL_STACK_SIZE, (void *) &task_B, 1, NULL);
    
    
    /* Place your initialization/startup code here (e.g. MyInst_Start()) */
    
    vTaskStartScheduler();  // À la fin car le programme ne sort jamais de cette fonction
    for(;;)
    {
        /* Place your application code here. */
    }
}

/* [] END OF FILE */
