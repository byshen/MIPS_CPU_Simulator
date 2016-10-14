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
static const char *ng0 = "F:/ComOrga_design/genesys/lab6/AluCtr.v";
static unsigned int ng1[] = {63U, 63U};
static unsigned int ng2[] = {2U, 0U};
static unsigned int ng3[] = {127U, 63U};
static unsigned int ng4[] = {6U, 0U};
static unsigned int ng5[] = {160U, 0U};
static unsigned int ng6[] = {162U, 0U};
static unsigned int ng7[] = {164U, 0U};
static unsigned int ng8[] = {0U, 0U};
static unsigned int ng9[] = {165U, 0U};
static unsigned int ng10[] = {1U, 0U};
static unsigned int ng11[] = {170U, 0U};
static unsigned int ng12[] = {7U, 0U};



static void Always_29_0(char *t0)
{
    char t4[8];
    char *t1;
    char *t2;
    char *t3;
    char *t5;
    char *t6;
    char *t7;
    int t8;
    char *t9;
    char *t10;

LAB0:    t1 = (t0 + 2528U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(29, ng0);
    t2 = (t0 + 2848);
    *((int *)t2) = 1;
    t3 = (t0 + 2560);
    *((char **)t3) = t2;
    *((char **)t1) = &&LAB4;

LAB1:    return;
LAB4:    xsi_set_current_line(30, ng0);
    t5 = (t0 + 1208U);
    t6 = *((char **)t5);
    t5 = (t0 + 1048U);
    t7 = *((char **)t5);
    xsi_vlogtype_concat(t4, 8, 8, 2U, t7, 2, t6, 6);

LAB5:    t5 = ((char*)((ng1)));
    t8 = xsi_vlog_unsigned_case_xcompare(t4, 8, t5, 8);
    if (t8 == 1)
        goto LAB6;

LAB7:    t2 = ((char*)((ng3)));
    t8 = xsi_vlog_unsigned_case_xcompare(t4, 8, t2, 8);
    if (t8 == 1)
        goto LAB8;

LAB9:    t2 = ((char*)((ng5)));
    t8 = xsi_vlog_unsigned_case_xcompare(t4, 8, t2, 8);
    if (t8 == 1)
        goto LAB10;

LAB11:    t2 = ((char*)((ng6)));
    t8 = xsi_vlog_unsigned_case_xcompare(t4, 8, t2, 8);
    if (t8 == 1)
        goto LAB12;

LAB13:    t2 = ((char*)((ng7)));
    t8 = xsi_vlog_unsigned_case_xcompare(t4, 8, t2, 8);
    if (t8 == 1)
        goto LAB14;

LAB15:    t2 = ((char*)((ng9)));
    t8 = xsi_vlog_unsigned_case_xcompare(t4, 8, t2, 8);
    if (t8 == 1)
        goto LAB16;

LAB17:    t2 = ((char*)((ng11)));
    t8 = xsi_vlog_unsigned_case_xcompare(t4, 8, t2, 8);
    if (t8 == 1)
        goto LAB18;

LAB19:
LAB21:
LAB20:    xsi_set_current_line(38, ng0);
    t2 = ((char*)((ng8)));
    t3 = (t0 + 1608);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 4);

LAB22:    goto LAB2;

LAB6:    xsi_set_current_line(31, ng0);
    t9 = ((char*)((ng2)));
    t10 = (t0 + 1608);
    xsi_vlogvar_assign_value(t10, t9, 0, 0, 4);
    goto LAB22;

LAB8:    xsi_set_current_line(32, ng0);
    t3 = ((char*)((ng4)));
    t5 = (t0 + 1608);
    xsi_vlogvar_assign_value(t5, t3, 0, 0, 4);
    goto LAB22;

LAB10:    xsi_set_current_line(33, ng0);
    t3 = ((char*)((ng2)));
    t5 = (t0 + 1608);
    xsi_vlogvar_assign_value(t5, t3, 0, 0, 4);
    goto LAB22;

LAB12:    xsi_set_current_line(34, ng0);
    t3 = ((char*)((ng4)));
    t5 = (t0 + 1608);
    xsi_vlogvar_assign_value(t5, t3, 0, 0, 4);
    goto LAB22;

LAB14:    xsi_set_current_line(35, ng0);
    t3 = ((char*)((ng8)));
    t5 = (t0 + 1608);
    xsi_vlogvar_assign_value(t5, t3, 0, 0, 4);
    goto LAB22;

LAB16:    xsi_set_current_line(36, ng0);
    t3 = ((char*)((ng10)));
    t5 = (t0 + 1608);
    xsi_vlogvar_assign_value(t5, t3, 0, 0, 4);
    goto LAB22;

LAB18:    xsi_set_current_line(37, ng0);
    t3 = ((char*)((ng12)));
    t5 = (t0 + 1608);
    xsi_vlogvar_assign_value(t5, t3, 0, 0, 4);
    goto LAB22;

}


extern void work_m_00000000002292405306_2516217677_init()
{
	static char *pe[] = {(void *)Always_29_0};
	xsi_register_didat("work_m_00000000002292405306_2516217677", "isim/test_for_Top_isim_beh.exe.sim/work/m_00000000002292405306_2516217677.didat");
	xsi_register_executes(pe);
}
