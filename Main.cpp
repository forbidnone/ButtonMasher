// included Libraries
#include <SFML/Graphics.hpp>


// entry point for the program
int main()
{
	//-----------------------------------------------------------------------------------
	// Game Setup
	// ----------------------------------------------------------------------------------


	// Make a variable called gameWindow of type RenderWindow
	sf::RenderWindow gameWindow;
	gameWindow.create(sf::VideoMode::getDesktopMode(), "Button Masher",
		sf::Style::Titlebar | sf::Style::Close);


	// Create Button Spirte
	sf::Texture buttonTexture;
	buttonTexture.loadFromFile("graphics/button.png");

	sf::Sprite buttonSprite;
	buttonSprite.setTexture(buttonTexture);
	buttonSprite.setPosition(
		gameWindow.getSize().x / 2 - buttonTexture.getSize().x / 2,
		gameWindow.getSize().y / 2 - buttonTexture.getSize().y / 2
	);


	//-----------------------------------------------------------------------------------
	// Game Loop
	//-----------------------------------------------------------------------------------
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

		// Clear the window to a single colour
		gameWindow.clear(sf::Color::Black);


		// Draw everything
		gameWindow.draw(buttonSprite);


		// Display the window contents on the screen
		gameWindow.display();

		

	}
	// exit point for the program
	return 0;
}