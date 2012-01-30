#ifndef PETITEIMAGE_H
#define PETITEIMAGE_H

#include <QString>
#include <QImage>
#include <QGraphicsPixmapItem>

class PetiteImage: public QGraphicsPixmapItem
{
  private:
    QString chemin;
    QImage *img;
    QPixmap * pixDiapo;

  public:
    PetiteImage(QString chem, int hauteur);
    PetiteImage(const PetiteImage &i);
    ~PetiteImage();

    QString getChemin();
    QImage* getImg();
    QPixmap* getPixDiapo();
    QPixmap* getPixDeTaille(int h, int w);

};
#endif // PETITEIMAGE_H
