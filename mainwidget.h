#ifndef MAINWIDGET_H //Ensures header only gets included by compiler once
#define MAINWIDGET_H //Necessary because class is derived from QWidget

#include <QWidget>
#include <QProcess>
#include <QMessageBox>
#include "game.h"

//"Creates" classes to be used by MainWidget class (only holds pointers)
//Forward Declaration
class QPushButton;
class QTextBrowser;

//This is the declaration of our MainWidget class
//The definition/implementation is in mainwidget.cpp
class MainWidget : public QWidget {
	Q_OBJECT //Pre-processor macro used by QT build tools

	public:
		explicit MainWidget(QWidget* parent = 0); //Constructor
		~MainWidget(); //Destructor;
	private:
		//Buttons
		QPushButton** buttons;
		QPushButton* topLeftButton;
		QPushButton* topMiddleButton;
		QPushButton* topRightButton;
		QPushButton* middleLeftButton;
		QPushButton* centerButton;
		QPushButton* middleRightButton;
		QPushButton* bottomLeftButton;
		QPushButton* bottomMiddleButton;
		QPushButton* bottomRightButton;
		//Dialog
		QMessageBox* dialogBox;
		QPushButton* dialogButton;
		//Process
		QProcess process_;
		//Other functions and fields
		Game* game;
		void updateScreen();

	private slots:
		void pressTopLeftButton();
		void pressTopMiddleButton();
		void pressTopRightButton();
		void pressMiddleLeftButton();
		void pressCenterButton();
		void pressMiddleRightButton();
		void pressBottomLeftButton();
		void pressBottomMiddleButton();
		void pressBottomRightButton();
		void playAgain();
};

#endif // MAINWIDGET_H
