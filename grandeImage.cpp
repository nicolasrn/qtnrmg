#include "grandeImage.h"

GrandeImage::GrandeImage(QWidget *ref, Bordure *bordure)
{
    nbImages = 0 ;
    vectImg = NULL;
    im = NULL;
    imageDefault = new QPixmap(QPixmap::fromImage(QImage("D:/Documents/Images/Qt/vide.png")));

    grille0(ref, bordure);
}

FrameContener* GrandeImage::getGrille()
{
    return grille;
}

void GrandeImage::grille0(QWidget *ref, Bordure *bordure)
{
    grille = new FrameContener(ref, FrameContener::VERTICALE);
    nbImages = 1;
    im = new QPixmap(QPixmap::fromImage(QImage("D:/Documents/Images/Qt/0.png"))); //logo
    grille->AddElement(new ElementGrandeImage(ref, &imageDefault->scaled(grille->width(),grille->height(), Qt::IgnoreAspectRatio), bordure));
}

void GrandeImage::grille1(QWidget *ref, Bordure *bordure)
{
    nbImages = 2;
    im = new QPixmap(QPixmap::fromImage(QImage("D:/Documents/Images/Qt/1.png"))); //logo

    grille = new FrameContener(ref, FrameContener::HORIZONTALE);

    grille->AddElement(new ElementGrandeImage(ref, &imageDefault->scaled(grille->width()/2,grille->height(), Qt::IgnoreAspectRatio), bordure));
    grille->AddElement(new ElementGrandeImage(ref, &imageDefault->scaled(grille->width()/2,grille->height(), Qt::IgnoreAspectRatio), bordure));
}

void GrandeImage::grille2(QWidget *ref, Bordure *bordure)
{
    nbImages = 2;
    im = new QPixmap(QPixmap::fromImage(QImage("D:/Documents/Images/Qt/2.png"))); //logo

    grille = new FrameContener(ref, FrameContener::VERTICALE);

    grille->AddElement(new ElementGrandeImage(ref, &imageDefault->scaled(grille->width(),grille->height()/2, Qt::IgnoreAspectRatio), bordure));
    grille->AddElement(new ElementGrandeImage(ref, &imageDefault->scaled(grille->width(),grille->height()/2, Qt::IgnoreAspectRatio), bordure));

}

void GrandeImage::grille3(QWidget *ref, Bordure *bordure)
{
    nbImages = 3;
    im = new QPixmap(QPixmap::fromImage(QImage("D:/Documents/Images/Qt/3.png"))); //logo

    grille = new FrameContener(ref, FrameContener::VERTICALE);

    FrameContener * g0 = new FrameContener(ref, FrameContener::HORIZONTALE);
    g0->AddElement(new ElementGrandeImage(ref, &imageDefault->scaled(grille->width()/2,grille->height()/2, Qt::IgnoreAspectRatio), bordure));
    g0->AddElement(new ElementGrandeImage(ref, &imageDefault->scaled(grille->width()/2,grille->height()/2, Qt::IgnoreAspectRatio), bordure));


    grille->AddElement(new ElementGrandeImage(ref, &imageDefault->scaled(grille->width(),grille->height()/2, Qt::IgnoreAspectRatio), bordure));
    grille->AddElement(g0);
}

void GrandeImage::grille4(QWidget *ref, Bordure *bordure)
{
    nbImages = 3;
    im = new QPixmap(QPixmap::fromImage(QImage("D:/Documents/Images/Qt/4.png"))); //logo

    grille = new FrameContener(ref, FrameContener::VERTICALE);

    FrameContener * g0 = new FrameContener(ref, FrameContener::HORIZONTALE);
    g0->AddElement(new ElementGrandeImage(ref, &imageDefault->scaled(grille->width()/2,grille->height()/2, Qt::IgnoreAspectRatio), bordure));
    g0->AddElement(new ElementGrandeImage(ref, &imageDefault->scaled(grille->width()/2,grille->height()/2, Qt::IgnoreAspectRatio), bordure));

    grille->AddElement(g0);
    grille->AddElement(new ElementGrandeImage(ref, &imageDefault->scaled(grille->width(),grille->height()/2, Qt::IgnoreAspectRatio), bordure));
}

