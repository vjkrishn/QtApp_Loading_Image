#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_button_image_clicked()
{
    QString filename = QFileDialog::getOpenFileName(this,tr("Choose"),"",tr("Images(*.png *.jpg *.bmp *.jpeg *.gif)"));

    if(QString::compare(filename,QString())!=0)
    {
        QImage image;
        bool valid = image.load(filename);

        if(valid)
        {
            image = image.scaledToWidth(ui->label_image->width(),Qt::SmoothTransformation);
            image = image.scaledToHeight(ui->label_image->height(),Qt::SmoothTransformation);
            ui->label_image->setPixmap(QPixmap::fromImage(image));
        }
        else
        {
            //Error handling
        }
    }
}
