#include "opt_midi.h"

#include <qbuttongroup.h>
#include <qwhatsthis.h>
#include <qcheckbox.h>
#include <qradiobutton.h>
#include <qcombobox.h>
#include <qlineedit.h>
#include <qfiledialog.h>
#include <qlabel.h>

#include "common.h"
#include "iconwidget.h"
#include "iconset.h"
#include "applicationinfo.h"
#include "psioptions.h"
#include "fileutil.h"

#include "ui_opt_midi.h"

class OptMidiUI : public QWidget, public Ui::OptMidi
{
public:
	OptMidiUI() : QWidget() { setupUi(this); }
};

//----------------------------------------------------------------------------
// OptionsTabMidi
//----------------------------------------------------------------------------

OptionsTabMidi::OptionsTabMidi(QObject *parent)
: OptionsTab(parent, "midi", "", tr("Midi"), tr("Midi Configuration"), "psi/playSounds")
{
	w = 0;
	//bg_se = bg_sePlay = 0;
}

OptionsTabMidi::~OptionsTabMidi()
{
//	if ( bg_se )
//		delete bg_se;
//	if ( bg_sePlay )
//		delete bg_sePlay;
}

QWidget *OptionsTabMidi::widget()
{
	if ( w )
		return 0;

	w = new OptMidiUI();
	OptMidiUI *d = (OptMidiUI *)w;
/**
	sounds_ << d->le_oeMessage << d->le_oeChat1 << d->le_oeChat2 << d->le_oeHeadline << d->le_oeSystem << d->le_oeOnline << d->le_oeOffline << d->le_oeSend << d->le_oeIncomingFT << d->le_oeFTComplete;

	bg_se = new QButtonGroup;
	bg_se->insert(d->tb_seMessage);
	modify_buttons_[d->tb_seMessage] = d->le_oeMessage;
	bg_se->insert(d->tb_seChat1);
	modify_buttons_[d->tb_seChat1] = d->le_oeChat1;
	bg_se->insert(d->tb_seChat2);
	modify_buttons_[d->tb_seChat2] = d->le_oeChat2;
	bg_se->insert(d->tb_seHeadline);
	modify_buttons_[d->tb_seHeadline] = d->le_oeHeadline;
	bg_se->insert(d->tb_seSystem);
	modify_buttons_[d->tb_seSystem] = d->le_oeSystem;
	bg_se->insert(d->tb_seOnline);
	modify_buttons_[d->tb_seOnline] = d->le_oeOnline;
	bg_se->insert(d->tb_seOffline);
	modify_buttons_[d->tb_seOffline] = d->le_oeOffline;
	bg_se->insert(d->tb_seSend);
	modify_buttons_[d->tb_seSend] = d->le_oeSend;
	bg_se->insert(d->tb_seIncomingFT);
	modify_buttons_[d->tb_seIncomingFT] = d->le_oeIncomingFT;
	bg_se->insert(d->tb_seFTComplete);
	modify_buttons_[d->tb_seFTComplete] = d->le_oeFTComplete;
	connect(bg_se, SIGNAL(buttonClicked(QAbstractButton*)), SLOT(chooseSoundEvent(QAbstractButton*)));

	bg_sePlay = new QButtonGroup;
	bg_sePlay->insert(d->tb_seMessagePlay);
	play_buttons_[d->tb_seMessagePlay] = d->le_oeMessage;
	bg_sePlay->insert(d->tb_seChat1Play);
	play_buttons_[d->tb_seChat1Play] = d->le_oeChat1;
	bg_sePlay->insert(d->tb_seChat2Play);
	play_buttons_[d->tb_seChat2Play] = d->le_oeChat2;
	bg_sePlay->insert(d->tb_seHeadlinePlay);
	play_buttons_[d->tb_seHeadlinePlay] = d->le_oeHeadline;
	bg_sePlay->insert(d->tb_seSystemPlay);
	play_buttons_[d->tb_seSystemPlay] = d->le_oeSystem;
	bg_sePlay->insert(d->tb_seOnlinePlay);
	play_buttons_[d->tb_seOnlinePlay] = d->le_oeOnline;
	bg_sePlay->insert(d->tb_seOfflinePlay);
	play_buttons_[d->tb_seOfflinePlay] = d->le_oeOffline;
	bg_sePlay->insert(d->tb_seSendPlay);
	play_buttons_[d->tb_seSendPlay] = d->le_oeSend;
	bg_sePlay->insert(d->tb_seIncomingFTPlay);
	play_buttons_[d->tb_seIncomingFTPlay] = d->le_oeIncomingFT;
	bg_sePlay->insert(d->tb_seFTCompletePlay);
	play_buttons_[d->tb_seFTCompletePlay] = d->le_oeFTComplete;
	connect(bg_sePlay, SIGNAL(buttonClicked(QAbstractButton*)), SLOT(previewSoundEvent(QAbstractButton*)));

	connect(d->pb_soundReset, SIGNAL(clicked()), SLOT(soundReset()));

	// set up proper tool button icons
	int n;
	for (n = 0; n < 10; n++) {
		IconToolButton *tb = (IconToolButton *)bg_se->buttons()[n];
		tb->setPsiIcon( IconsetFactory::iconPtr("psi/browse") );
		tb = (IconToolButton *)bg_sePlay->buttons()[n];
		tb->setPsiIcon( IconsetFactory::iconPtr("psi/play") );
	}

	// TODO: add QWhatsThis for all widgets

	QWhatsThis::add(d->le_player,
		tr("If your system supports multiple sound players, you may"
		" choose your preferred sound player application here."));
	QWhatsThis::add(d->ck_awaySound,
		tr("Enable this option if you wish to hear sound alerts when your status is \"away\" or \"extended away\"."));
	QWhatsThis::add(d->ck_gcSound,
		tr("Play sounds for all events in groupchat, not only for mentioning of your nick."));

#if defined(Q_WS_WIN)
	d->lb_player->hide();
	d->le_player->hide();
#elif defined(Q_WS_MAC)
	d->lb_player->hide();
	d->le_player->hide();
#endif
*/
	return w;
}