void GrandeImage::grille5(QWidget *ref, Bordure *bordure)
{
    nbImages = 3;
    im = new QPixmap(QPixmap::fromImage(QImage("D:/Documents/Images/Qt/5.png"))); //logo

    grille = new FrameContener(ref, FrameContener::HORIZONTALE);

    FrameContener * g0 = new FrameContener(ref, FrameContener::VERTICALE);

    g0->AddElement(new ElementGrandeImage(ref, &imageDefault->scaled(grille->width()/2,grille->height()/2, Qt::IgnoreAspectRatio), bordure));
    g0->AddElement(new ElementGrandeImage(ref, &imageDefault->scaled(grille->width()/2,grille->height()/2, Qt::IgnoreAspectRatio), bordure));

    grille->AddElement(new ElementGrandeImage(ref, &imageDefault->scaled(grille->width()/2,grille->height(), Qt::IgnoreAspectRatio), bordure));
    grille->AddElement(g0);
}

void GrandeImage::grille6(QWidget *ref, Bordure *bordure)
{
    nbImages = 3;
    im = new QPixmap(QPixmap::fromImage(QImage("D:/Documents/Images/Qt/6.png"))); //logo

    grille = new FrameContener(ref, FrameContener::HORIZONTALE);

    FrameContener * g0 = new FrameContener(ref, FrameContener::VERTICALE);

    g0->AddElement(new ElementGrandeImage(ref, &imageDefault->scaled(grille->width()/2,grille->height()/2, Qt::IgnoreAspectRatio), bordure));
    g0->AddElement(new ElementGrandeImage(ref, &imageDefault->scaled(grille->width()/2,grille->height()/2, Qt::IgnoreAspectRatio), bordure));

    grille->AddElement(g0);
    grille->AddElement(new ElementGrandeImage(ref, &imageDefault->scaled(grille->width()/2,grille->height(), Qt::IgnoreAspectRatio), bordure));
}

void GrandeImage::grille7(QWidget *ref, Bordure *bordure)
{
    nbImages = 3;
    im = new QPixmap(QPixmap::fromImage(QImage("D:/Documents/Images/Qt/7.png"))); //logo

    grille = new FrameContener(ref, FrameContener::VERTICALE);

    grille->AddElement(new ElementGrandeImage(ref, &imageDefault->scaled(grille->width(),grille->height()/3, Qt::IgnoreAspectRatio), bordure));
    grille->AddElement(new ElementGrandeImage(ref, &imageDefault->scaled(grille->width(),grille->height()/3, Qt::IgnoreAspectRatio), bordure));
    grille->AddElement(new ElementGrandeImage(ref, &imageDefault->scaled(grille->width(),grille->height()/3, Qt::IgnoreAspectRatio), bordure));

}

void GrandeImage::grille8(QWidget *ref, Bordure *bordure)
{
    nbImages = 3;
    im = new QPixmap(QPixmap::fromImage(QImage("D:/Documents/Images/Qt/8.png"))); //logo

    grille = new FrameContener(ref, FrameContener::HORIZONTALE);

    grille->AddElement(new ElementGrandeImage(ref, &imageDefault->scaled(grille->width()/3,grille->height(), Qt::IgnoreAspectRatio), bordure));
    grille->AddElement(new ElementGrandeImage(ref, &imageDefault->scaled(grille->width()/3,grille->height(), Qt::IgnoreAspectRatio), bordure));
    grille->AddElement(new ElementGrandeImage(ref, &imageDefault->scaled(grille->width()/3,grille->height(), Qt::IgnoreAspectRatio), bordure));


}

void GrandeImage::grille9(QWidget *ref, Bordure *bordure)
{
    nbImages = 4;
    im = new QPixmap(QPixmap::fromImage(QImage("D:/Documents/Images/Qt/9.png"))); //logo

    grille = new FrameContener(ref, FrameContener::HORIZONTALE);

    FrameContener * g1 = new FrameContener(ref, FrameContener::VERTICALE);
    g1->AddElement(new ElementGrandeImage(ref, &imageDefault->scaled(g1->width()/2,g1->height()/2, Qt::IgnoreAspectRatio), bordure));
    g1->AddElement(new ElementGrandeImage(ref, &imageDefault->scaled(g1->width()/2,g1->height()/2, Qt::IgnoreAspectRatio), bordure));

    FrameContener * g2 = new FrameContener(ref, FrameContener::VERTICALE);
    g2->AddElement(new ElementGrandeImage(ref, &imageDefault->scaled(g2->width()/2,g2->height()/2, Qt::IgnoreAspectRatio), bordure));
    g2->AddElement(new ElementGrandeImage(ref, &imageDefault->scaled(g2->width()/2,g2->height()/2, Qt::IgnoreAspectRatio), bordure));


    grille->AddElement(g1);
    grille->AddElement(g2);
}

