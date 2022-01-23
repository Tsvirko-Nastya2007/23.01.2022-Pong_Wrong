#include <SFML/Graphics.hpp>
#include "const.h"
#include"ball.h"
#include "bat.h"
#include "left_bat.h"

using namespace sf;

int main()
{
	// Объект, который, собственно, является главным окном приложения
	RenderWindow window(VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "SFML Works!");
	window.setFramerateLimit(60);

	Ball ball;
	LeftBat left_bat(20, SCREEN_HEIGHT / 2 - 50);
	// Главный цикл приложения. Выполняется, пока открыто окно
	while (window.isOpen())
	{
		// Обрабатываем очередь событий в цикле
		Event event;
		while (window.pollEvent(event))
		{
			// Пользователь нажал на «крестик» и хочет закрыть окно?
			if (event.type == Event::Closed)
				// тогда закрываем его
				window.close();
		}
		
	}
	ball.update();
	left_bat.update();
	window.clear(Color(250,50,50,0));
	window.draw(ball.getShape());
	window.draw(left_bat.getShape());
	window.display();

	return 0;
}