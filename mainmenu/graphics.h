#ifndef MAIN_MENU_GRAPHICS_H
#define MAIN_MENU_GRAPHICS_H

#include <iostream>
#include <vector>
#include <Windows.h>

COORD GetConsoleCursorPosition(HANDLE hConsoleOutput) // без понятия что тут твориться, с инета кусок
{
    CONSOLE_SCREEN_BUFFER_INFO cbsi;

    if (GetConsoleScreenBufferInfo(hConsoleOutput, &cbsi))
    {
        return cbsi.dwCursorPosition;
    }

    else
    {
        // The function failed. Call GetLastError() for details.
        COORD invalid = { 0, 0 };
        return invalid;
    }
}

#include "logic.h"

namespace mainmenu
{
    namespace graphics 
    {
        void drawName();
        void drawLetter(char symbol, int coordX);
        void drawMenu();

        std::vector<std::string> menu = {
            "Play",
            "Shop",
            "Army",
            "Exit"
        };
        std::string name = "heroes and magics";
        bool firstTime = true;

        HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);

        void display()
        {
            system("cls");

            mainmenu::graphics::drawName();
            mainmenu::graphics::drawMenu();
        }        

        void drawName()
        {
            for (int i = 0; i < name.size(); i++)
            {
                if (firstTime)
                {
                    Sleep(100);
                }

                COORD coord = GetConsoleCursorPosition(console);

                if (name[i] != ' ')
                {
                    coord.Y -= 7;
                    SetConsoleCursorPosition(console, coord);
                }

                else 
                {
                    coord.Y += 9;
                    coord.X = 0;
                    SetConsoleCursorPosition(console, coord);
                }

                mainmenu::graphics::drawLetter(name[i], coord.X);
            }

            firstTime = false;
        }

        void drawLetter(char symbol, int coordX)
        {
            std::vector<std::string> letter;
            if (symbol == 'h')
            {
                letter = {
                    "     ▄█    █▄     \n",
                    "    ███    ███    \n",
                    "    ███    ███    \n",  
                    "   ▄███▄▄▄▄███▄▄  \n",  
                    "  ▀▀███▀▀▀▀███▀   \n",
                    "    ███    ███    \n",
                    "    ███    ███    \n",  
                    "    ███    █▀     "     
                };
            }

            else if (symbol == 'e')
            {
                letter = {
                    "     ▄████████  \n",
                    "    ███    ███  \n", 
                    "    ███    █▀   \n",  
                    "   ▄███▄▄▄      \n",  
                    "  ▀▀███▀▀▀      \n",
                    "    ███    █▄   \n",
                    "    ███    ███  \n",    
                    "    ██████████  "  
                };
            }

            else if (symbol == 'r')
            {
                letter = {
                    "     ▄████████  \n",
                    "    ███    ███  \n",  
                    "    ███    ███  \n",  
                    "   ▄███▄▄▄▄██   \n",  
                    "  ▀▀███▀▀▀▀▀    \n", 
                    "  ▀███████████  \n",
                    "    ███    ███  \n",    
                    "    ███    ███  "  
                };
            }

            else if (symbol == 'o')
            {
                letter = {
                    "   ▄██████▄   \n",
                    "  ███    ███  \n",  
                    "  ███    ███  \n",  
                    "  ███    ███  \n", 
                    "  ███    ███  \n",  
                    "  ███    ███  \n",
                    "  ███    ███  \n",   
                    "   ▀██████▀   "  
                };
            }

            else if (symbol == 's')
            {
                letter = {
                    "     ▄████████  \n",
                    "    ███    ███  \n",  
                    "    ███    █▀   \n",  
                    "    ███         \n",  
                    "  ▀███████████  \n",  
                    "           ███  \n",
                    "      ▄█   ███  \n",    
                    "    ▄████████▀  "  
                };
            }

            else if (symbol == 'a')
            {
                letter = {
                    "     ▄████████   \n",
                    "    ███    ███   \n",  
                    "    ███    ███   \n",  
                    "    ███    ███   \n",  
                    "   ▀███████████  \n", 
                    "    ███    ███   \n",
                    "    ███    ███   \n",    
                    "    ███    █▀    "  
                };
            }

            else if (symbol == 'n')
            {
                letter = {
                    "  ███▄▄▄▄     \n",
                    "  ███▀▀▀██▄   \n",  
                    "  ███    ███  \n",  
                    "  ███    ███  \n",  
                    "  ███    ███  \n",  
                    "  ███    ███  \n",
                    "  ███    ███  \n",    
                    "   ▀█    █▀   "  
                };
            }

            else if (symbol == 'd')
            {
                letter = {
                    "  ████████▄   \n",
                    "  ███   ▀███  \n",
                    "  ███    ███  \n",  
                    "  ███    ███  \n",  
                    "  ███    ███  \n",  
                    "  ███    ███  \n",
                    "  ███    ███  \n",    
                    "  ████████▀   "  
                };
            }

            else if (symbol == 'm')
            {
                letter = {
                    "    ▄▄▄▄███▄▄▄▄    \n",
                    "  ▄██▀▀▀███▀▀▀██▄  \n",  
                    "  ███   ███   ███  \n",  
                    "  ███   ███   ███  \n",  
                    "  ███   ███   ███  \n",  
                    "  ███   ███   ███  \n",
                    "  ███   ███   ███  \n",    
                    "   ▀█   ███   █▀   "  
                };
            }

            else if (symbol == 'g')
            {
                letter = {
                    "    ▄██████▄    \n",
                    "    ███   ███   \n",  
                    "    ███   █▀    \n",  
                    "   ▄███         \n",  
                    "  ▀▀███ ████▄   \n",  
                    "    ███    ███  \n",
                    "    ███    ███  \n",    
                    "    ████████▀   "  
                };
            }

            else if (symbol == 'i')
            {
                letter = {
                    "   ▄█   \n",
                    "  ███   \n",  
                    "  ███▌  \n",  
                    "  ███▌  \n",  
                    "  ███▌  \n",  
                    "  ███   \n",
                    "  ███   \n",    
                    "  █▀    "  
                };
            }

            else if (symbol == 'c')
            {
                letter = {
                    "   ▄████████  \n",
                    "  ███    ███  \n",
                    "  ███    █▀   \n",  
                    "  ███         \n",  
                    "  ███         \n", 
                    "  ███    █▄   \n",
                    "  ███    ███  \n",   
                    "  ████████▀   "  
                };
            }

            for (int i = 0; i < letter.size(); i++)
            {
                COORD coordLocal = GetConsoleCursorPosition(console);
                coordLocal.X = coordX;
                SetConsoleCursorPosition(console, coordLocal);

                std::cout << letter[i];
            }
        }                                                                                                          

        void drawMenu()
        {
            std::cout << "\n\n\n";

            for (int i = 0; i < menu.size(); i++)
            {
                std::cout << "\t\t\t\t\t" << menu[i];

                if (mainmenu::logic::currentPoint == i)
                {
                    std::cout << " ◄ ";
                }

                std::cout << "\n";
            }
        }
    }
}

#endif