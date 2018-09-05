// included Libraries
#include <SFML/Graphics.hpp>


// entry point for the program
int main()
{
	
	// Make a variable called gameWindow of type RenderWindow
	sf::RenderWindow gameWindow;
	gameWindow.create(sf::VideoMode::getDesktopMode(), "Button Masher",
		sf::Style::Titlebar | sf::Style::Close);


	// Game Loop
	// Runs every frame until the game window is closed
	while (gameWindow.isOpen())
	{
		
		// Check for Input
		sf::Event gameEvent;

		while (gameWindow.pollEvent(gameEvent))
		{
			// Process events

			// Check if the event is the closed event
			if (gameEvent.type == sf::Event::Closed)
			{

				// Close the game window
				gameWindow.close();

			}
		}


		// TODO : Update game state

		// TODO : Draw Graphics


	}
	// exit point for the program
	return 0;
}