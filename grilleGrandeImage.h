#ifndef GRILLEGRANDEIMAGE_H
#define GRILLEGRANDEIMAGE_H

#include <QLayout>
#include <QPixmap>

class GrilleGrandeImage
{
public:
    GrilleGrandeImage();

private:
    int nbImages;
    QLayout *gdLay;
    QPixmap *im; //logo

    //différents modèles proposés
    void grille1();
};

#endif // GRILLEGRANDEIMAGE_H
