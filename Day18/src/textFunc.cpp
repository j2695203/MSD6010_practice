//
//  textFunc.cpp
//  testSFML
//
//  Created by Jinny Jeng on 9/19/22.
//

#include "textFunc.hpp"
#include <SFML/Graphics.hpp>
#include <iostream>

void textFunc(sf::Text& text){
    sf::Font font;
    font.loadFromFile("MarkerFelt.ttc");
//    sf::Text text;
    // select the font
    text.setFont(font); // font is a sf::Font

    // set the string to display
    text.setString("Hello world");

    // set the character size
    text.setCharacterSize(24); // in pixels, not points!

    // set the color
    text.setFillColor(sf::Color::Red);

    // set the text style
    text.setStyle(sf::Text::Bold | sf::Text::Underlined);

    std::cout<<"YOU ARE IN FUNCTION";
}
