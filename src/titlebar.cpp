#include <QApplication>
#include <QtGui>
#include <QLayout>
#include <QStyle>
#include <titlebar.h>


TitleBar::TitleBar(QWidget *parent, QString* title)
    {
        // Don't let this widget inherit the parent's backround color
//	setAutoFillBackground(true);
        // Use a brush with a Highlight color role to render the background 
    setBackgroundRole(QPalette::NoRole);
     
    minimize = new QToolButton(this);
	minimize->setObjectName("minimizeButton");
    maximize = new QToolButton(this);
	maximize->setObjectName("maximizeButton");
    close = new QToolButton(this);
	close->setObjectName("closeButton");
        
    // Use the style to set the button pixmaps
    QPixmap pix = style()->standardPixmap(QStyle::SP_TitleBarCloseButton);
	close->setIcon(pix);
	close->setAutoRaise(true);
        
    maxPix = style()->standardPixmap(QStyle::SP_TitleBarMaxButton);
    maximize->setIcon(maxPix);

	maximize->setAutoRaise(true);

        
    pix = style()->standardPixmap(QStyle::SP_TitleBarMinButton);
    minimize->setIcon(pix);
	minimize->setAutoRaise(true);

	restorePix = style()->standardPixmap(QStyle::SP_TitleBarNormalButton);
        
//    minimize->setMinimumHeight(20);
//    close->setMinimumHeight(20);
//    maximize->setMinimumHeight(20);
        
    label = new QLabel(this);
	label->setAttribute(Qt::WA_Disabled);
        
    QHBoxLayout *hbox = new QHBoxLayout(this);
    hbox->setContentsMargins ( 0,0,0,0 );  
    hbox->addWidget(label);
    hbox->addWidget(minimize, 0, Qt::AlignTop);
    hbox->addWidget(maximize, 0, Qt::AlignTop);
	hbox->addWidget(close, 0, Qt::AlignTop);
        
    hbox->insertStretch(1, 500);
    hbox->setSpacing(0);
    setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
        
    maxNormal = false;
        
    connect(close, SIGNAL( clicked() ), parent->parentWidget(), SLOT(close() ) );
    connect(minimize, SIGNAL( clicked() ), this, SLOT(showSmall() ) );
    connect(maximize, SIGNAL( clicked() ), this, SLOT(showMaxRestore() ) );
}
    
void TitleBar::showSmall()
{
    parentWidget()->parentWidget()->showMinimized();
}
    
void TitleBar::showMaxRestore()
{
	if (maxNormal) {
		parentWidget()->parentWidget()->showNormal();
        maxNormal = !maxNormal;
        maximize->setIcon(maxPix);
    } else {
        parentWidget()->parentWidget()->showMaximized();
        maxNormal = !maxNormal;
        maximize->setIcon(restorePix);
    }
}

void TitleBar::mousePressEvent(QMouseEvent *me)
{
	startPos = me->globalPos();
	clickPos = mapToParent(me->pos());
}

void TitleBar::mouseMoveEvent(QMouseEvent *me)
{
    if (maxNormal)
        return;
    parentWidget()->parentWidget()->move(me->globalPos() - clickPos);
}

void TitleBar::mouseDoubleClickEvent ( QMouseEvent * e )
{
	showMaxRestore();
}

void TitleBar::setTitle(QString title)
{
	label->setText(title);
	QFont font("Helvetica", 10, QFont::Bold);
    label->setFont(font);
	label->setStyleSheet("color:#333333");
	//label->setPalette(QPalette(QColor(51,51,51)));
}
