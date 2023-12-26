class move
{
private:
    // a short is 16 bits
    //the first 6 bits are the starting square the rank before the file 1111000110000000
    //the next are for the end square still the rank before the file    0000001111110000
    //this is a flag for check                                          0000000000001000
    // this is a flag for promotion                                     0000000000000100
    // these i dont use right now                                       0000000000000011
    short int movedata;
public:
    void setmove(int srank, int sfile,int erank, int efile)
    {
        movedata=0;
        movedata+=srank;
        movedata<<=3;
        movedata+=sfile;
        movedata<<=3;
        movedata+=erank;
        movedata<<=3;
        movedata+=efile;
        movedata<<=4;
    }
    int getmovebynumber(){
        return movedata;
    }
    move(/* args */);
    ~move();
};

move::move(/* args */)
{
}

move::~move()
{
}
