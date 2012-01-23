#include "frameContener.h"

FrameContener::FrameContener(QWidget *ref, int sens) : MaFrame(ref)
{
    vectFrame = new QVector<MaFrame *>();
    switch (sens)
    {
        case FrameContener::HORIZONTALE:
            lay = new QHBoxLayout();
            break;
        case FrameContener::VERTICALE:
            lay = new QVBoxLayout();
            break;
        default:
            lay = NULL;
    }
    this->setLayout(lay);
}

void FrameContener::AddElement(MaFrame * m)
{
    vectFrame->append(m);
}

void FrameContener::Affichage(QLayout *lay)
{
    qDebug() << "frameContener";
    lay->addWidget(this);
    for (int i = 0; i<vectFrame->size(); i++)
    {
        (*vectFrame)[i]->Affichage(this->lay);
    }
}
