#include <SFML/Graphics.hpp>
#include "textFunc.hpp"


int main()
{
    // create the window
    sf::RenderWindow window(sf::VideoMode(800, 600), "Jinny's window");

    // run the program as long as the window is open
    while (window.isOpen())
    {
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event))
        {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // clear the window with black color
        window.clear(sf::Color(200,200,200));

        /*
         Draw a Circle
         */
	sf::CircleShape shape(150.f);
        // texture
        sf::Texture texture;
        texture.loadFromFile("earth.jpeg");
        shape.setTexture(&texture);
        window.draw(shape);
        
        /*
         Print Text (fail....using function)
         */
//        sf::Text text;
//        textFunc(text);
//        window.draw(text);
    
        /*
         entities with vertex arrays
         */
//        // create an array of 3 vertices that define a triangle primitive
//        sf::VertexArray triangle(sf::Triangles, 3);
//
//        // define the position of the triangle's points
//        triangle[0].position = sf::Vector2f(10.f, 10.f);
//        triangle[1].position = sf::Vector2f(100.f, 10.f);
//        triangle[2].position = sf::Vector2f(100.f, 100.f);
//
//        // define the color of the triangle's points
//        triangle[0].color = sf::Color::Red;
//        triangle[1].color = sf::Color::Blue;
//        triangle[2].color = sf::Color::Green;
//
//        window.draw(triangle);
        
        
        /*
         Position
         */
        // set the absolute position of the entity
        shape.setPosition(10.f, 50.f);

        // move the entity relatively to its current position
        shape.move(5.f, 5.f);

        // retrieve the absolute position of the entity
        sf::Vector2f position = shape.getPosition(); // = (15, 55)
        
        
	// end the current frame
        window.display();
    }
    return 0;
}
