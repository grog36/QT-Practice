#include <QtWidgets>
#include <string>
#include "mainwidget.h"

//Constructor for main widget
MainWidget::MainWidget(QWidget* parent) : QWidget(parent) {

	//Creates the buttons
	topLeftButton = new QPushButton();
	topMiddleButton = new QPushButton();
	topRightButton = new QPushButton();
	middleLeftButton = new QPushButton();
	centerButton = new QPushButton();
	middleRightButton = new QPushButton();
	bottomLeftButton = new QPushButton();
	bottomMiddleButton = new QPushButton();
	bottomRightButton = new QPushButton();
	
	//Creates an array for the buttons
	QPushButton* buttons[9];
	buttons[0] = topLeftButton;
	buttons[1] = topMiddleButton;
	buttons[2] = topRightButton;
	buttons[3] = middleLeftButton;
	buttons[4] = centerButton;
	buttons[5] = middleRightButton;
	buttons[6] = bottomLeftButton;
	buttons[7] = bottomMiddleButton;
	buttons[8] = bottomRightButton;

	//Changes the styles of the buttons
	for (int i = 0; i < 9; i++) {
		buttons[i]->setStyleSheet("background-color: white; color: black");
	}

	//Lays them out
	QGridLayout* mainLayout = new QGridLayout;
	mainLayout->addWidget(topLeftButton, 0, 0);
	mainLayout->addWidget(topMiddleButton, 0, 1);
	mainLayout->addWidget(topRightButton, 0, 2);
	mainLayout->addWidget(middleLeftButton, 1, 0);
	mainLayout->addWidget(centerButton, 1, 1);
	mainLayout->addWidget(middleRightButton, 1, 2);
	mainLayout->addWidget(bottomLeftButton, 2, 0);
	mainLayout->addWidget(bottomMiddleButton, 2, 1);
	mainLayout->addWidget(bottomRightButton, 2, 2);

	//Adjust column & row sizes
	mainLayout->setColumnStretch(0, 1);
	mainLayout->setColumnStretch(1, 1);
	mainLayout->setColumnStretch(2, 1);
	mainLayout->setRowStretch(0, 1);
	mainLayout->setRowStretch(1, 1);
	mainLayout->setRowStretch(2, 1);
	

	//Main window details
	setLayout(mainLayout);
	setWindowTitle(tr("Greg's Tic-Tac-Toe!"));

	//Connect the Buttons' "released" signal to MainWidget's onButtonReleased method.
	connect(topLeftButton, SIGNAL(pressed()), this, SLOT(pressTopLeftButton()));
	connect(topMiddleButton, SIGNAL(pressed()), this, SLOT(pressTopMiddleButton()));
	connect(topRightButton, SIGNAL(pressed()), this, SLOT(pressTopRightButton()));
	connect(middleLeftButton, SIGNAL(pressed()), this, SLOT(pressMiddleLeftButton()));
	connect(centerButton, SIGNAL(pressed()), this, SLOT(pressCenterButton()));
	connect(middleRightButton, SIGNAL(pressed()), this, SLOT(pressMiddleRightButton()));
	connect(bottomLeftButton, SIGNAL(pressed()), this, SLOT(pressBottomLeftButton()));
	connect(bottomMiddleButton, SIGNAL(pressed()), this, SLOT(pressBottomMiddleButton()));
	connect(bottomRightButton, SIGNAL(pressed()), this, SLOT(pressBottomRightButton()));
	
	//Creates the game
	game = new Game(1);
}

//Destructor
MainWidget::~MainWidget() {
	delete buttons;
	delete topLeftButton;
	delete topMiddleButton;
	delete topRightButton;
	delete middleLeftButton;
	delete centerButton;
	delete middleRightButton;
	delete bottomLeftButton;
	delete bottomMiddleButton;
	delete bottomRightButton;
}

//Handlers for button press
void MainWidget::pressTopLeftButton() {
	game->playMove(0, 0);
	updateScreen();
}
void MainWidget::pressTopMiddleButton() {
	game->playMove(0, 1);
	updateScreen();
}
void MainWidget::pressTopRightButton() {
	game->playMove(0, 2);
	updateScreen();
}
void MainWidget::pressMiddleLeftButton() {
	game->playMove(1, 0);
	updateScreen();
}
void MainWidget::pressCenterButton() {
	game->playMove(1, 1);
	updateScreen();
}
void MainWidget::pressMiddleRightButton() {
	game->playMove(1, 2);
	updateScreen();
}
void MainWidget::pressBottomLeftButton() {
	game->playMove(2, 0);
	updateScreen();
}
void MainWidget::pressBottomMiddleButton() {
	game->playMove(2, 1);
	updateScreen();
}
void MainWidget::pressBottomRightButton() {
	game->playMove(2, 2);
	updateScreen();
}

//Updates the screen for the given board position
void MainWidget::updateScreen() {
	topLeftButton->setText(QString::fromStdString(std::string(1, game->getPlayerMarkerAt(0, 0))));
	topMiddleButton->setText(QString::fromStdString(std::string(1, game->getPlayerMarkerAt(0, 1))));
	topRightButton->setText(QString::fromStdString(std::string(1, game->getPlayerMarkerAt(0, 2))));
	middleLeftButton->setText(QString::fromStdString(std::string(1, game->getPlayerMarkerAt(1, 0))));
	centerButton->setText(QString::fromStdString(std::string(1, game->getPlayerMarkerAt(1, 1))));
	middleRightButton->setText(QString::fromStdString(std::string(1, game->getPlayerMarkerAt(1, 2))));
	bottomLeftButton->setText(QString::fromStdString(std::string(1, game->getPlayerMarkerAt(2, 0))));
	bottomMiddleButton->setText(QString::fromStdString(std::string(1, game->getPlayerMarkerAt(2, 1))));
	bottomRightButton->setText(QString::fromStdString(std::string(1, game->getPlayerMarkerAt(2, 2))));
}
