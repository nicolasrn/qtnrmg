#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "maFrame.h"
#include "frameContener.h"
#include "elementGrandeImage.h"

int min (int a, int b)
{
    if (a<b)
        return a;
    return b;
}

int max (int a, int b)
{
    if (a<b)
        return b;
    return a;
}

QVector<ElementGrandeImage *> copieDe(QVector<ElementGrandeImage *> v, Bordure* b)
{
    qDebug() << "je copie dans main, taille de v =" << v.size();
    QVector<ElementGrandeImage *> v2;

    for(int i=0; i<v.size(); i++)
    {
        qDebug() << v[i];
        v2.append(new ElementGrandeImage(*v[i]));
        v2[i]->setBordure(b);
    }
    qDebug() << v2;
    return v2;
}

MainWindow::MainWindow(QWidget *parent) : vectElem(QVector<ElementGrandeImage *>()),
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    vectImage = new QVector<PetiteImage *>();

    scene = new QGraphicsScene(this);
    ui->graphicsViewDiaporama->setScene(scene);
    pos = 0;

    connect(scene, SIGNAL(selectionChanged ()), this, SLOT(selectionImage()));
    connect(ui->rondeur, SIGNAL(valueChanged(int)), this, SLOT(changeRondeur()) );
    connect(ui->epaisseur, SIGNAL(valueChanged(int)), this, SLOT(changeEpaisseur()) );
    connect(ui->frames, SIGNAL(currentIndexChanged(int)), this, SLOT(changeFrame(int)));
    connect(ui->taille, SIGNAL(currentIndexChanged(int)), this, SLOT(changeTaille(int)));
    connect(ui->actionQuitter,SIGNAL(triggered()),qApp,SLOT(quit()));

    ColorierFond(QColor(0,0,255));
    ui->monGrandWidget->setAutoFillBackground(true);
    ui->couleurFond->setAutoFillBackground(true);
    ui->couleurCadres->setAutoFillBackground(true);
    QBrush b(Qt::black);
    b.setStyle(Qt::SolidPattern);
    QPalette pal;
    pal.setBrush(QPalette::Active, QPalette::Window, b);

    ui->couleurCadres->setPalette(pal);

    bordure = new Bordure();

    elementSelectione = NULL;

    currentItem = NULL;

    gdeImage = new GrandeImage(this, bordure, vectElem);
    gdeImage->getGrille()->Affichage(ui->monGrandLayout);


    ui->monGrandWidget->setLayout(ui->monGrandLayout);

    changeFrame(ui->frames->currentIndex());
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_btnAjouter_clicked()
{
    QStringList listefichier =  QFileDialog::getOpenFileNames(this, tr("Choisissez une ou plusieurs images"), QString(),"Images (*.png *.gif *.jpg *.jpeg *.bmp)");
    QString v;
    PetiteImage *pt;


    foreach (v,listefichier)
    {
        qDebug() << v; //pour vérifier qu'on a bient tous les fichiers

        pt = new PetiteImage(v,(ui->groupDiapo->height()-50) );

        vectImage->append(pt); //on l'ajoute dans le vecteur ainsi on garde toutes les images en mémoire

        pt->setOffset(pos,0); //on place l'image
        scene->addItem(pt);//on ajoute l'image

        pos = pos + pt->getPixDiapo()->width() +5;
        qDebug() << pos;//voir si on se déplace bien pour bien placer les images dans le diapo


    }

}

void MainWindow::on_btnModifierFond_clicked()
{
    QColor c = QColorDialog::getColor();
    ColorierFond(c);
}

void MainWindow::on_btnCouleurCadres_clicked()
{
    QColor *c = new QColor(QColorDialog::getColor());
    bordure->setCouleurBordure(c);

    QBrush b(*c);
    b.setStyle(Qt::SolidPattern);
    QPalette pal;
    pal.setBrush(QPalette::Active, QPalette::Window, b);

    ui->couleurCadres->setPalette(pal);
    mettreAJourBordure();
    //repaint();
    changeFrame(ui->frames->currentIndex());
}

void MainWindow::on_btnSepia_clicked()
{
    if (elementSelectione != NULL)
    {
        elementSelectione->ModifierImage(elementSelectione->toSepia());
    }
}

void MainWindow::on_btnNoirBlanc_clicked()
{
    if (elementSelectione != NULL)
    {
        elementSelectione->ModifierImage(elementSelectione->toNoirEtBlanc());
    }
}

void MainWindow::on_btnNegatif_clicked()
{
    if (elementSelectione != NULL)
    {
        qDebug() << "je veux passer en sepia";
        elementSelectione->ModifierImage(elementSelectione->toNegatif());
    }
}

void MainWindow::on_btnPlus90_clicked()
{
    if (elementSelectione != NULL)
    {
        qDebug() << "je veux passer en sepia";
        elementSelectione->ModifierImage(elementSelectione->rotate(90));
    }
}

