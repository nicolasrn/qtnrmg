#include "grandeImage.h"

GrandeImage::GrandeImage(QWidget *ref,Bordure *bordure,QVector <ElementGrandeImage*> vect)
{
    nbImages = 0 ;
    imageDefault = new QPixmap(QPixmap::fromImage(QImage(":/divers/vide")));
    vectElem = vect;

    grille0(ref, bordure, vectElem);
}


void GrandeImage::completerVecteur(QWidget *ref, Bordure *b,QVector <ElementGrandeImage*> vect)
{
    vectElem.clear();
    QVector<ElementGrandeImage *> temp;
    for (int i= 0; i< vect.size(); i++)
    {
        temp.append( new ElementGrandeImage(*vect[i]));
        temp[i]->setBordure(b);
    }
    if(nbImages>vect.size())
    {
        for (int j = vect.size(); j < nbImages; j++)
        {
            temp.append(new ElementGrandeImage(ref, imageDefault, b, new PetiteImage(":/divers/vide", 0)));
            temp[j]->setBordure(b);
        }
    }
    vectElem = temp;
    temp.clear();
}

FrameContener* GrandeImage::getGrille()
{
    return grille;
}

QVector <ElementGrandeImage*> GrandeImage::grille0(QWidget *ref,Bordure *bordure,QVector <ElementGrandeImage*> vect)
{
    grille = new FrameContener(ref, FrameContener::VERTICALE);
    nbImages = 1;
    completerVecteur(ref, bordure, vect);
    grille->AddElement(vectElem[0]);

    return vectElem;
}

QVector <ElementGrandeImage*> GrandeImage::grille1(QWidget *ref,Bordure *bordure,QVector <ElementGrandeImage*> vect)
{
    nbImages = 2;
    completerVecteur(ref, bordure, vect);
    grille = new FrameContener(ref, FrameContener::HORIZONTALE);

    grille->AddElement(vectElem[0]);
    grille->AddElement(vectElem[1]);

    return vectElem;
}

QVector <ElementGrandeImage*> GrandeImage::grille2(QWidget *ref,Bordure *bordure,QVector <ElementGrandeImage*> vect)
{
    nbImages = 2;
    completerVecteur(ref, bordure, vect);
    grille = new FrameContener(ref, FrameContener::VERTICALE);

    grille->AddElement(vectElem[0]);
    grille->AddElement(vectElem[1]);

    return vectElem;

}

QVector <ElementGrandeImage*> GrandeImage::grille3(QWidget *ref,Bordure *bordure,QVector <ElementGrandeImage*> vect)
{
    nbImages = 3;
    completerVecteur(ref, bordure, vect);
    grille = new FrameContener(ref, FrameContener::VERTICALE);

    FrameContener * g0 = new FrameContener(ref, FrameContener::HORIZONTALE);
    g0->AddElement(vectElem[0]);
    g0->AddElement(vectElem[1]);


    grille->AddElement(vectElem[2]);
    grille->AddElement(g0);

    return vectElem;
}

QVector <ElementGrandeImage*> GrandeImage::grille4(QWidget *ref,Bordure *bordure,QVector <ElementGrandeImage*> vect)
{
    nbImages = 3;
    completerVecteur(ref, bordure, vect);
    grille = new FrameContener(ref, FrameContener::VERTICALE);


    FrameContener * g0 = new FrameContener(ref, FrameContener::HORIZONTALE);
    g0->AddElement(vectElem[0]);
    g0->AddElement(vectElem[1]);

    grille->AddElement(g0);
    grille->AddElement(vectElem[2]);

    return vectElem;
}

QVector <ElementGrandeImage*>  GrandeImage::grille5(QWidget *ref,Bordure *bordure,QVector <ElementGrandeImage*> vect)
{
    nbImages = 3;
    completerVecteur(ref, bordure, vect);
    grille = new FrameContener(ref, FrameContener::HORIZONTALE);

    FrameContener * g0 = new FrameContener(ref, FrameContener::VERTICALE);

    g0->AddElement(vectElem[0]);
    g0->AddElement(vectElem[1]);

    grille->AddElement(vectElem[2]);
    grille->AddElement(g0);

    return vectElem;
}

QVector <ElementGrandeImage*>  GrandeImage::grille6(QWidget *ref,Bordure *bordure,QVector <ElementGrandeImage*> vect)
{
    nbImages = 3;
    completerVecteur(ref, bordure, vect);

    grille = new FrameContener(ref, FrameContener::HORIZONTALE);

    FrameContener * g0 = new FrameContener(ref, FrameContener::VERTICALE);

    g0->AddElement(vectElem[0]);
    g0->AddElement(vectElem[1]);

    grille->AddElement(g0);
    grille->AddElement(vectElem[2]);

    return vectElem;

}

