#ifndef ABSTRACTSTRATEGY_H
#define ABSTRACTSTRATEGY_H

#include <QString>
#include <QHash>

class AbsrtractStrategy
{
public:
    virtual ~AbsrtractStrategy(){}

    virtual void CalcStatistics(const QString& path) = 0;

    QHash<QString, double> GetStats() const  {
        return stats_;
    }

protected:
    QHash<QString, double> stats_;
};


#endif // ABSTRACTSTRATEGY_H
