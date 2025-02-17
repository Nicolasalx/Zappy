#!/bin/bash

RETURN_VALUE=0
i_test=0

NB_TEST=0
NB_PASSED_TEST=0

## make

test_name()
{
    ((i_test++))
    echo -e "Test[\e[95m$i_test\e[0m]: $1"
}

test_return_0()
{
    if [ $? -eq 0 ]; then
        echo -e "[\e[92mPASS\e[0m]"
        ((NB_PASSED_TEST++))
    else
        echo -e "[\e[91mFAIL\e[0m]"
        RETURN_VALUE=1
    fi
    ((NB_TEST++))
}

test_return_84()
{
    if [ $? -eq 84 ]; then
        echo -e "[\e[92mPASS\e[0m]"
        ((NB_PASSED_TEST++))
    else
        echo -e "[\e[91mFAIL\e[0m]"
        RETURN_VALUE=1
    fi
    ((NB_TEST++))
}

display_progress_bar()
{
    local passed="$1"
    local total="$2"
    local percentage=$(( passed * 100 / total ))
    local width=50

    local filled=$(( percentage * width / 100 ))
    local empty=$(( width - filled ))

    printf "\n["
    if [ "$percentage" -ge 75 ]; then
        printf "\e[92m%${filled}s\e[0m" | tr ' ' '='
        printf "\e[92m%${empty}s\e[0m" | tr ' ' ' '
    elif [ "$percentage" -ge 25 ]; then
        printf "\e[93m%${filled}s\e[0m" | tr ' ' '='
        printf "\e[93m%${empty}s\e[0m" | tr ' ' ' '
    else
        printf "\e[91m%${filled}s\e[0m" | tr ' ' '='
        printf "\e[91m%${empty}s\e[0m" | tr ' ' ' '
    fi

    printf "] %d%% (%d/%d)\n" "$percentage" "$passed" "$total"
}

##test_valid_arg_ai()
##{
##    test_name "$1"
##    ./zappy_ai $1 &
##    pid=$!
##    sleep 0.1
##    kill $pid 2> /dev/null
##    test_return_0
##}

test_invalid_arg_ai()
{
    test_name "$1"
    ./zappy_ai $1 &
    pid=$!
    sleep 0.1
    kill $pid 2> /dev/null
    wait $pid
    test_return_84
}

## ! TEST

test_invalid_arg_ai "zdsqdqsd"
test_invalid_arg_ai "-n"
test_invalid_arg_ai "-p"
test_invalid_arg_ai "-h"
test_invalid_arg_ai "-n -p"
test_invalid_arg_ai "-n -h"
test_invalid_arg_ai "-p -h"
test_invalid_arg_ai "-n -p -h"
test_invalid_arg_ai "-no"
test_invalid_arg_ai "-no Team1"
test_invalid_arg_ai "-po 4242"
test_invalid_arg_ai "-n Team1 -p"
test_invalid_arg_ai "-n Team1 Team2"
test_invalid_arg_ai "-p Team1 Team1"
test_invalid_arg_ai "-h test"
test_invalid_arg_ai "-p 0"
test_invalid_arg_ai "-p -1"
test_invalid_arg_ai "-p 65536"
test_invalid_arg_ai "-n @@@__###"
test_invalid_arg_ai "-n GRAPHIC"

## ? END TEST

display_progress_bar $NB_PASSED_TEST $NB_TEST
exit $RETURN_VALUE
