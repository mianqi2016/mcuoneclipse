/* ###################################################################
**     This component module is generated by Processor Expert. Do not modify it.
**     Filename    : HF1.h
**     Project     : ProcessorExpert
**     Processor   : MK64FN1M0VLL12
**     Component   : HardFault
**     Version     : Component 01.020, Driver 01.00, CPU db: 3.00.000
**     Compiler    : GNU C Compiler
**     Date/Time   : 2018-07-10, 11:42, # CodeGen: 3
**     Abstract    :
**          Component to simplify hard faults for ARM/Kinetis.
**     Settings    :
**          Component name                                 : HF1
**     Contents    :
**         HardFaultHandler - void HF1_HardFaultHandler(void);
**         Deinit           - void HF1_Deinit(void);
**         Init             - void HF1_Init(void);
**
** * Copyright (c) 2014-2017, Erich Styger
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
** @file HF1.h
** @version 01.00
** @brief
**          Component to simplify hard faults for ARM/Kinetis.
*/         
/*!
**  @addtogroup HF1_module HF1 module documentation
**  @{
*/         

#ifndef __HF1_H
#define __HF1_H

/* MODULE HF1. */
#include "MCUC1.h" /* SDK and API used */
#include "HF1config.h" /* configuration */




void HF1_HardFaultHandler(void);
/*
** ===================================================================
**     Method      :  HardFaultHandler (component HardFault)
**
**     Description :
**         Hard Fault Handler
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/

#ifdef __GNUC__ /* 'used' attribute needed for GNU LTO (Link Time Optimization) */
void HF1_HandlerC(uint32_t *hardfault_args) __attribute__((used));
#else
void HF1_HandlerC(uint32_t *hardfault_args);
#endif
/*
** ===================================================================
**     Method      :  HF1_HandlerC (component HardFault)
**
**     Description :
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/

void HF1_Deinit(void);
/*
** ===================================================================
**     Method      :  Deinit (component HardFault)
**
**     Description :
**         Deinitializes the driver
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/

void HF1_Init(void);
/*
** ===================================================================
**     Method      :  Init (component HardFault)
**
**     Description :
**         Initializes the driver
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/

/* END HF1. */

#endif
/* ifndef __HF1_H */
/*!
** @}
*/