void GrandeImage::grille10(QWidget *ref, Bordure *bordure)
{
    nbImages = 4;
    im = new QPixmap(QPixmap::fromImage(QImage("D:/Documents/Images/Qt/10.png"))); //logo

    grille = new FrameContener(ref, FrameContener::VERTICALE);

    FrameContener * g0 = new FrameContener(ref, FrameContener::HORIZONTALE);

    g0->AddElement(new ElementGrandeImage(ref, &imageDefault->scaled(g0->width()/3,g0->height()/2, Qt::IgnoreAspectRatio), bordure));
    g0->AddElement(new ElementGrandeImage(ref, &imageDefault->scaled(g0->width()/3,g0->height()/2, Qt::IgnoreAspectRatio), bordure));
    g0->AddElement(new ElementGrandeImage(ref, &imageDefault->scaled(g0->width()/3,g0->height()/2, Qt::IgnoreAspectRatio), bordure));

    grille->AddElement(new ElementGrandeImage(ref, &imageDefault->scaled(g0->width(),g0->height()/2, Qt::IgnoreAspectRatio), bordure));
    grille->AddElement(g0);
}

void GrandeImage::grille11(QWidget *ref, Bordure *bordure)
{
    nbImages = 4;
    im = new QPixmap(QPixmap::fromImage(QImage("D:/Documents/Images/Qt/11.png"))); //logo

    grille = new FrameContener(ref, FrameContener::VERTICALE);

    FrameContener * g0 = new FrameContener(ref, FrameContener::HORIZONTALE);

    g0->AddElement(new ElementGrandeImage(ref, &imageDefault->scaled(g0->width()/3,g0->height()/2, Qt::IgnoreAspectRatio), bordure));
    g0->AddElement(new ElementGrandeImage(ref, &imageDefault->scaled(g0->width()/3,g0->height()/2, Qt::IgnoreAspectRatio), bordure));
    g0->AddElement(new ElementGrandeImage(ref, &imageDefault->scaled(g0->width()/3,g0->height()/2, Qt::IgnoreAspectRatio), bordure));

    grille->AddElement(g0);
    grille->AddElement(new ElementGrandeImage(ref, &imageDefault->scaled(g0->width(),g0->height()/2, Qt::IgnoreAspectRatio), bordure));
}

void GrandeImage::grille12(QWidget *ref, Bordure *bordure)
{
    nbImages = 4;
    im = new QPixmap(QPixmap::fromImage(QImage("D:/Documents/Images/Qt/12.png"))); //logo

    grille = new FrameContener(ref, FrameContener::HORIZONTALE);

    FrameContener * g0 = new FrameContener(ref, FrameContener::VERTICALE);

    g0->AddElement(new ElementGrandeImage(ref, &imageDefault->scaled(g0->width()/2,g0->height()/3, Qt::IgnoreAspectRatio), bordure));
    g0->AddElement(new ElementGrandeImage(ref, &imageDefault->scaled(g0->width()/2,g0->height()/3, Qt::IgnoreAspectRatio), bordure));
    g0->AddElement(new ElementGrandeImage(ref, &imageDefault->scaled(g0->width()/2,g0->height()/3, Qt::IgnoreAspectRatio), bordure));

    grille->AddElement(g0);
    grille->AddElement(new ElementGrandeImage(ref, &imageDefault->scaled(g0->width()/2,g0->height(), Qt::IgnoreAspectRatio), bordure));
}

void GrandeImage::grille13(QWidget *ref, Bordure *bordure)
{
    nbImages = 4;
    im = new QPixmap(QPixmap::fromImage(QImage("D:/Documents/Images/Qt/13.png"))); //logo

    grille = new FrameContener(ref, FrameContener::HORIZONTALE);

    FrameContener * g0 = new FrameContener(ref, FrameContener::VERTICALE);

    g0->AddElement(new ElementGrandeImage(ref, &imageDefault->scaled(g0->width()/2,g0->height()/3, Qt::IgnoreAspectRatio), bordure));
    g0->AddElement(new ElementGrandeImage(ref, &imageDefault->scaled(g0->width()/2,g0->height()/3, Qt::IgnoreAspectRatio), bordure));
    g0->AddElement(new ElementGrandeImage(ref, &imageDefault->scaled(g0->width()/2,g0->height()/3, Qt::IgnoreAspectRatio), bordure));

    grille->AddElement(new ElementGrandeImage(ref, &imageDefault->scaled(g0->width()/2,g0->height(), Qt::IgnoreAspectRatio), bordure));
    grille->AddElement(g0);
}
