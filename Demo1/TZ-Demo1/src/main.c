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

#include "ansicolor.h"
#include "trustZone/nonsecure_entry.h"

// *****************************************************************************
// *****************************************************************************
// Section: Main Entry Point
// *****************************************************************************
// *****************************************************************************

int main ( void )
{
    uint32_t* specialInfo;
    
    /* Initialize all modules */
    SYS_Initialize ( NULL );

    printf( ANSI_WHITE ANSI_BK_RED "[Reset]" ANSI_RED ANSI_BK_BLACK "\n\r");
    SYSTICK_TimerStart();
    
    while ( true )
    {
        /* Maintain state machines of all polled MPLAB Harmony modules. */
        SYS_Tasks ( );
        NS_LED1_Toggle();
        printf("NS_LED1 Toggle\n\r");
        secure_print("NS_LED1 Toggle");
        specialInfo = (uint32_t*) secure_getInformation();
        printf("Info Address: %x\n\r", specialInfo);
        printf("Info: %x\n\r", *specialInfo);
        SYSTICK_DelayMs(500);
    }

    /* Execution should not come here during normal operation */

    return ( EXIT_FAILURE );
}


/*******************************************************************************
 End of File
*/

