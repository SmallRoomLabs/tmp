/* File: bus.h
   Author: Douglas Jones, Dept. of Comp. Sci., U. of Iowa, Iowa City, IA 52242.
   Date: July 26, 1995
   Updates: Mats Engstrom, April 2020
   Language: C (UNIX)
   Purpose: Declarations of bus lines shared by PDP8/E and peripherals.
            This is not, strictly speaking, either an omnibus or a positive
            I/O bus, but rather, it is a set of declarations driven by the
	    needs of system emulation.
		
   Based on the description in the PDP-8/E Small Computer Handbook,
   Digital Equipment Corporation, 1971.
*/


/******************************************/
/* Utility information needed by emulator */
/******************************************/

/* absolute path name of file where emulator object code is to be stored
*/
#define PDP8NAME "pdp8emu"

/* maximum length of a sensible file name
*/
#define NAME_LENGTH 120



/*****************************************************/
/* Globals that really aren't really part of the bus */
/*****************************************************/

extern char corename[NAME_LENGTH]; /* name of core image file, if any */
extern char * progname; /* name of program itself (argv[0]) */


/**********/
/* Memory */
/**********/

/* This emulator does not allow for non-contiguous memory fields.
   Checking of memory addressing errors is not done, so all addressable
   memory must be available.  Thus, the memory size depends on whether
   the KM8E option is present.
*/

#define MAXMEM 32768

extern int memory[MAXMEM];


/*******************************/
/* Generally visible registers */
/*******************************/

/* All of the following are visible outside the CPU in some context or
   another, either to some I/O device or to the front panel.
*/
extern int ac;  /* the accumulator, 12 bits */
extern int pc;  /* the program counter, 12 bits */
extern int mq;  /* the multiplier quotient, 12 bits */
extern int sr;  /* the switch register */
extern int cpma;/* the memory address register */
extern int mb;  /* the memory buffer register */

extern int link;/* the link bit, 1 bit, in position 010000 of the word */
extern int run; /* the run flipflop, 0 = halt, 1 = running */

extern int enab;/* interrupt enable bit, 0 = disable, 1=enable */
extern int enab_rtf; /* secodary enable needed for RTF deferred enable */
extern int irq; /* the interrupt request line, 0 = no request, >0 = request */

extern int sw;  /* the switch, 1 bit */

/* Note that any positive value of irq indicates a request!  Requests are
   posted by incrementing irq, and withdrawn by decrementing irq.
*/


/* 3 bit fields stored 12 places left so they can be ORed onto 12 addresses.
*/
extern int ifr; /* the instruction field register */
extern int dfr; /* the data field register */
extern int ib; /* the instruction field buffer (copy to if on branch, jsr) */

/* 7 bits, exactly as documented in the small computer handbook
*/
extern int sf; /* the save field register (save ir, if, df on interrupt) */

/* 1 bit, where ub is copied to uf on branch, jsr
*/
extern int uf; /* the user mode flag */
extern int ub; /* the user mode buffer */

/* 1 bit, reset on branch, jsr
*/
extern int km8e_uif; /* user interrupt flag (local to KM8E but used in KK8E) */

