#include <iostream>
#include <windows.h>
#include <cstdlib>
#include <ctime>

using namespace std;

bool **pix;
bool lp = true;
unsigned height = 10;
unsigned width = 10;
unsigned frameCount;
unsigned delay = 33;

void setup();
void loop();
void draw();
void rstpix();
void frameRate(unsigned);

struct Vetor{
    int x, y;
};

class Snake{
    Vetor pos;
    Vetor speed;
    Vetor *cauda;
    unsigned tam;
public:
    Snake();
    void update();
    void draw();
    void eat();
    void die();
    void checkDie();
    void setmov(int, int);
    void checkFood();

    friend void loop();

    ~Snake();
}*snk;

class Food{
    Vetor pos;
public:
    Food();
    void newFood();
    void draw();
    friend void Snake::checkFood();
    ~Food();
}*fd;

int main(){

    setup();
    while(lp){
        rstpix();
        loop();
        system("cls");
        draw();
        Sleep(delay);
        frameCount++;
    }
    for(unsigned i = 0; i < width; i ++){
        delete pix[i];
    }
    delete pix;
    delete fd;
    delete snk;
    return 0;
}


void setup(){
    snk = new Snake();
    fd = new Food;
    width = height = 20;
    pix = new bool*[height];
    for(unsigned i = 0; i < height; i ++){
        pix[i] = new bool[width];
    }
    frameRate(15);
}
void loop(){

    if((GetKeyState('A') & 0x8000)&&(snk->speed.x != 1)){
        snk->setmov(-1, 0);
    } else if((GetKeyState('D') & 0x8000)&&(snk->speed.x != -1)){
        snk->setmov(1, 0);
    } else if((GetKeyState('W') & 0x8000)&&(snk->speed.y != 1)){
        snk->setmov(0, -1);
    } else if((GetKeyState('S') & 0x8000)&&(snk->speed.y != -1)){
        snk->setmov(0, 1);
    }
    fd->draw();
    snk->update();
    snk->checkDie();
    snk->checkFood();
    snk->draw();

}
void draw(){
    for(unsigned i = 0; i < height; i ++){
        for(unsigned j = 0; j < width; j ++){
            if(pix[j][i]){
                std::cout<<"[]";
            } else{
                std::cout<<"  ";
            }
        }
        std::cout<<"|"<<std::endl;
    }
    for(unsigned i = 0; i < width; i ++){
        cout<<"==";
    }
}

void frameRate(unsigned x){
    delay = 1000/x;
}

void rstpix(){
    for(unsigned i = 0; i < height; i ++){
        for(unsigned j = 0; j < width; j ++){
            pix[i][j] = false;
        }
    }
}


Snake::Snake(){
    this->pos.x = width/2;
    this->pos.y = height/2;
    this->speed.x = this->speed.y = 0;
    tam = 1;

    cauda = new Vetor[width * height];
}

void Snake::update(){
    this->pos.x += this->speed.x;
    this->pos.y += this->speed.y;

    this->checkDie();


    this->cauda[this->tam].x = pos.x;
    this->cauda[this->tam].y = pos.y;

    for(unsigned i = 0; i < this->tam; i ++){
        this->cauda[i].x = this->cauda[i+1].x;
        this->cauda[i].y = this->cauda[i+1].y;
    }

}

void Snake::draw(){
    pix[this->pos.x][this->pos.y] = true;
    for(unsigned i = 0; i < this->tam; i ++){
        pix[this->cauda[i].x][this->cauda[i].y]= true;
    }
}

void Snake::setmov(int x, int y){
    this->speed.x = x;
    this->speed.y = y;
}

void Snake::die(){
    this->pos.x = width/2;
    this->pos.y = height/2;
    this->tam = 1;

    std::cout<<"PERDEU SEU INUTIL";
    system("PAUSE");
}

void Snake::checkDie(){

    if(this->pos.x < 0){
        this->die();
    } else if(this->pos.x > width){
        this->die();
    } else if(this->pos.y < 0){
        this->die();
    } else if(this->pos.y > height){
        this->die();
    }

    for(unsigned i = 3; i < tam; i ++){
        if((this->pos.x == this->cauda[i].x)&&(this->pos.y == this->cauda[i].y)){
            this->die();
        }
    }
}

void Snake::checkFood(){
    if((this->pos.x == fd->pos.x) && (this->pos.y == fd->pos.y)){
        fd->newFood();
        tam++;
    }
}


Snake::~Snake(){
    delete cauda;
}

Food::Food(){
    this->pos.x = rand()%width;
    this->pos.y = rand()%height;
}

void Food::newFood(){
    this->pos.x = rand()%width;
    this->pos.y = rand()%height;
}

void Food::draw(){
    pix[this->pos.x][this->pos.y] = true;
}

Food::~Food(){

}
