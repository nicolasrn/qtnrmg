#ifndef ELEMENTGRANDEIMAGE_H
#define ELEMENTGRANDEIMAGE_H

#include <maFrame.h>
#include <QLabel>
#include <QDebug>
#include <QLayout>
#include <QMouseEvent>
#include <QPainter>
#include <bordure.h>
#include <petiteImage.h>

class monLabel: public QLabel
{
    Q_OBJECT
private:

protected:
    void mousePressEvent(QMouseEvent *ev);

public:
    monLabel():QLabel(){}
    monLabel(const monLabel &m): QLabel(){}

signals:
    void envoyerMessage();
};

class ElementGrandeImage : public MaFrame
{
    Q_OBJECT

private:
    monLabel *lab;
    QPixmap *img;
    Bordure *bordure;
    PetiteImage *image;
    bool netb;
    bool sep;
    bool neg;
public:
    ElementGrandeImage(QWidget *ref, QPixmap *qpix,Bordure* b, PetiteImage *imgBase);
    ElementGrandeImage(const ElementGrandeImage &e);
    void Affichage(QLayout *lay);
    void ModifierImage(QPixmap *p);
    void Resizer(QSize s);
    QPixmap * toSepia();
    QPixmap * toNoirEtBlanc();
    QPixmap * toNegatif();
    QPixmap * rotate(qreal angle);

    monLabel * getLab();
    void setImage(PetiteImage * i);
    void setBordure(Bordure * b);


public slots:
    void receptionMessage();
    void modifierBordure();

signals:
    void envoyerMessage(ElementGrandeImage*);
};

#endif // ELEMENTGRANDEIMAGE_H
