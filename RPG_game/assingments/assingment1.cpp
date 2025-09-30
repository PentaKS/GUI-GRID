#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>

class shapes
{
public:
    sf::CircleShape circle;
    sf::RectangleShape rect;
    shapes(float radius = 0.0f, sf::Vector2f size = sf::Vector2f({ 0,0 })) : circle(radius), rect(size) {};

    float radius;
    float circleMoveSpeedx;
    float circleMoveSpeedy;

    sf::Vector2f size = sf::Vector2f({ 160, 40 });
    sf::Vector2f dimens;

};

void physics(shapes& j, sf::CircleShape& i, float wWidth, float wHeight)
{
    {
        i.setPosition({ i.getPosition().x + j.circleMoveSpeedx, i.getPosition().y + j.circleMoveSpeedy });

        if ((i.getPosition().x > (wWidth - j.radius * 2)) || (i.getPosition().x < 0))
        {
            j.circleMoveSpeedx = -j.circleMoveSpeedx;
        }
        if ((i.getPosition().y < 0) || (i.getPosition().y > (wHeight - j.radius * 2)))
        {
            j.circleMoveSpeedy = -j.circleMoveSpeedy;
        }
    }
}
void physics_rect(shapes& j, sf::RectangleShape& i, float wWidth, float wHeight)
{
    {
        i.setPosition({ i.getPosition().x + j.circleMoveSpeedx, i.getPosition().y + j.circleMoveSpeedy });

        if ((i.getPosition().x > (wWidth - j.dimens.x)) || (i.getPosition().x < 0))
        {
            j.circleMoveSpeedx = -j.circleMoveSpeedx;
        }
        if ((i.getPosition().y < 0) || (i.getPosition().y > (wHeight - j.dimens.y)))
        {
            j.circleMoveSpeedy = -j.circleMoveSpeedy;
        }
    }
}


