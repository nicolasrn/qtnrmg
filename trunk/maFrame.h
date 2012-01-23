#ifndef MAFRAME_H
#define MAFRAME_H

#include <QWidget>

class MaFrame : public QWidget
{
protected:
    QWidget *ref;

public:
    MaFrame(QWidget *ref) : QWidget(), ref(ref)
    {
    }

    virtual void Affichage(QLayout *lay) = 0;

};

#endif // MAFRAME_H
