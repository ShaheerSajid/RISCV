/*
 ****************************************************************************
 *
 *                   "DHRYSTONE" Benchmark Program
 *                   -----------------------------
 *                                                                            
 *  Version:    C, Version 2.1
 *                                                                            
 *  File:       dhry_1.c (part 2 of 3)
 *
 *  Date:       May 25, 1988
 *
 *  Author:     Reinhold P. Weicker
 *
 ****************************************************************************
 */

#include "dhry.h"
#include <string.h>
#include "libs/util/delay.h"
#include "libs/sys/serial/serial.h"
#include "libs/sys/gpio/gpio.h"
#include "libs/sys/timer/timer.h"
#include "libs/util/print.h"


#ifndef DHRY_ITERS
#define DHRY_ITERS 10000
#endif

/* Global Variables: */

Rec_Pointer     Ptr_Glob,
                Next_Ptr_Glob;
int             Int_Glob;
Boolean         Bool_Glob;
char            Ch_1_Glob,
                Ch_2_Glob;
int             Arr_1_Glob [50];
int             Arr_2_Glob [50] [50];

extern char     *malloc ();
Enumeration     Func_1 ();
  /* forward declaration necessary since Enumeration may not simply be int */

#ifndef REG
        Boolean Reg = false;
#define REG
        /* REG becomes defined as empty */
        /* i.e. no register variables   */
#else
        Boolean Reg = true;
#endif

/* variables for time measurement: */


int            Begin_Time,
                End_Time,
                User_Time;


/* end of variables for time measurement */


