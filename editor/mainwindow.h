//------------------------------------------------------------------------------
#ifndef EDITOR_MAINWINDOW_H
#define EDITOR_MAINWINDOW_H

//------------------------------------------------------------------------------
#include <QMainWindow>

class QMenu;
class QAction;

//------------------------------------------------------------------------------
class MainWindow : public QMainWindow {
public:
    MainWindow();

private slots:
    void about();

private:
    Q_OBJECT
    
    void createActions();
    void createMenus();

    QMenu *fileMenu;
    QMenu *editMenu;
    QMenu *helpMenu;

    QAction *aboutAct;
};

//------------------------------------------------------------------------------
#endif//EDITOR_MAINWINDOW_H

//------------------------------------------------------------------------------
