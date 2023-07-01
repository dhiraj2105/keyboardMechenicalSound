#include <iostream>
#include <SFML/Audio.hpp>
#include <ncurses.h>

int main()
{
    // play sound
    sf::SoundBuffer buffer;

    if (!buffer.loadFromFile("keypress-sound.wav"))
    {
        return -1;
    }

    sf::Sound sound;
    sound.setBuffer(buffer);

    // Initialize ncurses
    initscr();
    cbreak();
    noecho();
    keypad(stdscr, TRUE);

    // Main loop
    while (true)
    {
        int ch = getch();

        // Print the key code
        // std::cout << "Key pressed: " << ch << std::endl;
        //play sound
        sound.play();
    }

    // Clean up ncurses
    endwin();

    return 0;
}
