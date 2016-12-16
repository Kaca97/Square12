#pragma once
#include <SFML\Graphics.hpp>
#include "options.h"
#include <iostream>
#include <string>
#include <fstream>
#include <windows.h>
#include <stdio.h>
using namespace std;

options::options()
{
	settings.antialiasingLevel = 8;
	background.White;
	if (!retro.loadFromFile("font.ttf"))
		std::cout << "error loading font on options";
	header.setFont(retro);
	header.setFillColor(Color::White);
	header.setCharacterSize(70);
	header.setString("Options");
	header.setPosition(Vector2f((800 - header.getGlobalBounds().width) / 2, 10));

	back.setFont(retro);
	back.setFillColor(Color::White);
	back.setCharacterSize(35);
	back.setString("Back");
	back.setPosition(Vector2f((800 - back.getGlobalBounds().width) / 2, 530));

	moveup.setFont(retro);
	moveup.setFillColor(Color::White);
	moveup.setCharacterSize(24);
	moveup.setString("Move Up");
	moveup.setPosition(Vector2f(100, 150));

	movedown.setFont(retro);
	movedown.setFillColor(Color::White);
	movedown.setCharacterSize(24);
	movedown.setString("Move Down");
	movedown.setPosition(Vector2f(100, moveup.getPosition().y+50));

	moveright.setFont(retro);
	moveright.setFillColor(Color::White);
	moveright.setCharacterSize(24);
	moveright.setString("Move Right");
	moveright.setPosition(Vector2f(100, movedown.getPosition().y + 50));

	moveleft.setFont(retro);
	moveleft.setFillColor(Color::White);
	moveleft.setCharacterSize(24);
	moveleft.setString("Move Left");
	moveleft.setPosition(Vector2f(100, moveright.getPosition().y + 50));

	test.setFont(retro);
	test.setFillColor(Color::White);
	test.setCharacterSize(24);
	test.setPosition(Vector2f(400, moveup.getPosition().y));

}

bool options::mouseontext(RenderWindow &window, Text &text)
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

void options::check()
{
	ifstream settings;
	settings.open("C:\\Square\\settings\\settings.dat");
	if (settings.is_open() == false)
	{
		CreateDirectoryA("C:\\Square", NULL);
		CreateDirectoryA("C:\\Square\\settings", NULL);
		ofstream settings;
		settings.open("C:\\Square\\settings\\settings.dat");
		settings << "W" << endl;
		settings << "S" << endl;
		settings << "A" << endl;
		settings << "D" << endl;
		settings.close();
	}
	settings.close();
}

int options::display(RenderWindow &window)
{
	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
			{
				window.close();
			}
			if (event.type == Event::MouseButtonPressed && mouseontext(window, back))
			{
				return 1;
			}
			if (event.type == sf::Event::TextEntered)
			{
				if (event.text.unicode < 128)
					test.setString(event.text.unicode);
			}
		}
		mouseontext(window, back);
		window.clear(background);
		window.draw(header);
		window.draw(moveup);
		window.draw(movedown);
		window.draw(moveright);
		window.draw(moveleft);
		window.draw(test);
		window.draw(back);
		window.display();
	}

}