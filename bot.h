#ifndef BOT_H
#define BOT_H

#include <QPair>
#include <QVector>
class QPushButton;

class Bot {
public:
    QPair<int, int> chooseMove(const QVector<QVector<QPushButton*>> &buttons,
                               const QString &botSymbol,
                               const QString &playerSymbol,
                               int winLength);

private:
    bool checkPotentialWin(const QVector<QVector<QPushButton*>> &buttons,
                           int row, int col, const QString &symbol,
                           int winLength);

    int scoreMove(const QVector<QVector<QPushButton*>> &buttons,
                  int row, int col, const QString &symbol,
                  int winLength);
};

#endif // BOT_H
