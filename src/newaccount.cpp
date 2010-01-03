#include <QtCrypto>
#include <QMessageBox>
#include <QScrollArea>
#include <QRegExpValidator>
#include <QRegExp>

#include "newaccount.h"
#include "proxy.h"
#include "serverlistquerier.h"
#include "miniclient.h"
#include "xmpp_tasks.h"
#include "psioptions.h"
#include "jidutil.h"
#include "textutil.h"
#include "xdata_widget.h"

using namespace XMPP;

NewAccountDlg::NewAccountDlg(ProxyManager *pm, QWidget *parent) : QDialog(parent)
{
	ui_.setupUi(this);
	setModal(false);

	// Initialize settings
	ssl_ = UserAccount::SSL_Auto;
	legacy_ssl_probe_ = true;
	port_=8090;
	if (!PsiOptions::instance()->getOption("options.account.host").toString().isEmpty()) {
		host_ = QString(PsiOptions::instance()->getOption("options.account.host").toString());
	}   
	
	//filter for password and username
	QRegExp rx("[a-zA-Z0-9\\.\\-\\_]+");
	QValidator *validator = new QRegExpValidator(rx, this);
	ui_.password->setValidator(validator);
	ui_.username->setValidator(validator);

	// Cancel and next buttons
	connect(ui_.pb_cancel, SIGNAL(clicked()), SLOT(close()));
	connect(ui_.pb_next, SIGNAL(clicked()), SLOT(next()));

	// Proxy
	proxy_manager_ = pm;
	proxy_ = "";

	server_ = JIDUtil::accountFromString("");
	opt_host_ = true;	
}

NewAccountDlg::~NewAccountDlg()
{
}


void NewAccountDlg::next()
{
	jid_ = Jid(ui_.username->text(), server_.bare(), "");
	pass_ = ui_.password->text();
	if (!pass_.isEmpty() && !(ui_.username->text()).isEmpty()){
//		PsiOptions::instance()->setOption("options.account.client-jid", jid_.bare());
//		PsiOptions::instance()->setOption("options.account.client-pass", pass_);
		accept();
	} else {
		ui_.info->setText("<font color=\"red\">Password and/or Username is empty</font>");
	}
}
