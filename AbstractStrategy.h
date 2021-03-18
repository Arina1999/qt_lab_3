#ifndef ABSTRACTSTRATEGY_H
#define ABSTRACTSTRATEGY_H

#include <QString>
#include <QMap>

class AbstractStrategy
{
public:
    virtual ~AbstractStrategy(){}

    virtual void CalcStatistics(const QString& path) = 0;

    QMap<QString, double> GetStats() const  {
        return stats_;
    }

protected:
    QMap<QString, double> stats_;
};


#endif // ABSTRACTSTRATEGY_H
