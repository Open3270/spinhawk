/* CRYPTO.C     (c) Copyright Jan Jaeger, 2000-2010                  */
/*              Cryptographic instructions                           */

// $Id$
//
// $Log$
// Revision 1.14  2007/06/23 00:04:05  ivan
// Update copyright notices to include current year (2007)
//
// Revision 1.13  2006/12/08 09:43:19  jj
// Add CVS message log
//

#include "hstdinc.h"

#define _CRYPTO_C_
#define _HENGINE_DLL_

#include "hercules.h"

#if defined(FEATURE_MESSAGE_SECURITY_ASSIST)

#include "opcode.h"

#define CRYPTO_EXTERN
#include "crypto.h"

/*----------------------------------------------------------------------------*/
/* B93E KIMD  - Compute Intermediate Message Digest                     [RRE] */
/*----------------------------------------------------------------------------*/
DEF_INST(compute_intermediate_message_digest_r)
{
    if( ARCH_DEP(compute_intermediate_message_digest) )
        ARCH_DEP(compute_intermediate_message_digest) (inst, regs);
    else
    {
    int  r1, r2;                                /* register values   */

        RRE(inst, regs, r1, r2);

        ARCH_DEP(program_interrupt) (regs, PGM_OPERATION_EXCEPTION);
    }
}

/*----------------------------------------------------------------------------*/
/* B93F KLMD  - Compute Last Message Digest                             [RRE] */
/*----------------------------------------------------------------------------*/
DEF_INST(compute_last_message_digest_r)
{
    if( ARCH_DEP(compute_last_message_digest) )
        ARCH_DEP(compute_last_message_digest) (inst, regs);
    else
    {
    int  r1, r2;                                /* register values   */

        RRE(inst, regs, r1, r2);

        ARCH_DEP(program_interrupt) (regs, PGM_OPERATION_EXCEPTION);
    }
}

/*----------------------------------------------------------------------------*/
/* B92E KM    - Cipher Message                                          [RRE] */
/*----------------------------------------------------------------------------*/
DEF_INST(cipher_message_r)
{
    if( ARCH_DEP(cipher_message) )
        ARCH_DEP(cipher_message) (inst, regs);
    else
    {
    int  r1, r2;                                /* register values   */

        RRE(inst, regs, r1, r2);

        ARCH_DEP(program_interrupt) (regs, PGM_OPERATION_EXCEPTION);
    }
}

/*----------------------------------------------------------------------------*/
/* B91E KMAC  - Compute Message Authentication Code                     [RRE] */
/*----------------------------------------------------------------------------*/
DEF_INST(compute_message_authentication_code_r)
{
    if( ARCH_DEP(compute_message_authentication_code) )
        ARCH_DEP(compute_message_authentication_code) (inst, regs);
    else
    {
    int  r1, r2;                                /* register values   */

        RRE(inst, regs, r1, r2);

        ARCH_DEP(program_interrupt) (regs, PGM_OPERATION_EXCEPTION);
    }
}

/*----------------------------------------------------------------------------*/
/* B92F KMC   - Cipher Message with Chaining                            [RRE] */
/*----------------------------------------------------------------------------*/
DEF_INST(cipher_message_with_chaining_r)
{
    if( ARCH_DEP(cipher_message_with_chaining) )
        ARCH_DEP(cipher_message_with_chaining) (inst, regs);
    else
    {
    int  r1, r2;                                /* register values   */

        RRE(inst, regs, r1, r2);

        ARCH_DEP(program_interrupt) (regs, PGM_OPERATION_EXCEPTION);
    }
}

#endif /*defined(FEATURE_MESSAGE_SECURITY_ASSIST)*/

#ifdef FEATURE_MESSAGE_SECURITY_ASSIST_EXTENSION_4
/*----------------------------------------------------------------------------*/
/* B92D KMCTR - Cipher message with counter                             [RRF] */
/*----------------------------------------------------------------------------*/
DEF_INST(cipher_message_with_counter_r)
{
    if( ARCH_DEP(cipher_message_with_counter) )
        ARCH_DEP(cipher_message_with_counter) (inst, regs);
    else
    {
    int  r1, r2, r3;                            /* register values   */

        RRF_M(inst, regs, r1, r2, r3);

        ARCH_DEP(program_interrupt) (regs, PGM_OPERATION_EXCEPTION);
    }
}

/*----------------------------------------------------------------------------*/
/* B92A KMF   - Cipher message with cipher feedback                     [RRE] */
/*----------------------------------------------------------------------------*/
DEF_INST(cipher_message_with_cipher_feedback_r)
{
    if( ARCH_DEP(cipher_message_with_cipher_feedback) )
        ARCH_DEP(cipher_message_with_cipher_feedback) (inst, regs);
    else
    {
    int  r1, r2;                                /* register values   */

        RRE(inst, regs, r1, r2);

        ARCH_DEP(program_interrupt) (regs, PGM_OPERATION_EXCEPTION);
    }
}