void MainWindow::on_btnMoins90_clicked()
{
    if (elementSelectione != NULL)
    {
        qDebug() << "je veux passer en sepia";
        elementSelectione->ModifierImage(elementSelectione->rotate(-90));
    }
}

void MainWindow::on_btnGH_clicked()
{
    if (elementSelectione != NULL)
        elementSelectione->getLab()->setAlignment(Qt::AlignLeft | Qt::AlignTop);
}

void MainWindow::on_btnGM_clicked()
{
    if (elementSelectione != NULL)
        elementSelectione->getLab()->setAlignment(Qt::AlignLeft | Qt::AlignVCenter);
}

void MainWindow::on_btnGB_clicked()
{
    if (elementSelectione != NULL)
        elementSelectione->getLab()->setAlignment(Qt::AlignLeft | Qt::AlignBottom);
}

void MainWindow::on_btnMH_clicked()
{
    if (elementSelectione != NULL)
        elementSelectione->getLab()->setAlignment(Qt::AlignHCenter | Qt::AlignTop);
}

void MainWindow::on_btnMM_clicked()
{
    if (elementSelectione != NULL)
        elementSelectione->getLab()->setAlignment(Qt::AlignCenter);
}

void MainWindow::on_btnMB_clicked()
{
    if (elementSelectione != NULL)
        elementSelectione->getLab()->setAlignment(Qt::AlignHCenter | Qt::AlignBottom);
}

void MainWindow::on_btnDH_clicked()
{
    if (elementSelectione != NULL)
        elementSelectione->getLab()->setAlignment(Qt::AlignRight | Qt::AlignTop);
}

void MainWindow::on_btnDM_clicked()
{
    if (elementSelectione != NULL)
        elementSelectione->getLab()->setAlignment(Qt::AlignRight | Qt::AlignVCenter);
}

void MainWindow::on_btnDB_clicked()
{
    if (elementSelectione != NULL)
        elementSelectione->getLab()->setAlignment(Qt::AlignRight | Qt::AlignBottom);
}

void MainWindow::selectionImage()
{
    qDebug() << "ici";

    QList<QGraphicsItem *> selectedItems = scene->selectedItems();

    if ( ! selectedItems.empty() ) { // des éléments sont sélectionnés

        foreach(currentItem, selectedItems) {
            qDebug() << "là";
            //ui->gdLabel->setPixmap(*((PetiteImage*)currentItem)->getPixDeTaille(ui->gdLabel->height(), ui->gdLabel->width()));
        }
    }

}

void MainWindow::ColorierFond(QColor c)
{
    QBrush b(c);
    b.setStyle(Qt::SolidPattern);
    QPalette pal;
    pal.setBrush(QPalette::Active, QPalette::Window, b);

    ui->monGrandWidget->setPalette(pal);

    ui->couleurFond->setPalette(pal);
}

void MainWindow::receptionMessage(ElementGrandeImage *l)
{
    qDebug() << "main window recoit le message " << l;
    elementSelectione = l;
    if (currentItem != NULL)
    {
        qDebug() << "test: " << elementSelectione->size();
        elementSelectione->setImage((((PetiteImage*)currentItem)));
        elementSelectione->ModifierImage(((PetiteImage*)currentItem)->getPixDeTaille(elementSelectione->getLab()->height(), elementSelectione->getLab()->width()));
        qDebug() << "test2: " << elementSelectione->size();
        currentItem->setSelected(false);
        currentItem = NULL;
    }
}

void MainWindow::changeRondeur()
{
    qDebug() <<"changer rondeur";
    qDebug() << bordure;
    qDebug() << "ici";
    bordure->setRadiusBordure(ui->rondeur->value());
    mettreAJourBordure();
    changeFrame(ui->frames->currentIndex());
    //repaint();
}

void MainWindow::changeEpaisseur()
{
    qDebug() <<"changer epaisseur";

    bordure->setTailleBordure(ui->epaisseur->value());
    mettreAJourBordure();
    changeFrame(ui->frames->currentIndex());
    //repaint();
}



void MainWindow::viderLayout(Bordure * bordure)
{
    qDebug() <<"je vide le layout";
    Bordure *temp = new Bordure(*bordure);
    QLayoutItem *item;
       while ((item = ui->monGrandLayout->takeAt(0)) != 0) {
            item->widget()->deleteLater();
            delete item;

       //ui->monGrandLayout->removeItem();
       }
       this->bordure = temp;
       mettreAJourBordure();
}