main ()
/*****/
  /* main program, corresponds to procedures        */
  /* Main and Proc_0 in the Ada version             */
{
char snum[100];

        One_Fifty       Int_1_Loc;
  REG   One_Fifty       Int_2_Loc;
        One_Fifty       Int_3_Loc;
  REG   char            Ch_Index;
        Enumeration     Enum_Loc;
        Str_30          Str_1_Loc;
        Str_30          Str_2_Loc;
  REG   int             Run_Index;
  REG   int             Number_Of_Runs;

  /* Initializations */

  Next_Ptr_Glob = (Rec_Pointer) malloc (sizeof (Rec_Type));
  Ptr_Glob = (Rec_Pointer) malloc (sizeof (Rec_Type));

  Ptr_Glob->Ptr_Comp                    = Next_Ptr_Glob;
  Ptr_Glob->Discr                       = Ident_1;
  Ptr_Glob->variant.var_1.Enum_Comp     = Ident_3;
  Ptr_Glob->variant.var_1.Int_Comp      = 40;
  strcpy (Ptr_Glob->variant.var_1.Str_Comp, 
          "DHRYSTONE PROGRAM, SOME STRING");
  strcpy (Str_1_Loc, "DHRYSTONE PROGRAM, 1'ST STRING");

  Arr_2_Glob [8][7] = 10;
        /* Was missing in published program. Without this statement,    */
        /* Arr_2_Glob [8][7] would have an undefined value.             */
        /* Warning: With 16-Bit processors and Number_Of_Runs > 32000,  */
        /* overflow may occur for this array element.                   */
  sprintf(snum,"\n");serial_puts(snum);
  sprintf(snum,"Dhrystone Benchmark, Version 2.1 (Language: C)\n");serial_puts(snum);
  sprintf(snum,"\n");serial_puts(snum);
  if (Reg)
  {
    sprintf(snum,"Program compiled with 'register' attribute\n");serial_puts(snum);
    sprintf(snum,"\n");serial_puts(snum);
  }
  else
  {
    sprintf(snum,"Program compiled without 'register' attribute\n");serial_puts(snum);
    sprintf(snum,"\n");serial_puts(snum);
  }
#ifdef DHRY_ITERS
  Number_Of_Runs = DHRY_ITERS;
#else
  sprintf(snum,"Please give the number of runs through the benchmark: ");
  {
    int n;
    scanf ("%d", &n);
    Number_Of_Runs = n;
  }
  sprintf(snum,"\n");
#endif

  sprintf(snum,"Execution starts, %d runs through Dhrystone\n", Number_Of_Runs);serial_puts(snum);

  /***************/
  /* Start timer */
  /***************/
  timer_set_prescaler(PRE_1);
  Begin_Time = timer_read_cnt();


  for (Run_Index = 1; Run_Index <= Number_Of_Runs; ++Run_Index)
  {

    Proc_5();
    Proc_4();
      /* Ch_1_Glob == 'A', Ch_2_Glob == 'B', Bool_Glob == true */
    Int_1_Loc = 2;
    Int_2_Loc = 3;
    strcpy (Str_2_Loc, "DHRYSTONE PROGRAM, 2'ND STRING");
    Enum_Loc = Ident_2;
    Bool_Glob = ! Func_2 (Str_1_Loc, Str_2_Loc);
      /* Bool_Glob == 1 */
    while (Int_1_Loc < Int_2_Loc)  /* loop body executed once */
    {
      Int_3_Loc = 5 * Int_1_Loc - Int_2_Loc;
        /* Int_3_Loc == 7 */
      Proc_7 (Int_1_Loc, Int_2_Loc, &Int_3_Loc);
        /* Int_3_Loc == 7 */
      Int_1_Loc += 1;
    } /* while */
      /* Int_1_Loc == 3, Int_2_Loc == 3, Int_3_Loc == 7 */
    Proc_8 (Arr_1_Glob, Arr_2_Glob, Int_1_Loc, Int_3_Loc);
      /* Int_Glob == 5 */
    Proc_1 (Ptr_Glob);
    for (Ch_Index = 'A'; Ch_Index <= Ch_2_Glob; ++Ch_Index)
                             /* loop body executed twice */
    {
      if (Enum_Loc == Func_1 (Ch_Index, 'C'))
          /* then, not executed */
        {
        Proc_6 (Ident_1, &Enum_Loc);
        strcpy (Str_2_Loc, "DHRYSTONE PROGRAM, 3'RD STRING");
        Int_2_Loc = Run_Index;
        Int_Glob = Run_Index;
        }
    }
      /* Int_1_Loc == 3, Int_2_Loc == 3, Int_3_Loc == 7 */
    Int_2_Loc = Int_2_Loc * Int_1_Loc;
    Int_1_Loc = Int_2_Loc / Int_3_Loc;
    Int_2_Loc = 7 * (Int_2_Loc - Int_3_Loc) - Int_1_Loc;
      /* Int_1_Loc == 1, Int_2_Loc == 13, Int_3_Loc == 7 */
    Proc_2 (&Int_1_Loc);
      /* Int_1_Loc == 5 */

  } /* loop "for Run_Index" */

  /**************/
  /* Stop timer */
  /**************/
  

  End_Time = timer_read_cnt();


  sprintf(snum,"Execution ends\n");serial_puts(snum);
  sprintf(snum,"\n");serial_puts(snum);
  sprintf(snum,"Final values of the variables used in the benchmark:\n");serial_puts(snum);
  sprintf(snum,"\n");serial_puts(snum);
  sprintf(snum,"Int_Glob:            %d\n", Int_Glob);serial_puts(snum);
  sprintf(snum,"        should be:   %d\n", 5);serial_puts(snum);
  sprintf(snum,"Bool_Glob:           %d\n", Bool_Glob);serial_puts(snum);
  sprintf(snum,"        should be:   %d\n", 1);serial_puts(snum);
  sprintf(snum,"Ch_1_Glob:           %c\n", Ch_1_Glob);serial_puts(snum);
  sprintf(snum,"        should be:   %c\n", 'A');serial_puts(snum);
  sprintf(snum,"Ch_2_Glob:           %c\n", Ch_2_Glob);serial_puts(snum);
  sprintf(snum,"        should be:   %c\n", 'B');serial_puts(snum);
  sprintf(snum,"Arr_1_Glob[8]:       %d\n", Arr_1_Glob[8]);serial_puts(snum);
  sprintf(snum,"        should be:   %d\n", 7);serial_puts(snum);
  sprintf(snum,"Arr_2_Glob[8][7]:    %d\n", Arr_2_Glob[8][7]);serial_puts(snum);
  sprintf(snum,"        should be:   Number_Of_Runs + 10\n");serial_puts(snum);
  sprintf(snum,"Ptr_Glob->\n");serial_puts(snum);
  sprintf(snum,"  Ptr_Comp:          %d\n", (int) Ptr_Glob->Ptr_Comp);serial_puts(snum);
  sprintf(snum,"        should be:   (implementation-dependent)\n");serial_puts(snum);
  sprintf(snum,"  Discr:             %d\n", Ptr_Glob->Discr);serial_puts(snum);
  sprintf(snum,"        should be:   %d\n", 0);serial_puts(snum);
  sprintf(snum,"  Enum_Comp:         %d\n", Ptr_Glob->variant.var_1.Enum_Comp);serial_puts(snum);
  sprintf(snum,"        should be:   %d\n", 2);serial_puts(snum);
  sprintf(snum,"  Int_Comp:          %d\n", Ptr_Glob->variant.var_1.Int_Comp);serial_puts(snum);
  sprintf(snum,"        should be:   %d\n", 17);serial_puts(snum);
  sprintf(snum,"  Str_Comp:          %s\n", Ptr_Glob->variant.var_1.Str_Comp);serial_puts(snum);
  sprintf(snum,"        should be:   DHRYSTONE PROGRAM, SOME STRING\n");serial_puts(snum);
  sprintf(snum,"Next_Ptr_Glob->\n");serial_puts(snum);
  sprintf(snum,"  Ptr_Comp:          %d\n", (int) Next_Ptr_Glob->Ptr_Comp);serial_puts(snum);
  sprintf(snum,"        should be:   (implementation-dependent), same as above\n");serial_puts(snum);
  sprintf(snum,"  Discr:             %d\n", Next_Ptr_Glob->Discr);serial_puts(snum);
  sprintf(snum,"        should be:   %d\n", 0);serial_puts(snum);
  sprintf(snum,"  Enum_Comp:         %d\n", Next_Ptr_Glob->variant.var_1.Enum_Comp);serial_puts(snum);
  sprintf(snum,"        should be:   %d\n", 1);serial_puts(snum);
  sprintf(snum,"  Int_Comp:          %d\n", Next_Ptr_Glob->variant.var_1.Int_Comp);serial_puts(snum);
  sprintf(snum,"        should be:   %d\n", 18);serial_puts(snum);
  sprintf(snum,"  Str_Comp:          %s\n",
                                Next_Ptr_Glob->variant.var_1.Str_Comp);serial_puts(snum);
  sprintf(snum,"        should be:   DHRYSTONE PROGRAM, SOME STRING\n");serial_puts(snum);
  sprintf(snum,"Int_1_Loc:           %d\n", Int_1_Loc);serial_puts(snum);
  sprintf(snum,"        should be:   %d\n", 5);serial_puts(snum);
  sprintf(snum,"Int_2_Loc:           %d\n", Int_2_Loc);serial_puts(snum);
  sprintf(snum,"        should be:   %d\n", 13);serial_puts(snum);
  sprintf(snum,"Int_3_Loc:           %d\n", Int_3_Loc);serial_puts(snum);
  sprintf(snum,"        should be:   %d\n", 7);serial_puts(snum);
  sprintf(snum,"Enum_Loc:            %d\n", Enum_Loc);serial_puts(snum);
  sprintf(snum,"        should be:   %d\n", 1);serial_puts(snum);
  sprintf(snum,"Str_1_Loc:           %s\n", Str_1_Loc);serial_puts(snum);
  sprintf(snum,"        should be:   DHRYSTONE PROGRAM, 1'ST STRING\n");serial_puts(snum);
  sprintf(snum,"Str_2_Loc:           %s\n", Str_2_Loc);serial_puts(snum);
  sprintf(snum,"        should be:   DHRYSTONE PROGRAM, 2'ND STRING\n");serial_puts(snum);
  sprintf(snum,"\n");

  User_Time = End_Time - Begin_Time;
  sprintf(snum,"User time: %d Mcycles\n", User_Time);serial_puts(snum);

  /*if (User_Time < Too_Small_Time)
  {
    sprintf(snum,"Measured time too small to obtain meaningful results\n");
    sprintf(snum,"Please increase number of runs\n");
    sprintf(snum,"\n");
  }
  else
  {
#ifdef TIME
    Microseconds = (float) User_Time * Mic_secs_Per_Second 
                        / (float) Number_Of_Runs;
    Dhrystones_Per_Second = (float) Number_Of_Runs / (float) User_Time;
#else
    Microseconds = (float) User_Time * Mic_secs_Per_Second 
                        / ((float) HZ * ((float) Number_Of_Runs));
    Dhrystones_Per_Second = ((float) HZ * (float) Number_Of_Runs)
                        / (float) User_Time;
#endif
    sprintf(snum,"Microseconds for one run through Dhrystone: ");
    sprintf(snum,"%6.1f\n", Microseconds);
    sprintf(snum,"Dhrystones per Second:                      ");
    sprintf(snum,"%6.1f\n", Dhrystones_Per_Second);
    float dmips = Dhrystones_Per_Second / 1757;
    const float MHZ = HZ / 1e6;
    sprintf(snum,"DMIPS:                                      ");
    sprintf(snum,"%6.2f\n", dmips);
    sprintf(snum,"DMIPS/MHZ:                                  ");
    sprintf(snum,"%6.2f\n", dmips / MHZ);
    sprintf(snum,"\n");
}
*/
while (1){}

}

