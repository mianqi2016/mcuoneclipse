/* ###################################################################
**     This component module is generated by Processor Expert. Do not modify it.
**     Filename    : TMOUT1.h
**     Project     : ProcessorExpert
**     Processor   : MK64FN1M0VLL12
**     Component   : Timeout
**     Version     : Component 01.037, Driver 01.00, CPU db: 3.00.000
**     Compiler    : GNU C Compiler
**     Date/Time   : 2018-07-10, 11:42, # CodeGen: 3
**     Abstract    :
**
The module implements timeout functionality. With this implementation,
it is possible to wait for a given time, and the time is counted by
a periodic interrupt.
**     Settings    :
**          Component name                                 : TMOUT1
**          Maximum counters                               : 1
**          Counter tick period (ms)                       : 10
**          RTOS                                           : Disabled
**     Contents    :
**         GetCounter     - TMOUT1_CounterHandle TMOUT1_GetCounter(TMOUT1_CounterType nofTicks);
**         LeaveCounter   - void TMOUT1_LeaveCounter(TMOUT1_CounterHandle handle);
**         Value          - TMOUT1_CounterType TMOUT1_Value(TMOUT1_CounterHandle handle);
**         SetCounter     - TMOUT1_CounterType TMOUT1_SetCounter(TMOUT1_CounterHandle handle,...
**         CounterExpired - bool TMOUT1_CounterExpired(TMOUT1_CounterHandle handle);
**         AddTick        - void TMOUT1_AddTick(void);
**         Init           - void TMOUT1_Init(void);
**
** * Copyright (c) 2011-2016, Erich Styger
**  * Web:         https://mcuoneclipse.com
**  * SourceForge: https://sourceforge.net/projects/mcuoneclipse
**  * Git:         https://github.com/ErichStyger/McuOnEclipse_PEx
**  * All rights reserved.
**  *
**  * Redistribution and use in source and binary forms, with or without modification,
**  * are permitted provided that the following conditions are met:
**  *
**  * - Redistributions of source code must retain the above copyright notice, this list
**  *   of conditions and the following disclaimer.
**  *
**  * - Redistributions in binary form must reproduce the above copyright notice, this
**  *   list of conditions and the following disclaimer in the documentation and/or
**  *   other materials provided with the distribution.
**  *
**  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
**  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
**  * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
**  * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
**  * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
**  * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
**  * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
**  * ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
**  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
**  * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
** ###################################################################*/
/*!
** @file TMOUT1.h
** @version 01.00
** @brief
**
The module implements timeout functionality. With this implementation,
it is possible to wait for a given time, and the time is counted by
a periodic interrupt.
*/         
/*!
**  @addtogroup TMOUT1_module TMOUT1 module documentation
**  @{
*/         

#ifndef __TMOUT1_H
#define __TMOUT1_H

/* MODULE TMOUT1. */
#include "MCUC1.h" /* SDK and API used */
#include "TMOUT1config.h" /* configuration */

/* Include inherited components */
#include "MCUC1.h"
#include "CS1.h"


#ifndef __BWUserType_TMOUT1_CounterType
#define __BWUserType_TMOUT1_CounterType
  typedef uint32_t TMOUT1_CounterType ; /* Base type of counter which holds the counting value */
#endif
#ifndef __BWUserType_TMOUT1_CounterHandle
#define __BWUserType_TMOUT1_CounterHandle
  typedef uint8_t TMOUT1_CounterHandle ; /* Type for the timeout counter handle. */
#endif

#define TMOUT1_OUT_OF_HANDLE 0xff  /* special handle to indicate that we were running out of handlers */
#define TMOUT1_TICK_PERIOD_MS  \
  10                                    /* Tick period of timeout counter in milliseconds, as specified in component properties */


TMOUT1_CounterHandle TMOUT1_GetCounter(TMOUT1_CounterType nofTicks);
/*
** ===================================================================
**     Method      :  GetCounter (component Timeout)
**
**     Description :
**         Initializes a new timeout counter and returns the handle to
**         it. At the end, use LeaveCounter() to free up the resource.
**     Parameters  :
**         NAME            - DESCRIPTION
**         nofTicks        - Number of ticks for the counter
**                           until it expires.
**     Returns     :
**         ---             - Handle to the counter, to be used for
**                           further API calls.
** ===================================================================
*/

void TMOUT1_LeaveCounter(TMOUT1_CounterHandle handle);
/*
** ===================================================================
**     Method      :  LeaveCounter (component Timeout)
**
**     Description :
**         To be called to return the counter. Note that a counter
**         always should be returned so it can be reused.
**     Parameters  :
**         NAME            - DESCRIPTION
**         handle          - Counter handle
**     Returns     : Nothing
** ===================================================================
*/

bool TMOUT1_CounterExpired(TMOUT1_CounterHandle handle);
/*
** ===================================================================
**     Method      :  CounterExpired (component Timeout)
**
**     Description :
**         Returns true if the timeout counter has been expired
**     Parameters  :
**         NAME            - DESCRIPTION
**         handle          - The timeout handle retrieved using
**                           GetCounter()
**     Returns     :
**         ---             - Returns TRUE if the counter has been
**                           expired, FALSE otherwise
** ===================================================================
*/

void TMOUT1_AddTick(void);
/*
** ===================================================================
**     Method      :  AddTick (component Timeout)
**
**     Description :
**         Method to be called from a periodic timer or interrupt. It
**         will decrement all current counters by one down to zero.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/

void TMOUT1_Init(void);
/*
** ===================================================================
**     Method      :  Init (component Timeout)
**
**     Description :
**         Initialization of the driver
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/

TMOUT1_CounterType TMOUT1_Value(TMOUT1_CounterHandle handle);
/*
** ===================================================================
**     Method      :  Value (component Timeout)
**
**     Description :
**         Return the current value of the counter (in ticks)
**     Parameters  :
**         NAME            - DESCRIPTION
**         handle          - Handle of the timeout counter
**     Returns     :
**         ---             - Returns the value of the timeout counter.
** ===================================================================
*/

TMOUT1_CounterType TMOUT1_SetCounter(TMOUT1_CounterHandle handle, TMOUT1_CounterType nofTicks);
/*
** ===================================================================
**     Method      :  SetCounter (component Timeout)
**
**     Description :
**         Sets the counter to a new value and returns the value just
**         prior to the call.
**     Parameters  :
**         NAME            - DESCRIPTION
**         handle          - Counter handle which shall get a new
**                           value.
**         nofTicks        - New value (tick count) of the
**                           timeout counter. Pass zero to have it
**                           expire immediately.
**     Returns     :
**         ---             - Value of counter before reset.
** ===================================================================
*/

/* END TMOUT1. */

#endif
/* ifndef __TMOUT1_H */
/*!
** @}
*/
