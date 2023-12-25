#include <SFML/Graphics.hpp>
#include <iostream>
#include <ctype.h>


class boardloader
{
private:
static int filecounter;
static int rankcounter;

static sf::Texture findrightpiecetodraw(char piecetype)
{
    sf::Texture piece;
        switch (piecetype)
        {
        case 'b':
            if ((filecounter+rankcounter)%2==1)
            {
                piece.loadFromFile("sprites/pieces/black bishop.png");
            }
            else{piece.loadFromFile("sprites/pieces/black bishop (2).png");}
            break;
        case 'k':
            if ((filecounter+rankcounter)%2==1)
            {
                piece.loadFromFile("sprites/pieces/black king.png");
            }
            else{piece.loadFromFile("sprites/pieces/black king (2).png");}
            break;
        
        case 'n':
            if ((filecounter+rankcounter)%2==1)
            {
                piece.loadFromFile("sprites/pieces/black knight.png");
            }
            else{piece.loadFromFile("sprites/pieces/black knight (2).png");}
            break;

        case 'p':
            if ((filecounter+rankcounter)%2==1)
            {
                piece.loadFromFile("sprites/pieces/black pawn.png");
            }
            else{piece.loadFromFile("sprites/pieces/black pawn (2).png");}
            break;

        case 'q':
            if ((filecounter+rankcounter)%2==1)
            {
                piece.loadFromFile("sprites/pieces/black queen.png");
            }
            else{piece.loadFromFile("sprites/pieces/black queen (2).png");}
            break;

        case 'r':
            if ((filecounter+rankcounter)%2==1)
            {
                piece.loadFromFile("sprites/pieces/black rook.png");
            }
            else{piece.loadFromFile("sprites/pieces/black rook (2).png");}
            break;

        case 'e':
            if ((filecounter+rankcounter)%2==1)
            {
                piece.loadFromFile("sprites/pieces/empty.png");
            }
            else{piece.loadFromFile("sprites/pieces/empty (2).png");}
            break;
        
        case 'B':
            if ((filecounter+rankcounter)%2==1)
            {
                piece.loadFromFile("sprites/pieces/white bishop.png");
            }
            else{piece.loadFromFile("sprites/pieces/white bishop (2).png");}
            break;

        case 'K':
            if ((filecounter+rankcounter)%2==1)
            {
                piece.loadFromFile("sprites/pieces/white king.png");
            }
            else{piece.loadFromFile("sprites/pieces/white king (2).png");}
            break;

        case 'N':
            if ((filecounter+rankcounter)%2==1)
            {
                piece.loadFromFile("sprites/pieces/white knight.png");
            }
            else{piece.loadFromFile("sprites/pieces/white knight (2).png");}
            break;

        case 'P':
            if ((filecounter+rankcounter)%2==1)
            {
                piece.loadFromFile("sprites/pieces/white pawn.png");
            }
            else{piece.loadFromFile("sprites/pieces/white pawn (2).png");}
            break;

        case 'Q':
            if ((filecounter+rankcounter)%2==1)
            {
                piece.loadFromFile("sprites/pieces/white queen.png");
            }
            else{piece.loadFromFile("sprites/pieces/white queen (2).png");}
            break;

        case 'R':
            if ((filecounter+rankcounter)%2==1)
            {
                piece.loadFromFile("sprites/pieces/white rook.png");
            }
            else{piece.loadFromFile("sprites/pieces/white rook (2).png");}
            break;
        
        default:
            break;

            

        
        }
        return piece;
}

static void drawsquare(char piecetype,sf::RenderWindow& window)
    {
        if (filecounter==8)
        {
            
            filecounter=0;
            rankcounter++;
        }
        
        
        
        sf::Texture piecetex=findrightpiecetodraw(piecetype);
        sf::Sprite piece;
        piece.setTexture(piecetex);

        piece.setPosition(filecounter * 140,rankcounter * 140);

        window.draw(piece);
        filecounter++;
        return;
    }
public:
    static void drawfen(std::string FEN,sf::RenderWindow& window)
    {
        
        int i=0;
        filecounter=0;
        rankcounter=0;
        while (FEN[i]!=32)
        {
            if (isdigit(FEN[i]))
            {
                int emptySquareCount = FEN[i] - '0'; // Convert the digit character to an integer
                for (int j = 0; j < emptySquareCount; j++)
                {
                    drawsquare('e', window);
                }
                
            }
            else if (FEN[i]=='/')
            {
                i++;
                continue;
            }            
            else{
                drawsquare(FEN[i],window);
            }
            i++;
        }
        
    }
    boardloader(/* args */);
    ~boardloader();
};

boardloader::boardloader(/* args */)
{
    
}

boardloader::~boardloader()
{
}
int boardloader::rankcounter = 0;
int boardloader::filecounter = 0;
