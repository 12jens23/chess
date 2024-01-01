#include <iostream>
#include <ctype.h>
#include <stdbool.h>
#include "move.cpp"
#include <vector>
class board
{
private:
    char boardsquare[8][8];
    bool whiteturn;
    std::vector<move> pseudu_possible_moves;
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
                    boardsquare[7-rank][file]='e';
                    
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
                
                boardsquare[7-rank][file]=FEN[i];
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
        for (int i = 7; i > -1; i--)
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
    
    void add_move_if_inside_board(int srank,int sfile,int erank, int efile){
        if (-1 < srank && srank < 8 && -1 < sfile && sfile < 8 && -1 < erank && erank < 8 && -1 < efile && efile < 8)
        {
            
           move x;
           x.setmove(srank,sfile,erank,efile);
           pseudu_possible_moves.emplace_back(x);
           
           
        }
        
    }

    bool move_is_inside_board(int srank,int sfile,int erank, int efile){
         if (-1 < srank && srank < 8 && -1 < sfile && sfile < 8 && -1 < erank && erank < 8 && -1 < efile && efile < 8)
        {
            return true;
        }
        else{ return false;}
    }


    void generate_bishop_moves(int rank,int file)
    {
        if(!whiteturn){
                        
                        int i=1;
                        
                        while (rank+i<8 && file+i <8)
                        {
                            if (boardsquare[rank+i][file+i]!='e')
                            {
                                if (boardsquare[rank+i][file+i]<96)
                                {
                                    add_move_if_inside_board(rank,file,rank+i,file+i);
                                    break;
                                }
                                else break;
                                
                            }
                            else add_move_if_inside_board(rank,file,rank+i,file+i);
                            i++;
                        }
                        i=1;
                        
                        while (rank+i<8 && file-i >-1)
                        {
                            if (boardsquare[rank+i][file-i]!='e')
                            {
                                if (boardsquare[rank+i][file-i]<96)
                                {
                                    add_move_if_inside_board(rank,file,rank+i,file-i);
                                    break;
                                }
                                else break;
                                
                            }
                            else add_move_if_inside_board(rank,file,rank+i,file-i);
                            i++;
                        }
                        i=1;
                        
                        
                        while (((rank-i)>-1) && ((file+i) <8))
                        {
                            
                            if (boardsquare[rank-i][file+i]!='e')
                            {
                                if (boardsquare[rank-i][file+i]<96)
                               {
                                    add_move_if_inside_board(rank,file,rank-i,file+i);
                                    break;
                                }
                                else break;
                                
                            }
                            else add_move_if_inside_board(rank,file,rank-i,file+i);
                            i++;
                        }

                        i=1;

                        while (((rank-i)>-1) && ((file-i) > -1))
                        {
                            
                            if (boardsquare[rank-i][file-i]!='e')
                            {
                                if (boardsquare[rank-i][file-i]<96)
                               {
                                    add_move_if_inside_board(rank,file,rank-i,file-i);
                                    break;
                                }
                                else break;
                                
                            }
                            else add_move_if_inside_board(rank,file,rank-i,file-i);
                            i++;
                        }
                        
                        
                    }

        if(whiteturn){
                            
                        int i=1;
                        
                        while (rank+i<8 && file+i <8)
                        {
                            if (boardsquare[rank+i][file+i]!='e')
                            {
                                if (boardsquare[rank+i][file+i]>96)
                                {
                                    add_move_if_inside_board(rank,file,rank+i,file+i);
                                    break;
                                }
                                else break;
                                
                            }
                            else add_move_if_inside_board(rank,file,rank+i,file+i);
                            i++;
                        }
                        i=1;
                        
                        while (rank+i<8 && file-i >-1)
                        {
                            if (boardsquare[rank+i][file-i]!='e')
                            {
                                if (boardsquare[rank+i][file-i]>96)
                                {
                                    add_move_if_inside_board(rank,file,rank+i,file-i);
                                    break;
                                }
                                else break;
                                
                            }
                            else add_move_if_inside_board(rank,file,rank+i,file-i);
                            i++;
                        }
                        i=1;
                        
                        
                        while (((rank-i)>-1) && ((file+i) <8))
                        {
                            
                            if (boardsquare[rank-i][file+i]!='e')
                            {
                                if (boardsquare[rank-i][file+i]>96)
                               {
                                    add_move_if_inside_board(rank,file,rank-i,file+i);
                                    break;
                                }
                                else break;
                                
                            }
                            else add_move_if_inside_board(rank,file,rank-i,file+i);
                            i++;
                        }

                        i=1;

                        while (((rank-i)>-1) && ((file-i) > -1))
                        {
                            
                            if (boardsquare[rank-i][file-i]!='e')
                            {
                                if (boardsquare[rank-i][file-i]>96)
                               {
                                    add_move_if_inside_board(rank,file,rank-i,file-i);
                                    break;
                                }
                                else break;
                                
                            }
                            else add_move_if_inside_board(rank,file,rank-i,file-i);
                            i++;
                        }
                    }
        return;
    }

