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

    //diff�rents mod�les propos�s
    void grille1();
};

#endif // GRILLEGRANDEIMAGE_H
