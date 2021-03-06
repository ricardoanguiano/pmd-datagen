#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
	printf("MainWindow startup\n");
    ui->setupUi(this);
    ui->myLabel->setText("Hello World");

	// Start the listener	
	server = new MyServer(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    exit(0);
}

void MainWindow::connectionStatusMainWindow(bool status)
{
    QDateTime dateTime = QDateTime::currentDateTime();
    QString dateTimeString = dateTime.toString("hh:mmap");
	QByteArray dateStrArray = dateTimeString.toUtf8();
	char *pstr = dateStrArray.data();
	printf("MainWindow::connectionStatusMainWindow() %s\n", (status == false) ? "disconnected" : "connected");
	printf("MainWindow::connectionStatusMainWindow(): %s\n", pstr); 
}

