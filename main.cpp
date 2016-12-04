#include <iostream>
#include "game.h"
#include "mainHeader.h"

using namespace std;
using namespace Fantasy;

int main()
{
    // Create the main window interface
    app.create(sf::VideoMode(1366, 683), "David Dhas's Game");
    // Load a sprite to display
    if (!mainBackground.loadFromFile("images/background.jpg"))
        return EXIT_FAILURE;
    sprite.setTexture(mainBackground);


    if(!texture_hero.loadFromFile("images/hero.png"))
        return EXIT_FAILURE;

    sprite_hero.setTexture(texture_hero);
    sprite_hero.setPosition(-750,280);
    sprite_hero.setTextureRect(sf::IntRect(0,0,51,72));
    //sprite_hero.setPosition(81,558);
    //sf::IntRect rectSourceSprite(0,0,51,72);
    //sf::Sprite sprite_hero(tex, rectSourceSprite);

    // Load a music to play
    if (!music.openFromFile("sound/background1.wav"))
        return EXIT_FAILURE;
    // Play the music
    music.play();


    int hero_movement_speed =10;
    sf::Clock clock;
    sf::Texture tex_tile;

    if (!font.loadFromFile("fonts/8bit.TTF"))
        return EXIT_FAILURE;

    //Font positioning
    sf::Text text("INGLORIOUS BASTARDS",font,60);
    text.setColor(sf::Color::Red);
    //text.setCharacterSize(60);
    text.setPosition(-1020,100);


    sf::Text newGame("NEW GAME",font,30);
    newGame.setColor(sf::Color::Red);
    newGame.setPosition(-650,300);


    sf::Text location("CHOOSE LOCATION",font,30);
    location.setColor(sf::Color::Red);
    location.setPosition(-650,380);

    sf::Text quit("QUIT GAME",font,30);
    quit.setColor(sf::Color::Red);
    quit.setPosition(-650,460);

    int leftFoot = 0;


    // Start the game loop
    while (app.isOpen())
    {
        int counterwalking = 0;


        if (leftFoot ==0)
        {
            sprite_hero.setTextureRect(sf::IntRect(0,0,55,72));
            leftFoot=1;
        }
        else
        {
            sprite_hero.setTextureRect(sf::IntRect(110,0,55,72));
            leftFoot = 0;
        }



        if (text.getPosition().x < 180)
            text.move(1, 0);
        if (newGame.getPosition().x < 550)
            newGame.move(1, 0);
        if (location.getPosition().x < 550)
            location.move(1, 0);
        if (quit.getPosition().x < 550)
            quit.move(1, 0);
        if (sprite_hero.getPosition().x < 450)
            sprite_hero.move(1, 0);


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
                    sprite_hero.move(0, 80);
                    if (sprite_hero.getPosition().y == 520)
                        sprite_hero.setPosition(450, 280);
                    break;
                case sf::Keyboard::Up:
                    sprite_hero.move(0, -80);
                    if (sprite_hero.getPosition().y == 200)
                        sprite_hero.setPosition(450, 440);
                    break;
                case sf::Keyboard::Escape:
                    return EXIT_SUCCESS;
                case sf::Keyboard::Return:
                    if (sprite_hero.getPosition().y == 280)
                    {
                        fightStart(app,mainBackground,sprite,texture_hero,
                                   sprite_hero,music,font,flag);

                        sprite_hero.setTexture(texture_hero);
                        sprite_hero.setPosition(-750,280);
                        sprite_hero.setTextureRect(sf::IntRect(0,0,51,72));

                        text.setPosition(-1020,100);
                        newGame.setPosition(-650,300);
                        location.setPosition(-650,380);
                        quit.setPosition(-650,460);

                        // Load a music to play
                        if (!music.openFromFile("sound/background1.wav"))
                            return EXIT_FAILURE;
                        // Play the music
                        music.play();

                    }
                    else if (sprite_hero.getPosition().y == 360)
                    {
                        //choose map
                    }
                    else if (sprite_hero.getPosition().y == 440)
                        //quit game
                        return EXIT_SUCCESS;
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

        // Draw the sprite
        app.draw(sprite);

        //Draw our hero
        app.draw(sprite_hero);

        //sprite_hero.setPosition(81,558);

        //   app.draw(sprite_hero_punch);

        //Draw the text
        app.draw(text);
        app.draw(newGame);
        app.draw(location);
        app.draw(quit);

        // Update the window
        app.display();
    }

    return EXIT_SUCCESS;
}