void OptionsTabMidi::applyOptions()
{
	if ( !w )
		return;

	OptMidiUI *d = (OptMidiUI *)w;

	PsiOptions::instance()->setOption("options.account.host", d->xmpp_host->text());
	PsiOptions::instance()->setOption("options.account.port", d->xmpp_port->text());
	PsiOptions::instance()->setOption("options.account.server-jid", d->server_jid->text());
	PsiOptions::instance()->setOption("options.ui.midi.midi-queue-delay-ms", d->queue_delay->text());
	PsiOptions::instance()->setOption("options.ui.midi.send-batch-period-ms", d->batch_period->text());
	PsiOptions::instance()->setOption("options.ui.midi.keepintouch-period-s", d->in_touch_period->text());
	PsiOptions::instance()->setOption("options.ui.midi.xmpp-reconnect-inerval-s", d->reconnect_interval->text());
	
//	PsiOptions::instance()->setOption("options.midi-setting.midi-in-port-id", d->lineEdit->text());
//	PsiOptions::instance()->setOption("options.midi-setting.midi-out-port-id", d->lineEdit_2->text());
}

void OptionsTabMidi::restoreOptions()
{
	if ( !w )
		return;

	OptMidiUI *d = (OptMidiUI *)w;
/**
#if defined(Q_WS_WIN)
	d->le_player->setText(tr("Windows Sound"));
#elif defined(Q_WS_MAC)
	d->le_player->setText(tr("Mac OS Sound"));
#else
	d->le_player->setText( PsiOptions::instance()->getOption("options.ui.notifications.sounds.unix-sound-player").toString() );
#endif

	d->ck_awaySound->setChecked( !PsiOptions::instance()->getOption("options.ui.notifications.sounds.silent-while-away").toBool() );
	d->ck_gcSound->setChecked( PsiOptions::instance()->getOption("options.ui.notifications.sounds.notify-every-muc-message").toBool() );
*/
	d->queue_delay->setValue(PsiOptions::instance()->getOption("options.ui.midi.midi-queue-delay-ms").toInt());
	d->batch_period->setValue(PsiOptions::instance()->getOption("options.ui.midi.send-batch-period-ms").toInt());
	d->in_touch_period->setValue(PsiOptions::instance()->getOption("options.ui.midi.keepintouch-period-s").toInt());
	d->reconnect_interval->setValue(PsiOptions::instance()->getOption("options.ui.midi.xmpp-reconnect-inerval-s").toInt());
	d->server_jid->setText(PsiOptions::instance()->getOption("options.account.server-jid").toString());
	d->xmpp_host->setText(PsiOptions::instance()->getOption("options.account.host").toString());
	d->xmpp_port->setText(PsiOptions::instance()->getOption("options.account.port").toString());
}
/**
void OptionsTabSound::setData(PsiCon *, QWidget *p)
{
	parentWidget = p;
}

void OptionsTabSound::chooseSoundEvent(QAbstractButton* b)
{
	QString str = FileUtil::getOpenFileName(parentWidget,
	                                        tr("Choose a sound file"),
	                                        tr("Sound (*.wav)"));
	if (!str.isEmpty()) {
		modify_buttons_[b]->setText(str);
		emit dataChanged();
	}
}

void OptionsTabSound::previewSoundEvent(QAbstractButton* b)
{
	soundPlay(play_buttons_[b]->text());
}

void OptionsTabSound::soundReset()
{
	OptSoundUI *d = (OptSoundUI *)w;
	
	d->le_oeMessage->setText("sound/chat2.wav");
	d->le_oeChat1->setText("sound/chat1.wav");
	d->le_oeChat2->setText("sound/chat2.wav");
	d->le_oeSystem->setText("sound/chat2.wav");
	d->le_oeHeadline->setText("sound/chat2.wav");
	d->le_oeOnline->setText("sound/online.wav");
	d->le_oeOffline->setText("sound/offline.wav");
	d->le_oeSend->setText("sound/send.wav");
	d->le_oeIncomingFT->setText("sound/ft_incoming.wav");
	d->le_oeFTComplete->setText("sound/ft_complete.wav");
	emit dataChanged();
}
*/