    void generate_rook_moves(int rank, int file){
         if(!whiteturn)
                    {
                        for (int i = rank+1; i < 8; i++)
                        {
                            if (boardsquare[i][file]!='e')
                            {
                                if (boardsquare[i][file]<96)
                                {
                                   add_move_if_inside_board(rank,file,i,file);
                                }
                                
                                break;
                            }
                            add_move_if_inside_board(rank,file,i,file);
                            
                        }
                        for (int i = rank-1; i > -1; i--)
                        {
                            if (boardsquare[i][file]!='e')
                            {
                                if (boardsquare[i][file]<96)
                                {
                                    add_move_if_inside_board(rank,file,i,file);
                                }
                                
                                break;
                            }
                            add_move_if_inside_board(rank,file,i,file);
                            
                        }
                        for (int i = file+1; i < 8; i++)
                        {
                            if (boardsquare[rank][i]!='e')
                            {
                                if (boardsquare[rank][i]<96)
                                {
                                    add_move_if_inside_board(rank,file,rank,i);
                                }
                                
                                break;
                            }
                            add_move_if_inside_board(rank,file,rank,i);
                            
                        }
                        for (int i = file-1; i > -1; i--)
                        {
                            if (boardsquare[rank][i]!='e')
                            {
                                if (boardsquare[rank][i]<96)
                                {
                                    add_move_if_inside_board(rank,file,rank,i);
                                }
                                
                                break;
                            }
                            add_move_if_inside_board(rank,file,rank,i);
                            
                        }
                        
                    }
         if(whiteturn)
                    {
                        for (int i = rank+1; i < 8; i++)
                        {
                            if (boardsquare[i][file]!='e')
                            {
                                if (boardsquare[i][file]>96)
                                {
                                   add_move_if_inside_board(rank,file,i,file);
                                }
                                
                                break;
                            }
                            add_move_if_inside_board(rank,file,i,file);
                            
                        }
                        for (int i = rank-1; i > -1; i--)
                        {
                            if (boardsquare[i][file]!='e')
                            {
                                if (boardsquare[i][file]>96)
                                {
                                   add_move_if_inside_board(rank,file,i,file);
                                }
                                
                                break;
                            }
                            add_move_if_inside_board(rank,file,i,file);
                            
                        }
                        for (int i = file+1; i < 8; i++)
                        {
                            if (boardsquare[rank][i]!='e')
                            {
                                if (boardsquare[rank][i]>96)
                                {
                                    add_move_if_inside_board(rank,file,rank,i);
                                }
                                
                                break;
                            }
                           add_move_if_inside_board(rank,file,rank,i);
                            
                        }
                        for (int i = file-1; i > -1; i--)
                        {
                            if (boardsquare[rank][i]!='e')
                            {
                                if (boardsquare[rank][i]>96)
                                {
                                    add_move_if_inside_board(rank,file,rank,i);
                                }
                                
                                break;
                            }
                            add_move_if_inside_board(rank,file,rank,i);
                            
                        }
                        
                    }
    }

    void add_king_move_if_valid(int rank,int file,int rank_direction, int file_direction){
        if (!whiteturn)
        {
                    if (move_is_inside_board(rank,file,rank+rank_direction,file+file_direction))
                    {
                        if (boardsquare[rank+rank_direction][file+file_direction]=='e' ||boardsquare[rank+rank_direction][file+file_direction]<96 )
                        {
                            add_move_if_inside_board(rank,file,rank+rank_direction,file+file_direction);
                        }
                        
                    }
                    
        }
        if (whiteturn)
        {
            
            if (move_is_inside_board(rank,file,rank+rank_direction,file+file_direction))
            {
                
                if (boardsquare[rank+rank_direction][file+file_direction]=='e' || boardsquare[rank+rank_direction][file+file_direction]>96 )
                {   
                    
                    add_move_if_inside_board(rank,file,rank+rank_direction,file+file_direction);
                }
                        
            }
                    
        }
        return;
    }

