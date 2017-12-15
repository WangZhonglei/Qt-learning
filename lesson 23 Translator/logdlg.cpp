#include "logdlg.h"
#include "ui_logdlg.h"

Logdlg::Logdlg(QWidget *parent) : QDialog(parent), ui(new Ui::Logdlg)
{
    ui->setupUi(this);

    m_PTranslate = new QTranslator(this);  //如果父类被释放，子类也被释放

    m_IsCN = true;
}

Logdlg::~Logdlg()
{
    delete ui;
}

void Logdlg::changeEvent(QEvent *event)
{
    switch (event->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        if((m_IsCN == false) && (ui->comboBox->currentIndex() == 0))
        {
            ui->comboBox->setCurrentIndex(1);
        }
        break;
    default:
        break;
    }
}

void Logdlg::on_comboBox_activated(int index)
{
    switch (index)
    {
        case 0:
        m_PTranslate->load(":/new/prefix1/Translate_CN.qm");
        m_IsCN = true;
            break;
        case 1:
        m_PTranslate->load(":/new/prefix1/Translate_EN.qm");
        m_IsCN = false;
            break;
        default:
            break;
    }
    qApp->installTranslator(m_PTranslate);
    ui->retranslateUi(this);
}
