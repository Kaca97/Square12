#include "character.h"
#include "weapon.h"
#include "menu.h"
#include "options.h"
#include <windows.h>
#include <math.h>
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
using namespace sf;
character player;
weapon rifle;
menu mainmenu;
options option;
int main()
{	
		option.check();
		sf::ContextSettings settings;
		settings.antialiasingLevel = 8;
		RenderWindow window(VideoMode(800, 600),"Goniec", Style::Close, settings);
		window.setFramerateLimit(150);
		while (window.isOpen())
		{
			Event event;
			while (window.pollEvent(event))
			{
				if (event.type == Event::Closed)
					window.close();
				if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
					mainmenu.choiced = false;
			}
			switch (mainmenu.menudisplay(window))
			{
				case 1:
					window.clear(Color(255, 255, 255));
					player.display(window);
					rifle.display(window, player.position());
					break;
				case 2:
					if (option.display(window) == 1)
						mainmenu.choiced = false;
					break;
				default:
					std::cout << "Error01";
			}
			window.display();
		}
	return 0;
}