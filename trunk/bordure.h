#ifndef BORDURE_H
#define BORDURE_H

#include <QColor>
#include <QDebug>

class Bordure : public QObject
{
    Q_OBJECT
public:
    Bordure();
    Bordure(const Bordure &b);
    int getTailleBordure();
    int getRadiusBordure();
    QColor* getCouleurBordure();
    void setTailleBordure(int i);
    void setRadiusBordure(int i);
    void setCouleurBordure(QColor * c);


    QColor* couleurBordure;
private:
    int tailleBordure;
    int radiusBordure;
signals:
    void modificationBordure();
};

#endif // BORDURE_H
