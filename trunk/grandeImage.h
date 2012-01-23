#ifndef GRANDEIMAGE_H
#define GRANDEIMAGE_H

#include <QLayout>
#include <elementGrandeImage.h>
#include <QPixmap>
#include <QImage>
#include <frameContener.h>
#include <bordure.h>

class GrandeImage
{
private:
    int nbImages;
    QVector <ElementGrandeImage*> *vectImg;
    QPixmap *im; //logo
    QPixmap *imageDefault; //image par default quand la case est vide

    FrameContener * grille;

public:
    GrandeImage(QWidget *ref,Bordure *bordure);

    FrameContener* getGrille();
    void chargerNouvelleListe();
    //liste des modèles
    void grille0(QWidget *ref, Bordure *bordure);
    void grille1(QWidget *ref, Bordure *bordure);
    void grille2(QWidget *ref, Bordure *bordure);
    void grille3(QWidget *ref, Bordure *bordure);
    void grille4(QWidget *ref, Bordure *bordure);
    void grille5(QWidget *ref, Bordure *bordure);
    void grille6(QWidget *ref, Bordure *bordure);
    void grille7(QWidget *ref, Bordure *bordure);
    void grille8(QWidget *ref, Bordure *bordure);
    void grille9(QWidget *ref, Bordure *bordure);
    void grille10(QWidget *ref, Bordure *bordure);
    void grille11(QWidget *ref, Bordure *bordure);
    void grille12(QWidget *ref, Bordure *bordure);
    void grille13(QWidget *ref, Bordure *bordure);

};

#endif // GRANDEIMAGE_H
