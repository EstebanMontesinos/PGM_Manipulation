#include <iostream>
#include <fstream>
#include<iostream>
#include <string>
using namespace std;
ifstream input;//used to get input from user
ofstream output;
int width;
int height;
int pixels;
int **ptr;
int **ptr2;
string magic_number;
int max_p;



int read(string inputF,string outputF);
int oa(int **ptr);
int rotate();
int scale_down();
int scale_up();



//functions below

//argument function


//reading function
int read(string inputF,string outputF)
{
    //reading file
    input.open(inputF,ifstream::in);//opens file
    if(!input.is_open())
    {//if statement incase it doesnt work
        cerr<<"ERROR:could not open file.txt\n";
        exit(1);
    }
    //writing file
    output.open(outputF,ofstream::out);
    if(!output.is_open())
    {
        cerr<<"ERROR: could not open pgm.txt\n";
        exit(1);
    }

    input>>magic_number; //inputs magic number
    input>>width;//inputs witdh
    input>> height;//inputs height
    input>> max_p;//inputs max posible pixels

    //rotate();
    scale_down();
    //scale_up();
    return 0;
}

//rotate function
int rotate()
{
    ptr = new int *[height];
    for (int i = 0; i < height; i++)
    {
        ptr[i] = new int[width];
    }

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            input >> pixels;
            ptr[i][j] = pixels;
        }
    }
    output<<magic_number<<endl<<height<<" "<<width<<endl<<max_p<<endl;
    ptr2 = new int *[width];
    for (int i = 0; i < width; i++)
    {
        ptr2[i] = new int[height];
    }
    for (int i = 0; i < width; i++) {
        for (int j = 0; j < height; j++) {
            ptr2[i][j]=ptr[height-j-1][i];
            output<<ptr2[i][j]<<" ";
        }
    }

    return 0;
}

int scale_down()
{
    ptr = new int *[height];
    for (int i = 0; i < height; i++)
    {
        ptr[i] = new int[width];
    }

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            input >> pixels;
            ptr[i][j] = pixels;
        }
    }
    output<<magic_number<<endl<<width/2<<" "<<height/2<<endl<<max_p<<endl;

    int h=height/2;
    int w=width/2;
    ptr2=new int*[h];
    for(int i=0;i<h;i++){
        ptr2[i]=new int[w];
    }

    for(int i=0;i<height;i=i+2){
        for(int j=0;j<width;j=j+2){
            ptr2[i/2][j/2]=ptr[i][j];
            output<<ptr2[i/2][j/2]<<" ";

        }
    }
    return 0;
}
int scale_up()
{
    ptr = new int *[height];
    for (int i = 0; i < height; i++)
    {
        ptr[i] = new int[width];
    }

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            input >> pixels;
            ptr[i][j] = pixels;
        }
    }
    output<<magic_number<<endl<<width*2<<" "<<height*2<<endl<<max_p<<endl;
    int w=width*2;
    int h=height*2;
    ptr2 = new int *[h];
    for (int i = 0; i < h; i++)
    {
        ptr2[i] = new int[w];
    }
    for(int i=0;i<h;i=i+2){
        for(int j=0;j<w;j=j+2){
            pixels=ptr[i/2][j/2];
            ptr2[i][j]=pixels;
            ptr2[i][j+1]=pixels;
            ptr2[i+1][j]=pixels;
            ptr2[i+1][j+1]=pixels;

        }

    }
    for (int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            output<<ptr2[i][j]<<" ";
        }

    }
    return 0;

}




//main starts
int main(int argc, char *argv[])
{
    //reading file
    input.open(argv[1],ifstream::in);//opens file
    if(!input.is_open())
    {//if statement incase it doesnt work
        cerr<<"ERROR:could not open file.txt\n";
        exit(1);
    }
    //writing file
    output.open(argv[2],ofstream::out);
    if(!output.is_open())
    {
        cerr<<"ERROR: could not open pgm.txt\n";
        exit(1);
    }

    input>>magic_number; //inputs magic number
    input>>width;//inputs witdh
    input>> height;//inputs height
    input>> max_p;//inputs max posible pixels
    string p1=argv[3];
    if(p1=="-R"){
        rotate();
    }
    if(p1=="-S0.5"){
        scale_down();
    }
    if(p1=="-S2.0"){
        scale_up();
    }

    input.close();
    output.close();
    delete ptr;
    delete ptr2;



    return 0;

}
