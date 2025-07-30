// Copyright 2025 Danny Nguyen

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

int main() {
    // Create the main window
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML window");
    // Create a green cirlce
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);
    // Load a sprite to display
    sf::Texture texture;
    if (!texture.loadFromFile("sprite.png"))
        return EXIT_FAILURE;
    sf::Sprite sprite(texture);
    sprite.setScale(0.5f, 0.5f);
    // Start the game loop
    while (window.isOpen()) {
        // Process events
        sf::Event event;
        while (window.pollEvent(event)) {
            // Close window: exit
            if (event.type == sf::Event::Closed)
                window.close();
            // Randomize the circle's color by pressing Q
            if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::Q) {
                   shape.setFillColor(sf::Color(
                        std::rand() % 256,
                        std::rand() % 256,
                        std::rand() % 256));
                }
            }
        }
        float speed = 3.0f;  // pixels per frame
        // Movement Keys for Sprite
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
            sprite.move(-speed, 0);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
            sprite.move(speed, 0);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
            sprite.move(0, -speed);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
            sprite.move(0, speed);
        // Movement Keys for Circle
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
            shape.move(-speed, 0);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
            shape.move(speed, 0);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
            shape.move(0, -speed);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
            shape.move(0, speed);
        // Clear screen
        window.clear();
        // Draw the sprite
        window.draw(sprite);
        // Draw the circle
        window.draw(shape);
        // Draw the string
        window.display();
    }
    return EXIT_SUCCESS;
}

