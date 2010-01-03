#include <QApplication>
#include <QtGui>
#include <QLayout>
#include <QStyle>

class TitleBar : public QFrame
{
    Q_OBJECT
public:
    TitleBar(QWidget *parent, QString *title);
    
public slots:
    void showSmall();
    
    void showMaxRestore();

	void setTitle(QString);
    
protected:
    void mousePressEvent(QMouseEvent *me);
    
    void mouseMoveEvent(QMouseEvent *me);
	void mouseDoubleClickEvent ( QMouseEvent * e );

private:
	QLabel *label; 
    QToolButton *minimize;
    QToolButton *maximize;
    QToolButton *close;
    QPixmap restorePix, maxPix;
    bool maxNormal;
    QPoint startPos;
    QPoint clickPos;
};
