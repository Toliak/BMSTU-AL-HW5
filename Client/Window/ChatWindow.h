#pragma once

#include <QMainWindow>
#include <QLabel>

#include "ChatLabel.h"

namespace Ui
{
class ChatWindow;
}

/**
 * @brief Main chat window
 */
class ChatWindow: public QMainWindow
{
Q_OBJECT

public:
    /**
     * @brief Window constructor
     * @param connection Connection to chat server
     * @param parent QT Parent
     */
    explicit ChatWindow(ChatConnection *connection, QWidget *parent = nullptr);

    ~ChatWindow() override;

    /**
     * @brief Create label with message
     * @param text Message
     * @warning You must delete return object to prevent memory leak
     * @return Label pointer
     */
    static ChatLabel *createMessageLabel(const QString &text);

protected:
    void resizeEvent(QResizeEvent* event) override;

private slots:
    void on_send_clicked();
    void on_message_returnPressed();
    void on_message_textChanged(const QString &text);

private:
    void onChatMessage(const QJsonObject &data);
    void onErrorMessage(const QJsonObject &data);

    ChatConnection *connection;
    Ui::ChatWindow *ui;
};