#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include "blocks.h"
#include "matrix.h"
#include "personaje.h"
#include <QKeyEvent>
#include <QTimer>
#include <QApplication>
#include <QProcess>

#define squareSize 50
#define column 27
#define row 11
#define speed 10


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT
public slots:
    void temporizador();
public:
    MainWindow(QWidget *parent = nullptr);
    void keyPressEvent(QKeyEvent *i);
    ~MainWindow();

private:
    void setup_graphics(); //Función para acomodar la escena
    void set_map();
    Personaje *personaje;
    Ui::MainWindow *ui;
    QGraphicsScene *scene;
    Blocks *score, *map[row][column];
    Matrix *mat;
    QTimer *time;
    int cont = 180;
};
#endif // MAINWINDOW_H
