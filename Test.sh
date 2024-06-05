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

test_invalid_arg_server()
{
    test_name "$1"
    ./zappy_server $1 &
    pid=$!
    sleep 0.1
    kill $pid 2> /dev/null
    wait $pid
    test_return_84
}

test_valid_arg_server()
{
    test_name "$1"
    ./zappy_server $1 &
    pid=$!
    sleep 0.1
    kill $pid 2> /dev/null
    test_return_0
}

## ! TEST

test_invalid_arg_server "kqsnfjsdf"   # invalid arg
test_invalid_arg_server "-n aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa" # too long name
test_invalid_arg_server "-r"
test_invalid_arg_server "-r 4"
test_invalid_arg_server "-c -1"       # negative team count
test_invalid_arg_server "-n \"\""     # empty team name
test_invalid_arg_server "-n @@@__###" # non alpha num
test_invalid_arg_server "-n Team1 Team1"
test_invalid_arg_server "-x 0"
test_invalid_arg_server "-x -1"
test_invalid_arg_server "-x 101"
test_invalid_arg_server "-y 0"
test_invalid_arg_server "-y -1"
test_invalid_arg_server "-y 101"
test_invalid_arg_server "-x -y 101"
test_invalid_arg_server "-y -y 101"
test_invalid_arg_server "-y -a 101"
test_invalid_arg_server "-p 0"
test_invalid_arg_server "-p -1"
test_invalid_arg_server "-p 65536"
test_invalid_arg_server "-f 0"
test_invalid_arg_server "-f -1"
test_invalid_arg_server "-f 151"
test_invalid_arg_server "-ff 100"
test_invalid_arg_server "-no 1"
test_invalid_arg_server "-no"

test_valid_arg_server "-f 1"
test_valid_arg_server "-f 150"
test_valid_arg_server "-x 1 -y 1"
test_valid_arg_server "-x 100 -y 100"
test_valid_arg_server "-x 1"
test_valid_arg_server "-y 1"
test_valid_arg_server "-n Team1"
test_valid_arg_server "-n Team1 Team2 Team3 Team4"
test_valid_arg_server "-p 65535"

## ? END TEST

display_progress_bar $NB_PASSED_TEST $NB_TEST
exit $RETURN_VALUE
