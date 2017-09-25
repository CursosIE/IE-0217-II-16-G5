#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    bool* tur = new bool[1];
    tur[0]=false;
    this->t= Tablero(7);
    this->turno=tur;

    ui->setupUi(this);

    scene= new QGraphicsScene(this);
    ui->graphicsView->setScene(scene);

    QVector<QPoint> points;
    points << QPoint(20,50) << QPoint(80,50) << QPoint(110,80) << QPoint(50, 130) << QPoint(-10,80);

    //Make Fila 0
    QVector<QPoint> h_00;
    h_00 << QPoint(50,20);
    h_00 << QPoint(76,35);
    h_00 << QPoint(76,65);
    h_00 << QPoint(50,80);
    h_00 << QPoint(24,65);
    h_00 << QPoint(24,35);

    fichaG_00= new FichaG(h_00, 33, 38, 0, 0, this->t, this->turno);
    scene->addItem(fichaG_00);

    QVector<QPoint> h_01;
    h_01 << QPoint(105,20);
    h_01 << QPoint(131,35);
    h_01 << QPoint(131,65);
    h_01 << QPoint(105,80);
    h_01 << QPoint(79,65);
    h_01 << QPoint(79,35);

    fichaG_01= new FichaG(h_01, 88, 38, 0, 1, this->t, this->turno);
    scene->addItem(fichaG_01);

    QVector<QPoint>  h_02;
    h_02 << QPoint(160,20);
    h_02 << QPoint(186,35);
    h_02 << QPoint(186,65);
    h_02 << QPoint(160,80);
    h_02 << QPoint(134,65);
    h_02 << QPoint(134,35);

    fichaG_02= new FichaG(h_02, 143, 38, 0, 2, this->t, this->turno);
    scene->addItem(fichaG_02);

    QVector<QPoint> h_03;
    h_03 << QPoint(215,20);
    h_03 << QPoint(241,35);
    h_03 << QPoint(241,65);
    h_03 << QPoint(215,80);
    h_03 << QPoint(189,65);
    h_03 << QPoint(189,35);

    fichaG_03= new FichaG(h_03, 198, 38, 0, 3, this->t, this->turno);
    scene->addItem(fichaG_03);

    QVector<QPoint> h_04;
    h_04 << QPoint(270,20);
    h_04 << QPoint(296,35);
    h_04 << QPoint(296,65);
    h_04 << QPoint(270,80);
    h_04 << QPoint(244,65);
    h_04 << QPoint(244,35);

    fichaG_04= new FichaG(h_04, 253, 38, 0, 4, this->t, this->turno);
    scene->addItem(fichaG_04);

    QVector<QPoint> h_05;
    h_05 << QPoint(325,20);
    h_05 << QPoint(351,35);
    h_05 << QPoint(351,65);
    h_05 << QPoint(325,80);
    h_05 << QPoint(299,65);
    h_05 << QPoint(299,35);

    fichaG_05= new FichaG(h_05, 308, 38, 0, 5, this->t, this->turno);
    scene->addItem(fichaG_05);

    QVector<QPoint> h_06;
    h_06 << QPoint(380,20);
    h_06 << QPoint(406,35);
    h_06 << QPoint(406,65);
    h_06 << QPoint(380,80);
    h_06 << QPoint(354,65);
    h_06 << QPoint(354,35);

    fichaG_06= new FichaG(h_06, 363, 38, 0, 6, this->t, this->turno);
    scene->addItem(fichaG_06);

    //Make Fila 1
    QVector<QPoint> h_10;
    h_10 << QPoint(79,68);
    h_10 << QPoint(105,83);
    h_10 << QPoint(105,113);
    h_10 << QPoint(79,128);
    h_10 << QPoint(53,113);
    h_10 << QPoint(53,83);

    fichaG_10= new FichaG(h_10, 62, 86, 1, 0, this->t, this->turno);
    scene->addItem(fichaG_10);

    QVector<QPoint> h_11;
    h_11 << QPoint(134,68);
    h_11 << QPoint(160,83);
    h_11 << QPoint(160,113);
    h_11 << QPoint(134,128);
    h_11 << QPoint(108,113);
    h_11 << QPoint(108,83);

    fichaG_11= new FichaG(h_11, 117, 86, 1, 1, this->t, this->turno);
    scene->addItem(fichaG_11);

    QVector<QPoint> h_12;
    h_12 << QPoint(189,68);
    h_12 << QPoint(215,83);
    h_12 << QPoint(215,113);
    h_12 << QPoint(189,128);
    h_12 << QPoint(163,113);
    h_12 << QPoint(163,83);

    fichaG_12= new FichaG(h_12, 172, 86, 1, 2, this->t, this->turno);
    scene->addItem(fichaG_12);

    QVector<QPoint> h_13;
    h_13 << QPoint(244,68);
    h_13 << QPoint(270,83);
    h_13 << QPoint(270,113);
    h_13 << QPoint(244,128);
    h_13 << QPoint(218,113);
    h_13 << QPoint(218,83);

    fichaG_13= new FichaG(h_13, 227, 86, 1, 3, this->t, this->turno);
    scene->addItem(fichaG_13);

    QVector<QPoint> h_14;
    h_14 << QPoint(299,68);
    h_14 << QPoint(325,83);
    h_14 << QPoint(325,113);
    h_14 << QPoint(299,128);
    h_14 << QPoint(273,113);
    h_14 << QPoint(273,83);

    fichaG_14= new FichaG(h_14, 282, 86, 1, 4, this->t, this->turno);
    scene->addItem(fichaG_14);

    QVector<QPoint> h_15;
    h_15 << QPoint(354,68);
    h_15 << QPoint(380,83);
    h_15 << QPoint(380,113);
    h_15 << QPoint(354,128);
    h_15 << QPoint(328,113);
    h_15 << QPoint(328,83);

    fichaG_15= new FichaG(h_15, 337, 86, 1, 5, this->t, this->turno);
    scene->addItem(fichaG_15);

    QVector<QPoint> h_16;
    h_16 << QPoint(409,68);
    h_16 << QPoint(435,83);
    h_16 << QPoint(435,113);
    h_16 << QPoint(409,128);
    h_16 << QPoint(383,113);
    h_16 << QPoint(383,83);

    fichaG_16= new FichaG(h_16, 392, 86, 1, 6, this->t, this->turno);
    scene->addItem(fichaG_16);

    //Make Fila 2
    QVector<QPoint> h_20;
    h_20 << QPoint(108,116);
    h_20 << QPoint(134,131);
    h_20 << QPoint(134,161);
    h_20 << QPoint(108,176);
    h_20 << QPoint(82,161);
    h_20 << QPoint(82,131);

    fichaG_20= new FichaG(h_20, 91, 134, 2, 0, this->t, this->turno);
    scene->addItem(fichaG_20);

    QVector<QPoint> h_21;
    h_21 << QPoint(163,116);
    h_21 << QPoint(189,131);
    h_21 << QPoint(189,161);
    h_21 << QPoint(163,176);
    h_21 << QPoint(137,161);
    h_21 << QPoint(137,131);

    fichaG_21= new FichaG(h_21, 146, 134, 2, 1, this->t, this->turno);
    scene->addItem(fichaG_21);

    QVector<QPoint> h_22;
    h_22 << QPoint(218,116);
    h_22 << QPoint(244,131);
    h_22 << QPoint(244,161);
    h_22 << QPoint(218,176);
    h_22 << QPoint(192,161);
    h_22 << QPoint(192,131);

    fichaG_22= new FichaG(h_22, 201, 134, 2, 2, this->t, this->turno);
    scene->addItem(fichaG_22);

    QVector<QPoint> h_23;
    h_23 << QPoint(273,116);
    h_23 << QPoint(299,131);
    h_23 << QPoint(299,161);
    h_23 << QPoint(273,176);
    h_23 << QPoint(247,161);
    h_23 << QPoint(247,131);

    fichaG_23= new FichaG(h_23, 256, 134, 2, 3, this->t, this->turno);
    scene->addItem(fichaG_23);

    QVector<QPoint> h_24;
    h_24 << QPoint(328,116);
    h_24 << QPoint(354,131);
    h_24 << QPoint(354,161);
    h_24 << QPoint(328,176);
    h_24 << QPoint(302,161);
    h_24 << QPoint(302,131);

    fichaG_24= new FichaG(h_24, 311, 134, 2, 4, this->t, this->turno);
    scene->addItem(fichaG_24);

    QVector<QPoint> h_25;
    h_25 << QPoint(383,116);
    h_25 << QPoint(409,131);
    h_25 << QPoint(409,161);
    h_25 << QPoint(383,176);
    h_25 << QPoint(357,161);
    h_25 << QPoint(357,131);

    fichaG_25= new FichaG(h_25, 366, 134, 2, 5, this->t, this->turno);
    scene->addItem(fichaG_25);

    QVector<QPoint> h_26;
    h_26 << QPoint(438,116);
    h_26 << QPoint(464,131);
    h_26 << QPoint(464,161);
    h_26 << QPoint(438,176);
    h_26 << QPoint(412,161);
    h_26 << QPoint(412,131);

    fichaG_26= new FichaG(h_26, 421, 134, 2, 6, this->t, this->turno);
    scene->addItem(fichaG_26);

    //Make Fila 3
    QVector<QPoint> h_30;
    h_30 << QPoint(137,164);
    h_30 << QPoint(163,179);
    h_30 << QPoint(163,209);
    h_30 << QPoint(137,224);
    h_30 << QPoint(111,209);
    h_30 << QPoint(111,179);

    fichaG_30= new FichaG(h_30, 120, 182, 3, 0, this->t, this->turno);
    scene->addItem(fichaG_30);

    QVector<QPoint> h_31;
    h_31 << QPoint(192,164);
    h_31 << QPoint(218,179);
    h_31 << QPoint(218,209);
    h_31 << QPoint(192,224);
    h_31 << QPoint(166,209);
    h_31 << QPoint(166,179);

    fichaG_31= new FichaG(h_31, 175, 182, 3, 1, this->t, this->turno);
    scene->addItem(fichaG_31);

    QVector<QPoint> h_32;
    h_32 << QPoint(247,164);
    h_32 << QPoint(273,179);
    h_32 << QPoint(273,209);
    h_32 << QPoint(247,224);
    h_32 << QPoint(221,209);
    h_32 << QPoint(221,179);

    fichaG_32= new FichaG(h_32, 230, 182, 3, 2, this->t, this->turno);
    scene->addItem(fichaG_32);

    QVector<QPoint> h_33;
    h_33 << QPoint(302,164);
    h_33 << QPoint(328,179);
    h_33 << QPoint(328,209);
    h_33 << QPoint(302,224);
    h_33 << QPoint(276,209);
    h_33 << QPoint(276,179);

    fichaG_33= new FichaG(h_33, 285, 182, 3, 3, this->t, this->turno);
    scene->addItem(fichaG_33);

    QVector<QPoint> h_34;
    h_34 << QPoint(357,164);
    h_34 << QPoint(383,179);
    h_34 << QPoint(383,209);
    h_34 << QPoint(357,224);
    h_34 << QPoint(331,209);
    h_34 << QPoint(331,179);

    fichaG_34= new FichaG(h_34, 340, 182, 3, 4, this->t, this->turno);
    scene->addItem(fichaG_34);

    QVector<QPoint> h_35;
    h_35 << QPoint(412,164);
    h_35 << QPoint(438,179);
    h_35 << QPoint(438,209);
    h_35 << QPoint(412,224);
    h_35 << QPoint(386,209);
    h_35 << QPoint(386,179);

    fichaG_35= new FichaG(h_35, 395, 182, 3, 5, this->t, this->turno);
    scene->addItem(fichaG_35);

   QVector<QPoint> h_36;
    h_36 << QPoint(467,164);
    h_36 << QPoint(493,179);
    h_36 << QPoint(493,209);
    h_36 << QPoint(467,224);
    h_36 << QPoint(441,209);
    h_36 << QPoint(441,179);

    fichaG_36= new FichaG(h_36, 450, 182, 3, 6, this->t, this->turno);
    scene->addItem(fichaG_36);

    //Make Fila 4
    QVector<QPoint> h_40;
    h_40 << QPoint(166,212);
    h_40 << QPoint(192,227);
    h_40 << QPoint(192,257);
    h_40 << QPoint(166,272);
    h_40 << QPoint(140,257);
    h_40 << QPoint(140,227);

    fichaG_40= new FichaG(h_40, 149, 230, 4, 0, this->t, this->turno);
    scene->addItem(fichaG_40);

    QVector<QPoint> h_41;
    h_41 << QPoint(221,212);
    h_41 << QPoint(247,227);
    h_41 << QPoint(247,257);
    h_41 << QPoint(221,272);
    h_41 << QPoint(195,257);
    h_41 << QPoint(195,227);

    fichaG_41= new FichaG(h_41, 204, 230, 4, 1, this->t, this->turno);
    scene->addItem(fichaG_41);

    QVector<QPoint> h_42;
    h_42 << QPoint(276,212);
    h_42 << QPoint(302,227);
    h_42 << QPoint(302,257);
    h_42 << QPoint(276,272);
    h_42 << QPoint(250,257);
    h_42 << QPoint(250,227);

    fichaG_42= new FichaG(h_42, 259, 230, 4, 2, this->t, this->turno);
    scene->addItem(fichaG_42);

    QVector<QPoint> h_43;
    h_43 << QPoint(331,212);
    h_43 << QPoint(357,227);
    h_43 << QPoint(357,257);
    h_43 << QPoint(331,272);
    h_43 << QPoint(305,257);
    h_43 << QPoint(305,227);

    fichaG_43= new FichaG(h_43, 314, 230, 4, 3, this->t, this->turno);
    scene->addItem(fichaG_43);

    QVector<QPoint> h_44;
    h_44 << QPoint(386,212);
    h_44 << QPoint(412,227);
    h_44 << QPoint(412,257);
    h_44 << QPoint(386,272);
    h_44 << QPoint(360,257);
    h_44 << QPoint(360,227);

    fichaG_44= new FichaG(h_44, 369, 230, 4, 4, this->t, this->turno);
    scene->addItem(fichaG_44);

    QVector<QPoint> h_45;
    h_45 << QPoint(441,212);
    h_45 << QPoint(467,227);
    h_45 << QPoint(467,257);
    h_45 << QPoint(441,272);
    h_45 << QPoint(415,257);
    h_45 << QPoint(415,227);

    fichaG_45= new FichaG(h_45, 424, 230, 4, 5, this->t, this->turno);
    scene->addItem(fichaG_45);

    QVector<QPoint> h_46;
    h_46 << QPoint(496,212);
    h_46 << QPoint(522,227);
    h_46 << QPoint(522,257);
    h_46 << QPoint(496,272);
    h_46 << QPoint(470,257);
    h_46 << QPoint(470,227);

    fichaG_46= new FichaG(h_46, 479, 230, 4, 6, this->t, this->turno);
    scene->addItem(fichaG_46);

    //Make Fila 5
    QVector<QPoint> h_50;
    h_50 << QPoint(195,260);
    h_50 << QPoint(221,275);
    h_50 << QPoint(221,305);
    h_50 << QPoint(195,320);
    h_50 << QPoint(169,305);
    h_50 << QPoint(169,275);

    fichaG_50= new FichaG(h_50, 178, 278, 5, 0, this->t, this->turno);
    scene->addItem(fichaG_50);

    QVector<QPoint> h_51;
    h_51 << QPoint(250,260);
    h_51 << QPoint(276,275);
    h_51 << QPoint(276,305);
    h_51 << QPoint(250,320);
    h_51 << QPoint(226,305);
    h_51 << QPoint(226,275);

    fichaG_51= new FichaG(h_51, 235, 278, 5, 1, this->t, this->turno);
    scene->addItem(fichaG_51);

    QVector<QPoint> h_52;
    h_52 << QPoint(305,260);
    h_52 << QPoint(331,275);
    h_52 << QPoint(331,305);
    h_52 << QPoint(305,320);
    h_52 << QPoint(279,305);
    h_52 << QPoint(279,275);

    fichaG_52= new FichaG(h_52, 288, 278, 5, 2, this->t, this->turno);
    scene->addItem(fichaG_52);

    QVector<QPoint> h_53;
    h_53 << QPoint(360,260);
    h_53 << QPoint(386,275);
    h_53 << QPoint(386,305);
    h_53 << QPoint(360,320);
    h_53 << QPoint(334,305);
    h_53 << QPoint(334,275);

    fichaG_53= new FichaG(h_53, 343, 278, 5, 3, this->t, this->turno);
    scene->addItem(fichaG_53);

    QVector<QPoint> h_54;
    h_54 << QPoint(415,260);
    h_54 << QPoint(441,275);
    h_54 << QPoint(441,305);
    h_54 << QPoint(415,320);
    h_54 << QPoint(389,305);
    h_54 << QPoint(389,275);

    fichaG_54= new FichaG(h_54, 398, 278, 5, 4, this->t, this->turno);
    scene->addItem(fichaG_54);

    QVector<QPoint> h_55;
    h_55 << QPoint(470,260);
    h_55 << QPoint(496,275);
    h_55 << QPoint(496,305);
    h_55 << QPoint(470,320);
    h_55 << QPoint(444,305);
    h_55 << QPoint(444,275);

    fichaG_55= new FichaG(h_55, 453, 278, 5, 5, this->t, this->turno);
    scene->addItem(fichaG_55);

    QVector<QPoint> h_56;
    h_56 << QPoint(525,260);
    h_56 << QPoint(551,275);
    h_56 << QPoint(551,305);
    h_56 << QPoint(525,320);
    h_56 << QPoint(499,305);
    h_56 << QPoint(499,275);

    fichaG_56= new FichaG(h_56, 508, 278, 5, 6, this->t, this->turno);
    scene->addItem(fichaG_56);

    //Make Fila 6
    QVector<QPoint> h_60;
    h_60 << QPoint(224,308);
    h_60 << QPoint(250,323);
    h_60 << QPoint(250,353);
    h_60 << QPoint(224,368);
    h_60 << QPoint(198,353);
    h_60 << QPoint(198,323);

    fichaG_60= new FichaG(h_60, 207, 326, 6, 0, this->t, this->turno);
    scene->addItem(fichaG_60);

    QVector<QPoint> h_61;
    h_61 << QPoint(279,308);
    h_61 << QPoint(305,323);
    h_61 << QPoint(305,353);
    h_61 << QPoint(279,368);
    h_61 << QPoint(253,353);
    h_61 << QPoint(253,323);

    fichaG_61= new FichaG(h_61, 262, 326, 6, 1, this->t, this->turno);
    scene->addItem(fichaG_61);

    QVector<QPoint> h_62;
    h_62 << QPoint(334,308);
    h_62 << QPoint(360,323);
    h_62 << QPoint(360,353);
    h_62 << QPoint(334,368);
    h_62 << QPoint(308,353);
    h_62 << QPoint(308,323);

    fichaG_62= new FichaG(h_62, 317, 326, 6, 2, this->t, this->turno);
    scene->addItem(fichaG_62);

    QVector<QPoint> h_63;
    h_63 << QPoint(389,308);
    h_63 << QPoint(415,323);
    h_63 << QPoint(415,353);
    h_63 << QPoint(389,368);
    h_63 << QPoint(363,353);
    h_63 << QPoint(363,323);

    fichaG_63= new FichaG(h_63, 372, 326, 6, 3, this->t, this->turno);
    scene->addItem(fichaG_63);

    QVector<QPoint> h_64;
    h_64 << QPoint(444,308);
    h_64 << QPoint(470,323);
    h_64 << QPoint(470,353);
    h_64 << QPoint(444,368);
    h_64 << QPoint(418,353);
    h_64 << QPoint(418,323);

    fichaG_64= new FichaG(h_64, 427, 326, 6, 4, this->t, this->turno);
    scene->addItem(fichaG_64);

    QVector<QPoint> h_65;
    h_65 << QPoint(499,308);
    h_65 << QPoint(525,323);
    h_65 << QPoint(525,353);
    h_65 << QPoint(499,368);
    h_65 << QPoint(473,353);
    h_65 << QPoint(473,323);

    fichaG_65= new FichaG(h_65, 482, 326, 6, 5, this->t, this->turno);
    scene->addItem(fichaG_65);

    QVector<QPoint> h_66;
    h_66 << QPoint(554,308);
    h_66 << QPoint(580,323);
    h_66 << QPoint(580,353);
    h_66 << QPoint(554,368);
    h_66 << QPoint(528,353);
    h_66 << QPoint(528,323);

    fichaG_66= new FichaG(h_66, 537, 326, 6, 6, this->t, this->turno);
    scene->addItem(fichaG_66);
}

Dialog::~Dialog()
{
    delete ui;
}
