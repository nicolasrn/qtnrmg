#ifndef ELEMENTGRANDEIMAGE_H
#define ELEMENTGRANDEIMAGE_H

#include <maFrame.h>
#include <QLabel>
#include <QDebug>
#include <QLayout>
#include <QMouseEvent>
#include <QPainter>
#include <bordure.h>

class monLabel: public QLabel
{
    Q_OBJECT
private:

protected:
    void mousePressEvent(QMouseEvent *ev);

public:
    monLabel():QLabel(){}

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
public:
    ElementGrandeImage(QWidget *ref, QPixmap *i,Bordure* b);
    void Affichage(QLayout *lay);
    void ModifierImage(QPixmap *p);
    QPixmap * toSepia();
    QPixmap * toNoirEtBlanc();
    QPixmap * toNegatif();
    QPixmap * rotate(qreal angle);

    monLabel * getLab();


public slots:
    void receptionMessage();
    void modifierBordure();

signals:
    void envoyerMessage(ElementGrandeImage*);
};

#endif // ELEMENTGRANDEIMAGE_H