int main()
{
    const int wWidth = 1280;
    const int wHeight = 720;

    sf::RenderWindow window(sf::VideoMode({ wWidth, wHeight }), "SFML works!");
    window.setFramerateLimit(60);

    std::vector<sf::CircleShape> circles;
    std::vector<class shapes> circle_classes;
    std::vector<sf::RectangleShape> rectangles;
    std::vector<class shapes> rectangle_classes;
    std::vector<sf::Text> texts;

    shapes circle1(100);
    shapes circle2(150);
    shapes circle3(90);
    shapes circle4(70);

    circle1.radius = 100;
    circle2.radius = 150;
    circle3.radius = 90;
    circle4.radius = 70;

    circle1.circle.setPosition({ 12, 72 });
    circle2.circle.setPosition({ 100, 150 });
    circle3.circle.setPosition({ 40 , 300 });
    circle4.circle.setPosition({ 1280 / 2, 720 / 2 });

    circle1.circle.setFillColor(sf::Color::Red);
    circle2.circle.setFillColor(sf::Color::Blue);
    circle3.circle.setFillColor(sf::Color::Green);
    circle4.circle.setFillColor(sf::Color::Cyan);

    circles.push_back(circle1.circle);
    circles.push_back(circle2.circle);
    circles.push_back(circle3.circle);
    circles.push_back(circle4.circle);

    circle_classes.push_back(circle1);
    circle_classes.push_back(circle2);
    circle_classes.push_back(circle3);
    circle_classes.push_back(circle4);

    circle1.circleMoveSpeedx = 8.0f;
    circle1.circleMoveSpeedy = 8.0f;

    circle2.circleMoveSpeedx = 1.0f;
    circle2.circleMoveSpeedy = 1.0f;

    circle3.circleMoveSpeedx = -8.0f;
    circle3.circleMoveSpeedy = -8.0f;

    circle4.circleMoveSpeedx = -1.0f;
    circle4.circleMoveSpeedy = -1.0f;

    sf::Vector2f text_outline = sf::Vector2f({ 160, 40 });


    shapes rect1(0, text_outline);
    rect1.rect.setFillColor(sf::Color::Black);
    rectangles.push_back(rect1.rect);
    rectangle_classes.push_back(rect1);
    rect1.circleMoveSpeedx = 5.0f;
    rect1.circleMoveSpeedy = 5.0f;

    shapes rect2(0, text_outline);
    rect2.rect.setFillColor(sf::Color::Black);
    rectangles.push_back(rect2.rect);
    rectangle_classes.push_back(rect2);
    rect2.circleMoveSpeedx = 5.0f;
    rect2.circleMoveSpeedy = 5.0f;

    shapes rect3(0, text_outline);
    rect3.rect.setFillColor(sf::Color::Black);
    rectangles.push_back(rect3.rect);
    rectangle_classes.push_back(rect3);
    rect3.circleMoveSpeedx = 5.0f;
    rect3.circleMoveSpeedy = 5.0f;

    shapes rect4(0, text_outline);
    rect4.rect.setFillColor(sf::Color::Black);
    rectangles.push_back(rect4.rect);
    rectangle_classes.push_back(rect4);
    rect4.circleMoveSpeedx = 5.0f;
    rect4.circleMoveSpeedy = 5.0f;

    shapes rect5(0, sf::Vector2f({ 200, 300 }));
    rect5.dimens = sf::Vector2f({ 200, 300 });
    rect5.rect.setFillColor(sf::Color::Yellow);
    rectangles.push_back(rect5.rect);
    rectangle_classes.push_back(rect5);
    rect5.circleMoveSpeedx = -5.0f;
    rect5.circleMoveSpeedy = -5.0f;

    shapes rect6(0, sf::Vector2f({ 250, 70 }));
    rect6.dimens = sf::Vector2f({ 250, 70 });

    rect6.rect.setFillColor(sf::Color::Magenta);
    rectangles.push_back(rect6.rect);
    rectangle_classes.push_back(rect6);
    rect6.circleMoveSpeedx = 3.0f;
    rect6.circleMoveSpeedy = 3.0f;

    shapes rect7(0, text_outline);
    rect7.rect.setFillColor(sf::Color::Black);
    rectangles.push_back(rect7.rect);
    rectangle_classes.push_back(rect7);
    rect7.circleMoveSpeedx = 5.0f;
    rect7.circleMoveSpeedy = 5.0f;

    shapes rect8(0, text_outline);
    rect8.rect.setFillColor(sf::Color::Black);
    rectangles.push_back(rect8.rect);
    rectangle_classes.push_back(rect8);
    rect8.circleMoveSpeedx = 5.0f;
    rect8.circleMoveSpeedy = 5.0f;

    sf::Font font("NataSans-VariableFont_wght.ttf");
    sf::Text text1(font);
    sf::Text text2(font);
    sf::Text text3(font);
    sf::Text text4(font);
    sf::Text text5(font);
    sf::Text text6(font);

    texts.push_back(text1);
    texts.push_back(text2);
    texts.push_back(text3);
    texts.push_back(text4);
    texts.push_back(text5);
    texts.push_back(text6);

    std::string str[6] = { "red", "blue", "green", "cyan", "yellow", "magenta" };

    for (int i = 0; i < texts.size(); i++)
    {
        texts[i].setString(str[i]);
        texts[i].setCharacterSize(30);
        texts[i].setFillColor(sf::Color::Black);
        texts[i].setStyle(sf::Text::Bold);
        //texts[i].setLetterSpacing(3);

        std::cout << (std::string)texts[i].getString() << std::endl;

    }

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

        physics(circle1, circles[0], wWidth, wHeight);
        physics(circle2, circles[1], wWidth, wHeight);
        physics(circle3, circles[2], wWidth, wHeight);
        physics(circle4, circles[3], wWidth, wHeight);
        physics_rect(rect5, rectangles[4], wWidth, wHeight);
        physics_rect(rect6, rectangles[5], wWidth, wHeight);

        window.clear();
        for (int i = 0; i < 4; i++)
        {
            window.draw(circles[i]);
            rectangle_classes[i].rect.setPosition(sf::Vector2f(circles[i].getPosition().x + circle_classes[i].radius - rectangle_classes[i].size.x / 2, circles[i].getPosition().y + circle_classes[i].radius - rectangle_classes[i].size.y / 2));
            //window.draw(rectangle_classes[i].rect);
            texts[i].setPosition({ circles[i].getPosition().x + circle_classes[i].radius - (texts[i].getString().getSize() * (texts[i].getCharacterSize() / 3)), circles[i].getPosition().y + circle_classes[i].radius - (float)(texts[i].getCharacterSize() / 2) });
            window.draw(texts[i]);
        }
        for (int i = 4; i < 6; i++)
        {
            window.draw(rectangles[i]);
            rectangle_classes[i + 2].rect.setPosition(sf::Vector2f(rectangles[i].getPosition().x + rectangle_classes[i].dimens.x / 2 - rectangle_classes[i + 2].size.x / 2, rectangles[i].getPosition().y + rectangle_classes[i].dimens.y / 2 - rectangle_classes[i + 2].size.y / 2));
            //window.draw(rectangle_classes[i+2].rect);
            texts[i].setPosition({ rectangles[i].getPosition().x + rectangle_classes[i].dimens.x / 2 - (texts[i].getString().getSize() * (texts[i].getCharacterSize() / 3)), rectangles[i].getPosition().y + rectangle_classes[i].dimens.y / 2 - (float)(texts[i].getCharacterSize() / 2) });
            window.draw(texts[i]);
        }
        window.display();
    }
}