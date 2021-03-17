#include "CustomFileModel.h"
#include "AbstractStrategy.h"

#include <QFileInfo>

CustomFileModel::CustomFileModel(QObject *parent)
    : QAbstractTableModel(parent)
{ }

void CustomFileModel::setStatisticsStrategy(const QSharedPointer<AbstractStrategy> &strategy)
{
    strategy_ = strategy;
    UpdateStatistics(path_);
}

void CustomFileModel::UpdateStatistics(const QString &path)
{
    path_ = path;
    beginResetModel();
    strategy_->CalcStatistics(path);
    stats_ = strategy_->GetStats();
    endResetModel();
}

int CustomFileModel::columnCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent)
    return 2;
}

int CustomFileModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent)
    return stats_.count();
}

QVariant CustomFileModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (orientation == Qt::Horizontal) {
        if (section == 0 && role == Qt::DisplayRole)
            return "Name";

        if (section == 1 && role == Qt::DisplayRole)
            return "Percentage";
    }

    return QAbstractTableModel::headerData(section, orientation, role);
}

QVariant CustomFileModel::data(const QModelIndex &index, int role) const
{
    if (index.isValid() && role == Qt::DisplayRole) {
        if (index.column() == 0) {
            return QFileInfo(stats_.keys()[index.row()]).completeBaseName();
        }

        if (index.column() == 1) {
            double val = 100. * stats_.values()[index.row()];
            if (val < 0.01)
                return "< 0.01%";

            return QString::number(val, 'f', 2) + "%";
        }
    }

    return QVariant();
}
