#include "addpolygon.h"

AddTriangle::AddTriangle(QWidget* parent)
    : QDialog(parent, Qt::WindowTitleHint | Qt::WindowSystemMenuHint)
{
    //Stets window properties
    this->setWindowTitle ("Add Triangle");
    this->setModal(true);
    this->resize(200,90);

    //Initializes point fields
    x1 = new QDoubleSpinBox;
    y1 = new QDoubleSpinBox;
    x2 = new QDoubleSpinBox;
    y2 = new QDoubleSpinBox;
    x3 = new QDoubleSpinBox;
    y3 = new QDoubleSpinBox;

    //Sets field ranges
    x1->setRange(-525,525);
    y1->setRange(-300,300);
    x2->setRange(-525,525);
    y2->setRange(-300,300);
    x1->setRange(-525,525);
    y1->setRange(-300,300);
    x3->setRange(-525,525);
    y3->setRange(-300,300);

    //Adds labels
    QLabel* p1 = new QLabel("1st point");
    QLabel* p2 = new QLabel("2nd point");
    QLabel* p3 = new QLabel("3rd point");

    //Adds default buttons
    QPushButton* ok = new QPushButton("&Ok");
    QPushButton* cancel = new QPushButton("&Cancel");

    //Sets Layout
    layout = new QGridLayout;
    layout->addWidget(p1, 0, 0);
    layout->addWidget(p2, 1, 0);
    layout->addWidget(p3, 2, 0);
    layout->addWidget(x1, 0, 1);
    layout->addWidget(y1, 0, 2);
    layout->addWidget(x2, 1, 1);
    layout->addWidget(y2, 1, 2);
    layout->addWidget(x3, 2, 1);
    layout->addWidget(y3, 2, 2);
    layout->addWidget(cancel, 5, 2);
    layout->addWidget(ok, 5, 1);
    setLayout(layout);

    connect(ok, SIGNAL(clicked()), SLOT(accept()));
    connect(cancel, SIGNAL(clicked()), SLOT(reject()));
}

AddTriangle::~AddTriangle()
{
    delete x1;
    delete y1;
    delete x2;
    delete y2;
    delete x3;
    delete y3;
    delete layout;
}

QPolygonF AddTriangle::getPoints()
{
    QPolygonF pol;
    pol << QPointF(x1->value(), y1->value()) << QPointF(x2->value(), y2->value()) << QPointF(x3->value(), y3->value());
    return pol;
}

AddQuadrangle::AddQuadrangle(QWidget* parent )
    :AddTriangle(parent)
{
    //Initializes point fields
    x4 = new QDoubleSpinBox;
    y4 = new QDoubleSpinBox;

    //Sets field ranges
    x4->setRange(-525,525);
    y4->setRange(-300,300);

    //Adds labels
    QLabel* p4 = new QLabel("4th point");

    //Sets Layout
    layout->addWidget(p4, 3, 0);
    layout->addWidget(x4, 3, 1);
    layout->addWidget(y4, 3, 2);
}

AddQuadrangle::~AddQuadrangle()
{
    delete x4;
    delete y4;
}

QPolygonF AddQuadrangle::getPoints()
{
    QPolygonF pol = AddTriangle::getPoints();
    pol << QPointF(x4->value(), y4->value());
    return pol;
}

AddPentagon::AddPentagon(QWidget* parent )
    :AddQuadrangle(parent)
{
    //Initializes point fields
    x5 = new QDoubleSpinBox;
    y5 = new QDoubleSpinBox;

    //Sets field ranges
    x5->setRange(-525,525);
    y5->setRange(-300,300);

    //Adds labels
    QLabel* p5 = new QLabel("5th point");

    //Sets Layout
    layout->addWidget(p5, 4, 0);
    layout->addWidget(x5, 4, 1);
    layout->addWidget(y5, 4, 2);
}

AddPentagon::~AddPentagon()
{
    delete x5;
    delete y5;
}

QPolygonF AddPentagon::getPoints()
{
    QPolygonF pol = AddQuadrangle::getPoints();
    pol << QPointF(x4->value(), y4->value());
    return pol;
}

