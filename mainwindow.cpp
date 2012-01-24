#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "maFrame.h"
#include "frameContener.h"
#include "elementGrandeImage.h"



MainWindow::MainWindow(QWidget *parent) :
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

    gdeImage = new GrandeImage(this, bordure);
    gdeImage->getGrille()->Affichage(ui->monGrandLayout);

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
    QColor c = QColorDialog::getColor();
    bordure->setCouleurBordure(&c);

    QBrush b(c);
    b.setStyle(Qt::SolidPattern);
    QPalette pal;
    pal.setBrush(QPalette::Active, QPalette::Window, b);

    ui->couleurCadres->setPalette(pal);
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
        elementSelectione->ModifierImage(((PetiteImage*)currentItem)->getPixDeTaille(elementSelectione->getLab()->height(), elementSelectione->getLab()->width()));
        currentItem->setSelected(false);
        currentItem = NULL;
    }
}

void MainWindow::changeRondeur()
{
    bordure->setRadiusBordure(ui->rondeur->value());
}

void MainWindow::changeEpaisseur()
{
    bordure->setTailleBordure(ui->epaisseur->value());
}

void MainWindow::viderLayout(Bordure * bordure)
{
    Bordure *temp = new Bordure(*bordure);
    QLayoutItem *item;
       while ((item = ui->monGrandLayout->takeAt(0)) != 0) {
            item->widget()->deleteLater();
            delete item;

       //ui->monGrandLayout->removeItem();
       }
       this->bordure = temp;
}

void MainWindow::changeFrame(int i)
{
    viderLayout(bordure);

    switch (i)
    {
        case 0:
            gdeImage->grille0(this,bordure);
            break;
        case 1:
            gdeImage->grille1(this,bordure);
            break;
        case 2:
            gdeImage->grille2(this,bordure);
            break;
        case 3:
            gdeImage->grille3(this,bordure);
            break;
        case 4:
            gdeImage->grille4(this,bordure);
            break;
        case 5:
            gdeImage->grille5(this,bordure);
            break;
        case 6:
            gdeImage->grille6(this,bordure);
            break;
        case 7:
            gdeImage->grille7(this,bordure);
            break;
        case 8:
            gdeImage->grille8(this,bordure);
            break;
        case 9:
            gdeImage->grille9(this,bordure);
            break;
        case 10:
            gdeImage->grille10(this,bordure);
            break;
        case 11:
            gdeImage->grille11(this,bordure);
            break;
        case 12:
            gdeImage->grille12(this,bordure);
            break;
        case 13:
            gdeImage->grille13(this,bordure);
            break;
    }
    gdeImage->getGrille()->Affichage(ui->monGrandLayout);
}
