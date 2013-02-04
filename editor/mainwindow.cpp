#include "mainwindow.h"

#include <QtGui>

#include "gui/glwidget.h"

MainWindow::MainWindow(){
    QWidget *widget = new QWidget;
    setCentralWidget(widget);

    GLWidget * glw = new GLWidget();

    QVBoxLayout *layout = new QVBoxLayout;
    layout->setMargin(5);
    layout->addWidget(glw);
    
    widget->setLayout(layout);

    createActions();
    createMenus();
}

void MainWindow::createActions(){
    aboutAct = new QAction(tr("&About"), this);
    aboutAct->setStatusTip(tr("Show the application's About box"));
    connect(aboutAct, SIGNAL(triggered()), this, SLOT(about()));
}

void MainWindow::createMenus(){
    fileMenu = menuBar()->addMenu(tr("&File"));
    fileMenu->addSeparator();

    editMenu = menuBar()->addMenu(tr("&Edit"));
    editMenu->addSeparator();

    helpMenu = menuBar()->addMenu(tr("&Help"));
    helpMenu->addAction( aboutAct );
}

void MainWindow::about(){
    printf("About\n" );
}
