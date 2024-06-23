/*
** EPITECH PROJECT, 2024
** tests
** File description:
** tests
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "zappy_server.h"

Test(Test_01, pdi_reply)
{
    server_t server = {0};
    client_t client = {0};

    pdi_reply(&server, &client);
}

Test(Test_02, pdr_reply)
{
    server_t server = {0};
    client_t client = {0};

    pdr_reply(&server, &client, -1);
}

Test(Test_19, pdr_reply)
{
    server_t server = {0};
    client_t client = {0};

    pdr_reply(&server, &client, 42);
}

Test(Test_20, pdr_reply)
{
    server_t server = {0};
    client_t client = {0};

    pdr_reply(&server, &client, 452);
}

Test(Test_21, pdr_reply)
{
    server_t server = {0};
    client_t client = {0};

    pdr_reply(&server, &client, 7585);
}

Test(Test_03, pgt_reply)
{
    server_t server = {0};
    client_t client = {0};

    pgt_reply(&server, &client, 42);
}

Test(Test_22, pgt_reply)
{
    server_t server = {0};
    client_t client = {0};

    pgt_reply(&server, &client, -1);
}

Test(Test_23, pgt_reply)
{
    server_t server = {0};
    client_t client = {0};

    pgt_reply(&server, &client, 854);
}

Test(Test_24, pgt_reply)
{
    server_t server = {0};
    client_t client = {0};

    pgt_reply(&server, &client, -1);
}

Test(Test_04, smg_reply)
{
    server_t server = {0};

    smg_reply(&server, "egg created");
}

Test(Test_05, ppo_reply)
{
    server_t server = {0};
    client_t client = {0};

    ppo_reply(&server, &client);
}

Test(Test_06, pin_reply)
{
    server_t server = {0};
    client_t client = {0};

    pin_reply(&server, &client);
}

Test(Test_07, pnw_reply)
{
    server_t server = {0};
    client_t client = {0};

    pnw_reply(&server, &client);
}

Test(Test_08, enw_reply)
{
    server_t server = {0};
    client_t client = {0};
    egg_t egg = {0};

    enw_reply(&server, &client, &egg);
}

Test(Test_09, pfk_reply)
{
    server_t server = {0};
    client_t client = {0};

    pfk_reply(&server, &client);
}

Test(Test_10, ebo_reply)
{
    server_t server = {0};
    egg_t new_egg = {0};

    ebo_reply(&server, &new_egg);
}

Test(Test_12, pic_reply)
{
    server_t server = {0};
    client_t client = {0};

    pic_reply(&server, &client);
}

Test(Test_13, pie_reply)
{
    server_t server = {0};
    client_t client = {0};

    pie_reply(&server, &client, true);
}

Test(Test_14, plv_reply)
{
    server_t server = {0};
    client_t client = {0};

    plv_reply(&server, &client);
}

Test(Test_15, pbc_reply)
{
    server_t server = {0};
    client_t client = {0};

    pbc_reply(&server, &client, "dead");
}

Test(Test_16, pex_reply)
{
    server_t server = {0};
    client_t client = {0};

    pex_reply(&server, &client);
}

Test(Test_17, edi_reply)
{
    server_t server = {0};
    client_t client = {0};
    egg_t new_egg = {0};

    edi_reply(&server, &client, &new_egg);
}

Test(Test_18, seg_reply)
{
    server_t server = {0};

    seg_reply(&server, NULL);
}
