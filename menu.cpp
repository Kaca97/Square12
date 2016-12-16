#pragma once
#include <SFML\Graphics.hpp>
#include "menu.h"
#include <iostream>
using namespace sf;
menu::menu()
{
	settings.antialiasingLevel = 8;
	background.White;
	if (!retro.loadFromFile("font.ttf"))
		std::cout << "error loading font on menu";
	tittle.setFont(retro);
	tittle.setFillColor(Color::White);
	tittle.setCharacterSize(100);
	tittle.setString("Square");
	tittle.setPosition(Vector2f((800 - tittle.getGlobalBounds().width) / 2, 50));
	
	line.setSize(Vector2f(500, 2));
	line.setFillColor(Color::White);
	line.setPosition(Vector2f((800 - line.getGlobalBounds().width) / 2, tittle.getPosition().y + 130));
	
	play.setFont(retro);
	play.setFillColor(Color::White);
	play.setCharacterSize(50);
	play.setString("Play");
	play.setPosition(Vector2f((800 - play.getGlobalBounds().width) / 2, line.getPosition().y + 50));
	
	options.setFont(retro);
	options.setFillColor(Color::White);
	options.setCharacterSize(50);
	options.setString("Options");
	options.setPosition(Vector2f((800 - options.getGlobalBounds().width) / 2, play.getPosition().y + 70));
	
	autor.setFont(retro);
	autor.setFillColor(Color::White);
	autor.setCharacterSize(18);
	autor.setPosition(Vector2f(585, 570));
	autor.setString("Maciej Kaca (C) 2016");

	exit.setFont(retro);
	exit.setFillColor(Color::White);
	exit.setCharacterSize(50);
	exit.setString("Exit");
	exit.setPosition(Vector2f((800 - exit.getGlobalBounds().width) / 2, options.getPosition().y + 70));

	choiced = false;
}

bool menu::mouseontext(RenderWindow &window, Text &text)
{
	FloatRect boundingBox = text.getGlobalBounds();
	Vector2f mouse(Mouse::getPosition(window).x, Mouse::getPosition(window).y);
	if (boundingBox.contains(mouse))
	{
		text.setFillColor(Color::Red);
		return true;
	}
	else
	{
		text.setFillColor(Color::White);
		return false;
	}
}

int menu::menudisplay(RenderWindow &window)
{
	if (choiced == false)
	{
		while (window.isOpen())
		{
			Event event;
			while (window.pollEvent(event))
			{
				if (event.type == Event::MouseButtonPressed && mouseontext(window, play))
				{
					choiced = true;
					choice = 1;
					return 1;
				}
				if (event.type == Event::MouseButtonPressed && mouseontext(window, options))
				{
					choiced = true;
					choice = 2;
					return 2;
				}
				if (event.type == Event::MouseButtonPressed && mouseontext(window, exit) || event.type == Event::Closed)
				{
					window.close();
				}
				mouseontext(window, play);
				mouseontext(window, options);
				mouseontext(window, exit);
				window.clear(background);
				window.draw(tittle);
				window.draw(line);
				window.draw(play);
				window.draw(exit);
				window.draw(autor);
				window.draw(options);
				window.display();
			}

		}
	}
	else
		switch (choice)
		{
			case 1:
				return 1;
			case 2:
				return 2;
		}
}
