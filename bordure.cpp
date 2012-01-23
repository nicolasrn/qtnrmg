#include "bordure.h"

Bordure::Bordure() : QObject()
{
    tailleBordure = 5;
    couleurBordure = new QColor(Qt::black);
    radiusBordure = 5;
}

Bordure::Bordure(const Bordure &b): QObject()
{
    tailleBordure = b.tailleBordure;
    couleurBordure = new QColor(*b.couleurBordure);
    radiusBordure = b.radiusBordure;
}

int Bordure::getRadiusBordure()
{
    return radiusBordure;
}

int Bordure::getTailleBordure()
{
    return tailleBordure;
}

QColor* Bordure::getCouleurBordure()
{
    return couleurBordure;
}

void Bordure::setRadiusBordure(int i)
{
    radiusBordure = i;
    emit modificationBordure();
}

void Bordure::setTailleBordure(int i)
{
    tailleBordure = i;
    emit modificationBordure();
}

void Bordure::setCouleurBordure(QColor *c)
{
    couleurBordure = c;
    emit modificationBordure();
}
