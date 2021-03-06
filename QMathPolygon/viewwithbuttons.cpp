#include "viewwithbuttons.h"

ViewWithButtons::ViewWithButtons(CoordPlaneScene *scene, QWidget *parent)
    :CoordPlaneView(scene,parent)
{
    // Adds buttons above the view
    QPushButton* gridplus = new QPushButton("Grid +", this);
    QPushButton* gridminus = new QPushButton("Grid -", this);
    gridplus->move(5,5);
    gridminus->move(5,40);
    gridplus->show();
    gridminus->show();

    // Makes buttons to decrease and increase size of the grid by 5 for ecah click
    connect(gridplus, SIGNAL(clicked()), this, SLOT(incGridSize()));
    connect(gridminus, SIGNAL(clicked()), this, SLOT(decGridSize()));
    connect(this, SIGNAL(toChangeGridSize(qreal, qreal)), scene,SLOT(changeGridSize(qreal, qreal)));
}


void ViewWithButtons::incGridSize()
{
    emit toChangeGridSize(5, 5);
}

void ViewWithButtons::decGridSize()
{
    emit toChangeGridSize(-5, -5);
}
