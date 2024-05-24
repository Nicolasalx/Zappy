/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** setInventory
*/

#include "zappyAi.hpp"

void Ai::Player::setElemToInventory(Item item, int nbElem)
{
    switch(item) {
        case FOOD:
            this->inventory.food = nbElem;
            break;
        case LINEMATE:
            this->inventory.linemate = nbElem;
            break;
        case DERAUMERE:
            this->inventory.deraumere = nbElem;
            break;
        case SIBUR:
            this->inventory.sibur = nbElem;
            break;
        case MENDIANE:
            this->inventory.mendiane = nbElem;
            break;
        case PHIRAS:
            this->inventory.phiras = nbElem;
            break;
        case THYSTAME:
            this->inventory.thystame = nbElem;
            break;
    }
}
