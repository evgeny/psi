#ifndef OPT_MIDI_H
#define OPT_MIDI_H

#include <QMap>

#include "optionstab.h"

class QWidget;
class QLineEdit;
class QButtonGroup;
class QAbstractButton;

class OptionsTabMidi : public OptionsTab
{
	Q_OBJECT
public:
	OptionsTabMidi(QObject *parent);
	~OptionsTabMidi();

	QWidget *widget();
	void applyOptions();
	void restoreOptions();
/**
private slots:
	void chooseSoundEvent(QAbstractButton*);
	void previewSoundEvent(QAbstractButton*);
	void soundReset();
	void setData(PsiCon *, QWidget *);
*/
private:
	QWidget *w, *parentWidget;
//	QList<QLineEdit*> sounds_;
//	QMap<QAbstractButton*,QLineEdit*> modify_buttons_;
//	QMap<QAbstractButton*,QLineEdit*> play_buttons_;
//	QButtonGroup *bg_se, *bg_sePlay;
};

#endif
