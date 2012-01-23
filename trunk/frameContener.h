#ifndef FRAMECONTENER_H
#define FRAMECONTENER_H

#include <maFrame.h>
#include <QLayout>
#include <QDebug>

class FrameContener : public MaFrame
{
private:
    QLayout *lay;
    QVector <MaFrame*> *vectFrame;
public:
    FrameContener(QWidget *ref, int sens);
    void Affichage(QLayout *lay);
    void AddElement(MaFrame * m);
    static const int HORIZONTALE = 0;
    static const int VERTICALE = 1;
};

#endif // FRAMECONTENER_H
