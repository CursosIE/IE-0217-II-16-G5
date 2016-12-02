#ifndef DIALOG_H
#define DIALOG_H

//#include <QMainWindow>
#include <QtCore>
#include <QtGui>
#include <QDialog>
#include "fichag.h"
#include "ficha.h"
#include "tablero.h"

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    Tablero t;
    bool* turno;

    explicit Dialog(QWidget *parent = 0);
    ~Dialog();

private:
    Ui::Dialog *ui;
    QGraphicsScene *scene;
    FichaG *fichaG_00;
    FichaG *fichaG_01;
    FichaG *fichaG_02;
    FichaG *fichaG_03;
    FichaG *fichaG_04;
    FichaG *fichaG_05;
    FichaG *fichaG_06;

    FichaG *fichaG_10;
    FichaG *fichaG_11;
    FichaG *fichaG_12;
    FichaG *fichaG_13;
    FichaG *fichaG_14;
    FichaG *fichaG_15;
    FichaG *fichaG_16;

    FichaG *fichaG_20;
    FichaG *fichaG_21;
    FichaG *fichaG_22;
    FichaG *fichaG_23;
    FichaG *fichaG_24;
    FichaG *fichaG_25;
    FichaG *fichaG_26;

    FichaG *fichaG_30;
    FichaG *fichaG_31;
    FichaG *fichaG_32;
    FichaG *fichaG_33;
    FichaG *fichaG_34;
    FichaG *fichaG_35;
    FichaG *fichaG_36;

    FichaG *fichaG_40;
    FichaG *fichaG_41;
    FichaG *fichaG_42;
    FichaG *fichaG_43;
    FichaG *fichaG_44;
    FichaG *fichaG_45;
    FichaG *fichaG_46;

    FichaG *fichaG_50;
    FichaG *fichaG_51;
    FichaG *fichaG_52;
    FichaG *fichaG_53;
    FichaG *fichaG_54;
    FichaG *fichaG_55;
    FichaG *fichaG_56;

    FichaG *fichaG_60;
    FichaG *fichaG_61;
    FichaG *fichaG_62;
    FichaG *fichaG_63;
    FichaG *fichaG_64;
    FichaG *fichaG_65;
    FichaG *fichaG_66;
};

#endif // DIALOG_H
