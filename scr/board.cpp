#include<iostream>
#include <ctype.h>
#include <stdbool.h>
class board
{
private:
    char boardsquare[8][8];
    bool whiteturn;
public:
    void setboardbyfen(std::string FEN)
    {        
        int file=0;
        int rank=0;
        int i=0;
        
        while (FEN[i]!=' ')
        {
            if (file>7)
            {
                rank++;
                file=0;
            }
            if(isdigit(FEN[i]))
            {
                int emptySquareCount = FEN[i] - '0'; // Convert the digit character to an integer
                for (int j = 0; j < emptySquareCount; j++)
                {
                    boardsquare[rank][file]='e';
                    
                    file++;
                }
            }
            else if (FEN[i]=='/')
            {
                
                i++;
                continue;
            }
            else
            {
                
                boardsquare[rank][file]=FEN[i];
                file++;
            }         
            i++;
        }

        
        for (int c = 0; c < 8; c++)
            {
                for (int x = 0; x < 8; x++)
                {
                    
                }
            }
        
        return;
    }
    std::string getboardbystring()
    {
        int emptycount=0;
        std::string rval="";
        for (int i = 0; i < 8; i++)
        {
            for (int j = 0; j < 8; j++)
            {
                if(boardsquare[i][j]!='e')
                {
                    if (emptycount!=0)
                    {
                        rval.append(sizeof(char),(char)emptycount+48);
                        emptycount=0;
                    }
                    rval.append(sizeof(char),boardsquare[i][j]);                   
                }
                else emptycount++;
            }
            if (emptycount!=0)
            {
                 rval.append(sizeof(char),(char)emptycount+48);
                        emptycount=0;
            } 
        }
        rval.append(" ");
        return rval;
    }
    void makemove(int sfile,int srank,int efile,int erank){
        if (isvalidmove(sfile,srank,efile,erank))
        {
            std::cout<< "in makemove\n";
        boardsquare[erank][efile]=boardsquare[srank][sfile];
        boardsquare[srank][sfile]='e';    
        if (whiteturn==true)
        {
            whiteturn=0;
        }
        else whiteturn=1;
           
        }
        
        
        return;
    }
    
    bool isvalidmove(int sfile,int srank,int efile,int erank){
        bool sofar=true;
        if(whiteturn && boardsquare[srank][sfile]<96 && boardsquare[srank][sfile] != 'e'){
            
        }
        else if (!whiteturn && boardsquare[srank][sfile]>96 && boardsquare[srank][sfile] != 'e')
        {
            
        }
        else
        {
            std::cout<<"invald move";
            return false;
        }
        if (sfile==efile && srank==erank)
        {
            std::cout<<"invald move";
            return false;
        }
        
        return sofar;
    }
    
    board(/* args */);
    ~board();
};

board::board(/* args */)
{
    whiteturn=true;
}

board::~board()
{
}
