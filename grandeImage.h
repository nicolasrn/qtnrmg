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
    QPixmap *imageDefault; //image par default quand la case est vide
    QVector <ElementGrandeImage*> vectElem;
    FrameContener * grille;


    void completerVecteur(QWidget *ref, Bordure *b,QVector <ElementGrandeImage*> vect);

public:
    GrandeImage(QWidget *ref,Bordure *bordure,QVector <ElementGrandeImage*> vect);

    FrameContener* getGrille();
    void chargerNouvelleListe();
    //liste des modèles
    QVector <ElementGrandeImage*> grille0(QWidget *ref,Bordure *bordure,QVector <ElementGrandeImage*> vect);
    QVector <ElementGrandeImage*> grille1(QWidget *ref,Bordure *bordure,QVector <ElementGrandeImage*> vect);
    QVector <ElementGrandeImage*> grille2(QWidget *ref,Bordure *bordure,QVector <ElementGrandeImage*> vect);
    QVector <ElementGrandeImage*> grille3(QWidget *ref,Bordure *bordure,QVector <ElementGrandeImage*> vect);
    QVector <ElementGrandeImage*> grille4(QWidget *ref,Bordure *bordure,QVector <ElementGrandeImage*> vect);
    QVector <ElementGrandeImage*> grille5(QWidget *ref,Bordure *bordure,QVector <ElementGrandeImage*> vect);
    QVector <ElementGrandeImage*> grille6(QWidget *ref,Bordure *bordure,QVector <ElementGrandeImage*> vect);
    QVector <ElementGrandeImage*> grille7(QWidget *ref,Bordure *bordure,QVector <ElementGrandeImage*> vect);
    QVector <ElementGrandeImage*> grille8(QWidget *ref,Bordure *bordure,QVector <ElementGrandeImage*> vect);
    QVector <ElementGrandeImage*> grille9(QWidget *ref,Bordure *bordure,QVector <ElementGrandeImage*> vect);
    QVector <ElementGrandeImage*> grille10(QWidget *ref,Bordure *bordure,QVector <ElementGrandeImage*> vect);
    QVector <ElementGrandeImage*> grille11(QWidget *ref,Bordure *bordure,QVector <ElementGrandeImage*> vect);
    QVector <ElementGrandeImage*> grille12(QWidget *ref,Bordure *bordure,QVector <ElementGrandeImage*> vect);
    QVector <ElementGrandeImage*> grille13(QWidget *ref,Bordure *bordure,QVector <ElementGrandeImage*> vect);

};

#endif // GRANDEIMAGE_H
