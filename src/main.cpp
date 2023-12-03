/*
** EPITECH PROJECT, 2023
** main.cpp
** File description:
** main
*/

#include "MyGKrellm.hpp"

int main(int ac, char **av)
{
    MyGKrellm mg((ac != 2) ? "" : av[1]);
    return (mg.StartMyGKrellm());
}
