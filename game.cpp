#include "game.h"

//using namespace Fantasy;

int fightStart(sf::RenderWindow &app, sf::Texture &mainBackground,
               sf::Sprite &sprite, sf::Texture &texture_hero,
               sf::Sprite &sprite_hero, sf::Music &music,
               sf::Font &font, int &walkingStep)
{
//game starts
    sprite_hero.setPosition(381,520);
    sprite_hero.scale(sf::Vector2f(1.5f, 1.5f));

    sf::Texture texture_trump;
    if(!texture_trump.loadFromFile("images/trump.png"))
        return EXIT_FAILURE;
    sf::Sprite sprite_trump(texture_trump);
    sprite_trump.setPosition(781,425);
    sprite_trump.setTextureRect(sf::IntRect(410,0,-124,133));
    sprite_trump.scale(sf::Vector2f(1.5f, 1.5f));


    sf::Text ready("READY",font,80);
    ready.setColor(sf::Color::Red);
    ready.setPosition(500,200);
    int readyCount = 0;

    sf::Text go("FIGHT",font,80);
    go.setColor(sf::Color::Red);
    go.setPosition(500,200);

    int jumpSpeed = 1;
    bool up = false;
    int quickPunchLeft = 0;
    int quickPunchRight = 0;
    bool facingRight = true;

// Load a music to play
    music.stop();
    sf::Music fightingMusic;
    if (!fightingMusic.openFromFile("sound/background.wav"))
        return EXIT_FAILURE;
// Play the music
    fightingMusic.play();


    while (app.isOpen())
    {
        if (up)
        {
            sprite_hero.move(0, -jumpSpeed);
            if (sprite_hero.getPosition().y <= 150)
                up = false;
        }
        else if (!up && sprite_hero.getPosition().y < 520)
        {
            sprite_hero.move(0, jumpSpeed);
        }

        switch (quickPunchLeft)
        {
        case 1:
            sprite_hero.setTextureRect(sf::IntRect(320,85,54,72));
            quickPunchLeft = 2;
            break;
        case 2:
            sprite_hero.setTextureRect(sf::IntRect(0,0,54,72));
            quickPunchLeft = 0;
            break;
        }

        switch (quickPunchRight)
        {
        case 1:
            sprite_hero.setTextureRect(sf::IntRect(374,85,-54,72));
            quickPunchRight = 2;
            break;
        case 2:
            sprite_hero.setTextureRect(sf::IntRect(54,0,-54,72));
            quickPunchRight = 0;
            break;
        }

        // Process events
        sf::Event event2;
        while (app.pollEvent(event2))
        {
            if (event2.type == sf::Event::Closed)
                app.close();
            //else if (event2.type == sf::Event::Resized)
            //  cout<<event.size.width<<':'<<event.size.height<<endl;
            //else if (event2.type == sf::Event::LostFocus)
            //app.pause();
            //else if (event2.type == sf::Event::GainedFocus)
            //app.resume();
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        {

        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        {
            if (sprite_hero.getPosition().y == 520)
                up = true;
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        {
            facingRight = false;
            switch (walkingStep)
            {
            case 0:
                sprite_hero.setTextureRect(sf::IntRect(55,0,-55,72));
                sprite_hero.move(-0.5,0);
                walkingStep=1;
                break;
            case 1:
                sprite_hero.setTextureRect(sf::IntRect(110,0,-55,72));
                sprite_hero.move(-0.5,0);
                walkingStep=2;
                break;
            case 2:
                sprite_hero.setTextureRect(sf::IntRect(165,0,-55,72));
                sprite_hero.move(-0.5,0);
                walkingStep=3;
                break;
            case 3:
                sprite_hero.setTextureRect(sf::IntRect(220,0,-55,72));
                sprite_hero.move(-0.5,0);
                walkingStep=0;
                break;
            }
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        {
            facingRight = true;
            switch (walkingStep)
            {
            case 0:
                sprite_hero.setTextureRect(sf::IntRect(0,0,55,72));
                sprite_hero.move(0.5,0);
                walkingStep=1;
                break;
            case 1:
                sprite_hero.setTextureRect(sf::IntRect(55,0,55,72));
                sprite_hero.move(0.5,0);
                walkingStep=2;
                break;
            case 2:
                sprite_hero.setTextureRect(sf::IntRect(110,0,55,72));
                sprite_hero.move(0.5,0);
                walkingStep=3;
                break;
            case 3:
                sprite_hero.setTextureRect(sf::IntRect(165,0,55,72));
                sprite_hero.move(0.5,0);
                walkingStep=0;
                break;
            }
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
        {
            fightingMusic.stop();
            return 0;
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        {
            if (facingRight)
            {
                sprite_hero.setTextureRect(sf::IntRect(265,85,54,72));
                quickPunchLeft = 1;
            }
            else
            {
                sprite_hero.setTextureRect(sf::IntRect(319,85,-54,72));
                quickPunchRight = 1;
            }
        }


        // Clear screen
        app.clear();



        // Draw the sprite
        app.draw(sprite);


        if (readyCount < 1000)
        {
            app.draw(ready);
            readyCount++;
        }
        else if (readyCount >= 1000 && readyCount < 2000)
        {
            app.draw(go);
            readyCount++;
        }


        //Draw our hero
        app.draw(sprite_hero);

        //Draw Trump
        app.draw(sprite_trump);

        //app.draw(sprite_hero_punch);

        // Update the window
        app.display();

    }

    return 0;
}
