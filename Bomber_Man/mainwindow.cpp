#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>

using namespace std;
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setup_graphics();
    set_map();
    personaje = new Personaje(":/imagenes/personaje.png", squareSize, squareSize);
    personaje->setPos(50,150);
    scene->addItem(personaje);
    time = new QTimer;
    connect(time,SIGNAL(timeout()),this,SLOT(temporizador()));
    time->start(1000);


}

void MainWindow::keyPressEvent(QKeyEvent *i)
{


    int posX=int (personaje->x()), posY=int(personaje->y());
    //cout <<posX<<" "<<posY;

    if(i->key()==Qt::Key_W){
        if (mat->mat[posX/squareSize][((posY-speed)/squareSize)-2]==8 && mat->mat[(posX+49)/squareSize][((posY-speed)/squareSize)-2]==8 ){
            personaje->setY(personaje->y()-speed);
            }
        //cout<<mat->mat[posX/squareSize][((posY-speed)/squareSize)-2]<<" : "<<mat->mat[(posX+49)/squareSize][((posY-speed)/squareSize)-2];
        }
    if(i->key()==Qt::Key_S){
        if (mat->mat[posX/squareSize][((posY+49+speed)/squareSize)-2]==8 && mat->mat[(posX+49)/squareSize][((posY+49+speed)/squareSize)-2]==8){
            personaje->setY(personaje->y()+speed);
            }
        cout<<mat->mat[posX/squareSize][((posY+49+speed)/squareSize)-2]<<" : "<<mat->mat[(posX+49)/squareSize][((posY+49+speed)/squareSize)-2];
        }
    if(i->key()==Qt::Key_A){
        if (mat->mat[(posX-speed)/squareSize][((posY)/squareSize)-2]==8 && mat->mat[(posX-speed)/squareSize][((posY+49)/squareSize)-2]==8) {
            personaje->setX(personaje->x()-speed);
            }
        //cout<<mat->mat[(posX-speed)/squareSize][((posY)/squareSize)-2]<<" : "<<mat->mat[(posX-speed)/squareSize][((posY+49)/squareSize)-2];
        }
    if(i->key()==Qt::Key_D){
       if (mat->mat[(posX+speed+49)/squareSize][((posY)/squareSize)-2]==8 && mat->mat[(posX+speed+49)/squareSize][((posY+49)/squareSize)-2]==8){
            personaje->setX(personaje->x()+speed);
            }
        //cout<<mat->mat[(posX+speed+49)/squareSize][((posY)/squareSize)-2]<<" : "<<mat->mat[(posX+speed+49)/squareSize][((posY+49)/squareSize)-2];
        }
}

MainWindow::~MainWindow()
{
    delete ui;
    delete scene;
    delete score;
    delete mat;
    delete personaje;
    delete time;
}

void MainWindow::setup_graphics()
{
    scene = new QGraphicsScene;
    scene -> setSceneRect(0, 0, column*squareSize, squareSize*(row+2)); //Definición del tamaño de la escena
    ui->graphicsView->setGeometry(0, 0, squareSize*column+2, (row+2)*squareSize+2); //Tamaño del graphicsview
    ui->graphicsView->setScene(scene); //Carga la escena en el graphicsview
    setMaximumSize(column*squareSize+2, (row+2)*squareSize+2);
    setMinimumSize(column*squareSize+2, (row+2)*squareSize+2);
    setWindowTitle("Bomber Man");
    setWindowIcon(QIcon(":/imagenes/icono.jpg"));

}

void MainWindow::set_map() //Se agrega cada bloque de imagen a la escena
{
    score = new Blocks;
    mat = new Matrix(row, column);
    mat->generate_map();
    score->set_size(column*squareSize, 2*squareSize);
    score->set_img(9);
    score->setPos(0,0);
    scene->addItem(score);


    for( int f=0; f<row; f++ ){
        for ( int c=0;c<column ;c++ ) {
            map[f][c] = new Blocks;
            map[f][c] -> set_size(squareSize, squareSize);
            map[f][c] -> set_img(mat->mat[f][c]);
            map[f][c] -> setPos(c*squareSize, (2+f)*squareSize);
            scene -> addItem(map[f][c]);
            cout<<(mat->mat[f][c]);
        }
        cout<<endl;

    }
}

void MainWindow::temporizador()
{
    ui->lcdNumber->display(cont);
    if (cont == 0){
        time->stop();
        qApp->quit();
        QProcess::startDetached(qApp->arguments()[0], qApp->arguments());
    }
    cont-=1;

}
