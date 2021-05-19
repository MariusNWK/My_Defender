/*
** EPITECH PROJECT, 2021
** htplaystr
** File description:
** the string how to play which contains the explications
*/

#include"include/my.h"

char const *htplay_str(void)
{
    char const *str = " Kill the knights by placing towers to defend your"
    " castle.\n Armored knights initialy have 200 hp. Others start with 100"
    " hp.\n Everytime a knight is killed, the initial number of hp of armored"
    " knights\n increase of 2, that of the unarmored knights increase of 1.\n"
    " The number of knights who spawn increase as time goes by.\n"
    " The maximum spawn is reached when 200 knights are killed.\n Each tower"
    " has its own characteristic :\n Stone tower : damages (increase by"
    " upgrading)\n Poison tower : more a knight got touched by poisons, "
    "more poisons hurt. (increase by upgrading)\n Wizard tower : 1 second"
    " slow + few damages (increase by upgrading)\n Tesla tower : damages"
    " (very fast attack) + range (increase by upgrading)\n Magnus tower :"
    " one shot knights but very slow projectiles (can't be upgrade)\n"
    " The castle starts the game with 100 hp. Everytime a knight hit"
    " the castle, its loses 5 hp.\n Kill knights to get golds :\n 1 knight "
    "-> 10 golds, 50 knights -> 1000 golds, 500 knights -> 10000 golds.\n"
    " You can upgrade only if you have enough golds.\n If you want"
    " to try every upgrade of towers, reset the game (menu\n"
    " or try again). You will then start with a lot of golds so you"
    " can try every upgrade.\n Number of knights killed displayed top right.";

    return (str);
}