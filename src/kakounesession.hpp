#ifndef KAKOUNESESSION_HPP
#define KAKOUNESESSION_HPP

#include <QtWidgets>

class KakouneSession : public QObject
{
    Q_OBJECT
  public:
    KakouneSession();
    KakouneSession(QString session_id);
    ~KakouneSession();

    QString getSessionId();
    void setSessionId(const QString &session_id);

  private:
    QProcess m_process;
    QString m_session_id;
};

#endif
