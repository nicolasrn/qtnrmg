#include "petiteImage.h"

PetiteImage::PetiteImage(QString chem, int hauteur):QGraphicsPixmapItem()
{
    chemin = chem;
    img = new QImage(chemin);
    pixDiapo = new QPixmap(QPixmap::fromImage(img->scaledToHeight(hauteur)));
    this->setPixmap(*pixDiapo);
    this->setFlag(QGraphicsItem::ItemIsSelectable, true);
}

PetiteImage::PetiteImage(const PetiteImage &i)
{
    chemin = i.chemin;
    img = new QImage(chemin);
    pixDiapo = new QPixmap(*i.pixDiapo);
    this->setPixmap(*pixDiapo);
    this->setFlag(QGraphicsItem::ItemIsSelectable, true);
}

PetiteImage::~PetiteImage()
{

}

QString PetiteImage::getChemin()
{
    return chemin;
}

QImage* PetiteImage::getImg()
{
    return img;
}

QPixmap* PetiteImage::getPixDiapo()
{
    return pixDiapo;
}

QPixmap* PetiteImage::getPixDeTaille(int h, int w)
{
    return new QPixmap(QPixmap::fromImage(img->scaled(w,h,  Qt::KeepAspectRatioByExpanding,Qt::SmoothTransformation)));
    //return new QPixmap(QPixmap::fromImage(*img).scaled(w,h,  Qt::IgnoreAspectRatio));
    //Qt::KeepAspectRatio
    //Qt::KeepAspectRatioByExpanding
}

