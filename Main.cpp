// included Libraries
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>


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

	//Center the sprite on the screen
	buttonSprite.setPosition(
		gameWindow.getSize().x / 2 - buttonTexture.getSize().x / 2,
		gameWindow.getSize().y / 2 - buttonTexture.getSize().y / 2
	);


	//Create Music
	sf::Music gameMusic;
	gameMusic.openFromFile("audio/music.ogg");
	//gameMusic.play();


	// Create Font
	sf::Font gameFont;
	gameFont.loadFromFile("fonts/mainFont.ttf");


	//Create title
	sf::Text titleText;
	titleText.setFont(gameFont);
	titleText.setString("Button Masher!");
	titleText.setPosition(gameWindow.getSize().x / 2
		- titleText.getLocalBounds().width / 2, 30);

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
		gameWindow.draw(titleText);


		// Display the window contents on the screen
		gameWindow.display();

		

	}
	// exit point for the program
	return 0;
}