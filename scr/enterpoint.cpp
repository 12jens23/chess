#include <SFML/Graphics.hpp>
#include <iostream>
#include<cmath>
#include"boardloader.cpp"
#include"board.cpp"

class position
{

public:
    int file;
    int rank;

};



int main()
{
    sf::RenderWindow window(sf::VideoMode(1400, 1400), "SFML works!");
    
    
    std::string fenstart="rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR ";

    position selectedsquare;
    selectedsquare.file=9;
    selectedsquare.rank=9;
    
    board mainboard;
    
    mainboard.setboardbyfen("8/8/8/8/8/4b3/8/8 ");
    while (window.isOpen())
    {
        
        
        
        
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();  
            if (event.type ==sf::Event::MouseButtonPressed)
            {
                if (event.mouseButton.button==sf::Mouse::Right)
                {
                    if (selectedsquare.file != 9 && selectedsquare.rank != 9)
                    {
                        mainboard.makemove(selectedsquare.file, selectedsquare.rank,event.mouseButton.x/140,event.mouseButton.y/140);
                        selectedsquare.file=9;
                        selectedsquare.rank=9;
                    }
                    else{
                        selectedsquare.file=event.mouseButton.x/140;
                        selectedsquare.rank=event.mouseButton.y/140;
                        std::cout<< "selceted:" <<event.mouseButton.x/140<<","<< event.mouseButton.y/140;
                    }
                    
                }
                
            }
                          
        }

        
        window.clear();
        boardloader::drawfen(mainboard.getboardbystring(),window);
        window.display();
    }

    return 0;
}