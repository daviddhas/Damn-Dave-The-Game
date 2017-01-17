#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

int fightStart(sf::RenderWindow &app, sf::Texture &mainBackground,
               sf::Sprite &sprite, sf::Texture &texture_hero,
               sf::Sprite &sprite_hero, sf::Music &music,
               sf::Font &font, int &walkingStep);

#endif // GAME_H_INCLUDED
