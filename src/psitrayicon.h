#ifndef PSITRAYICON_H
#define PSITRAYICON_H

#include <QObject>
#include <QRgb>
#include <QPixmap>

class Icon;
class TrayIcon; // old
class QMenu;
class QSystemTrayIcon;
class QPoint;

class PsiTrayIcon : public QObject
{
	Q_OBJECT
public:
	PsiTrayIcon(const QString &tip, QMenu *popup, bool old = true, QObject *parent=0);
	~PsiTrayIcon();

	void setToolTip(const QString &);
	void setIcon(const Icon *, bool alert = false);
	void setAlert(const Icon *);
	bool isAnimating() const;

	bool isWMDock();

signals:
	void clicked(const QPoint &, int);
	void doubleClicked(const QPoint &);
	void closed();

public slots:
	void show();
	void hide();

private slots:
	void animate();

protected:
	QPixmap makeIcon();
	QRgb pixelBlend(QRgb p1, QRgb p2);

private:
	bool old_;
	Icon* icon_;
	TrayIcon* old_trayicon_; // old
	QSystemTrayIcon* trayicon_;
};


#endif