    void generate_moves ()
    {
        pseudu_possible_moves.clear();
        for (int rank = 0; rank < 8; rank++)
        {
            for (int file = 0; file < 8; file++)
            {
                switch (boardsquare[rank][file])
                {
                case 'e':
                    /* code */
                    break;
                case 'n':
                    if (!whiteturn)
                    {
                        if ((boardsquare[rank+2][file+1]<96 || boardsquare[rank+2][file+1]=='e') && move_is_inside_board(rank,file,rank+2,file+1))
                        {
                            add_move_if_inside_board(rank,file,rank+2,file+1);
                        }
                        if ((boardsquare[rank+1][file+2]<96 || boardsquare[rank+1][file+2]=='e') && move_is_inside_board(rank,file,rank+1,file+2))
                        {
                            add_move_if_inside_board(rank,file,rank+1,file+2);
                        }
                        if ((boardsquare[rank+2][file-1]<96 || boardsquare[rank+2][file-1]=='e') && move_is_inside_board(rank,file,rank+2,file-1))
                        {
                            add_move_if_inside_board(rank,file,rank+2,file-1);
                        }
                        if ((boardsquare[rank+1][file-2]<96 || boardsquare[rank+1][file-2]=='e') && move_is_inside_board(rank,file,rank+1,file-2))
                        {
                            add_move_if_inside_board(rank,file,rank+1,file-2);
                        }
                        if ((boardsquare[rank-2][file+1]<96 || boardsquare[rank-2][file+1]=='e') && move_is_inside_board(rank,file,rank-2,file+1))
                        {
                            add_move_if_inside_board(rank,file,rank-2,file+1);
                        }
                        if ((boardsquare[rank-1][file+2]<96 || boardsquare[rank-1][file+2]=='e') && move_is_inside_board(rank,file,rank-1,file+2))
                        {
                            add_move_if_inside_board(rank,file,rank-1,file+2);
                        }
                        if ((boardsquare[rank-2][file-1]<96 || boardsquare[rank-2][file-1]=='e') && move_is_inside_board(rank,file,rank-2,file-1))
                        {
                            add_move_if_inside_board(rank,file,rank-2,file-1);
                        }
                        if ((boardsquare[rank-1][file-2]<96 || boardsquare[rank-1][file-2]=='e') && move_is_inside_board(rank,file,rank-1,file-2))
                        {
                            add_move_if_inside_board(rank,file,rank-1,file-2);
                        }
                        
                        
                        
                        
                        
                        
                        
                        
                        
                        
                        
                    }
                    
                    break;
                case 'N':
                    if (whiteturn)
                    {
                        if (boardsquare[rank+2][file+1]>96 && move_is_inside_board(rank,file,rank+2,file+1))
                        {
                            add_move_if_inside_board(rank,file,rank+2,file+1);
                        }
                        if (boardsquare[rank+1][file+2]>96 && move_is_inside_board(rank,file,rank+1,file+2))
                        {
                            add_move_if_inside_board(rank,file,rank+1,file+2);
                        }
                        if (boardsquare[rank+2][file-1]>96 && move_is_inside_board(rank,file,rank+2,file-1))
                        {
                            add_move_if_inside_board(rank,file,rank+2,file-1);
                        }
                        if (boardsquare[rank+1][file-2]>96 && move_is_inside_board(rank,file,rank+1,file-2))
                        {
                            add_move_if_inside_board(rank,file,rank+1,file-2);
                        }
                        if (boardsquare[rank-2][file+1]>96 && move_is_inside_board(rank,file,rank-2,file+1))
                        {
                            add_move_if_inside_board(rank,file,rank-2,file+1);
                        }
                        if (boardsquare[rank-1][file+2]>96 && move_is_inside_board(rank,file,rank-1,file+2))
                        {
                            add_move_if_inside_board(rank,file,rank-1,file+2);
                        }
                        if (boardsquare[rank-2][file-1]>96 && move_is_inside_board(rank,file,rank-2,file-1))
                        {
                            add_move_if_inside_board(rank,file,rank-2,file-1);
                        }
                        if (boardsquare[rank-1][file-2]>96 && move_is_inside_board(rank,file,rank-1,file-2))
                        {
                            add_move_if_inside_board(rank,file,rank-1,file-2);
                        }
                    }
                    break;
                case 'r':
                if (!whiteturn)
                {
                    generate_rook_moves(rank,file);
                }
                
                   
                    break;
                case 'R':
                if (whiteturn)
                {
                    generate_rook_moves(rank,file);
                }
                
                   
                    break;
                case 'b':
                if (!whiteturn)
                {
                    generate_bishop_moves(rank,file);
                }
                
                

                    break;
                case 'B':
                if (whiteturn)
                {
                    generate_bishop_moves(rank,file);
                }

                    break;
                case 'q':
                if (!whiteturn)
                {
                    generate_bishop_moves(rank,file);
                    generate_rook_moves(rank,file);
                }
                
                    
                    break;
                case 'Q':
                if (whiteturn)
                {
                    generate_bishop_moves(rank,file);
                    generate_rook_moves(rank,file);
                }
                
                    
                    break;
                case 'p':
                    if (!whiteturn)
                {
                    if (move_is_inside_board(rank,file,rank-1,file))
                    {
                        if (boardsquare[rank-1][file]=='e')
                        {
                        add_move_if_inside_board(rank,file,rank-1,file);
                        }  
                    }
                    if (move_is_inside_board(rank,file,rank-2,file) && rank==6)
                    {
                        if (boardsquare[rank-2][file]=='e')
                        {
                        add_move_if_inside_board(rank,file,rank-2,file);
                        } 
                    }
                    if (move_is_inside_board(rank,file,rank-1,file+1))
                    {
                        if (boardsquare[rank-1][file+1]!='e' && boardsquare[rank-1][file+1]<96)
                        {
                        add_move_if_inside_board(rank,file,rank-1,file+1);
                        }
                    }
                    if (move_is_inside_board(rank,file,rank-1,file-1))
                    {
                        if (boardsquare[rank-1][file-1]!='e' && boardsquare[rank-1][file-1]<96)
                        {
                        add_move_if_inside_board(rank,file,rank-1,file-1);
                        }
                    }
                }    
                    break;
                case 'P':
                if (whiteturn)
                {
                    if (move_is_inside_board(rank,file,rank+1,file))
                    {
                        if (boardsquare[rank+1][file]=='e')
                        {
                        add_move_if_inside_board(rank,file,rank+1,file);
                        }  
                    }
                    if (move_is_inside_board(rank,file,rank+2,file) && rank==1)
                    {
                        if (boardsquare[rank+2][file]=='e')
                        {
                        add_move_if_inside_board(rank,file,rank+2,file);
                        } 
                    }
                    if (move_is_inside_board(rank,file,rank+1,file+1))
                    {
                        if (boardsquare[rank+1][file+1]!='e' && boardsquare[rank+1][file+1]>96)
                        {
                        add_move_if_inside_board(rank,file,rank+1,file+1);
                        }
                    }
                    if (move_is_inside_board(rank,file,rank+1,file-1))
                    {
                        if (boardsquare[rank+1][file-1]!='e' && boardsquare[rank+1][file+1]>96)
                        {
                        add_move_if_inside_board(rank,file,rank+1,file-1);
                        }
                    }
                    
                    
                     
                    
                    
                    
                     
                }
                    break;
                case 'k':
                if (!whiteturn)
                {
                    add_king_move_if_valid(rank,file,1,1);
                    add_king_move_if_valid(rank,file,1,0);
                    add_king_move_if_valid(rank,file,1,-1);
                    add_king_move_if_valid(rank,file,0,1);
                    add_king_move_if_valid(rank,file,0,-1);
                    add_king_move_if_valid(rank,file,-1,1);
                    add_king_move_if_valid(rank,file,-1,0);
                    add_king_move_if_valid(rank,file,-1,-1);

                }
                break;

                case 'K':
                if (whiteturn)
                {
                    add_king_move_if_valid(rank,file,1,1);
                    add_king_move_if_valid(rank,file,1,0);
                    add_king_move_if_valid(rank,file,1,-1);
                    add_king_move_if_valid(rank,file,0,1);
                    add_king_move_if_valid(rank,file,0,-1);
                    add_king_move_if_valid(rank,file,-1,1);
                    add_king_move_if_valid(rank,file,-1,0);
                    add_king_move_if_valid(rank,file,-1,-1);

                }

                break;

                default:
                    break;
                }
            }
            
        }
        
    }
    
    bool isvalidmove(int sfile,int srank,int efile,int erank){
        move x;
        x.setmove(srank,sfile,erank,efile);
        generate_moves();
        for (int i = 0; i < pseudu_possible_moves.size(); i++)
        {
            if (pseudu_possible_moves[i].getmovebynumber()==x.getmovebynumber())
            {
                return true;
            }
            
            
        }
        return false;
    }
    
    void print_board(){
        for (int rank = 0; rank < 8; rank++)
        {
            for (int file = 0; file < 8; file++)
            {
                std::cout<<" "<< boardsquare[rank][file];
            }
            std::cout<<"\n";
        }
        
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

