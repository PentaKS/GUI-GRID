#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <windows.h>

std::vector<int> ind = { 0,0 };
std::vector<int> global_input_coord = { 0,0 };
sf::RectangleShape square(float i, float j, sf::Vector2f size, float division, float spacing, std::vector<int> cellpos)
{
    sf::RectangleShape sq;
    float side = size.x / division;
    //float spacing = 20;
    sq.setSize({ side - spacing, side - spacing });
    if (cellpos[0] == ind[0] && cellpos[1] == ind[1])
    {
        sq.setFillColor(sf::Color::Yellow);
    }
    else
    {
        sq.setFillColor(sf::Color(42, 42, 46));

    }
    sq.setPosition({ i* side + (spacing/2), j* side + spacing/2});
    return sq;
}

void changeCell(std::vector<int> coord)
{
    global_input_coord = coord;
}

int main()
{
    const int wWidth = 1280;
    const int wHeight = 1280;

    sf::RenderWindow window(sf::VideoMode({ wWidth, wHeight }), "SFML works!");
    window.setFramerateLimit(60);

    while (window.isOpen())
    {
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
                window.close();
            else if (const auto* Keypressed = event->getIf<sf::Event::KeyPressed>())
            {
                if (Keypressed->scancode == sf::Keyboard::Scancode::Escape)
                    window.close();
            }
        }
        float div = 16;
        float space = 10;
        changeCell({ 3,4 });
        window.clear(sf::Color(72, 72, 79));
        for (int i = 0; i < div; i++)
        {
            for (int j = 0; j < div; j++)
            {
                ind = { i + 1,j + 1 };
                sf::RectangleShape req_sq = square(i, j, { wWidth, wHeight }, div, space, global_input_coord);
                window.draw(req_sq);
            }
        }
        window.display();
    }
}