Proc_1 (Ptr_Val_Par)
/******************/

REG Rec_Pointer Ptr_Val_Par;
    /* executed once */
{
  REG Rec_Pointer Next_Record = Ptr_Val_Par->Ptr_Comp;  
                                        /* == Ptr_Glob_Next */
  /* Local variable, initialized with Ptr_Val_Par->Ptr_Comp,    */
  /* corresponds to "rename" in Ada, "with" in Pascal           */
  
  structassign (*Ptr_Val_Par->Ptr_Comp, *Ptr_Glob); 
  Ptr_Val_Par->variant.var_1.Int_Comp = 5;
  Next_Record->variant.var_1.Int_Comp 
        = Ptr_Val_Par->variant.var_1.Int_Comp;
  Next_Record->Ptr_Comp = Ptr_Val_Par->Ptr_Comp;
  Proc_3 (&Next_Record->Ptr_Comp);
    /* Ptr_Val_Par->Ptr_Comp->Ptr_Comp 
                        == Ptr_Glob->Ptr_Comp */
  if (Next_Record->Discr == Ident_1)
    /* then, executed */
  {
    Next_Record->variant.var_1.Int_Comp = 6;
    Proc_6 (Ptr_Val_Par->variant.var_1.Enum_Comp, 
           &Next_Record->variant.var_1.Enum_Comp);
    Next_Record->Ptr_Comp = Ptr_Glob->Ptr_Comp;
    Proc_7 (Next_Record->variant.var_1.Int_Comp, 10, 
           &Next_Record->variant.var_1.Int_Comp);
  }
  else /* not executed */
    structassign (*Ptr_Val_Par, *Ptr_Val_Par->Ptr_Comp);
} /* Proc_1 */


