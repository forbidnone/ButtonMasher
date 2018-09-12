// included Libraries
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <string>


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

	titleText.setCharacterSize(100);
	titleText.setFillColor(sf::Color::Magenta);
	titleText.setStyle(sf::Text::Bold | sf::Text::Italic);


	titleText.setPosition(gameWindow.getSize().x / 2
		- titleText.getLocalBounds().width / 2, 30);

	sf::Text authorText;
	authorText.setFont(gameFont);
	authorText.setString("By Cameron");
	authorText.setPosition(gameWindow.getSize().x / 2 
		- titleText.getLocalBounds().width / 2, 130);


	// Score
	int score = 0;

	//Score text
	sf::Text scoreText;
	scoreText.setFont(gameFont);
	scoreText.setString("Score: " + std::to_string(score));
	scoreText.setCharacterSize(16);
	scoreText.setFillColor(sf::Color::White);
	scoreText.setPosition(30, 30);

	//Timer text
	sf::Text timerText;
	timerText.setFont(gameFont);
	timerText.setString("Time Remaining: " + std::to_string(score));
	timerText.setCharacterSize(16);
	timerText.setFillColor(sf::Color::White);
	timerText.setPosition(gameWindow.getSize().x - timerText.getLocalBounds().width - 30, 30);


	//Timer functionallity
	sf::Time timerLimit = sf::seconds(10.0f);
	sf::Time timeRemaining = timerLimit;
	sf::Clock gameClock;


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

			// Check if the event is a mouse button pressed event
			if (gameEvent.type == sf::Event::MouseButtonPressed)
			{

				if (buttonSprite.getGlobalBounds().contains(gameEvent.mouseButton.x, gameEvent.mouseButton.y))
				{ 

					// We Clicked the button
					score = score + 1;

				}
			}
		}


		//Update game state
		sf::Time frameTime = gameClock.restart();
		timeRemaining = timeRemaining - frameTime;
		timerText.setString("Time Remaining: " + std::to_string((int)std::ceilf(timeRemaining.asSeconds())));

		scoreText.setString("Score: " + std::to_string(score));


		// Clear the window to a single colour
		gameWindow.clear(sf::Color::Black);


		// Draw everything
		gameWindow.draw(buttonSprite);
		gameWindow.draw(titleText);
		gameWindow.draw(authorText);
		gameWindow.draw(scoreText);
		gameWindow.draw(timerText);


		// Display the window contents on the screen
		gameWindow.display();

		

	}
	// exit point for the program
	return 0;
}