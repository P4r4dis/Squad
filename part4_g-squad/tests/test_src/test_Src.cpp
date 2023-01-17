#include "../test_include/test_Phaser.hpp"
#include <criterion/redirect.h>

void    redirect_all_stdout(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}
