#ifndef KAKOUNEWINDOW_H
#define KAKOUNEWINDOW_H

#include "kakouneclient.h"
#include "rpc.h"
#include <QtWidgets>

class KakouneWidget : public QWidget {
    Q_OBJECT
public:
    KakouneWidget(QWidget* parent=nullptr);
    ~KakouneWidget();
protected:
	void paintEvent(QPaintEvent* ev) override;
	void keyPressEvent(QKeyEvent* ev) override;
	void resizeEvent(QResizeEvent* ev) override;
private slots:
    void handleRequest(QJsonObject request);
private:
    void setFont(const QString& font_name, int font_size);

    QColor getColor(RPC::Color color, RPC::Color default_color);
    void drawAtom(QPainter& painter, RPC::Atom atom, QPoint position, const RPC::Face& default_face);
    void drawLine(QPainter& painter, RPC::Line line, QPoint position, const RPC::Face& default_face);

    KakouneClient* m_client;

    QFont m_font;
    QSize m_cell_size;

    QList<RPC::Line> m_lines;
    RPC::Face m_default_face;
    RPC::Face m_padding_face;

    RPC::Line m_status_line;
    RPC::Line m_mode_line;
    RPC::Face m_status_default_face;
};

#endif