void MainWindow::changeFrame(int i)
{
    //toutResizer();
    QVector<ElementGrandeImage *> vectTemp = copieDe(vectElem, bordure);
    viderLayout(bordure);

    switch (i)
    {
        case 0:
            vectElem = gdeImage->grille0(this,bordure, vectTemp);
            break;
        case 1:
            vectElem = gdeImage->grille1(this,bordure, vectTemp);
            break;
        case 2:
            vectElem = gdeImage->grille2(this,bordure, vectTemp);
            break;
        case 3:
            vectElem = gdeImage->grille3(this,bordure, vectTemp);
            break;
        case 4:
            vectElem = gdeImage->grille4(this,bordure, vectTemp);
            break;
        case 5:
            vectElem = gdeImage->grille5(this,bordure, vectTemp);
            break;
        case 6:
            vectElem = gdeImage->grille6(this,bordure, vectTemp);
            break;
        case 7:
            vectElem = gdeImage->grille7(this,bordure, vectTemp);
            break;
        case 8:
            vectElem = gdeImage->grille8(this,bordure, vectTemp);
            break;
        case 9:
            vectElem = gdeImage->grille9(this,bordure, vectTemp);
            break;
        case 10:
            vectElem = gdeImage->grille10(this,bordure, vectTemp);
            break;
        case 11:
            vectElem = gdeImage->grille11(this,bordure, vectTemp);
            break;
        case 12:
            vectElem = gdeImage->grille12(this,bordure, vectTemp);
            break;
        case 13:
            vectElem = gdeImage->grille13(this,bordure, vectTemp);
            break;
    }
    toutResizer();
    elementSelectione = NULL;
    gdeImage->getGrille()->Affichage(ui->monGrandLayout);
    vectTemp.clear();
}

void MainWindow::changeTaille(int i)
{
    int temp;
    switch (i)
    {
        case 0:
            temp = min(ui->MonTresGrandWidget->height(),ui->MonTresGrandWidget->width());
            qDebug() << temp;
            ui->monGrandWidget->setFixedHeight(temp);
            ui->monGrandWidget->setFixedWidth(temp);
            break;
        case 1:
            if (ui->MonTresGrandWidget->width()/2 < ui->MonTresGrandWidget->height() )
                temp = ui->MonTresGrandWidget->width() /2;
            else
                temp = ui->MonTresGrandWidget->height();
            qDebug() << temp;
            ui->monGrandWidget->setFixedHeight(temp);
            ui->monGrandWidget->setFixedWidth(2 * temp);
            break;
        case 2:
            if (ui->MonTresGrandWidget->width()/3 < ui->MonTresGrandWidget->height()/2 )
                    temp = ui->MonTresGrandWidget->width() /3;
                else
                    temp = ui->MonTresGrandWidget->height()/2;
            qDebug() << temp;
            ui->monGrandWidget->setFixedHeight(2 * temp);
            ui->monGrandWidget->setFixedWidth(3 * temp);
            break;
        case 3:
            if (ui->MonTresGrandWidget->width()/4 < ui->MonTresGrandWidget->height()/3 )
                    temp = ui->MonTresGrandWidget->width() /4;
                else
                    temp = ui->MonTresGrandWidget->height()/3;
            qDebug() << temp;
            ui->monGrandWidget->setFixedHeight(3 * temp);
            ui->monGrandWidget->setFixedWidth(4 * temp);
            break;
        case 4:
            if (ui->MonTresGrandWidget->width()/5 < ui->MonTresGrandWidget->height()/4 )
                    temp = ui->MonTresGrandWidget->width() /5;
                else
                    temp = ui->MonTresGrandWidget->height()/4;
            qDebug() << temp;
            ui->monGrandWidget->setFixedHeight(4 * temp);
            ui->monGrandWidget->setFixedWidth(5 * temp);
            break;
        case 5:
            if (ui->MonTresGrandWidget->width()/16 < ui->MonTresGrandWidget->height()/9 )
                    temp = ui->MonTresGrandWidget->width() /16;
                else
                    temp = ui->MonTresGrandWidget->height()/9;
            qDebug() << temp;
            ui->monGrandWidget->setFixedHeight(9 * temp);
            ui->monGrandWidget->setFixedWidth(16 * temp);
            break;

        gdeImage->getGrille()->Affichage(ui->monGrandLayout);

    }

}

void MainWindow::toutResizer()
{
    for (int i = 0; i<vectElem.size(); i++)
    {
        qDebug() <<"num de l'element resizé" << i;
        //vectElem[i]->adjustSize();
        //vectElem[i]->setBaseSize(vectElem[i]->getLab()->size());

        vectElem[i]->Resizer(vectElem[i]->getLab()->size());
    }
}

void MainWindow::mettreAJourBordure()
{
    for (int i = 0; i<vectElem.size(); i++)
    {
        vectElem[i]->setBordure(bordure);
    }
}

void MainWindow::on_actionSauvegarder_triggered()
{
    QString filename = QFileDialog::getSaveFileName( this, "Enregistrer", QString(), "Images (*.jpeg)" );
      if ( !filename.isEmpty() )
      {
        QPixmap::grabWidget(ui->monGrandWidget).save(filename);
      }

}
