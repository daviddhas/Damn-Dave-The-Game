#include "game.h"

//using namespace Fantasy;

int fightStart(sf::RenderWindow &app,
    sf::Texture &texture,
    sf::Sprite &sprite,
    sf::Texture &texture_hero,
    sf::Sprite &sprite_hero,
    sf::Music &music,
    sf::Font &font,
    int &flag)
{
//game starts

    sprite_hero.setPosition(381,558);

    sf::Texture texture_trump;
    if(!texture_trump.loadFromFile("images/trump.png"))
        return EXIT_FAILURE;
    sf::Sprite sprite_trump(texture_trump);
    sprite_trump.setPosition(781,490);
    sprite_trump.setTextureRect(sf::IntRect(410,0,-124,133));

    sf::Text ready("READY",font,80);
    ready.setColor(sf::Color::Red);
    ready.setPosition(500,200);
    int readyCount = 0;

    sf::Text go("FIGHT",font,80);
    go.setColor(sf::Color::Red);
    go.setPosition(500,200);

    int jumpSpeed = 2;
    bool up = false;

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
            if (sprite_hero.getPosition().y <= 358)
                up = false;
        }
        else if (!up && sprite_hero.getPosition().y < 558)
        {
            sprite_hero.move(0, jumpSpeed);
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
            if (sprite_hero.getPosition().y == 558)
                up = true;
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        {
            if (flag ==1)
            {
                //  sprite_hero.setScale(-1.0f,1.0f);
                sprite_hero.setTextureRect(sf::IntRect(55,0,-55,72));
                sprite_hero.move(-1,0);
                flag =0;
            }
            else
            {
                sprite_hero.setTextureRect(sf::IntRect(165,0,-55,72));
                sprite_hero.move(-1,0);
                flag =1;
            }
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        {
            if (flag ==0)
            {
                //    sprite_hero.setScale(-1.0f,1.0f);
                sprite_hero.setTextureRect(sf::IntRect(0,0,55,72));
                sprite_hero.move(1,0);
                flag=1;
            }
            else
            {
                sprite_hero.setTextureRect(sf::IntRect(110,0,55,72));
                sprite_hero.move(1,0);
                flag=0;
            }
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
            return 0;
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        {
            sprite_hero.setTextureRect(sf::IntRect(270,78,54,78));
        }


        // Clear screen
        app.clear();



        // Draw the sprite
        app.draw(sprite);


        if (readyCount < 400)
        {
            app.draw(ready);
            readyCount++;
        }
        else if (readyCount >= 400 && readyCount < 800)
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
