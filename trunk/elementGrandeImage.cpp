#include "elementGrandeImage.h"


void monLabel::mousePressEvent(QMouseEvent *ev)
{
    Q_UNUSED(ev);
    emit envoyerMessage();
}


ElementGrandeImage::ElementGrandeImage(QWidget *ref, QPixmap *qpix, Bordure* b, PetiteImage *imageBase) : MaFrame(ref)
{
    img = qpix;
    image = imageBase;
    bordure = b;
    connect(bordure,SIGNAL(modificationBordure()),this,SLOT(modifierBordure()));
    lab = new monLabel();
    modifierBordure();
    lab->setAlignment(Qt::AlignCenter);
    lab->setPixmap(*img);
    connect(lab, SIGNAL(envoyerMessage()), this, SLOT(receptionMessage()));
    netb = false;
    sep = false;
    neg = false;
}

ElementGrandeImage::ElementGrandeImage(const ElementGrandeImage  &e) : MaFrame(e.ref)
{
    img = new QPixmap(*e.img);

    netb = e.netb;
    sep = e.sep;
    neg = e.neg;

    if (netb)
        img = toNoirEtBlanc();
    if (sep)
        img = toSepia();
    if (neg)
        img = toNegatif();

    image = new PetiteImage(*e.image);
    bordure = e.bordure;


    connect(bordure,SIGNAL(modificationBordure()),this,SLOT(modifierBordure()));
    lab = new monLabel(*e.lab);
    modifierBordure();
    lab->setAlignment(Qt::AlignCenter);
    lab->setPixmap(*img);
    connect(lab, SIGNAL(envoyerMessage()), this, SLOT(receptionMessage()));
    modifierBordure();




}

void ElementGrandeImage::Affichage(QLayout *lay)
{
    //qDebug() << "img: ";
    lay->addWidget(lab);
    connect(this, SIGNAL(envoyerMessage(ElementGrandeImage*)), this->ref, SLOT(receptionMessage(ElementGrandeImage*)));
}

void ElementGrandeImage::ModifierImage(QPixmap *p)
{
    img = p;
    lab->setPixmap(*img);
}

void ElementGrandeImage::receptionMessage()
{
    qDebug() << "je suis pressé comme un citron";
    emit envoyerMessage(this);
}

QPixmap * ElementGrandeImage::toSepia()
{
    sep = true;
    QImage income = img->toImage();
    QImage base = income.convertToFormat(QImage::Format_RGB32);

    QPixmap *result;
    QColor gtr = QColor(162,128,101);
    int sepiaH, sepiaS, sepiaL;
    gtr.getHsv( &sepiaH, &sepiaS, &sepiaL );
    int x, y, pixelLuminance;
    QRgb* rgb;
    QColor sepiaColor;
    uchar* scanLine;


      for( y=0; y<base.height(); y++)
      {
          scanLine = base.scanLine(y);
          for( x=0; x<base.width(); x++)
          {
            rgb = ((QRgb*)scanLine+x);
            pixelLuminance = (int) (0.2125*qRed(*rgb) + 0.7154*qGreen(*rgb) + 0.0721*qBlue(*rgb));
            sepiaColor.setHsv( sepiaH, sepiaS, pixelLuminance );
            *rgb = sepiaColor.rgb();
          }
       }
    result = new QPixmap(QPixmap::fromImage(base));

    return result;

}

QPixmap * ElementGrandeImage::toNegatif()
{
    neg = true;
    QImage income = img->toImage();
    QPixmap *result;
    QImage base = income.convertToFormat(QImage::Format_RGB32);
    base.invertPixels();
    result = new QPixmap(QPixmap::fromImage(base));

    return result;
}

QPixmap * ElementGrandeImage::toNoirEtBlanc()
{
    qDebug() << "noir et blanc";
    netb = true;
    QImage income = img->toImage();
    QImage base = income.convertToFormat(QImage::Format_RGB32);

    QPixmap *result;
    for (int y = 0; y < base.height(); ++y)
    {
             for (int x = 0; x < base.width(); ++x)
             {
                 int pixel = base.pixel(x, y);
                 int gray = qGray(pixel);
                 int alpha = qAlpha(pixel);
                 base.setPixel(x, y, qRgba(gray, gray, gray, alpha));
             }
    }

    result = new QPixmap(QPixmap::fromImage(base));

    return result;
}

QPixmap * ElementGrandeImage::rotate(qreal angle)
{
    QTransform t;
    t.rotate(angle);
    QPixmap *rotatedPixmap = new QPixmap(img->transformed(t));
    return rotatedPixmap;
}

void ElementGrandeImage::modifierBordure()
{
    int r;
    int g;
    int b;
    bordure->getCouleurBordure()->getRgb(&r,&g,&b);

    //qDebug() << "rouge:" + QString::number(r) + " vert:"+ QString::number(g) + " bleu:" + QString::number(b);

    QString s = "QLabel{ border-style: solid; border-width:"+QString::number(bordure->getTailleBordure())+"px; border-color: rgb("+ QString::number(r) + ","+ QString::number(g) +","+ QString::number(b) +"); border-radius:"+QString::number(bordure->getRadiusBordure())+"px ; }";
    //qDebug() << s;
    lab->setStyleSheet(s);
}

monLabel * ElementGrandeImage::getLab()
{
    return lab;
}

void ElementGrandeImage::Resizer(QSize s)
{


    //img = new QPixmap(QPixmap::fromImage(image.scaled(s,  Qt::KeepAspectRatioByExpanding,Qt::SmoothTransformation)));
    //delete img;
    //img = new QPixmap(QPixmap::fromImage(image->scaled(this->getLab()->size(),  Qt::KeepAspectRatioByExpanding,Qt::SmoothTransformation)));
    this->ModifierImage((image->getPixDeTaille(s.height(), s.width())));

    modifierBordure();
}




void ElementGrandeImage::setImage(PetiteImage *i)
{
    image = i;
}

void ElementGrandeImage::setBordure(Bordure *b)
{
    bordure =  b;
    qDebug() << b;
}
