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

mainInterface:
    sf::Sprite sprite_hero(texture_hero);
    sprite_hero.setPosition(450,280);
    sprite_hero.setTextureRect(sf::IntRect(0,0,51,72));
    //sprite_hero.setPosition(81,558);
    //sf::IntRect rectSourceSprite(0,0,51,72);
    //sf::Sprite sprite_hero(tex, rectSourceSprite);





    // Load a music to play
    sf::Music music;
    if (!music.openFromFile("sound/background1.wav"))
        return EXIT_FAILURE;
    // Play the music
    music.play();


    int hero_movement_speed =10;
    sf::Clock clock;
    sf::Texture tex_tile;
    int flag =1;

    sf::Font font;
    if (!font.loadFromFile("fonts/8bit.TTF"))
        return EXIT_FAILURE;

    //Font positioning
    sf::Text text("INGLORIOUS BASTARDS",font,60);
    text.setColor(sf::Color::Red);
    //text.setCharacterSize(60);
    text.setPosition(180,100);


    sf::Text newGame("NEW GAME",font,30);
    newGame.setColor(sf::Color::Red);
    newGame.setPosition(550,300);


    sf::Text location("CHOOSE LOCATION",font,30);
    location.setColor(sf::Color::Red);
    location.setPosition(550,380);

    sf::Text quit("QUIT GAME",font,30);
    quit.setColor(sf::Color::Red);
    quit.setPosition(550,460);

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
                                int height = 558;
                                bool up = false;
                                bool upperRight = false;
                                bool upperLeft = false;

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
                                        else if (event2.type == sf::Event::Resized)
                                            cout<<event.size.width<<':'<<event.size.height<<endl;
                                        //else if (event2.type == sf::Event::LostFocus)
                                            //app.pause();
                                        //else if (event2.type == sf::Event::GainedFocus)
                                            //app.resume();
                                        //else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
                                        /*else if (event2.type == sf::Event::KeyPressed)
                                        {

                                            if(event2.key.code == sf::Keyboard::Down)
                                            {

                                            }
                                            else if(event2.key.code == sf::Keyboard::Up)
                                            {
                                                if (sprite_hero.getPosition().y == 558)
                                                    up = true;
                                            }
                                            else if(event2.key.code == sf::Keyboard::Left)
                                            {
                                                if (flag ==1)
                                                {

                                                  //  sprite_hero.setScale(-1.0f,1.0f);
                                                    sprite_hero.setTextureRect(sf::IntRect(55,0,-55,72));
                                                    sprite_hero.move(-hero_movement_speed,0);
                                                    flag =0;
                                                }
                                                else
                                                {
                                                    sprite_hero.setTextureRect(sf::IntRect(165,0,-55,72));
                                                    sprite_hero.move(-hero_movement_speed,0);
                                                    flag =1;
                                                }
                                            }
                                            else if(event2.key.code == sf::Keyboard::Right)
                                            {
                                                if (flag ==0)
                                                {
                                                    //    sprite_hero.setScale(-1.0f,1.0f);
                                                    sprite_hero.setTextureRect(sf::IntRect(0,0,55,72));
                                                    sprite_hero.move(hero_movement_speed,0);
                                                    flag=1;
                                                }
                                                else
                                                {
                                                    sprite_hero.setTextureRect(sf::IntRect(110,0,55,72));
                                                    sprite_hero.move(hero_movement_speed,0);
                                                    flag=0;
                                            if(event2.key.code == sf::Keyboard::Down)
                                            {

                                            }
                                            else if(event2.key.code == sf::Keyboard::Up)
                                            {
                                                if (sprite_hero.getPosition().y == 558)
                                                    up = true;
                                            }
                                            else if(event2.key.code == sf::Keyboard::Left)
                                            {
                                                if (flag ==1)
                                                {

                                                  //  sprite_hero.setScale(-1.0f,1.0f);
                                                    sprite_hero.setTextureRect(sf::IntRect(55,0,-55,72));
                                                    sprite_hero.move(-hero_movement_speed,0);
                                                    flag =0;
                                                }
                                                else
                                                {
                                                    sprite_hero.setTextureRect(sf::IntRect(165,0,-55,72));
                                                    sprite_hero.move(-hero_movement_speed,0);
                                                    flag =1;
                                                }
                                            }
                                            else if(event2.key.code == sf::Keyboard::Right)
                                            {
                                                if (flag ==0)
                                                {
                                                    //    sprite_hero.setScale(-1.0f,1.0f);
                                                    sprite_hero.setTextureRect(sf::IntRect(0,0,55,72));
                                                    sprite_hero.move(hero_movement_speed,0);
                                                    flag=1;
                                                }
                                                }
                                            }
                                            else if(event2.key.code == sf::Keyboard::Escape)
                                            {
                                                fightingMusic.stop();
                                                goto mainInterface;
                                            }
                                        }
                                        */
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
                                        goto mainInterface;




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

        //Draw Trump
//        app.draw(sprite_trump);
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
