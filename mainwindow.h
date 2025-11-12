#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGridLayout>
#include <QPushButton>
#include <QQueue>
#include <QMap>
#include <QComboBox>
#include <QLabel>
#include "bot.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_startButton_clicked();
    void handleCellClick();
    void updateWinOptions();

private:
    bool infiniteGameMode;
    QMap<QString, QQueue<QPushButton*>> symbolHistory;
    void enforceSymbolLimit(const QString &symbol);
    Ui::MainWindow *ui;
    QVector<QVector<QPushButton*>> buttons;
    QGridLayout *gridLayout;
    QString currentPlayer;
    QString botPlayer;
    int boardSize;
    int winLength;
    bool gameOver;
    Bot bot;

    void createBoard();
    void clearBoard();
    void makeBotMove();
    bool checkWin(const QString &symbol);
    bool checkLine(int r, int c, int dr, int dc, const QString &symbol);
};

#endif // MAINWINDOW_H