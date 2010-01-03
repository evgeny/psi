/*
 * accountregdlg.h
 * Copyright (C) 2001, 2002, 2006  Justin Karneges, Remko Troncon
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this library; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 *
 */

#ifndef NEWACCOUNTDLG_H
#define NEWACCOUNTDLG_H

#include <QDialog>
#include <QString>

#include "profiles.h"
#include "xmpp_jid.h"
#include "ui_newaccount.h"

class ProxyManager;
class ProxyChooser;
class QWidget;
class QScrollArea;
class QStringList;
class MiniClient;
class XDataWidget;
class ServerListQuerier;
namespace XMPP {
	class Form;
	class XData;
}

class NewAccountDlg : public QDialog
{
	Q_OBJECT
public:
	NewAccountDlg(ProxyManager*, QWidget *parent=0);
	~NewAccountDlg();

	const XMPP::Jid& jid() const { return jid_; }
	const QString& pass() const { return pass_; }
	bool useHost() const { return opt_host_; }
	const QString& host() const { return host_; }
	int port() const { return port_; }
	bool legacySSLProbe() { return legacy_ssl_probe_; }
	UserAccount::SSLFlag ssl() const { return ssl_; }
	QString proxy() const { return proxy_; }

protected slots:
	void next();

private:
	Ui::NewAccount ui_;
	ProxyManager *proxy_manager_;
;


	// Account settings
	XMPP::Jid jid_, server_;
	UserAccount::SSLFlag ssl_;
	bool opt_host_, legacy_ssl_probe_;
	QString host_;
	int port_;
	QString pass_;
	QString proxy_;
};

#endif