Proc_2 (Int_Par_Ref)
/******************/
    /* executed once */
    /* *Int_Par_Ref == 1, becomes 4 */

One_Fifty   *Int_Par_Ref;
{
  One_Fifty  Int_Loc;  
  Enumeration   Enum_Loc;

  Int_Loc = *Int_Par_Ref + 10;
  do /* executed once */
    if (Ch_1_Glob == 'A')
      /* then, executed */
    {
      Int_Loc -= 1;
      *Int_Par_Ref = Int_Loc - Int_Glob;
      Enum_Loc = Ident_1;
    } /* if */
  while (Enum_Loc != Ident_1); /* true */
} /* Proc_2 */


Proc_3 (Ptr_Ref_Par)
/******************/
    /* executed once */
    /* Ptr_Ref_Par becomes Ptr_Glob */

Rec_Pointer *Ptr_Ref_Par;

{
  if (Ptr_Glob != Null)
    /* then, executed */
    *Ptr_Ref_Par = Ptr_Glob->Ptr_Comp;
  Proc_7 (10, Int_Glob, &Ptr_Glob->variant.var_1.Int_Comp);
} /* Proc_3 */


Proc_4 () /* without parameters */
/*******/
    /* executed once */
{
  Boolean Bool_Loc;

  Bool_Loc = Ch_1_Glob == 'A';
  Bool_Glob = Bool_Loc | Bool_Glob;
  Ch_2_Glob = 'B';
} /* Proc_4 */


Proc_5 () /* without parameters */
/*******/
    /* executed once */
{
  Ch_1_Glob = 'A';
  Bool_Glob = false;
} /* Proc_5 */


        /* Procedure for the assignment of structures,          */
        /* if the C compiler doesn't support this feature       */
#ifdef  NOSTRUCTASSIGN
memcpy (d, s, l)
register char   *d;
register char   *s;
register int    l;
{
        while (l--) *d++ = *s++;
}
#endif
