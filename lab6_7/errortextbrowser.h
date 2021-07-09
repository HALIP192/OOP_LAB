#ifndef ERRORTEXTBROWSER_H
#define ERRORTEXTBROWSER_H

#include <QTextBrowser>
#include <QTextEdit>

class ErrorTextBrowser
        : public QTextBrowser
{
public:
    void WriteError(const QString& word);
    ErrorTextBrowser(QWidget*& q) : QTextBrowser(q) { }
};

#endif // ERRORTEXTBROWSER_H
