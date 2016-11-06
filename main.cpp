#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
using namespace std;
int main()
{
    // Create the main window
    sf::RenderWindow app(sf::VideoMode(1366, 683), "David Dhas's Game");
    // Load a sprite to display
    sf::Texture texture;
    if (!texture.loadFromFile("images/background.jpg"))
        return EXIT_FAILURE;

    sf::Sprite sprite(texture);
    sf::Texture tex;
    tex.loadFromFile("images/hero.png");
    sf::IntRect rectSourceSprite(0,00,51,72);
    sf::IntRect rectSourceSprite_punch(330,100,383,152);
    sf::Sprite sprite_hero_punch(tex, rectSourceSprite_punch);
    sf::Sprite sprite_hero(tex, rectSourceSprite);
    sf::Clock clock;
    sf::Texture tex_tile;
    //sprite.setPosition(800,600);
    sprite_hero.setPosition(336,380);
    sprite_hero_punch.setPosition(500,500);
	// Start the game loop
    while (app.isOpen())
    {
        // Process events
        sf::Event event;
        while (app.pollEvent(event))
        {
            switch(event.type)
            {
                case sf::Event::Closed:
                    app.close();

                case sf::Event::Resized:
                        cout<<event.size.width<<':'<<event.size.height<<endl;

                case sf::Event::LostFocus:
                        cout<<"Lost Focus"<<endl;

                case sf::Event::GainedFocus:
                        cout<<"Gained Focus"<<endl;
                // Close window : exit
                case sf::Event::KeyPressed:
                     cout<<"Key has been pressed"<<endl;

                    switch(event.key.code)
                    {
                        case sf::Keyboard::Down:
                            //cout<<"Down"<<endl;
                             sprite_hero.setPosition(336,480);
                            break;
                        case sf::Keyboard::Up:
                            cout<<"UP"<<endl;
                            sprite_hero.setPosition(336,380);
                            break;
                        case sf::Keyboard::Left:
                            cout<<"Left"<<endl;
                            break;
                        case sf::Keyboard::Right:
                            cout<<"Right"<<endl;
                            break;
                        case sf::Keyboard::Return:
                            cout<<"Enter pressed"<<endl;
                            if (sprite_hero.getPosition().y == 480)
                                app.close();

                            if (sprite_hero.getPosition().y == 380)
                                app.close();
                            break;
                        default:
                            cout<<"Invalid Operation"<<endl;

                    }
            }
        }

        //cout<<sf::Mouse::getPosition().x<<" x "<<sf::Mouse::getPosition().y<<endl;
        // Clear screen
        app.clear();

        sf::Font font;
        if (!font.loadFromFile("fonts/typesimp.TTF"))
        {
            return EXIT_FAILURE;
        }

        //Font positioning
        sf::Text text("David's Fantasy World!",font,25);
        text.setColor(sf::Color::Red);
        text.setCharacterSize(50);
        text.setPosition(200,200);

        sf::Text text1("New Game",font,20);
        text1.setColor(sf::Color::Red);
        text1.setCharacterSize(50);
        text1.setPosition(400,400);


        sf::Text text2("Quit",font,20);
        text2.setColor(sf::Color::Red);
        text2.setCharacterSize(50);
        text2.setPosition(400,500);


        // Draw the sprite
        app.draw(sprite);

        //Draw our hero
        app.draw(sprite_hero);
        app.draw(sprite_hero_punch);

        //Draw the text
        app.draw(text);
        app.draw(text1);
        app.draw(text2);

        // Update the window
        app.display();
    }

    return EXIT_SUCCESS;
}
