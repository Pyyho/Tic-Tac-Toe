#include "bot.h"
#include <QPushButton>
#include <QMap>
#include <algorithm>

QPair<int, int> Bot::chooseMove(const QVector<QVector<QPushButton*>> &buttons, const QString &botSymbol, const QString &playerSymbol, int winLength) {
    int n = buttons.size();
    int bestScore = -1;
    QPair<int, int> bestMove = {-1, -1};

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (buttons[i][j]->text().isEmpty()) {
                // Победа
                buttons[i][j]->setText(botSymbol);
                if (checkPotentialWin(buttons, i, j, botSymbol, winLength)) {
                    buttons[i][j]->setText("");
                    return {i, j};
                }
                buttons[i][j]->setText("");

                // Блокировка игрока
                buttons[i][j]->setText(playerSymbol);
                if (checkPotentialWin(buttons, i, j, playerSymbol, winLength)) {
                    buttons[i][j]->setText("");
                    return {i, j};
                }
                buttons[i][j]->setText("");

                // Оценка позиции
                int score = scoreMove(buttons, i, j, botSymbol, winLength);
                if (score > bestScore) {
                    bestScore = score;
                    bestMove = {i, j};
                }
            }
        }
    }

    return bestMove;
}

bool Bot::checkPotentialWin(const QVector<QVector<QPushButton*>> &buttons, int row, int col, const QString &symbol, int winLength) {
    int n = buttons.size();
    const QVector<QPair<int, int>> directions = {{1,0},{0,1},{1,1},{1,-1}};
    for (auto [dr, dc] : directions) {
        int count = 1;
        for (int k = 1; k < winLength; ++k) {
            int r = row + k * dr, c = col + k * dc;
            if (r >= 0 && r < n && c >= 0 && c < n && buttons[r][c]->text() == symbol)
                count++;
            else
                break;
        }
        for (int k = 1; k < winLength; ++k) {
            int r = row - k * dr, c = col - k * dc;
            if (r >= 0 && r < n && c >= 0 && c < n && buttons[r][c]->text() == symbol)
                count++;
            else
                break;
        }
        if (count >= winLength) return true;
    }
    return false;
}

int Bot::scoreMove(const QVector<QVector<QPushButton*>> &buttons, int row, int col, const QString &symbol, int winLength) {
    int n = buttons.size();
    int score = 0;
    const QVector<QPair<int, int>> directions = {{1,0},{0,1},{1,1},{1,-1}};

    for (auto [dr, dc] : directions) {
        int count = 1;
        int blanks = 0;
        for (int k = 1; k < winLength; ++k) {
            int r = row + k * dr, c = col + k * dc;
            if (r >= 0 && r < n && c >= 0 && c < n) {
                if (buttons[r][c]->text() == symbol)
                    count++;
                else if (buttons[r][c]->text().isEmpty())
                    blanks++;
                else
                    break;
            }
        }
        for (int k = 1; k < winLength; ++k) {
            int r = row - k * dr, c = col - k * dc;
            if (r >= 0 && r < n && c >= 0 && c < n) {
                if (buttons[r][c]->text() == symbol)
                    count++;
                else if (buttons[r][c]->text().isEmpty())
                    blanks++;
                else
                    break;
            }
        }
        if (count + blanks >= winLength)
            score += count * count;
    }

    return score;
}
