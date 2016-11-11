#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
using namespace std;

int main()
{
    // Create the main window
    sf::RenderWindow app(sf::VideoMode(1366, 683), "David Dhas's Game");
    int counterwalking = 0;
    // Load a sprite to display
    sf::Texture texture;
    if (!texture.loadFromFile("images/background.jpg"))
        return EXIT_FAILURE;
    sf::Sprite sprite(texture);


    sf::Texture texture_hero;
    if(!texture_hero.loadFromFile("images/hero.png"))
        return EXIT_FAILURE;
    sf::Sprite sprite_hero(texture_hero);
    sprite_hero.setPosition(81,558);
    sprite_hero.setTextureRect(sf::IntRect(0,0,51,72));
    //sf::IntRect rectSourceSprite(0,0,51,72);
    //sf::Sprite sprite_hero(tex, rectSourceSprite);
    int hero_movement_speed =10;
    sf::Clock clock;
    sf::Texture tex_tile;
    int flag =1;
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
                             //sprite_hero.setPosition(336,480);
                            break;
                        case sf::Keyboard::Up:
                            cout<<"UP"<<endl;
                            //sprite_hero.setPosition(336,380);
                            break;
                        case sf::Keyboard::Left:
                            {
                                if (flag ==1)
                                    sprite_hero.setScale(-1.0f,1.0f);

                                cout<<"Left"<<endl;
                                sprite_hero.move(-hero_movement_speed,0);
                                sprite_hero.setTextureRect(sf::IntRect(counterwalking*55,0,51,72));
                                flag =0;
                                //Flipping the sprite
                                //sprite_hero.setTextureRect(sf::IntRect(counterwalking*55, 0, -55, 72));
                                break;
                            }
                        case sf::Keyboard::Right:
                            {
                                if (flag ==0)
                                    sprite_hero.setScale(-1.0f,1.0f);
                                cout<<"Right"<<endl;
                                sprite_hero.move(hero_movement_speed,0);
                                sprite_hero.setTextureRect(sf::IntRect(counterwalking*55,0,51,72));
                                flag=1;
                                break;
                            }
                        case sf::Keyboard::Return:
                            cout<<"Enter is pressed"<<endl;
                            break;
                        default:
                            cout<<"Invalid Operation"<<endl;

                    }
            }
            counterwalking++;
            if (counterwalking == 3)
                counterwalking =0;
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

        // Draw the sprite
        app.draw(sprite);

        //Draw our hero
        app.draw(sprite_hero);
        //sprite_hero.setPosition(81,558);

     //   app.draw(sprite_hero_punch);

        //Draw the text
        app.draw(text);

        // Update the window
        app.display();
    }

    return EXIT_SUCCESS;
}
