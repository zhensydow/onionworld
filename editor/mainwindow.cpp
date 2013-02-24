#include "mainwindow.h"

#include <QtGui>

#include "gui/glwidget.h"

MainWindow::MainWindow(){
    QWidget *widget = new QWidget;
    setCentralWidget( widget );

    GLWidget * glw = new GLWidget();

    QHBoxLayout *body = new QHBoxLayout;
    body->setMargin( 5 );

    QGroupBox *left = new QGroupBox( tr("Edit") );
    QVBoxLayout *leftl = new QVBoxLayout;
    left->setLayout( leftl );

    QGroupBox *rigth = new QGroupBox( tr("View") );
    QVBoxLayout *rigthl = new QVBoxLayout;
    rigthl->addWidget( glw );

    QGroupBox *cameraBox = new QGroupBox( tr("Camera") );
    rigthl->addWidget( cameraBox );

    rigth->setLayout( rigthl );

    body->addWidget( left );
    body->addWidget( rigth );

    widget->setLayout( body );

    createActions();
    createMenus();
}

void MainWindow::createActions(){
    aboutAct = new QAction( tr("&About"), this);
    aboutAct->setStatusTip( tr("Show the application's About box") );
    connect( aboutAct, SIGNAL(triggered()), this, SLOT(about()) );
}

void MainWindow::createMenus(){
    fileMenu = menuBar()->addMenu( tr("&File") );
    fileMenu->addSeparator();

    editMenu = menuBar()->addMenu( tr("&Edit") );
    editMenu->addSeparator();

    helpMenu = menuBar()->addMenu( tr("&Help") );
    helpMenu->addAction( aboutAct );
}

void MainWindow::about(){
    printf( "About\n" );
}
