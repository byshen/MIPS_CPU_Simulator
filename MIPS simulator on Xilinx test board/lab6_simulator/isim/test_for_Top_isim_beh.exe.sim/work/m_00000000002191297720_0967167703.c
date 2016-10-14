/**********************************************************************/
/*   ____  ____                                                       */
/*  /   /\/   /                                                       */
/* /___/  \  /                                                        */
/* \   \   \/                                                       */
/*  \   \        Copyright (c) 2003-2009 Xilinx, Inc.                */
/*  /   /          All Right Reserved.                                 */
/* /---/   /\                                                         */
/* \   \  /  \                                                      */
/*  \___\/\___\                                                    */
/***********************************************************************/

/* This file is designed for use with ISim build 0x7708f090 */

#define XSI_HIDE_SYMBOL_SPEC true
#include "xsi.h"
#include <memory.h>
#ifdef __GNUC__
#include <stdlib.h>
#else
#include <malloc.h>
#define alloca _alloca
#endif
static const char *ng0 = "F:/ComOrga_design/genesys/lab6/signext.v";
static unsigned int ng1[] = {65535U, 0U};
static int ng2[] = {15, 0};



static void Cont_25_0(char *t0)
{
    char t3[8];
    char t7[8];
    char t11[8];
    char *t1;
    char *t2;
    char *t4;
    char *t5;
    char *t6;
    char *t8;
    char *t9;
    char *t10;
    char *t12;
    char *t13;
    char *t14;
    char *t15;
    char *t16;
    char *t17;

LAB0:    t1 = (t0 + 2368U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(25, ng0);
    t2 = (t0 + 1048U);
    t4 = *((char **)t2);
    t2 = ((char*)((ng1)));
    t5 = (t0 + 1048U);
    t6 = *((char **)t5);
    t5 = (t0 + 1008U);
    t8 = (t5 + 72U);
    t9 = *((char **)t8);
    t10 = ((char*)((ng2)));
    xsi_vlog_generic_get_index_select_value(t7, 16, t6, t9, 2, t10, 32, 1);
    memset(t11, 0, 8);
    xsi_vlog_unsigned_multiply(t11, 16, t2, 16, t7, 16);
    xsi_vlogtype_concat(t3, 32, 32, 2U, t11, 16, t4, 16);
    t12 = (t0 + 2768);
    t13 = (t12 + 56U);
    t14 = *((char **)t13);
    t15 = (t14 + 56U);
    t16 = *((char **)t15);
    memcpy(t16, t3, 8);
    xsi_driver_vfirst_trans(t12, 0, 31);
    t17 = (t0 + 2688);
    *((int *)t17) = 1;

LAB1:    return;
}


extern void work_m_00000000002191297720_0967167703_init()
{
	static char *pe[] = {(void *)Cont_25_0};
	xsi_register_didat("work_m_00000000002191297720_0967167703", "isim/test_for_Top_isim_beh.exe.sim/work/m_00000000002191297720_0967167703.didat");
	xsi_register_executes(pe);
}
