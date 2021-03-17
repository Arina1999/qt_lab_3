#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QFileSystemModel>

#include "FileStrategy.h"
#include "FolderStrategy.h"
#include "CustomFileModel.h"

//#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , strat1(new FileStrategy)
    , strat2(new FolderStrategy)
    , treeModel(new QFileSystemModel(this))
    , customModel(new CustomFileModel(this))
{
    ui->setupUi(this);

    ui->treeView->setModel(treeModel);
    ui->treeView->header()->setSectionResizeMode(QHeaderView::Stretch);
    ui->treeView->setRootIndex(treeModel->setRootPath(QDir::homePath()));

    ui->tableView->setModel(customModel);
    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    customModel->setStatisticsStrategy(strat1);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_treeView_clicked(const QModelIndex &index)
{
    if (index.isValid()) {
        customModel->UpdateStatistics(treeModel->filePath(index));
    }
}

void MainWindow::on_radioButton_toggled(bool checked)
{
    if (checked)
        customModel->setStatisticsStrategy(strat1);
}

void MainWindow::on_radioButton_2_clicked(bool checked)
{
    if (checked)
        customModel->setStatisticsStrategy(strat2);
}
