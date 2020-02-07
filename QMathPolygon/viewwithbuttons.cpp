#include "viewwithbuttons.h"

ViewWithButtons::ViewWithButtons(CoordPlaneScene *scene, QWidget *parent)
    :CoordPlaneView(scene,parent)
{
    // Adds buttons above the view
    gridplus = new QPushButton("Grid +", this);
    gridminus = new QPushButton("Grid -", this);
    gridplus->move(5,5);
    gridminus->move(5,40);
    gridplus->show();
    gridminus->show();

    // Makes buttons to decrease and increase size of the grid
    connect(gridplus, SIGNAL(clicked()), this, SLOT(incGridSize()));
    connect(gridminus, SIGNAL(clicked()), this, SLOT(decGridSize()));
    connect(this, SIGNAL(toChangeGridSize(qreal, qreal)), scene,SLOT(changeGridSize(qreal, qreal)));
}

ViewWithButtons::~ViewWithButtons()
{
    delete gridplus;
    delete gridminus;
}

void ViewWithButtons::incGridSize()
{
    emit toChangeGridSize(5, 5);
}

void ViewWithButtons::decGridSize()
{
    emit toChangeGridSize(-5, -5);
}