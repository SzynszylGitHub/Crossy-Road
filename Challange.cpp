#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "Ground.h"
#include "Player.h"
#include "Auta.h"
#include "Background.h"
#include "Respawn.h"
#include "Menu.h"
#include <iostream>
#include "Bar.h"
#include "HeartDisplay.h"


#define width 1500
#define height 1100
#define startpos 1000;

Background SetBackground(sf::Texture &tekstura, sf::Texture &finish)
{
   auto init = Background::init(tekstura,finish, sf::Vector2f(width, height),
        100, TypeOfGround::asphalt, sf::Vector2f(0, 0));
    Background background(init, sf::Vector2f(0,0));
    background.SetInOrder();
    return background;
}

Respawn SetRespawn(sf::Vector2f pos)
{
    const int NumOfTexture = 3;
    sf::Texture t[NumOfTexture];
    for (int i = 0; i < NumOfTexture; i++) {
        t[i].loadFromFile(std::string("Assets/Auto") + std::to_string(i + 2) + std::string(".png"));
    }

    std::vector<sf::Texture*> g;
    for (int i = 0; i < NumOfTexture; i++)
        g.emplace_back(new sf::Texture(t[i]));

    auto init = Respawn::init(g, sf::Vector2f(width, height), pos);

    Respawn respawn(init, sf::Vector2f(0, 0));
    return respawn;
}

bool isEnd(Player &player,bool &restart)
{
    if (player.GetHitboxPosition().y < 100)
    {
        restart = true;
        return true;
    } return false;
}

bool Colission(Player& player, Respawn& respawn, HeartDisplay& hearts)
{
    for (auto& el : respawn)
    {
        if (player.Contact(el->GetHitbox()))
        {
            hearts.deleteHeart();
            return true;
        }
    } return false;
}

int main()
{
    std::string win = "CONGRATULATIONS! YOU SUCCESSFULLY FINISHED YOUR GAME!";
    sf::Font f1;
    f1.loadFromFile("Assets/font/EnglishTowne.ttf");
    Bar bar(win, f1,
        sf::Vector2f(0, height / 2), sf::Vector2f(width, 200));
    bar.reSizeCharacter(40);
    bar.setTitlePosition(sf::Vector2f(135, 100));
    bar.setColorRectangle(sf::Color(255, 255, 255, 255*0.6));
    
    bool draw_bar = false;
    bool restart = false;
    bool pause = false;

    int Hearts = 3;

    do
    {
    sf::RenderWindow window(sf::VideoMode(width, height), "Crossyroad");
    sf::Event event;
    window.setFramerateLimit(60);

    sf::Texture Menu_background;
    Menu_background.loadFromFile("Assets/Menu.png");
    Menu menu(width,height);
    menu.setBackground(Menu_background);
    
    if (restart)
    {
        menu.OpenWindow(false);
    }
        
        restart = false;

        sf::Texture grass;
        grass.loadFromFile("Assets/grass.png");

        sf::Texture road;
        road.loadFromFile("Assets/road.png");
        Background b1 = SetBackground(road, grass);

        sf::Texture texplayer;
        texplayer.loadFromFile("Assets/Auto1.png");
        Player player(texplayer, sf::Vector2f(750, 1050));
        player.SetHitboxColor(sf::Color::Red);
    
        HeartDisplay hearts("Assets/heart.png", Hearts, 70);
        hearts.setPosition(sf::Vector2f(width - 50, 0));


        

        Respawn respawn = SetRespawn(sf::Vector2f(0, 0));

        sf::Clock clock;
        clock.restart();
        sf::Time timer = sf::Time::Zero;

        while (window.isOpen()) {

            if (!menu.isOpen()) {
                if (!pause)
                    timer += clock.restart();
                respawn.Update(timer);
            }

            draw_bar = isEnd(player,restart);

            restart = Colission(player, respawn, hearts);
            Hearts = hearts.getHp();

            // check all the window's events that were triggered since the last iteration of the loop
            if (restart == true)
            {
                window.close();
            }
            
            
            sf::Event event;
            while (window.pollEvent(event)) {
                if (!pause)
                    player.Control(event);

                // "close requested" event: we close the window
                if (event.type == sf::Event::Closed)
                    window.close();

                if (event.key.code == sf::Keyboard::P && event.type == sf::Event::KeyReleased)
                    pause ? pause = false : pause = true;

                if (event.key.code == sf::Keyboard::R && 
                    event.type == sf::Event::KeyReleased)
                {
                    restart = true;
                    Hearts = 3;

                    window.close();
                }

                if (menu.isOpen()) {
                    if (event.mouseButton.button == sf::Mouse::Left)
                        menu.handleClick(event.mouseButton.x, event.mouseButton.y);

                    menu.PressSth(event);

                    if (event.key.code == sf::Keyboard::Enter) {
                        auto selected = menu.getSelectedItem();
                        if (selected == Options::Play)
                            menu.OpenWindow(false);

                        if (selected == Options::Close)
                            window.close();

                        //std::cout << "wybrane: " << menu.getSelectedItemIndex() << std::endl;
                    }
                }
            }
            if (hearts.getHp() <= 0) {
                bar.setString("You lose!");
                bar.center();
            }

            // clear the window with black color
            window.clear(sf::Color::Black);

            if (!menu.isOpen()) {
                // draw everything here...
                b1.Draw(window);
                hearts.draw(window);
                player.draw(window);

                respawn.Draw(window);

            }

            if (draw_bar or hearts.getHp() <= 0)
            {
                if (hearts.getHp() > 0) {
                    bar.setString(win);
                    bar.setTitlePosition(sf::Vector2f(135, 100));
                }

                bar.draw(window);

            }
            // render menu
            menu.draw(window);

            // end the current frame
            window.display();
        }

    } while (restart);
    return 0;
}
