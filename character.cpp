#include <SFML\Graphics.hpp>
#include "weapon.h"
#include "character.h"
#include <string>
using namespace sf;

enum InputType
{
	KeyboardInput,
};

struct MyKeys
{
	InputType myInputType;
	sf::Event::EventType myEventType;
	sf::Keyboard::Key myKeyCode;
};




character::character()
{
	characterShape.setRadius(15);
	characterShape.setOutlineThickness(2);
	characterShape.setFillColor(Color(0, 255, 0));
	characterShape.setOutlineColor(Color(255, 0, 0));
	characterShape.setPosition(20, 20);
}
void character::up()
{
	if (position().y > 10)
		characterShape.move(0, -1);
};
void character::down()
{
	if (position().y < 550)
		characterShape.move(0, 1);
};
void character::left()
{
	if (position().x > 10)
		characterShape.move(-1, 0);
};
void character::right()
{
	if (position().x < 750)
		characterShape.move(1, 0);
};

void character::steering()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift) == 1)
			left();
		left();
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift) == 1)
			right();
		right();
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift) == 1)
			up();
		up();
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift) == 1)
			down();
		down();
	}
}

void character::display(RenderWindow &window)
{
	steering();
	window.draw(characterShape);
}

Vector2f character::position()
{
	return characterShape.getPosition();
}