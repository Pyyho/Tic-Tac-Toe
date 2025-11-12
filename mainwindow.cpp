#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QQueue>
#include <QIcon>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow), gridLayout(new QGridLayout), bot()
{
    ui->setupUi(this);

    this->setWindowIcon(QIcon(":/icon.png"));

    QString neonStyle = R"(
        QWidget {
            background-color: #0d0d0d;
            color: #00f0ff;
            font-family: Consolas, monospace;
            font-size: 16px;
        }
        QPushButton {
            background-color: #000022;
            color: #00f0ff;
            border: 2px solid #00f0ff;
            border-radius: 10px;
            padding: 6px;
        }
        QPushButton:hover {
            background-color: #001133;
            border: 2px solid #39ff14;
            color: #39ff14;
        }
        QComboBox {
            background-color: #000022;
            color: #00f0ff;
            border: 2px solid #00f0ff;
            border-radius: 5px;
            padding: 4px;
        }
        QComboBox QAbstractItemView {
            background-color: #000022;
            color: #00f0ff;
            selection-background-color: #001133;
        }
    )";
    this->setStyleSheet(neonStyle);


    infiniteGameMode = false;
    connect(ui->infiniteGameButton, &QPushButton::clicked, this, [this]() {
        infiniteGameMode = true;
        ui->sizeBox->setCurrentText("3");
        ui->winBox->setCurrentText("3");
        ui->symbolBox->setCurrentText("X");
        on_startButton_clicked();
    });

    gridLayout = qobject_cast<QGridLayout*>(ui->boardContainer->layout());
    ui->sizeBox->addItems({"3", "4", "5", "6", "7"});
    ui->symbolBox->addItems({"X", "O"});
    connect(ui->sizeBox, &QComboBox::currentTextChanged, this, &MainWindow::updateWinOptions);
    updateWinOptions();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::updateWinOptions() {
    int maxWin = ui->sizeBox->currentText().toInt();
    ui->winBox->clear();
    for (int i = 3; i <= maxWin; ++i) {
        ui->winBox->addItem(QString::number(i));
    }
}

void MainWindow::on_startButton_clicked()
{
    clearBoard();
    boardSize = ui->sizeBox->currentText().toInt();
    winLength = ui->winBox->currentText().toInt();
    currentPlayer = ui->symbolBox->currentText();
    botPlayer = (currentPlayer == "X") ? "O" : "X";
    gameOver = false;
    createBoard();
    if (currentPlayer == "O")
        makeBotMove();
}

void MainWindow::createBoard() {
    clearBoard();
    buttons.resize(boardSize);
    for (int i = 0; i < boardSize; ++i) {
        buttons[i].resize(boardSize);
        for (int j = 0; j < boardSize; ++j) {
            QPushButton *btn = new QPushButton("");
            btn->setFixedSize(100, 100);
            btn->setStyleSheet("background-color: #0f0f3f; color: white; font-size: 60px;");
            gridLayout->addWidget(btn, i, j);
            buttons[i][j] = btn;
            connect(btn, &QPushButton::clicked, this, &MainWindow::handleCellClick);
        }
    }
}

void MainWindow::clearBoard() {
    QLayoutItem *item;
    while ((item = gridLayout->takeAt(0))) {
        delete item->widget();
        delete item;
    }
    buttons.clear();
}

void MainWindow::handleCellClick() {
    if (gameOver) return;
    QPushButton *btn = qobject_cast<QPushButton*>(sender());
    if (!btn || !btn->text().isEmpty()) return;
    if (infiniteGameMode) enforceSymbolLimit(currentPlayer);
    btn->setText(currentPlayer);
    symbolHistory[currentPlayer].enqueue(btn);
    if (checkWin(currentPlayer)) {
        QMessageBox::information(this, "Победа", currentPlayer + " победил!");
        gameOver = true;
        return;
    }
    makeBotMove();
}

void MainWindow::makeBotMove() {
    if (gameOver) return;
    QPair<int, int> move = bot.chooseMove(buttons, botPlayer, currentPlayer, winLength);
    if (move.first >= 0 && move.second >= 0) {
        QPushButton *btn = buttons[move.first][move.second];
        if (infiniteGameMode) enforceSymbolLimit(botPlayer);
        btn->setText(botPlayer);
        symbolHistory[botPlayer].enqueue(btn);
        if (checkWin(botPlayer)) {
            QMessageBox::information(this, "Поражение", botPlayer + " победил!");
            gameOver = true;
        }
    }
}

bool MainWindow::checkWin(const QString &symbol) {
    for (int r = 0; r < boardSize; ++r) {
        for (int c = 0; c < boardSize; ++c) {
            if (checkLine(r, c, 1, 0, symbol) ||
                checkLine(r, c, 0, 1, symbol) ||
                checkLine(r, c, 1, 1, symbol) ||
                checkLine(r, c, 1, -1, symbol)) return true;
        }
    }
    return false;
}

bool MainWindow::checkLine(int r, int c, int dr, int dc, const QString &symbol) {
    for (int i = 0; i < winLength; ++i) {
        int nr = r + i * dr, nc = c + i * dc;
        if (nr < 0 || nc < 0 || nr >= boardSize || nc >= boardSize) return false;
        if (buttons[nr][nc]->text() != symbol) return false;
    }
    for (int i = 0; i < winLength; ++i) {
        int nr = r + i * dr, nc = c + i * dc;
        buttons[nr][nc]->setStyleSheet("background-color: #00cc66; color: black; font-weight: bold; font-size: 60px;");
    }
    return true;
}


void MainWindow::enforceSymbolLimit(const QString &symbol) {
    auto &queue = symbolHistory[symbol];
    QQueue<QPushButton*> updated;
    for (QPushButton *btn : queue) {
        if (btn->text() == symbol)
            updated.enqueue(btn);
    }
    queue = updated;
    if (queue.size() >= 3) {
        QPushButton* toRemove = queue.dequeue();
        if (toRemove)
            toRemove->setText("");
    }
}
