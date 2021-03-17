#ifndef FILESTATMODEL_H
#define FILESTATMODEL_H

#include <QAbstractTableModel>
#include <QSharedPointer>
class AbstractStrategy;

class CustomFileModel : public QAbstractTableModel
{
    Q_OBJECT
public:
    explicit CustomFileModel(QObject *parent = nullptr);

    void setStatisticsStrategy(const QSharedPointer<AbstractStrategy> &strategy);

    int columnCount(const QModelIndex &parent = QModelIndex()) const override;

    int rowCount(const QModelIndex &parent = QModelIndex()) const override;

    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

public slots:
    void UpdateStatistics(const QString& path);

private:
    QSharedPointer<AbstractStrategy> strategy_ = nullptr;
    QMap<QString, double> stats_;
    QString path_;
};

#endif // FILESTATMODEL_H
