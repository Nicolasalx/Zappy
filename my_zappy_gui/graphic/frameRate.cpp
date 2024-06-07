/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** FrameRate
*/

#include "FrameRate.hpp"
#include <chrono>
#include <thread>

std::size_t Gui::FrameRate::_frameRate = 30;
long Gui::FrameRate::_frameTime = 1000 / Gui::FrameRate::_frameRate;
std::chrono::time_point<std::chrono::steady_clock> Gui::FrameRate::_lastClock;

void Gui::FrameRate::setFrameRate(std::size_t frameRate)
{
    if (frameRate == 0) {
        frameRate = 30;
    }
    Gui::FrameRate::_frameRate = frameRate;
    Gui::FrameRate::_frameTime = 1000 / frameRate;
}

void Gui::FrameRate::start()
{
    Gui::FrameRate::_lastClock = std::chrono::steady_clock::now();
}

void Gui::FrameRate::end()
{
    auto deltaT = std::chrono::duration_cast<std::chrono::milliseconds>(
        std::chrono::steady_clock::now() - Gui::FrameRate::_lastClock).count();
    if (deltaT < Gui::FrameRate::_frameTime && (_frameTime - deltaT) > 0) {
        std::this_thread::sleep_for(std::chrono::milliseconds(_frameTime - deltaT));
    }
}
