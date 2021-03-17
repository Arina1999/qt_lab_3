#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class AbstractStrategy;
class CustomFileModel;
class QFileSystemModel;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_treeView_clicked(const QModelIndex &index);

    void on_radioButton_toggled(bool checked);

    void on_radioButton_2_clicked(bool checked);

private:
    Ui::MainWindow *ui;
    QSharedPointer<AbstractStrategy> strat1;
    QSharedPointer<AbstractStrategy> strat2;
    QFileSystemModel *treeModel;
    CustomFileModel* customModel;
};

#endif // MAINWINDOW_H
