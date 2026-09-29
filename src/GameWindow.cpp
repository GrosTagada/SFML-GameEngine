#include <GameWindow.h>

GameWindow::GameWindow()
{
}

void GameWindow::Show()
{
	sf::Window window(sf::VideoMode({ 800,800 }), "My window");
}

