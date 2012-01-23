#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include <QDebug>
#include <QVector>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <petiteImage.h>
#include <QColorDialog>
#include <bordure.h>
#include <grandeImage.h>
#include <QLayout>

#include "elementGrandeImage.h"

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_btnAjouter_clicked();
    void on_btnModifierFond_clicked();
    void on_btnSepia_clicked();
    void on_btnNoirBlanc_clicked();
    void on_btnNegatif_clicked();
    void on_btnPlus90_clicked();
    void on_btnMoins90_clicked();
    void on_btnCouleurCadres_clicked();
    void on_btnGH_clicked();
    void on_btnGM_clicked();
    void on_btnGB_clicked();
    void on_btnMH_clicked();
    void on_btnMM_clicked();
    void on_btnMB_clicked();
    void on_btnDH_clicked();
    void on_btnDM_clicked();
    void on_btnDB_clicked();
    void selectionImage();
    void changeRondeur();
    void changeEpaisseur();
    void changeFrame(int i);

public slots:
    void receptionMessage(ElementGrandeImage *l);

private:
    Ui::MainWindow *ui;
    QVector <PetiteImage*> *vectImage;
    QGraphicsScene *scene;
    ElementGrandeImage *elementSelectione;
    int pos; //position de la prochaine image dans le diapo
    void ColorierFond(QColor c);
    Bordure * bordure;
    GrandeImage * gdeImage;


    QGraphicsItem *currentItem;


    void viderLayout(Bordure * bordure);


};

#endif // MAINWINDOW_H