QVector <ElementGrandeImage*>  GrandeImage::grille7(QWidget *ref,Bordure *bordure,QVector <ElementGrandeImage*> vect)
{
    nbImages = 3;
    completerVecteur(ref, bordure, vect);

    grille = new FrameContener(ref, FrameContener::VERTICALE);

    grille->AddElement(vectElem[0]);
    grille->AddElement(vectElem[1]);
    grille->AddElement(vectElem[2]);

    return vectElem;

}
QVector <ElementGrandeImage*>  GrandeImage::grille8(QWidget *ref,Bordure *bordure,QVector <ElementGrandeImage*> vect)
{
    nbImages = 3;
    completerVecteur(ref, bordure, vect);

    grille = new FrameContener(ref, FrameContener::HORIZONTALE);

    grille->AddElement(vectElem[0]);
    grille->AddElement(vectElem[1]);
    grille->AddElement(vectElem[2]);

    return vectElem;
}

QVector <ElementGrandeImage*>  GrandeImage::grille9(QWidget *ref,Bordure *bordure,QVector <ElementGrandeImage*> vect)
{
    nbImages = 4;
    completerVecteur(ref, bordure, vect);

    grille = new FrameContener(ref, FrameContener::HORIZONTALE);

    FrameContener * g1 = new FrameContener(ref, FrameContener::VERTICALE);
    g1->AddElement(vectElem[0]);
    g1->AddElement(vectElem[1]);

    FrameContener * g2 = new FrameContener(ref, FrameContener::VERTICALE);
    g2->AddElement(vectElem[2]);
    g2->AddElement(vectElem[3]);


    grille->AddElement(g1);
    grille->AddElement(g2);

    return vectElem;
}

QVector <ElementGrandeImage*>  GrandeImage::grille10(QWidget *ref,Bordure *bordure,QVector <ElementGrandeImage*> vect)
{
    nbImages = 4;
    completerVecteur(ref, bordure, vect);

    grille = new FrameContener(ref, FrameContener::VERTICALE);

    FrameContener * g0 = new FrameContener(ref, FrameContener::HORIZONTALE);

    g0->AddElement(vectElem[0]);
    g0->AddElement(vectElem[1]);
    g0->AddElement(vectElem[2]);

    grille->AddElement(vectElem[3]);
    grille->AddElement(g0);

    return vectElem;
}

QVector <ElementGrandeImage*>  GrandeImage::grille11(QWidget *ref,Bordure *bordure,QVector <ElementGrandeImage*> vect)
{
    nbImages = 4;
    completerVecteur(ref, bordure, vect);

    grille = new FrameContener(ref, FrameContener::VERTICALE);

    FrameContener * g0 = new FrameContener(ref, FrameContener::HORIZONTALE);

    g0->AddElement(vectElem[0]);
    g0->AddElement(vectElem[1]);
    g0->AddElement(vectElem[2]);

    grille->AddElement(g0);
    grille->AddElement(vectElem[3]);

    return vectElem;
}

QVector <ElementGrandeImage*>  GrandeImage::grille12(QWidget *ref,Bordure *bordure,QVector <ElementGrandeImage*> vect)
{
    nbImages = 4;
    completerVecteur(ref, bordure, vect);

    grille = new FrameContener(ref, FrameContener::HORIZONTALE);

    FrameContener * g0 = new FrameContener(ref, FrameContener::VERTICALE);

    g0->AddElement(vectElem[0]);
    g0->AddElement(vectElem[1]);
    g0->AddElement(vectElem[2]);

    grille->AddElement(g0);
    grille->AddElement(vectElem[3]);

    return vectElem;
}

QVector <ElementGrandeImage*>  GrandeImage::grille13(QWidget *ref,Bordure *bordure,QVector <ElementGrandeImage*> vect)
{
    nbImages = 4;
    completerVecteur(ref, bordure, vect);

    grille = new FrameContener(ref, FrameContener::HORIZONTALE);

    FrameContener * g0 = new FrameContener(ref, FrameContener::VERTICALE);

    g0->AddElement(vectElem[0]);
    g0->AddElement(vectElem[1]);
    g0->AddElement(vectElem[2]);

    grille->AddElement(vectElem[3]);
    grille->AddElement(g0);

    return vectElem;
}