/*----------------------------------------------------------------------------*/
/* B92B KMO   - Cipher message with output feedback                     [RRE] */
/*----------------------------------------------------------------------------*/
DEF_INST(cipher_message_with_output_feedback_r)
{
    if( ARCH_DEP(cipher_message_with_output_feedback) )
        ARCH_DEP(cipher_message_with_output_feedback) (inst, regs);
    else
    {
    int  r1, r2;                                /* register values   */

        RRE(inst, regs, r1, r2);

        ARCH_DEP(program_interrupt) (regs, PGM_OPERATION_EXCEPTION);
    }
}

/*----------------------------------------------------------------------------*/
/* B92C PCC  - Perform cryptographic computation                        [RRE] */
/*----------------------------------------------------------------------------*/
DEF_INST(perform_cryptographic_computation_r)
{
    if( ARCH_DEP(perform_cryptographic_computation) )
        ARCH_DEP(perform_cryptographic_computation) (inst, regs);
    else
    {
    int  r1, r2;                                /* register values   */

        RRE(inst, regs, r1, r2);

        ARCH_DEP(program_interrupt) (regs, PGM_OPERATION_EXCEPTION);
    }
}
#endif /* FEATURE_MESSAGE_SECURITY_ASSIST_EXTENSION_4 */

#ifdef FEATURE_MESSAGE_SECURITY_ASSIST_EXTENSION_3
/*----------------------------------------------------------------------------*/
/* B928 PCKMO - Perform cryptographic key management operation          [RRE] */
/*----------------------------------------------------------------------------*/
DEF_INST(perform_cryptographic_key_management_operations_r)
{
    if( ARCH_DEP(perform_cryptographic_key_management_operations) )
        ARCH_DEP(perform_cryptographic_key_management_operations) (inst, regs);
    else
    {
    int  r1, r2;                                /* register values   */

        RRE(inst, regs, r1, r2);

        ARCH_DEP(program_interrupt) (regs, PGM_OPERATION_EXCEPTION);
    }
}

#ifndef __WK__
#define __WK__
/*----------------------------------------------------------------------------*/
/* Function: renew_wrapping_keys                                              */
/*                                                                            */
/* Each time a clear reset is performed, a new set of wrapping keys and their */
/* associated verification patterns are generated. The contents of the two    */
/* wrapping-key registers are kept internal to the model so that no program,  */
/* including the operating system, can directly observe their clear value.    */
/*----------------------------------------------------------------------------*/
void renew_wrapping_keys(void)
{
  int i;
  U64 time;
  BYTE lparname[8];

  obtain_lock(&sysblk.wklock);
  time = host_tod();
  srandom(time);
  for(i = 0; i < 32; i++)
    sysblk.wkaes_reg[i] = random();
  for(i = 0; i < 24; i++)
    sysblk.wkdea_reg[i] = random();
  memset(sysblk.wkvpaes_reg, 0, 32);
  memset(sysblk.wkvpdea_reg, 0, 24);
  get_lparname(lparname);
  memcpy((char *) sysblk.wkvpaes_reg, lparname, 8);
  memcpy((char *) sysblk.wkvpdea_reg, lparname, 8);
  for(i = 0; i < 8; i++)
  {
    sysblk.wkvpaes_reg[31 - i] = time;
    sysblk.wkvpdea_reg[23 - i] = time;
    time >>= 8;
  }
  release_lock(&sysblk.wklock);

#if 0
  logmsg("AES wrapping key: ");
  for(i = 0; i < 32; i++)
    logmsg("%02X", sysblk.wkaes_reg[i]);
  logmsg("\nAES wrapping key verification pattern: ");
  for(i = 0; i < 32; i++)
    logmsg("%02X", sysblk.wkvpaes_reg[i]);
  logmsg("\nDEA wrapping key: ");
  for(i = 0; i < 24; i++)
    logmsg("%02X", sysblk.wkdea_reg[i]);
  logmsg("\nDEA wrapping key verification pattern: ");
  for(i = 0; i < 24; i++)
    logmsg("%02X", sysblk.wkvpdea_reg[i]);
  logmsg("\n");
#endif
}
#endif
#endif /* FEATURE_MESSAGE_SECURITY_ASSIST_EXTENSION_3 */

#if !defined(_GEN_ARCH)

#if defined(_ARCHMODE2)
 #define  _GEN_ARCH _ARCHMODE2
 #include "crypto.c"
#endif

#if defined(_ARCHMODE3)
 #undef   _GEN_ARCH
 #define  _GEN_ARCH _ARCHMODE3
 #include "crypto.c"
#endif

#endif /*!defined(_GEN_ARCH)*/
