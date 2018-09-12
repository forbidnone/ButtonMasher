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
	int highScore = 0;

	//Score text
	sf::Text scoreText;
	scoreText.setFont(gameFont);
	scoreText.setString("Score: " + std::to_string(score));
	scoreText.setCharacterSize(16);
	scoreText.setFillColor(sf::Color::White);
	scoreText.setPosition(30, 30);

	
	//High Score text
	sf::Text highScoreText;
	highScoreText.setFont(gameFont);
	highScoreText.setString("High Score: " + std::to_string(highScore));
	highScoreText.setCharacterSize(16);
	highScoreText.setFillColor(sf::Color::White);
	highScoreText.setPosition(30, 60);


	//Timer text
	sf::Text timerText;
	timerText.setFont(gameFont);
	timerText.setString("Time Remaining: " + std::to_string(score));
	timerText.setCharacterSize(16);
	timerText.setFillColor(sf::Color::White);
	timerText.setPosition(gameWindow.getSize().x - timerText.getLocalBounds().width - 30, 30);


	//Prompt text
	sf::Text promptText;
	promptText.setFont(gameFont);
	promptText.setString("Click the button to start the game");
	promptText.setCharacterSize(16);
	promptText.setFillColor(sf::Color::White);
	promptText.setPosition(gameWindow.getSize().x / 2 - timerText.getLocalBounds().width - 30, gameWindow.getSize().y - 100);




	//Timer functionallity
	sf::Time timerLimit = sf::seconds(10.0f);
	sf::Time timeRemaining = timerLimit;
	sf::Time resetTimeLimit = sf::seconds(3.0f);
	sf::Time resetRemaining = sf::seconds(0.0f);
	sf::Clock gameClock;


	//Click Sound Effect
	sf::SoundBuffer clickBuffer;
	clickBuffer.loadFromFile("audio/buttonclick.ogg");
	sf::Sound clickSound;
	clickSound.setBuffer(clickBuffer);


	//Game over sound
	sf::SoundBuffer overBuffer;
	overBuffer.loadFromFile("audio/gameover.ogg");
	sf::Sound overSound;
	overSound.setBuffer(overBuffer);

	// Game State
	bool playing = false;


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

					// Are we playing?
					if (playing == true)
					{
						//if yes, increase score
						score = score + 1;

						if (score >= highScore)
						{
							highScore = score;
						}

					}
					else
					{
						if (resetRemaining.asSeconds() <= 0.0f)
						{
							//if not, start playing
							playing = true;



							// Reset the game data
							score = 0;
							timeRemaining = timerLimit;
							promptText.setString("Click the button as fast as you can!");
						}
					}
					
					// Play the click sound
					clickSound.play();

				}
			}
		}


		//Update game state
		sf::Time frameTime = gameClock.restart();

		if (playing == true)
		{
		
			timeRemaining = timeRemaining - frameTime;

			if (timeRemaining.asSeconds() <= 0.0f)
			{

				timeRemaining = sf::seconds(0.0f);
				playing = false;
				promptText.setString("Your final score was " + std::to_string(score) + "!\nClick the button to restart the game");
				resetRemaining = resetTimeLimit;
				overSound.play();

			}


		}

		else
		{
				resetRemaining = resetRemaining - frameTime;
		}
		
		// Update text displays based on Data
		timerText.setString("Time Remaining: " + std::to_string((int)std::ceilf(timeRemaining.asSeconds())));
		scoreText.setString("Score: " + std::to_string(score));
		highScoreText.setString("High Score: " + std::to_string(highScore));


		// Clear the window to a single colour
		gameWindow.clear(sf::Color::Black);


		// Draw everything
		gameWindow.draw(buttonSprite);
		gameWindow.draw(titleText);
		gameWindow.draw(authorText);
		gameWindow.draw(scoreText);
		gameWindow.draw(timerText);
		gameWindow.draw(promptText);
		gameWindow.draw(highScoreText);


		// Display the window contents on the screen
		gameWindow.display();

		

	}
	// exit point for the program
	return 0;
}