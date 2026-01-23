/*******************************************************************************
  Main Source File

  Company:
    Microchip Technology Inc.

  File Name:
    main.c

  Summary:
    This file contains the "main" function for a project.

  Description:
    This file contains the "main" function for a project.  The
    "main" function calls the "SYS_Initialize" function to initialize the state
    machines of all modules in the system
 *******************************************************************************/

// *****************************************************************************
// *****************************************************************************
// Section: Included Files
// *****************************************************************************
// *****************************************************************************

#include <stddef.h>                     // Defines NULL
#include <stdbool.h>                    // Defines true
#include <stdlib.h>                     // Defines EXIT_FAILURE
#include "definitions.h"                // SYS function prototypes
#include <stdio.h>

#include "ansicolor.h"

#define S_LED0_BLINK_RATE 500           // milliseconds

/* typedef for non-secure callback functions */
typedef void (*funcptr_void) (void) __attribute__((cmse_nonsecure_call));

struct systickContext {
    uint32_t nextToggle;
};

void toggle_S_LED0(uintptr_t context);

int main ( void )
{
    uint32_t msp_ns = *((uint32_t *)(TZ_START_NS));
    volatile funcptr_void NonSecure_ResetHandler;

    struct systickContext toggleContext;
    uintptr_t pTC = (uintptr_t)&toggleContext;

    /* Initialize all modules */
    SYS_Initialize ( NULL );

    printf( ANSI_BLACK ANSI_BK_GREEN "[Reset]" ANSI_GREEN ANSI_BK_BLACK "\n\r");

    SYSTICK_TimerCallbackSet ( toggle_S_LED0, pTC );

    SYSTICK_TimerStart();

    S_LED0_Clear();
    
    toggleContext.nextToggle = SYSTICK_GetTickCounter() + S_LED0_BLINK_RATE;
    
    if (msp_ns != 0xFFFFFFFF)
    {
        /* Set non-secure main stack (MSP_NS) */
        __TZ_set_MSP_NS(msp_ns);

        /* Get non-secure reset handler */
        NonSecure_ResetHandler = (funcptr_void)(*((uint32_t *)((TZ_START_NS) + 4U)));

        /* Start non-secure state software application */
        NonSecure_ResetHandler();
    }
       
    while ( true )
    {
    }

    /* Execution should not come here during normal operation */
    return ( EXIT_FAILURE );
}

void toggle_S_LED0(uintptr_t context) {
    uint32_t currentTick;
    struct systickContext *toggleContext = (struct systickContext*) context;
    
    currentTick = SYSTICK_GetTickCounter();

    if(currentTick == toggleContext->nextToggle) {
        toggleContext->nextToggle = currentTick + S_LED0_BLINK_RATE;
        S_LED0_Toggle();
        printf("S_LED0 Toggle\n\r");
    }
}
/*******************************************************************************
 End of File
*/

