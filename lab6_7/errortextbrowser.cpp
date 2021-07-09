#include "errortextbrowser.h"

void ErrorTextBrowser::WriteError(const QString& word) {
    setTextColor(QColor(255, 0, 0));
    append(word);
    setTextColor(QColor(122,122,122));
}
