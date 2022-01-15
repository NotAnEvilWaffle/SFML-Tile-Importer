#include "Game.h"


namespace Zero {
	Game::Game(int width, int height, std::string windowTitle) : machine(StateMachine())
	{
		m_Window = std::make_shared<sf::RenderWindow>(sf::VideoMode(width, height), windowTitle, sf::Style::Close);


		/*This should be destroyed the moment the game goes out of scope
		  No need for dynamic allocation*/
		machine.PushState(std::make_unique<GameState>(m_Window));
	}
	void Game::Run()
	{
		while (this->m_Window->isOpen()) {
			machine.GetCurrentState()->Update(dt);
		}
	}
}