/*
** EPITECH PROJECT, 2023
** Tests.cpp
** File description:
** unit_tests
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "MyGKrellm.hpp"

Test(MyGKrellm, Test_CheckMyGKrellm_Success_text) {
    MyGKrellm myGKrellm("text");
    int result = myGKrellm.CheckMyGKrellm();
    cr_assert_eq(result, SUCCESS, "CheckMyGKrellm not returning SUCCESS");
}

Test(MyGKrellm, Test_CheckMyGKrellm_Success_graph) {
    MyGKrellm myGKrellm("graphical");
    int result = myGKrellm.CheckMyGKrellm();
    cr_assert_eq(result, SUCCESS, "CheckMyGKrellm not returning SUCCESS");
}

Test(MyGKrellm, Test_CheckMyGKrellm_Failed) {
    MyGKrellm myGKrellm("aaa");
    int result = myGKrellm.CheckMyGKrellm();
    cr_assert_eq(result, ERROR, "CheckMyGKrellm not returning SUCCESS");
}
