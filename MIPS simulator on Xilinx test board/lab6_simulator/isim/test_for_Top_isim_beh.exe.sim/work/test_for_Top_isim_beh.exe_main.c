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

#include "xsi.h"

struct XSI_INFO xsi_info;



int main(int argc, char **argv)
{
    xsi_init_design(argc, argv);
    xsi_register_info(&xsi_info);

    xsi_register_min_prec_unit(-12);
    work_m_00000000000670688500_2244092194_init();
    work_m_00000000002191297720_0967167703_init();
    work_m_00000000002292405306_2516217677_init();
    work_m_00000000002825245677_2587490486_init();
    work_m_00000000000646562763_3913188552_init();
    work_m_00000000000311216812_3258266500_init();
    work_m_00000000003109179494_2828040072_init();
    work_m_00000000002175686611_3683860065_init();
    work_m_00000000003936793600_3885983851_init();
    work_m_00000000004134447467_2073120511_init();


    xsi_register_tops("work_m_00000000003936793600_3885983851");
    xsi_register_tops("work_m_00000000004134447467_2073120511");


    return xsi_run_simulation(argc, argv);

}
